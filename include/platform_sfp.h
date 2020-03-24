#ifndef PLATFORM_SFP_H
#define PLATFORM_SFP_H

#include <onlp/sfp.h>
#include <platform_common.h>

#define MAX_SFP_INFO_STR_LEN 17

typedef enum sfp_media_type_e_ {
  SFP_MEDIA_TYPE_COPPER,
  SFP_MEDIA_TYPE_FIBER,
  SFP_MEDIA_TYPE_LAST = SFP_MEDIA_TYPE_FIBER,
  SFP_MEDIA_TYPE_COUNT,
  SFP_MEDIA_TYPE_INVALID = -1,
} sfp_media_type_e;

typedef enum sfp_status_e_ {
  SFP_STATUS_PRESENT,
  SFP_STATUS_ABSENT,
  SFP_STATUS_MAX
} sfp_status_e;

typedef enum sfp_module_caps_e_ {
  SFP_MODULE_CAPS_F_100 = 1,
  SFP_MODULE_CAPS_F_1G  = 2,
  SFP_MODULE_CAPS_F_10G = 4,
  SFP_MODULE_CAPS_F_25G = 8,
  SFP_MODULE_CAPS_F_40G = 16,
  SFP_MODULE_CAPS_F_100G = 32,
  SFP_MODULE_CAPS_F_INVALID = -1,
} sfp_module_caps_e;

typedef enum sfp_module_type_e_ {
  SFP_MODULE_TYPE_100G_AOC,
  SFP_MODULE_TYPE_100G_BASE_CR4,
  SFP_MODULE_TYPE_100G_BASE_SR4,
  SFP_MODULE_TYPE_100G_BASE_LR4,
  SFP_MODULE_TYPE_100G_CWDM4,
  SFP_MODULE_TYPE_40G_BASE_CR4,
  SFP_MODULE_TYPE_40G_BASE_SR4,
  SFP_MODULE_TYPE_40G_BASE_LR4,
  SFP_MODULE_TYPE_40G_BASE_LM4,
  SFP_MODULE_TYPE_40G_BASE_ACTIVE,
  SFP_MODULE_TYPE_40G_BASE_CR,
  SFP_MODULE_TYPE_40G_BASE_SR2,
  SFP_MODULE_TYPE_40G_BASE_SM4,
  SFP_MODULE_TYPE_25G_BASE_CR,
  SFP_MODULE_TYPE_10G_BASE_SR,
  SFP_MODULE_TYPE_10G_BASE_LR,
  SFP_MODULE_TYPE_10G_BASE_LRM,
  SFP_MODULE_TYPE_10G_BASE_ER,
  SFP_MODULE_TYPE_10G_BASE_CR,
  SFP_MODULE_TYPE_10G_BASE_SX,
  SFP_MODULE_TYPE_10G_BASE_LX,
  SFP_MODULE_TYPE_10G_BASE_ZR,
  SFP_MODULE_TYPE_10G_BASE_SRL,
  SFP_MODULE_TYPE_1G_BASE_SX,
  SFP_MODULE_TYPE_1G_BASE_LX,
  SFP_MODULE_TYPE_1G_BASE_CX,
  SFP_MODULE_TYPE_1G_BASE_T,
  SFP_MODULE_TYPE_100_BASE_LX,
  SFP_MODULE_TYPE_100_BASE_FX,
  SFP_MODULE_TYPE_4X_MUX,
  SFP_MODULE_TYPE_LAST = SFP_MODULE_TYPE_4X_MUX,
  SFP_MODULE_TYPE_COUNT,
  SFP_MODULE_TYPE_INVALID = -1,
} sfp_module_type_e;


typedef enum sfp_type_e_ {
  SFP_TYPE_SFP,
  SFP_TYPE_QSFP,
  SFP_TYPE_QSFP_PLUS,
  SFP_TYPE_QSFP28,
  SFP_TYPE_LAST = SFP_TYPE_QSFP28,
  SFP_TYPE_COUNT,
  SFP_TYPE_INVALID = -1,
} sfp_type_e;


typedef struct platform_sfp_info_s {
  uint16_t swPort;
  //bool valid;
  uint8_t valid;
  sfp_status_e status;
  char vendor[MAX_SFP_INFO_STR_LEN];
  char model[MAX_SFP_INFO_STR_LEN];
  char serial[MAX_SFP_INFO_STR_LEN];
  sfp_type_e sfp_type;
  //char sfp_type_name[MAX_SFP_INFO_STR_LEN];
  sfp_module_type_e sfp_module_type;
  //char sfp_module_type_name[MAX_SFP_INFO_STR_LEN];
  sfp_media_type_e sfp_media_type;
  //char sfp_media_type_name[MAX_SFP_INFO_STR_LEN];
  sfp_module_caps_e sfp_caps;
  int length;
  char length_desc[MAX_SFP_INFO_STR_LEN];
} platform_sfp_info_t;

int platform_get_num_of_sfps(int *count);
void platform_sfp_info_init(platform_sfp_info_t *sfp_info);
void platform_sfp_info_bulk_init(platform_sfp_info_t *sfp_info, int arr_len);
int platform_sfp_info_bulk_get(platform_sfp_info_t *sfp_info, int arr_len);
void platform_sfp_info_dump(platform_sfp_info_t *sfp_info);
void platform_sfp_parse(uint8_t *data, platform_sfp_info_t *info);
//int platform_sfp_bitmap_get();
//int platform_sfp_presence_bitmap_get();

#endif /* PLATFORM_SFP_H */
