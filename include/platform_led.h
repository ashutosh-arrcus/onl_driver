#ifndef PLATFORM_LED_H
#define PLATFORM_LED_H

#include <onlp/led.h>
#include <platform_common.h>

typedef enum led_mode_e {                                                
    LED_MODE_OFF,                                                        
    LED_MODE_ON,                                                         
    LED_MODE_BLINKING,                                                   
    LED_MODE_RED = 10,                                                   
    LED_MODE_RED_BLINKING = 11,                                          
    LED_MODE_ORANGE = 12,                                                
    LED_MODE_ORANGE_BLINKING = 13,                                       
    LED_MODE_YELLOW = 14,                                                
    LED_MODE_YELLOW_BLINKING = 15,                                       
    LED_MODE_GREEN = 16,                                                 
    LED_MODE_GREEN_BLINKING = 17,                                        
    LED_MODE_BLUE = 18,                                                  
    LED_MODE_BLUE_BLINKING = 19,                                         
    LED_MODE_PURPLE = 20,                                                
    LED_MODE_PURPLE_BLINKING = 21,                                       
    LED_MODE_AUTO = 22,                                                  
    LED_MODE_AUTO_BLINKING = 23,                                         
} led_mode_t;

typedef enum led_state_e {                                              
    LED_STATE_ON,                                            
    LED_STATE_OFF,
    LED_STATE_MAX
} led_state_t;

typedef enum led_status_e {                                              
    LED_STATUS_PRESENT,
    LED_STATUS_ABSENT,
    LED_STATUS_MAX
} led_status_t;

typedef struct platform_led_info_s {
        char desc[INFO_STR_MAX];
        led_status_t status;
        led_state_t state;
        led_mode_t mode;
} platform_led_info_t;

int platform_get_num_leds(void);
int platform_get_led_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_led_info_init(platform_led_info_t *info);
int platform_led_info_get(uint32_t id, platform_led_info_t *info);
#endif /* PLATFORM_LED_H */
