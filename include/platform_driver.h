#ifndef PLATFORM_DRIVER_H
#define PLATFORM_DRIVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <onlp/sys.h>
#include <onlp/fan.h>
#include <onlp/psu.h>
#include <onlp/thermal.h>
#include <onlp/led.h>

#define INFO_STR_MAX 64
#define INVALID_OID (-1)
#define MAC_ADDR_LEN (6)
#define INVALID_TEMP (-1)

typedef enum fan_direction_e {
        INVALID_DIR = 0,
        BACK_TO_FRONT = 1,
        FRONT_TO_BACK = 2,
        MAX_DIRECTION = 3 //Always be last
} fan_direction_t;

typedef enum fan_status_e {
        FAN_PRESENT = 1,
        FAN_NOT_PRESENT = 2
} fan_status_t;

typedef struct platform_fan_info_s {
        char desc[INFO_STR_MAX];
        int rpm;
        fan_status_t present;
        int percentage;
        fan_direction_t direction;
        char model[INFO_STR_MAX];
        char serial_num[INFO_STR_MAX];
} platform_fan_info_t;

typedef enum psu_status_e {
        PSU_PRESENT = 1,
        PSU_NOT_PRESENT = 2
} psu_status_t;

typedef struct platform_psu_info_s {
        char desc[INFO_STR_MAX];
        int milli_volt_in;
        int milli_volt_out;
        int milli_amp_in;
        int milli_amp_out;
        int milli_watt_in;
        int milli_watt_out;
        psu_status_t status;
        char model[INFO_STR_MAX];
        char serial_num[INFO_STR_MAX];
} platform_psu_info_t;

typedef struct plaform_sys_info_s {
        char product_name[INFO_STR_MAX];
        char part_number[INFO_STR_MAX];
        char serial_num[INFO_STR_MAX];
        uint8_t mac_addr[MAC_ADDR_LEN];
        uint16_t mac_range;
        char manufacturer[INFO_STR_MAX];
        char manufacture_date[INFO_STR_MAX];
        char vendor[INFO_STR_MAX];
        char platform_name[INFO_STR_MAX];
        uint8_t device_version;
        char label_revision[INFO_STR_MAX];
        char country_code[INFO_STR_MAX];
        char diag_version[INFO_STR_MAX];
        char service_tag[INFO_STR_MAX];
        char onie_version[INFO_STR_MAX];
} platform_sys_info_t;

typedef enum thermal_status_e {
        THERMAL_PRESENT = 1,
        THERMAL_FAILED = 2
} thermal_status_t;

typedef struct platform_thermal_info_s {
        char desc[INFO_STR_MAX];
        thermal_status_t status;
        int temperature;
        int warn_threshold; //milli celsius
        int err_threshold; //milli celsius
        int shutdown_threshold; //milli celsius
} platform_thermal_info_t;

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

int platform_driver_init(void);
void platform_driver_dinit(void);
void platform_oid_list_init(uint32_t *id_list, int size);
int platform_get_num_fans(void);
int platform_get_fan_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_fan_info_init(platform_fan_info_t *info);
int platform_fan_info_get(uint32_t id, platform_fan_info_t *info);
void platform_sys_info_init(platform_sys_info_t *info);
int platform_sys_info_get(platform_sys_info_t *info);
int platform_get_num_psus(void);
int platform_get_psu_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_psu_info_init(platform_psu_info_t *info);
int platform_psu_info_get(uint32_t id, platform_psu_info_t *info);
int platform_get_num_thermals(void);
int platform_get_thermal_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_thermal_info_init(platform_thermal_info_t *info);
int platform_thermal_info_get(uint32_t id, platform_thermal_info_t *info);
int platform_get_num_leds(void);
int platform_get_led_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_led_info_init(platform_led_info_t *info);
int platform_led_info_get(uint32_t id, platform_led_info_t *info);
#endif /* PLATFORM_DRIVER_H */
