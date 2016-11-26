
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "nrf.h"
#include "nrf_drv_adc.h"
#include "nrf_soc.h"
#include "app_util_platform.h"

volatile int32_t adc_sample;

#define ADC_BUFFER_SIZE 1                                /**< Size of buffer for ADC samples.  */
static nrf_adc_value_t       adc_buffer[ADC_BUFFER_SIZE]; /**< ADC buffer. */
static nrf_drv_adc_channel_t m_channel_config = NRF_DRV_ADC_DEFAULT_CHANNEL(NRF_ADC_CONFIG_INPUT_3); /**< Channel instance. Default configuration used. */

uint32_t user_start_adc() {
	APP_ERROR_CHECK(nrf_drv_adc_buffer_convert(adc_buffer,ADC_BUFFER_SIZE));
	nrf_drv_adc_sample();
}

uint16_t user_get_adc() {
	return (uint16_t)adc_sample;
}

/**
 * @brief ADC interrupt handler.
 */
static void adc_event_handler(nrf_drv_adc_evt_t const * p_event)
{
    if (p_event->type == NRF_DRV_ADC_EVT_DONE)
    {
        uint32_t i, temp = 0;
        for (i = 0; i < p_event->data.done.size; i++)
        {
			temp += p_event->data.done.p_buffer[i];
//            NRF_LOG_PRINTF("Current sample value: %d\r\n", p_event->data.done.p_buffer[i]);
        }
		adc_sample = temp / ADC_BUFFER_SIZE;
    }
}

/**
 * @brief ADC initialization.
 */
void adc_config(void)
{
    ret_code_t ret_code;
    nrf_drv_adc_config_t config = NRF_DRV_ADC_DEFAULT_CONFIG;

    ret_code = nrf_drv_adc_init(&config, adc_event_handler);
    APP_ERROR_CHECK(ret_code);
	m_channel_config.config.config.input = ADC_CONFIG_INPSEL_AnalogInputOneThirdPrescaling;

    nrf_drv_adc_channel_enable(&m_channel_config);
}

/*
int main(void)
{
    LEDS_CONFIGURE(BSP_LED_0_MASK);
    LEDS_OFF(BSP_LED_0_MASK);

    adc_config();
    UNUSED_RETURN_VALUE(NRF_LOG_INIT());

	SEGGER_RTT_Init();
    SEGGER_RTT_printf(0, "\r\nello,rtt\r\n");
    NRF_LOG_PRINTF("ADC example\r\n");

    while (true)
    {
        APP_ERROR_CHECK(nrf_drv_adc_buffer_convert(adc_buffer,ADC_BUFFER_SIZE));
        uint32_t i;
        for (i = 0; i < ADC_BUFFER_SIZE; i++)
        {
            // manually trigger ADC conversion
            nrf_drv_adc_sample();
            // enter into sleep mode
            __SEV();
            __WFE();
            __WFE();

            nrf_delay_ms(100);
            LEDS_INVERT(BSP_LED_0_MASK);
        }
    }
}
*/
