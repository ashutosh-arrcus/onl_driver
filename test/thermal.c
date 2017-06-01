#include <platform_driver.h>

int main(int argc, char *argv[]) {
        int ret_val = 0;
        int num_thermals = 0;
        uint32_t *thermal_oid_list = NULL;
        int cnt = 0;
        platform_thermal_info_t thermal_info;
        int idx = 0;

        ret_val = platform_driver_init();
        if (ret_val < 0) {
                printf("Failed to platform_driver_init() %d\n", ret_val);
                return ret_val;
        }

        num_thermals = platform_get_num_thermals();
        printf("Number of Thermals: %d\n", num_thermals);

        thermal_oid_list = (uint32_t *)malloc(num_thermals * sizeof(uint32_t));
        if (thermal_oid_list == NULL) {
                printf("thermal_oid_list: malloc error\n");
                return -1;
        }

        platform_oid_list_init(thermal_oid_list, num_thermals);

        ret_val = platform_get_thermal_oid_list(thermal_oid_list, num_thermals, &cnt);
        if (ret_val < 0) {
                printf("Error platform_get_thermal_oid_list()\n");
                return ret_val;
        }

        for (idx = 0; idx < num_thermals; idx++) {
                if (thermal_oid_list[idx] == INVALID_OID) {
                        printf("Error invalid thermal_oid\n");
                        continue;
                }
                platform_thermal_info_init(&thermal_info);
                printf("Thermal OID: %u\n", thermal_oid_list[idx]);
                ret_val = platform_thermal_info_get(thermal_oid_list[idx], &thermal_info);
                if (ret_val < 0) {
                        printf("Thermal Present: %d\n", THERMAL_STATUS_ABSENT);
                        printf("\n\n");
                        continue;
                }
                printf("Thermal Description: %s\n", thermal_info.desc);
                printf("Thermal Present: %d\n", thermal_info.status);
                printf("Temperature: %f\n", thermal_info.temperature);
                printf("Warning Threshold: %f\n", thermal_info.warn_threshold);
                printf("Error Threshold: %f\n", thermal_info.err_threshold);
                printf("Shutdown Threshold: %f\n", thermal_info.shutdown_threshold);
                printf("\n\n");
        }
        free(thermal_oid_list);
        thermal_oid_list = NULL;
        platform_driver_dinit();
        return 0;
}
