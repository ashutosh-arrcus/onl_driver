#include <platform_driver.h>

extern int (*platformi_sfp_init)(void);
extern void (*platformi_sfp_deinit)(void);
extern void (*platformi_sfp_bitmap_t_init)(onlp_sfp_bitmap_t *bmap);
extern int (*platformi_sfp_bitmap_get)(onlp_sfp_bitmap_t *bmap);
extern int (*platformi_sfp_is_present)(int port);
//extern int (*platformi_sfp_port_map)(int port, int *rport);
extern int (*platformi_sfp_eeprom_read)(int port, uint8_t **data);
extern int (*platformi_sfp_presence_bitmap_get)(onlp_sfp_bitmap_t *bmap);
extern int (*platformi_sff_eeprom_parse)(sff_eeprom_t *rv, uint8_t *data);


extern const char* (*platformi_sff_sfp_type_name)(sff_sfp_type_t e);
extern const char* (*platformi_sff_module_type_name)(sff_module_type_t e);
extern const char* (*platformi_sff_media_type_name)(sff_media_type_t e);
extern const char* (*platformi_sff_module_caps_name)(sff_module_caps_t e);


#if 0
int platform_sfp_bitmap_get() {
  onlp_sfp_bitmap_t bmap;
//  int idx = 0;
  int ret_val = 0;
  int bit;

  (*platformi_sfp_bitmap_t_init)(&bmap);

  ret_val = (*platformi_sfp_bitmap_get)(&bmap);
  if (ret_val < 0) {
    printf("Error platformi_sfp_bitmap_get()\n");
    return ret_val;
  }
  printf("List of Valid SFP capable Ports:\n");
  AIM_BITMAP_ITER(&bmap, bit) {
    printf("%d\t", bit);
  }
  printf("\n");
  return 0;
}

int platform_sfp_presence_bitmap_get() {
  onlp_sfp_bitmap_t bmap;
  int idx = 0;
  int ret_val = 0;
  int bit;
  uint8_t *data;
  sff_eeprom_t rv;

  data = (uint8_t *)malloc(256 * sizeof(uint8_t));

  (*platformi_sfp_bitmap_t_init)(&bmap);

  ret_val = (*platformi_sfp_presence_bitmap_get)(&bmap);
  if (ret_val < 0) {
    printf("Error platformi_sfp_presence_bitmap_get\n");
    return ret_val;
  }

  printf("List of Presence SFP Ports:\n");
  AIM_BITMAP_ITER(&bmap, bit) {
    memset(data, 0, 256 * sizeof(uint8_t));
    printf("Port : %d\n", bit);
    ret_val = (*platformi_sfp_eeprom_read)(bit, &data);
    if (ret_val < 0) {
      printf("Unable to read eeprom of port %d\n", bit);
    } else {
      for (idx = 0; idx < 256; idx++) {
        printf("%02x  ", data[idx]);
        if (idx % 8 == 0) {
          printf("\n");
        }
      }
      printf("\n");
      ret_val = (*platformi_sff_eeprom_parse)(&rv, data);
      if (ret_val < 0) {
        printf("Unable to parse eeprom\n");
      } else {
        printf("sff_info_t.vendor=%s\n", rv.info.vendor);
      }
    }
  }
  printf("\n");
  return 0;
}
#endif

int platform_get_num_of_sfps(int *count) {
  onlp_sfp_bitmap_t bmap;
  int ret_val = 0;
  int bit;

  (*platformi_sfp_bitmap_t_init)(&bmap);

  ret_val = (*platformi_sfp_bitmap_get)(&bmap);
  if (ret_val < 0) {
    printf("Error platformi_sfp_bitmap_get()\n");
    return ret_val;
  }
  AIM_BITMAP_ITER(&bmap, bit) {
    (*count)++;
  }
  return 0;
}

void platform_sfp_info_init(platform_sfp_info_t *sfp_info) {
  if (sfp_info == NULL) {
    printf("Error sfp_info is NULL\n");
    return;
  }
  sfp_info->status = SFP_STATUS_ABSENT;
  sfp_info->swPort = 0;
  sfp_info->valid = 0;
  memset(sfp_info->vendor, 0, MAX_SFP_INFO_STR_LEN * sizeof(char));
  memset(sfp_info->model, 0, MAX_SFP_INFO_STR_LEN * sizeof(char));
  memset(sfp_info->serial, 0, MAX_SFP_INFO_STR_LEN * sizeof(char));
  sfp_info->sfp_type = SFP_TYPE_INVALID;
  sfp_info->sfp_module_type = SFP_MODULE_TYPE_INVALID;
  sfp_info->sfp_media_type = SFP_MEDIA_TYPE_INVALID;
  sfp_info->sfp_caps = SFP_MODULE_CAPS_F_INVALID;
  sfp_info->length = -1;
  memset(sfp_info->length_desc, 0, MAX_SFP_INFO_STR_LEN * sizeof(char));
  return;
}

void platform_sfp_info_bulk_init(platform_sfp_info_t *sfp_info_arr, int arr_len) {
  int idx = 0;

  if (sfp_info_arr == NULL) {
    printf("Error sfp_info is NULL\n");
    return;
  }

  for (idx = 0; idx < arr_len; idx++) {
    platform_sfp_info_init(&sfp_info_arr[idx]);
  }
  return;
}

static int platform_sfp_bitmap_get(onlp_sfp_bitmap_t *bmap) {
  int idx = 0;
  int ret_val = 0;
  int bit;

  (*platformi_sfp_bitmap_t_init)(bmap);

  ret_val = (*platformi_sfp_bitmap_get)(bmap);
  if (ret_val < 0) {
    printf("Error platformi_sfp_bitmap_get\n");
    return ret_val;
  }

  return 0;
}

static int platform_sfp_presence_bitmap_get(onlp_sfp_bitmap_t *bmap) {
  int idx = 0;
  int ret_val = 0;
  int bit;

  (*platformi_sfp_bitmap_t_init)(bmap);

  ret_val = (*platformi_sfp_presence_bitmap_get)(bmap);
  if (ret_val < 0) {
    printf("Error platformi_sfp_presence_bitmap_get\n");
    return ret_val;
  }

  return 0;
}

int platform_sfp_info_bulk_get(platform_sfp_info_t *sfp_info, int arr_len) {
  int ret_val = 0;
  onlp_sfp_bitmap_t pbmap;
  onlp_sfp_bitmap_t bmap;
  int bit;
  uint8_t *data;
  sff_eeprom_t rv;
  int rbit = 0;
  int idx = -1;

  data = (uint8_t *)malloc(256 * sizeof(uint8_t));
  if (data == NULL) {
    printf("Malloc error\n");
    return -1;
  }

  if (sfp_info == NULL) {
    printf("Error sfp_info is NULL\n");
    return -1;
  }

  ret_val = platform_sfp_bitmap_get(&bmap);
  if (ret_val < 0) {
    printf("Error getting the SFP bitmap\n");
    return ret_val;
  }

  ret_val = platform_sfp_presence_bitmap_get(&pbmap);
  if (ret_val < 0) {
    printf("Error getting the SFP Presence bitmap\n");
    return ret_val;
  }

  AIM_BITMAP_ITER(&bmap, bit) {
    if (bit > arr_len) {
      return 0;
    }
    idx++;
    sfp_info[idx].swPort = bit;
    if (!AIM_BITMAP_GET(&pbmap, bit)) {
      continue;
    }
    memset(data, 0, 256 * sizeof(uint8_t));
    ret_val = (*platformi_sfp_eeprom_read)(bit, &data);
    if (ret_val < 0) {
      printf("Unable to read eeprom of port %d\n", bit);
    } else {
      sfp_info[idx].status = SFP_STATUS_PRESENT;
      ret_val = (*platformi_sff_eeprom_parse)(&rv, data);
      if (ret_val < 0) {
        printf("Unable to parse eeprom\n");
      } else if (rv.identified == 1) {
        sfp_info[idx].valid = 1;
        strncpy(sfp_info[idx].vendor, rv.info.vendor, MAX_SFP_INFO_STR_LEN * sizeof(char));
        strncpy(sfp_info[idx].model, rv.info.model, MAX_SFP_INFO_STR_LEN * sizeof(char));
        strncpy(sfp_info[idx].serial, rv.info.serial, MAX_SFP_INFO_STR_LEN * sizeof(char));
        sfp_info[idx].sfp_type = rv.info.sfp_type;
        sfp_info[idx].sfp_module_type = rv.info.module_type;
        sfp_info[idx].sfp_media_type = rv.info.media_type;
        sfp_info[idx].sfp_caps = rv.info.caps;
        sfp_info[idx].length = rv.info.length;
        strncpy(sfp_info[idx].length_desc, rv.info.length_desc, MAX_SFP_INFO_STR_LEN * sizeof(char));
      } else {
        sfp_info[idx].valid = 0;
      }
    }
  }

  return 0;
}

void platform_sfp_info_dump(platform_sfp_info_t *info) {
  if (info == NULL) {
    printf("Error info is NULL\n");
    return;
  }

  printf("SwPort: %d\n", info->swPort);
  if (info->status == SFP_STATUS_PRESENT) {
    printf("Status = PRESENT\n");
    if (info->valid == 1) {
      printf("Valid = %d\n", info->valid);
      printf("Vendor = %s\n", info->vendor);
      printf("Model = %s\n", info->model);
      printf("Serial = %s\n", info->serial);
      printf("SFP Type = %d(%s)\n", info->sfp_type, (*platformi_sff_sfp_type_name)(info->sfp_type));
      printf("SFP Module Type = %d(%s)\n", info->sfp_module_type, (*platformi_sff_module_type_name)(info->sfp_module_type));
      printf("SFP Media Type = %d(%s)\n", info->sfp_media_type, (*platformi_sff_media_type_name)(info->sfp_media_type));
      printf("SFP Capability = %d(%s)\n", info->sfp_caps, (*platformi_sff_module_caps_name)(info->sfp_caps));
      printf("SFP Length = %d\n", info->length);
      printf("SFP Length Desc = %s\n", info->length_desc);
    } else {
      printf("Valid(invalid) = %d\n", info->valid);
    }
  } else {
    printf("Status = ABSENT\n");
  }
  printf("\n\n");
  return;
}
