#include <platform_driver.h>

extern int (*platformi_sys_info_get)(onlp_sys_info_t*);
extern onlp_sys_info_t sysi;
extern int (*platformi_fan_info_get)(onlp_oid_t, onlp_fan_info_t*);

int platform_get_num_fans(void) {
        int fan_count = 0;
        onlp_oid_t *oid_ptr;

        if (NULL == platformi_sys_info_get) {
                printf("platform_sys_info_get() is not initialized\n");
                return -1;
        }

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, FAN) {
                fan_count++;
        }
        return fan_count;
}

int platform_get_fan_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt) {
        int idx = 0;
        onlp_oid_t *oid_ptr;

        if (NULL == platformi_sys_info_get) {
                printf("platform_sys_info_get() is not initialized\n");
                return -1;
        }

        if (NULL == id_list) {
                printf("Platform Fan Id List passed is NULL\n");
                return -1;
        }

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, FAN) {
                id_list[idx++] = (uint32_t)*oid_ptr;
                if (idx >= arr_max) {
                        break;
                }
        }
        *arr_cnt = idx;
        return 0;
}

void platform_fan_info_init(platform_fan_info_t *info) {
        memset(info->desc, 0, INFO_STR_MAX * sizeof(char));
        info->status = FAN_STATUS_ABSENT;
        info->rpm = 0;
        info->percentage = 0;
        info->dir = FAN_DIR_UNKNOWN;
        memset(info->model, 0, INFO_STR_MAX * sizeof(char));
        memset(info->serial_num, 0, INFO_STR_MAX * sizeof(char));
}

int platform_fan_info_get(uint32_t id, platform_fan_info_t *info) {
        onlp_fan_info_t fan_info;
        int ret_val = 0;

        if (NULL == platformi_fan_info_get) {
                printf("platformi_fan_info_get() is not initialized\n");
                return -1;
        }

        if (NULL == info) {
                printf("Platform Fan Info passed is NULL\n");
                return -1;
        }

        ret_val = (*platformi_fan_info_get)(id, &fan_info);        
        if (ret_val < 0) {
                printf("Error getting Fan info for FanId: %d\n", id);
                return -1;
        }

        strncpy(info->desc, fan_info.hdr.description, INFO_STR_MAX);
        if (fan_info.status & ONLP_FAN_STATUS_PRESENT) {
                info->status = FAN_STATUS_PRESENT;
                info->rpm = fan_info.rpm;
                info->percentage = fan_info.percentage;
                if (fan_info.status & ONLP_FAN_STATUS_B2F) {
                        info->dir = FAN_DIR_B2F;
                } else if (fan_info.status & ONLP_FAN_STATUS_F2B) {
                        info->dir = FAN_DIR_F2B;
                } else {
                        info->dir = FAN_DIR_UNKNOWN;
                }
                strncpy(info->model, fan_info.model, INFO_STR_MAX);
                strncpy(info->serial_num, fan_info.serial, INFO_STR_MAX);
        } else {
                info->status = FAN_STATUS_ABSENT;
        }
        return 0;
}
