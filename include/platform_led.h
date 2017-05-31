#ifndef PLATFORM_LED_H
#define PLATFORM_LED_H

#include <onlp/led.h>
#include <platform_common.h>

typedef enum led_caps_e {                                                   
    LED_CAPS_ON_OFF = (1 << 0),                                             
    LED_CAPS_CHAR = (1 << 1),                                               
    LED_CAPS_RED = (1 << 10),                                               
    LED_CAPS_RED_BLINKING = (1 << 11),                                      
    LED_CAPS_ORANGE = (1 << 12),                                            
    LED_CAPS_ORANGE_BLINKING = (1 << 13),                                   
    LED_CAPS_YELLOW = (1 << 14),                                            
    LED_CAPS_YELLOW_BLINKING = (1 << 15),                                   
    LED_CAPS_GREEN = (1 << 16),                                             
    LED_CAPS_GREEN_BLINKING = (1 << 17),                                    
    LED_CAPS_BLUE = (1 << 18),                                              
    LED_CAPS_BLUE_BLINKING = (1 << 19),                                     
    LED_CAPS_PURPLE = (1 << 20),                                            
    LED_CAPS_PURPLE_BLINKING = (1 << 21),                                   
    LED_CAPS_AUTO = (1 << 22),                                              
    LED_CAPS_AUTO_BLINKING = (1 << 23),                                     
} led_caps_t;

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

typedef enum led_status_e {                                              
    LED_STATUS_PRESENT = (1 << 0),                                       
    LED_STATUS_FAILED = (1 << 1),                                        
    LED_STATUS_ON = (1 << 2),                                            
} led_status_t;

typedef struct platform_led_info_s {
        char desc[INFO_STR_MAX];
        uint8_t status;
        led_mode_t mode;
        uint32_t caps;
        char character;
} platform_led_info_t;

int platform_get_num_leds(void);
int platform_get_led_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_led_info_init(platform_led_info_t *info);
int platform_led_info_get(uint32_t id, platform_led_info_t *info);
#endif /* PLATFORM_LED_H */
