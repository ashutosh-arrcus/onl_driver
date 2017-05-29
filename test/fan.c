#include <platform_driver.h>

int main(int argc, char *argv[]) {
        int ret_val = 0;
        int num_fans = 0;
        uint32_t *fan_oid_list = NULL;
        int cnt = 0;
        platform_fan_info_t fan_info;
        int idx = 0;

        ret_val = platform_driver_init();
        if (ret_val < 0) {
                printf("Failed to platform_driver_init() %d\n", ret_val);
                return ret_val;
        }

        num_fans = platform_get_num_fans();
        printf("Number of Fans: %d\n", num_fans);

        fan_oid_list = (uint32_t *)malloc(num_fans * sizeof(uint32_t));
        if (fan_oid_list == NULL) {
                printf("fan_oid_list: malloc error\n");
                return -1;
        }

        platform_oid_list_init(fan_oid_list, num_fans);

        ret_val = platform_get_fan_oid_list(fan_oid_list, num_fans, &cnt);
        if (ret_val < 0) {
                printf("Error platform_get_fan_oid_list()\n");
                return ret_val;
        }

        for (idx = 0; idx < num_fans; idx++) {
                if (fan_oid_list[idx] == INVALID_OID) {
                        printf("Error invalid fan_oid\n");
                        continue;
                }
                platform_fan_info_init(&fan_info);
                ret_val = platform_fan_info_get(fan_oid_list[idx], &fan_info);
                if (ret_val < 0) {
                        printf("Error platform_fan_info_get()\n");
                        continue;
                }
                printf("Fan OID: %u RPM: %d Model: %s SerialNum: %s\n",
                        fan_oid_list[idx], fan_info.rpm, fan_info.model,
                        fan_info.serial_num);
        }
        free(fan_oid_list);
        fan_oid_list = NULL;
        platform_driver_dinit();
        return 0;
}
