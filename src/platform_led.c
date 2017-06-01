#include <platform_driver.h>

extern int (*platformi_sys_info_get)(onlp_sys_info_t*);
extern onlp_sys_info_t sysi;
extern int (*platformi_led_info_get)(onlp_oid_t, onlp_led_info_t*);

int platform_get_num_leds(void) {
        int led_count = 0;
        onlp_oid_t *oid_ptr;

        if (NULL == platformi_sys_info_get) {
                printf("platform_sys_info_get() is not initialized\n");
                return -1;
        }

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, LED) {
                led_count++;
        }
        return led_count;
}

int platform_get_led_oid_list(uint32_t *id_list, int arr_max, int *arr_cnt) {
        int idx = 0;
        onlp_oid_t *oid_ptr;

        if (NULL == platformi_sys_info_get) {
                printf("platform_sys_info_get() is not initialized\n");
                return -1;
        }

        if (NULL == id_list) {
                printf("Platform Led Id List passed is NULL\n");
                return -1;
        }

        ONLP_OID_TABLE_ITER_TYPE(sysi.hdr.coids, oid_ptr, LED) {
                id_list[idx++] = (uint32_t)*oid_ptr;
                if (idx >= arr_max) {
                        break;
                }
        }
        *arr_cnt = idx;
        return 0;
}

void platform_led_info_init(platform_led_info_t *info) {
        memset(info->desc, 0, INFO_STR_MAX * sizeof(char));
        info->status = LED_STATUS_ABSENT;
        info->state = LED_STATE_OFF;
        info->mode = LED_MODE_OFF;
}

int platform_led_info_get(uint32_t id, platform_led_info_t *info) {
        onlp_led_info_t led_info;
        int ret_val = 0;

        if (NULL == platformi_led_info_get) {
                printf("platformi_led_info_get() is not initialized\n");
                return -1;
        }

        if (NULL == info) {
                printf("Platform Led Info passed is NULL\n");
                return -1;
        }

        ret_val = (*platformi_led_info_get)(id, &led_info);        
        if (ret_val < 0) {
                printf("Error getting Led info for LedId: %d\n", id);
                return -1;
        }

        strncpy(info->desc, led_info.hdr.description, INFO_STR_MAX);
        if (led_info.status & ONLP_LED_STATUS_PRESENT) {
                info->status = LED_STATUS_PRESENT;
                if (led_info.status == ONLP_LED_STATUS_ON) {
                        info->state = LED_STATE_ON;
                } else {
                        info->state = LED_STATE_OFF;
                }
                switch(led_info.mode) {
                        case ONLP_LED_MODE_OFF:
                                info->mode = LED_MODE_OFF;
                                break;
                        case ONLP_LED_MODE_ON:
                                info->mode = LED_MODE_ON;
                                break;
                        case ONLP_LED_MODE_BLINKING:
                                info->mode = LED_MODE_BLINKING;
                                break;
                        case ONLP_LED_MODE_RED:
                                info->mode = LED_MODE_RED;
                                break;
                        case ONLP_LED_MODE_RED_BLINKING:
                                info->mode = LED_MODE_RED_BLINKING;
                                break;
                        case ONLP_LED_MODE_ORANGE:
                                info->mode = LED_MODE_ORANGE;
                                break;
                        case ONLP_LED_MODE_ORANGE_BLINKING:
                                info->mode = LED_MODE_ORANGE_BLINKING;
                                break;
                        case ONLP_LED_MODE_YELLOW:
                                info->mode = LED_MODE_YELLOW;
                                break;
                        case ONLP_LED_MODE_YELLOW_BLINKING:
                                info->mode = LED_MODE_YELLOW_BLINKING;
                                break;
                        case ONLP_LED_MODE_GREEN:
                                info->mode = LED_MODE_GREEN;
                                break;
                        case ONLP_LED_MODE_GREEN_BLINKING:
                                info->mode = LED_MODE_GREEN_BLINKING;
                                break;
                        case ONLP_LED_MODE_BLUE:
                                info->mode = LED_MODE_BLUE;
                                break;
                        case ONLP_LED_MODE_BLUE_BLINKING:
                                info->mode = LED_MODE_BLUE_BLINKING;
                                break;
                        case ONLP_LED_MODE_PURPLE:
                                info->mode = LED_MODE_PURPLE;
                                break;
                        case ONLP_LED_MODE_PURPLE_BLINKING:
                                info->mode = LED_MODE_PURPLE_BLINKING;
                                break;
                        case ONLP_LED_MODE_AUTO:
                                info->mode = LED_MODE_AUTO;
                                break;
                        case ONLP_LED_MODE_AUTO_BLINKING:
                                info->mode = LED_MODE_AUTO_BLINKING;
                                break;
                }
        } else {
                info->status = LED_STATUS_ABSENT;
        }

        return 0;
}
