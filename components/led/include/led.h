#ifndef _LED_H_
#define _LED_H_

typedef enum {
    LED_BLINK,
    LED_ON
} LedCommand;

void configure_led(void);
void init_led(void);
uint8_t get_led_state(void);
void set_led_state_toggle(void);
void led_set_pixel_color(int, int, int);
void on_led(void);
void off_led(void);
void set_command_led(LedCommand);
void turn_on_led(void);

#endif /* _LED_H_ */
