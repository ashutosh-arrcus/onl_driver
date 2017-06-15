#include <platform_driver.h>

/* ONLP init */
int (*platformi_init)(void);
static void *lib_hdl;

/* System EEPROM */
int (*platformi_sys_info_get)(onlp_sys_info_t*);
onlp_sys_info_t sysi;

/* FAN */
int (*platformi_fan_info_get)(onlp_oid_t, onlp_fan_info_t*);

/* PSU */
int (*platformi_psu_info_get)(onlp_oid_t, onlp_psu_info_t*);

/* THERMAL */
int (*platformi_thermal_info_get)(onlp_oid_t, onlp_thermal_info_t*);

/* LED */
int (*platformi_led_info_get)(onlp_oid_t, onlp_led_info_t*);

/* SFP */
int (*platformi_sfp_init)(void);
void (*platformi_sfp_deinit)(void);
void (*platformi_sfp_bitmap_t_init)(onlp_sfp_bitmap_t *bmap);
int (*platformi_sfp_bitmap_get)(onlp_sfp_bitmap_t *bmap);
int (*platformi_sfp_is_present)(int port);
//int (*platformi_sfp_port_map)(int port, int *rport);
int (*platformi_sfp_eeprom_read)(int port, uint8_t **data);
int (*platformi_sfp_presence_bitmap_get)(onlp_sfp_bitmap_t *bmap);
int (*platformi_sff_eeprom_parse)(sff_eeprom_t *rv, uint8_t *eeprom);
const char* (*platformi_sff_sfp_type_name)(sff_sfp_type_t e);
const char* (*platformi_sff_module_type_name)(sff_module_type_t e);
const char* (*platformi_sff_media_type_name)(sff_media_type_t e);
const char* (*platformi_sff_module_caps_name)(sff_module_caps_t e);

#define LIB_NAME "/lib/x86_64-linux-gnu/libonlp.so"

static int
platform_symbol_load() {
        lib_hdl = dlopen(LIB_NAME, RTLD_LAZY);
        if (NULL == lib_hdl) {
                printf("Error: %s\n", dlerror());
                return -1;
        }

        platformi_init = dlsym(lib_hdl, "onlp_init");
        if (NULL != dlerror()) {
                printf("Error: onlp_init() %s\n", dlerror());
                return -1;
        }

        platformi_sys_info_get = dlsym(lib_hdl, "onlp_sys_info_get");
        if (NULL != dlerror()) {
                printf("Error: onlp_sys_info_get() %s\n", dlerror());
                return -1;
        }

        platformi_fan_info_get = dlsym(lib_hdl, "onlp_fan_info_get");
        if (NULL != dlerror()) {
                printf("Error: onlp_fan_info_get() %s\n", dlerror());
                return -1;
        }

        platformi_psu_info_get = dlsym(lib_hdl, "onlp_psu_info_get");
        if (NULL != dlerror()) {
                printf("Error: onlp_psu_info_get() %s\n", dlerror());
                return -1;
        }

        platformi_thermal_info_get = dlsym(lib_hdl, "onlp_thermal_info_get");
        if (NULL != dlerror()) {
                printf("Error: onlp_thermal_info_get() %s\n", dlerror());
                return -1;
        }

        platformi_led_info_get = dlsym(lib_hdl, "onlp_led_info_get");
        if (NULL != dlerror()) {
                printf("Error: onlp_led_info_get() %s\n", dlerror());
                return -1;
        }

        platformi_sfp_init = dlsym(lib_hdl, "onlp_sfp_init");
        if (NULL != dlerror()) {
                printf("Error: onlp_sfp_init() %s\n", dlerror());
                return -1;
        }

        platformi_sfp_deinit = dlsym(lib_hdl, "onlp_sfp_denit");
        if (NULL != dlerror()) {
                printf("Error: onlp_sfp_denit() %s\n", dlerror());
                return -1;
        }

        platformi_sfp_bitmap_t_init = dlsym(lib_hdl, "onlp_sfp_bitmap_t_init");
        if (NULL != dlerror()) {
                printf("Error: onlp_sfp_bitmap_t_init() %s\n", dlerror());
                return -1;
        }

        platformi_sfp_bitmap_get = dlsym(lib_hdl, "onlp_sfp_bitmap_get");
        if (NULL != dlerror()) {
                printf("Error: onlp_sfp_bitmap_get() %s\n", dlerror());
                return -1;
        }

        platformi_sfp_is_present = dlsym(lib_hdl, "onlp_sfp_is_present");
        if (NULL != dlerror()) {
                printf("Error: onlp_sfp_is_present() %s\n", dlerror());
                return -1;
        }

#if 0
        platformi_sfp_port_map = dlsym(lib_hdl, "onlp_sfp_port_map");
        if (NULL != dlerror()) {
                printf("Error: onlp_sfp_port_map() %s\n", dlerror());
                return -1;
        }
#endif
        platformi_sfp_eeprom_read = dlsym(lib_hdl, "onlp_sfp_eeprom_read");
        if (NULL != dlerror()) {
                printf("Error: onlp_sfp_eeprom_read() %s\n", dlerror());
                return -1;
        }

        platformi_sfp_presence_bitmap_get = dlsym(lib_hdl, "onlp_sfp_presence_bitmap_get");
        if (NULL != dlerror()) {
                printf("Error: onlp_sfp_presence_bitmap_get() %s\n", dlerror());
                return -1;
        }

        platformi_sff_eeprom_parse = dlsym(lib_hdl, "sff_eeprom_parse");
        if (NULL != dlerror()) {
                printf("Error: sff_eeprom_parse() %s\n", dlerror());
                return -1;
        }
        platformi_sff_sfp_type_name = dlsym(lib_hdl, "sff_sfp_type_name");
        if (NULL != dlerror()) {
                printf("Error: sff_sfp_type_name() %s\n", dlerror());
                return -1;
        }

        platformi_sff_module_type_name = dlsym(lib_hdl, "sff_module_type_name");
        if (NULL != dlerror()) {
                printf("Error: sff_module_type_name() %s\n", dlerror());
                return -1;
        }

        platformi_sff_media_type_name = dlsym(lib_hdl, "sff_media_type_name");
        if (NULL != dlerror()) {
                printf("Error: sff_media_type_name() %s\n", dlerror());
                return -1;
        }

        platformi_sff_module_caps_name = dlsym(lib_hdl, "sff_module_caps_name");
        if (NULL != dlerror()) {
                printf("Error: sff_module_caps_name() %s\n", dlerror());
                return -1;
        }

        return 0;
}

int platform_driver_init(void) {
        int ret_val = 0;

        ret_val = platform_symbol_load();
        if (ret_val < 0) {
                printf("Error loading the ONLP Symbol\n");
                return -1;
        } 
        if (NULL == platformi_init) {
                printf("Unable to find symbol for onlp_init()\n");
                return -1;
        }

        if (NULL == platformi_sys_info_get) {
                printf("Unable to find symbol for onlp_sys_info_get()\n");
                return -1;
        }

        (*platformi_init)();

        ret_val = (*platformi_sfp_init)();
        if (ret_val < 0) {
          printf("Failed : platformi_sfp_init()\n");
          return -1;
        }

        ret_val = (*platformi_sys_info_get)(&sysi);
        if (ret_val < 0) {
                printf("Failed: platformi_sys_info_get()\n");
                return -1;
        }
        return 0;
}

void platform_driver_dinit(void) {
        dlclose(lib_hdl);
}

void platform_oid_list_init(uint32_t *id_list, int size) {
        int idx = 0;

        if (NULL == id_list) {
                printf("Platform Fan Id List passed is NULL\n");
                return;
        }

        for (idx = 0; idx < size; idx++) {
                id_list[idx] = INVALID_OID;
        }
}
