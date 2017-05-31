#ifndef PLATFORM_PSU_H
#define PLATFORM_PSU_H

#include <onlp/psu.h>
#include <platform_common.h>

typedef enum psu_status_e {
        PSU_STATUS_PRESENT,
        PSU_STATUS_ABSENT,
        PSU_STATUS_MAX
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

int platform_get_num_psus(void);
int platform_get_psu_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt);
void platform_psu_info_init(platform_psu_info_t *info);
int platform_psu_info_get(uint32_t id, platform_psu_info_t *info);
#endif /* PLATFORM_PSU_H */
