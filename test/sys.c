#include <platform_driver.h>

int main(int argc, char *argv[]) {
        int ret_val = 0;
        int idx = 0;
        platform_sys_info_t sys_info;

        ret_val = platform_driver_init();
        if (ret_val < 0) {
                printf("Failed to platform_driver_init() %d\n", ret_val);
                return ret_val;
        }

        platform_sys_info_init(&sys_info);
        ret_val = platform_sys_info_get(&sys_info);
        if (ret_val < 0) {
                printf("Failed to get platform sys info\n");
                return ret_val;
        }
        printf("Product Name: %s\n", sys_info.product_name);
        printf("Part Number: %s\n", sys_info.part_number);
        printf("Serial Number: %s\n", sys_info.serial_num);
        printf("Mac Address: %02X:%02X:%02X:%02X:%02X:%02X\n",
                sys_info.mac_addr[0], sys_info.mac_addr[1],
                sys_info.mac_addr[2], sys_info.mac_addr[3],
                sys_info.mac_addr[4], sys_info.mac_addr[5]);
        printf("Mac Range: %d\n", sys_info.mac_range);
        printf("Manufacturer: %s\n", sys_info.manufacturer);
        printf("Manufacture Date: %s\n", sys_info.manufacture_date);
        printf("Vendor: %s\n", sys_info.vendor);
        printf("Platform Name: %s\n", sys_info.platform_name);
        printf("Device Version: %u\n", sys_info.device_version);
        printf("Label Revision: %s\n", sys_info.label_revision);
        printf("Country Code: %s\n", sys_info.country_code);
        printf("Diag Version: %s\n", sys_info.diag_version);
        printf("Service Tag: %s\n", sys_info.service_tag);
        printf("ONIE Version: %s\n", sys_info.onie_version);
        platform_driver_dinit();
        return 0;
}
