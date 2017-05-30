#include <platform_driver.h>                                                  
                                                                              
extern int (*platformi_sys_info_get)(onlp_sys_info_t*);                       
extern onlp_sys_info_t sysi;                                                  
                                                                              
void platform_sys_info_init(platform_sys_info_t *info) {                      
        memset(info, 0, sizeof(platform_sys_info_t));                         
}                                                                             
                                                                              
int platform_sys_info_get(platform_sys_info_t *info) {                        
        int ret_val = 0;                                                      
        int idx = 0;
        onlp_sys_info_t sys_info;                                             
                                                                              
        if (NULL == platformi_sys_info_get) {                                 
                printf("platformi_sys_info_get() is not initialized\n");      
                return -1;                                                    
        }                                                                     
                                                                              
        if (NULL == info) {                                                   
                printf("Platform Sys Info passed is NULL\n");                 
                return -1;                                                    
        }                                                                     
                                                                              
        ret_val = (*platformi_sys_info_get)(&sys_info);                       
        if (ret_val < 0) {                                                    
                printf("Error getting Sys info\n");                           
                return -1;                                                    
        }                                                                     
                                                                              
        strncpy(info->product_name, sys_info.onie_info.product_name, INFO_STR_MAX);
        strncpy(info->part_number, sys_info.onie_info.part_number, INFO_STR_MAX);
        strncpy(info->serial_num, sys_info.onie_info.serial_number, INFO_STR_MAX);
        for (idx = 0; idx < MAC_ADDR_LEN; idx++) {                            
                info->mac_addr[idx] = sys_info.onie_info.mac[idx];            
        }
        info->mac_range = sys_info.onie_info.mac_range;
        strncpy(info->manufacturer, sys_info.onie_info.manufacturer, INFO_STR_MAX);
        strncpy(info->manufacture_date, sys_info.onie_info.manufacture_date, INFO_STR_MAX);
        strncpy(info->vendor, sys_info.onie_info.vendor, INFO_STR_MAX);
        strncpy(info->platform_name, sys_info.onie_info.platform_name, INFO_STR_MAX);
        info->device_version = sys_info.onie_info.device_version;
        strncpy(info->label_revision, sys_info.onie_info.label_revision, INFO_STR_MAX);
        strncpy(info->country_code, sys_info.onie_info.country_code, INFO_STR_MAX);
        strncpy(info->diag_version, sys_info.onie_info.diag_version, INFO_STR_MAX);
        strncpy(info->service_tag, sys_info.onie_info.service_tag, INFO_STR_MAX);
        strncpy(info->onie_version, sys_info.onie_info.onie_version, INFO_STR_MAX);
        return 0;
}
