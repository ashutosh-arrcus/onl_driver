#include <platform_driver.h>

extern int (*platformi_sys_info_get)(onlp_sys_info_t*);
extern onlp_sys_info_t sysi;
extern int (*platformi_thermal_info_get)(onlp_oid_t, onlp_thermal_info_t*);

int platform_get_num_thermals(void) {
        int thermal_count = 0;
        onlp_oid_t *oid_ptr;

        if (NULL == platformi_sys_info_get) {
                printf("platform_sys_info_get() is not initialized\n");
                return -1;
        }

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, THERMAL) {
                thermal_count++;
        }
        return thermal_count;
}

int platform_get_thermal_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt) {
        int idx = 0;
        onlp_oid_t *oid_ptr;

        if (NULL == platformi_sys_info_get) {
                printf("platform_sys_info_get() is not initialized\n");
                return -1;
        }

        if (NULL == id_list) {
                printf("Platform Thermal Id List passed is NULL\n");
                return -1;
        }

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, THERMAL) {
                id_list[idx++] = (uint32_t)*oid_ptr;
                if (idx >= arr_max) {
                        break;
                }
        }
        *arr_cnt = idx;
        return 0;
}

void platform_thermal_info_init(platform_thermal_info_t *info) {
        memset(info, 0, sizeof(platform_thermal_info_t));
        info->temperature = INVALID_TEMP;
        info->warn_threshold = INVALID_TEMP;
        info->err_threshold = INVALID_TEMP;
        info->shutdown_threshold = INVALID_TEMP;
}

int platform_thermal_info_get(uint32_t id, platform_thermal_info_t *info) {
        onlp_thermal_info_t thermal_info;
        int ret_val = 0;

        if (NULL == platformi_thermal_info_get) {
                printf("platformi_thermal_info_get() is not initialized\n");
                return -1;
        }

        if (NULL == info) {
                printf("Platform Thermal Info passed is NULL\n");
                return -1;
        }

        ret_val = (*platformi_thermal_info_get)(id, &thermal_info);        
        if (ret_val < 0) {
                printf("Error getting Thermal info for ThermalId: %d\n", id);
                return -1;
        }

        strncpy(info->desc, thermal_info.hdr.description, INFO_STR_MAX);
        if (thermal_info.status & ONLP_THERMAL_STATUS_PRESENT) {
                info->status = THERMAL_PRESENT;
                if (thermal_info.caps & ONLP_THERMAL_CAPS_GET_TEMPERATURE) {
                        info->temperature = thermal_info.mcelsius;
                }
                if (thermal_info.caps & ONLP_THERMAL_CAPS_GET_WARNING_THRESHOLD) {
                        info->warn_threshold = thermal_info.thresholds.warning;
                }
                if (thermal_info.caps & ONLP_THERMAL_CAPS_GET_ERROR_THRESHOLD) {
                        info->err_threshold = thermal_info.thresholds.error;
                }
                if (thermal_info.caps & ONLP_THERMAL_CAPS_GET_SHUTDOWN_THRESHOLD) {
                        info->shutdown_threshold = thermal_info.thresholds.shutdown;
                }
        } else {
                info->status = THERMAL_FAILED;
        }

        return 0;
}
