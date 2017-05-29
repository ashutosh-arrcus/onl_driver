#ifndef PLATFORM_DRIVER_H
#define PLATFORM_DRIVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <onlp/sys.h>
#include <onlp/fan.h>

#define INFO_STR_MAX 64
#define INVALID_OID (-1)

typedef struct platform_fan_info_s {
        int rpm;
        char model[INFO_STR_MAX];
        char serial_num[INFO_STR_MAX];
} platform_fan_info_t;

int platform_driver_init(void);
void platform_driver_dinit(void);
void platform_oid_list_init(uint32_t *id_list, int size);
int platform_get_num_fans(void);
int platform_get_fan_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_fan_info_init(platform_fan_info_t *info);
int platform_fan_info_get(uint32_t id, platform_fan_info_t *info);

#endif /* PLATFORM_DRIVER_H */
