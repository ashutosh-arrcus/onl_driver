#ifndef PLATFORM_FAN_H
#define PLATFORM_FAN_H

#include <onlp/fan.h>
#include <platform_common.h>


typedef enum fan_status_e {
        FAN_STATUS_PRESENT,
        FAN_STATUS_ABSENT,
        FAN_STATUS_MAX
} fan_status_t;

typedef enum fan_dir_e {
        FAN_DIR_B2F,
        FAN_DIR_F2B,
        FAN_DIR_UNKNOWN,
        FAN_DIR_MAX
} fan_dir_t;

typedef struct platform_fan_info_s {
        char desc[INFO_STR_MAX];
        fan_status_t status;
        int rpm;
        int percentage;
        fan_dir_t dir;
        char model[INFO_STR_MAX];
        char serial_num[INFO_STR_MAX];
} platform_fan_info_t;

int platform_get_num_fans(void);                                                 
int platform_get_fan_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);  
void platform_fan_info_init(platform_fan_info_t *info);                          
int platform_fan_info_get(uint32_t id, platform_fan_info_t *info);
#endif /* PLATFORM_FAN_H */
