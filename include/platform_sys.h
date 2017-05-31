#ifndef PLATFORM_SYS_H
#define PLATFORM_SYS_H

#include <onlp/sys.h>
#include <platform_common.h>

typedef struct plaform_sys_info_s {
        char product_name[INFO_STR_MAX];
        char part_number[INFO_STR_MAX];
        char serial_num[INFO_STR_MAX];
        char manufacturer[INFO_STR_MAX];
        char manufacture_date[INFO_STR_MAX];
        char vendor[INFO_STR_MAX];
        char platform_name[INFO_STR_MAX];
        char label_revision[INFO_STR_MAX];
        char country_code[INFO_STR_MAX];
        char diag_version[INFO_STR_MAX];
        char service_tag[INFO_STR_MAX];
        char onie_version[INFO_STR_MAX];
        uint8_t device_version;
        uint8_t mac_addr[MAC_ADDR_LEN];
        uint16_t mac_range;
} platform_sys_info_t;

void platform_sys_info_init(platform_sys_info_t *info);
int platform_sys_info_get(platform_sys_info_t *info);
#endif /* PLATFORM_SYS_H */
