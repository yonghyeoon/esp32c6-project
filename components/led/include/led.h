#ifndef HW_DRIVERS_LED_H_
#define HW_DRIVERS_LED_H_

void blink_led(void);
void configure_led(void);
void init_led(void);

#ifdef CONFIG_BLINK_LED_STRIP
uint8_t get_led_state(void);
void set_led_state_toggle(void);
void led_set_pixel_color(int, int, int);


// #elif CONFIG_BLINK_LED_GPIO
// void blink_led(void);
// void configure_led(void);
// void led_init(void);

#endif
#endif /* HW_DRIVERS_LED_H_ */
