#include <platform_driver.h>

int main(int argc, char *argv[]) {
        int ret_val = 0;
        int num_leds = 0;
        uint32_t *led_oid_list = NULL;
        int cnt = 0;
        platform_led_info_t led_info;
        int idx = 0;

        ret_val = platform_driver_init();
        if (ret_val < 0) {
                printf("Failed to platform_driver_init() %d\n", ret_val);
                return ret_val;
        }

        num_leds = platform_get_num_leds();
        printf("Number of Leds: %d\n", num_leds);

        led_oid_list = (uint32_t *)malloc(num_leds * sizeof(uint32_t));
        if (led_oid_list == NULL) {
                printf("led_oid_list: malloc error\n");
                return -1;
        }

        platform_oid_list_init(led_oid_list, num_leds);

        ret_val = platform_get_led_oid_list(led_oid_list, num_leds, &cnt);
        if (ret_val < 0) {
                printf("Error platform_get_led_oid_list()\n");
                return ret_val;
        }

        for (idx = 0; idx < num_leds; idx++) {
                if (led_oid_list[idx] == INVALID_OID) {
                        printf("Error invalid led_oid\n");
                        continue;
                }
                platform_led_info_init(&led_info);
                printf("Led OID: %u\n", led_oid_list[idx]);
                ret_val = platform_led_info_get(led_oid_list[idx], &led_info);
                if (ret_val < 0) {
                        printf("Led Not Present\n");
                        printf("\n\n");
                        continue;
                }
                printf("Description: %s\n", led_info.desc);
                printf("Status: %u\n", led_info.status);
                printf("State: %u\n", led_info.state);
                printf("Mode: %d\n", led_info.mode);
                printf("\n\n");
        }
        free(led_oid_list);
        led_oid_list = NULL;
        platform_driver_dinit();
        return 0;
}
