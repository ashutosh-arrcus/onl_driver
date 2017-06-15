#ifndef PLATFORM_DRIVER_H
#define PLATFORM_DRIVER_H

#include <platform_fan.h>
#include <platform_psu.h>
#include <platform_sys.h>
#include <platform_thermal.h>
#include <platform_led.h>
#include <platform_sfp.h>

int platform_driver_init(void);
void platform_driver_dinit(void);
void platform_oid_list_init(uint32_t *id_list, int size);
#endif /* PLATFORM_DRIVER_H */
