#include <platform_driver.h>

/* ONLP init */
int (*platformi_init)(void);
static void *lib_hdl;

/* System EEPROM */
int (*platformi_sys_info_get)(onlp_sys_info_t*);
onlp_sys_info_t sysi;

/* FAN */
int (*platformi_fan_info_get)(onlp_oid_t, onlp_fan_info_t*);

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

int platform_get_num_fans(void) {
        int fan_count = 0;
        onlp_oid_t *oid_ptr;

        if (NULL == platformi_sys_info_get) {
                printf("platform_sys_info_get() is not initialized\n");
                return -1;
        }

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, FAN) {
                fan_count++;
        }
        return fan_count;
}

int platform_get_fan_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt) {
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

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, FAN) {
                id_list[idx++] = (uint32_t)*oid_ptr;
                if (idx >= arr_max) {
                        break;
                }
        }
        *arr_cnt = idx;
        return 0;
}

void platform_fan_info_init(platform_fan_info_t *info) {
        memset(info, 0, sizeof(platform_fan_info_t));
}

int platform_fan_info_get(uint32_t id, platform_fan_info_t *info) {
        onlp_fan_info_t fan_info;
        int ret_val = 0;

        if (NULL == platformi_fan_info_get) {
                printf("platformi_fan_info_get() is not initialized\n");
                return -1;
        }

        if (NULL == info) {
                printf("Platform Fan Info passed is NULL\n");
                return -1;
        }

        ret_val = (*platformi_fan_info_get)(id, &fan_info);        
        if (ret_val < 0) {
                printf("Error getting Fan info for FanId: %d\n", id);
                return -1;
        }

        info->rpm = fan_info.rpm;
        strncpy(info->model, fan_info.model, INFO_STR_MAX);
        strncpy(info->serial_num, fan_info.serial, INFO_STR_MAX);
        return 0;
}
