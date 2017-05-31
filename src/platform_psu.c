#include <platform_driver.h>

extern int (*platformi_sys_info_get)(onlp_sys_info_t*);
extern onlp_sys_info_t sysi;
extern int (*platformi_psu_info_get)(onlp_oid_t, onlp_psu_info_t*);

int platform_get_num_psus(void) {
        int psu_count = 0;
        onlp_oid_t *oid_ptr;

        if (NULL == platformi_sys_info_get) {
                printf("platform_sys_info_get() is not initialized\n");
                return -1;
        }

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, PSU) {
                psu_count++;
        }
        return psu_count;
}

int platform_get_psu_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt) {
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

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, PSU) {
                id_list[idx++] = (uint32_t)*oid_ptr;
                if (idx >= arr_max) {
                        break;
                }
        }
        *arr_cnt = idx;
        return 0;
}

void platform_psu_info_init(platform_psu_info_t *info) {
        memset(info->desc, 0, INFO_STR_MAX * sizeof(char));
        info->milli_volt_in = 0;
        info->milli_volt_out = 0;
        info->milli_amp_in = 0;
        info->milli_amp_out = 0;
        info->milli_watt_in = 0;
        info->milli_watt_out = 0;
        info->status = PSU_STATUS_ABSENT;
        memset(info->model, 0, INFO_STR_MAX * sizeof(char));
        memset(info->serial_num, 0, INFO_STR_MAX * sizeof(char));
}

int platform_psu_info_get(uint32_t id, platform_psu_info_t *info) {
        onlp_psu_info_t psu_info;
        int ret_val = 0;

        if (NULL == platformi_psu_info_get) {
                printf("platformi_psu_info_get() is not initialized\n");
                return -1;
        }

        if (NULL == info) {
                printf("Platform PSU Info passed is NULL\n");
                return -1;
        }

        ret_val = (*platformi_psu_info_get)(id, &psu_info);        
        if (ret_val < 0) {
                printf("Error getting PSU info for PSUId: %d\n", id);
                return -1;
        }

        strncpy(info->desc, psu_info.hdr.description, INFO_STR_MAX);
        if (psu_info.status & ONLP_PSU_STATUS_PRESENT) {
                info->status = PSU_STATUS_PRESENT;
                info->milli_volt_in = psu_info.mvin;
                info->milli_volt_out = psu_info.mvout;
                info->milli_amp_in = psu_info.miin;
                info->milli_amp_out = psu_info.miout;
                info->milli_watt_in = psu_info.mpin;
                info->milli_watt_out = psu_info.mpout;
                strncpy(info->model, psu_info.model, INFO_STR_MAX);
                strncpy(info->serial_num, psu_info.serial, INFO_STR_MAX);
        } else {
                info->status = PSU_STATUS_ABSENT;
        }

        return 0;
}
