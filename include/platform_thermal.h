#ifndef PLATFORM_THERMAL_H
#define PLATFORM_THERMAL_H

#include <onlp/thermal.h>
#include <platform_common.h>

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

int platform_get_num_thermals(void);
int platform_get_thermal_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_thermal_info_init(platform_thermal_info_t *info);
int platform_thermal_info_get(uint32_t id, platform_thermal_info_t *info);
#endif /* PLATFORM_THERMAL_H */
