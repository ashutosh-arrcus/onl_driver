#include <platform_driver.h>

int main(int argc, char *argv[]) {
        int ret_val = 0;
        int num_psus = 0;
        uint32_t *psu_oid_list = NULL;
        int cnt = 0;
        platform_psu_info_t psu_info;
        int idx = 0;

        ret_val = platform_driver_init();
        if (ret_val < 0) {
                printf("Failed to platform_driver_init() %d\n", ret_val);
                return ret_val;
        }

        num_psus = platform_get_num_psus();
        printf("Number of PSUs: %d\n", num_psus);

        psu_oid_list = (uint32_t *)malloc(num_psus * sizeof(uint32_t));
        if (psu_oid_list == NULL) {
                printf("psu_oid_list: malloc error\n");
                return -1;
        }

        platform_oid_list_init(psu_oid_list, num_psus);

        ret_val = platform_get_psu_oid_list(psu_oid_list, num_psus, &cnt);
        if (ret_val < 0) {
                printf("Error platform_get_psu_oid_list()\n");
                return ret_val;
        }

        for (idx = 0; idx < num_psus; idx++) {
                if (psu_oid_list[idx] == INVALID_OID) {
                        printf("Error invalid psu_oid\n");
                        continue;
                }
                platform_psu_info_init(&psu_info);
                printf("PSU OID: %u\n", psu_oid_list[idx]);
                ret_val = platform_psu_info_get(psu_oid_list[idx], &psu_info);
                if (ret_val < 0) {
                        printf("PSU Present: %d\n", PSU_STATUS_ABSENT);
                        printf("\n\n");
                        continue;
                }
                printf("PSU Description: %s\n", psu_info.desc);
                printf("PSU Present: %d\n", psu_info.status);
                printf("Milli Volts In: %d\n", psu_info.milli_volt_in);
                printf("Milli Volts Out: %d\n", psu_info.milli_volt_out);
                printf("Milli Amp In: %d\n", psu_info.milli_amp_in);
                printf("Milli Amp Out: %d\n", psu_info.milli_amp_out);
                printf("Milli Watts In: %d\n", psu_info.milli_watt_in);
                printf("Milli Watts Out: %d\n", psu_info.milli_watt_out);
                printf("Model: %s\n", psu_info.model);
                printf("Serial Num: %s\n", psu_info.serial_num);
                printf("\n\n");
        }
        free(psu_oid_list);
        psu_oid_list = NULL;
        platform_driver_dinit();
        return 0;
}
