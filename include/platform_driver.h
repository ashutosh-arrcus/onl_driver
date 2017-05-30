#ifndef PLATFORM_DRIVER_H
#define PLATFORM_DRIVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <onlp/sys.h>
#include <onlp/fan.h>
#include <onlp/psu.h>

#define INFO_STR_MAX 64
#define INVALID_OID (-1)
#define MAC_ADDR_LEN (6)

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
#endif /* PLATFORM_DRIVER_H */
