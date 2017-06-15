#include <platform_driver.h>

int main(int argc, char *argv[]) {
        int ret_val = 0;
        int num_of_sfps = 0;
        platform_sfp_info_t *info = NULL;
        int idx = 0;

        ret_val = platform_driver_init();
        if (ret_val < 0) {
                printf("Failed to platform_driver_init() %d\n", ret_val);
                return ret_val;
        }
        printf("Platform SFP Bitmap Get:\n");
        ret_val = platform_get_num_of_sfps(&num_of_sfps);
        if (ret_val < 0) {
                printf("Failed to platform_get_num_of_sfps() %d\n", ret_val);
                return ret_val;
        }

        info = (platform_sfp_info_t *)malloc(num_of_sfps * sizeof(platform_sfp_info_t));
        platform_sfp_info_bulk_init(info, num_of_sfps);
        ret_val = platform_sfp_info_bulk_get(info, num_of_sfps);
        if (ret_val < 0) {
                printf("Failed to platform_sfp_info_bulk_get() %d\n", ret_val);
                return ret_val;
        }

        for (idx = 0; idx < num_of_sfps; idx++) {
          platform_sfp_info_dump(&info[idx]);
        }
        platform_driver_dinit();
        return 0;
}
