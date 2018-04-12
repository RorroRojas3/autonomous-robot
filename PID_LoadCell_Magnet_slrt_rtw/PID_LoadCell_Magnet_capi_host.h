#ifndef RTW_HEADER_PID_LoadCell_Magnet_cap_host_h_
#define RTW_HEADER_PID_LoadCell_Magnet_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} PID_LoadCell_Magnet_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void PID_LoadCell_Magnet_host_InitializeDataMapInfo
    (PID_LoadCell_Magnet_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_PID_LoadCell_Magnet_cap_host_h_ */

/* EOF: PID_LoadCell_Magnet_capi_host.h */
