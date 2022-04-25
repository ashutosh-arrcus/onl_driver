#include <platform_driver.h>
uint8_t eeprom[] = {
0x11, 0x07, 0x00, 0x0f, 0x00, 0xff, 0x40, 0x00, 0x00, 0x55, 0x55, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x94, 0x00, 0x00, 0x83, 0xf9, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0d, 0x48, 0x0d, 0x48, 0x0d, 0x48, 
0x0d, 0x48, 0x33, 0x86, 0x33, 0x86, 0x33, 0x86, 0x33, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 
0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x11, 0x8c, 0x23, 0x80, 0x00, 0x00, 0x00, 0x40, 0x00, 0x02, 0x00, 0x05, 0xff, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x0b, 0x00, 0x54, 0x31, 0x4e, 0x45, 0x58, 0x55, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20, 
0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x54, 0x31, 0x2d, 0x41, 0x4f, 0x43, 0x2d, 0x31, 
0x30, 0x30, 0x47, 0x2d, 0x31, 0x31, 0x4d, 0x20, 0x20, 0x20, 0x42, 0x68, 0x07, 0xd0, 0x46, 0x56, 
0x01, 0x07, 0xc0, 0xda, 0x54, 0x31, 0x44, 0x30, 0x30, 0x30, 0x31, 0x35, 0x38, 0x20, 0x20, 0x20, 
0x20, 0x20, 0x20, 0x20, 0x31, 0x39, 0x30, 0x38, 0x33, 0x30, 0x20, 0x20, 0x08, 0x00, 0x00, 0xf6, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 
};

uint8_t eeprom_2[] = {
0x0d, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x89, 0x00, 0x00, 0x81, 0x10, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x49, 0x20, 0x46, 0xf0, 0x45, 0xb0, 0x4b, 0x50, 0x0b, 0x60, 0x0b, 0xa0, 0x0b, 0xc0,
0x0b, 0x60, 0x2d, 0x80, 0x2e, 0x80, 0x2f, 0x00, 0x2d, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00,
0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0x0d, 0x00, 0xec, 0x80, 0x50, 0x00, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x86, 0xc4, 0x79, 0x18, 0x84, 0xd0, 0x7b, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0x01, 0xf4, 0xff, 0xff, 0x03, 0xe8, 0x1b, 0x58, 0x01, 0xf4, 0x17, 0x70, 0x02, 0x42,
0x6d, 0x60, 0x07, 0xd0, 0x5d, 0xc0, 0x0b, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

uint8_t eeprom_3[] = {
0x0d, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x0d, 0x10, 0x23, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x67, 0x00, 0x00, 0x00,
0x00, 0x00, 0x03, 0xa0, 0x46, 0x69, 0x62, 0x65, 0x72, 0x73, 0x74, 0x6f, 0x72, 0x65, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x09, 0x3a, 0x51, 0x53, 0x46, 0x50, 0x2d, 0x34, 0x30, 0x47,
0x2d, 0x44, 0x41, 0x43, 0x20, 0x20, 0x20, 0x20, 0x30, 0x33, 0x04, 0x06, 0x00, 0x00, 0x46, 0xa9,
0x00, 0x00, 0x00, 0xc0, 0x47, 0x31, 0x38, 0x30, 0x34, 0x30, 0x30, 0x33, 0x35, 0x31, 0x31, 0x2d,
0x31, 0x20, 0x20, 0x20, 0x32, 0x30, 0x31, 0x38, 0x30, 0x34, 0x32, 0x36, 0x00, 0x00, 0x00, 0x53,
0x00, 0x00, 0x08, 0x24, 0xa3, 0xf5, 0x42, 0x04, 0xd1, 0xef, 0xab, 0x29, 0x27, 0x14, 0xee, 0x12,
0x3a, 0xaa, 0x82, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1d, 0x7d, 0x75, 0x06
};

uint8_t eeprom_4[] = {
  0x0d, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x0d, 0x00, 0x23, 0x08, 0x00, 0x00, 0x00, 0x41, 0x80, 0x80, 0xd5, 0x00, 0x64, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x02, 0xa0, 0x57, 0x32, 0x57, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x07, 0x00, 0x00, 0x00, 0x37, 0x35, 0x2d, 0x51, 0x30, 0x31, 0x30, 0x2d,
  0x34, 0x34, 0x49, 0x4e, 0x20, 0x20, 0x20, 0x20, 0x41, 0x20, 0x05, 0x08, 0x00, 0x00, 0x46, 0xb6,
  0x00, 0x00, 0x00, 0x00, 0x31, 0x34, 0x31, 0x32, 0x32, 0x31, 0x33, 0x30, 0x30, 0x30, 0x35, 0x30,
  0x20, 0x20, 0x20, 0x20, 0x31, 0x35, 0x30, 0x31, 0x31, 0x39, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3
};

//LEGRAND AOC QSFP+
uint8_t eeprom_5[] = {
0x0d, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x4b, 0x00, 0x00, 0x86, 0xb0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x49, 0x20, 0x46, 0xc8, 0x48, 0xf8, 0x45, 0x88, 0x0b, 0x80, 0x0b, 0x80, 0x0b, 0x40,
0x0b, 0xc0, 0x2e, 0x00, 0x2e, 0x00, 0x2d, 0x00, 0x2f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00,
0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03,
0x5a, 0x00, 0xec, 0x00, 0x50, 0x00, 0xf6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x86, 0xc4, 0x79, 0x18, 0x84, 0xd0, 0x7b, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xff, 0xff, 0x01, 0xf4, 0xff, 0xff, 0x03, 0xe8, 0x1b, 0x58, 0x01, 0xf4, 0x17, 0x70, 0x02, 0xee,
0x6d, 0x60, 0x07, 0xd0, 0x5d, 0xc0, 0x0b, 0xb8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

//T1 Nexus
uint8_t eeprom_6[] = {
0x11, 0x07, 0x02, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x06, 0x00, 0x00, 0x87, 0x71, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x3b, 0x88, 0x3b, 0x88, 0x3b, 0x88, 0x3b, 0x88, 0x0d, 0x48, 0x0d, 0x48, 0x0d, 0x48,
0x0d, 0x48, 0x33, 0x86, 0x33, 0x86, 0x33, 0x86, 0x33, 0x86, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
0x00, 0x00, 0xff, 0x00, 0xff, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x11, 0x8c, 0x23, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x02, 0x00, 0x05, 0xff, 0x00, 0x00, 0x00,
0x00, 0x00, 0x0b, 0x00, 0x54, 0x31, 0x4e, 0x45, 0x58, 0x55, 0x53, 0x20, 0x20, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x54, 0x31, 0x2d, 0x41, 0x4f, 0x43, 0x2d, 0x31,
0x30, 0x30, 0x47, 0x2d, 0x31, 0x31, 0x4d, 0x20, 0x20, 0x20, 0x42, 0x68, 0x07, 0xd0, 0x46, 0xd6,
0x01, 0x07, 0xc0, 0xda, 0x54, 0x31, 0x44, 0x30, 0x30, 0x30, 0x31, 0x35, 0x38, 0x20, 0x20, 0x20,
0x20, 0x20, 0x20, 0x20, 0x31, 0x39, 0x30, 0x38, 0x33, 0x30, 0x20, 0x20, 0x08, 0x00, 0x00, 0xf6,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

int main(int argc, char *argv[]) {
        int ret_val;
        platform_sfp_info_t info;


        ret_val = platform_driver_init();
        if (ret_val < 0) {
                printf("Failed to platform_driver_init() %d\n", ret_val);
                return ret_val;
        }

        memset(&info, 0, sizeof(platform_sfp_info_t));
        platform_sfp_parse(eeprom, &info);
        platform_sfp_info_dump(&info);

        memset(&info, 0, sizeof(platform_sfp_info_t));
        platform_sfp_parse(eeprom_2, &info);
        platform_sfp_info_dump(&info);

        memset(&info, 0, sizeof(platform_sfp_info_t));
        platform_sfp_parse(eeprom_3, &info);
        platform_sfp_info_dump(&info);

        memset(&info, 0, sizeof(platform_sfp_info_t));
        platform_sfp_parse(eeprom_4, &info);
        platform_sfp_info_dump(&info);

        memset(&info, 0, sizeof(platform_sfp_info_t));
        platform_sfp_parse(eeprom_5, &info);
        platform_sfp_info_dump(&info);

        memset(&info, 0, sizeof(platform_sfp_info_t));
        platform_sfp_parse(eeprom_6, &info);
        platform_sfp_info_dump(&info);

        platform_driver_dinit();
        return 0;
}
