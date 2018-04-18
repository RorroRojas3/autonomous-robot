/*
 * PID_LoadCell_Magnet_capi.c
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "PID_LoadCell_Magnet".
 *
 * Model version              : 1.130
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Tue Apr 17 20:34:12 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "PID_LoadCell_Magnet_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "PID_LoadCell_Magnet.h"
#include "PID_LoadCell_Magnet_capi.h"
#include "PID_LoadCell_Magnet_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("AbsDError"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("AbsError"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 2, 0, TARGET_STRING("DerivativePID"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("Gain"),
    TARGET_STRING(""), 0, 0, 1, 0, 0 },

  { 4, 0, TARGET_STRING("Kd"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("Ki"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 6, 0, TARGET_STRING("Kp"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("gain"),
    TARGET_STRING("Setpoint"), 0, 0, 0, 0, 1 },

  { 8, 0, TARGET_STRING("gain1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("IntegratorPID"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("Merge"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("Saturation"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("Load Cell"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 13, 0, TARGET_STRING("Analog Filter Design"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 14, 0, TARGET_STRING("Analog Filter Design1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 15, 0, TARGET_STRING("Sum1"),
    TARGET_STRING("Error Sigal"), 0, 0, 0, 0, 1 },

  { 16, 0, TARGET_STRING("Sum4"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 17, 0, TARGET_STRING("Switch1"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 18, 0, TARGET_STRING("Else Subsystem/In1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 19, 0, TARGET_STRING("If Subsystem/In1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 20, 0, TARGET_STRING(
    "Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees"),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  { 21, 0, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING(""), 0, 0, 0, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 22, TARGET_STRING("5V"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 23, TARGET_STRING("Degree"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 24, TARGET_STRING("DegreeErrorThresh"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 25, TARGET_STRING("RateErrorThresh"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 26, TARGET_STRING("magnetOn"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 27, TARGET_STRING("Gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 28, TARGET_STRING("Kd"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 29, TARGET_STRING("Ki"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 30, TARGET_STRING("Kp"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 31, TARGET_STRING("gain"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 32, TARGET_STRING("gain1"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 33, TARGET_STRING("IntegratorPID"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 34, TARGET_STRING("Saturation"),
    TARGET_STRING("UpperLimit"), 0, 0, 0 },

  { 35, TARGET_STRING("Saturation"),
    TARGET_STRING("LowerLimit"), 0, 0, 0 },

  { 36, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 37, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P2"), 0, 2, 0 },

  { 38, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P3"), 0, 2, 0 },

  { 39, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 40, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P5"), 0, 2, 0 },

  { 41, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P6"), 0, 2, 0 },

  { 42, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 43, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 44, TARGET_STRING("Channel 0 -Control signal to  motor through amplifier "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 45, TARGET_STRING("Load Cell"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 46, TARGET_STRING("Load Cell"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 47, TARGET_STRING("Load Cell"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 48, TARGET_STRING("Load Cell"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 49, TARGET_STRING("Load Cell"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 50, TARGET_STRING("Load Cell"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 51, TARGET_STRING("Analog Filter Design"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 52, TARGET_STRING("Analog Filter Design"),
    TARGET_STRING("B"), 0, 0, 0 },

  { 53, TARGET_STRING("Analog Filter Design"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 54, TARGET_STRING("Analog Filter Design"),
    TARGET_STRING("X0"), 0, 0, 0 },

  { 55, TARGET_STRING("Analog Filter Design1"),
    TARGET_STRING("A"), 0, 0, 0 },

  { 56, TARGET_STRING("Analog Filter Design1"),
    TARGET_STRING("B"), 0, 0, 0 },

  { 57, TARGET_STRING("Analog Filter Design1"),
    TARGET_STRING("C"), 0, 0, 0 },

  { 58, TARGET_STRING("Analog Filter Design1"),
    TARGET_STRING("X0"), 0, 0, 0 },

  { 59, TARGET_STRING("Switch1"),
    TARGET_STRING("Threshold"), 0, 0, 0 },

  { 60, TARGET_STRING("Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 61, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 62, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 63, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 64, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 65, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 66, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 67, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 68, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 69, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 70, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 71, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P11"), 0, 0, 0 },

  { 72, TARGET_STRING("Real motor/Channel 0 of  Encoder Inputs "),
    TARGET_STRING("P12"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &PID_LoadCell_Magnet_B.AbsDError,    /* 0: Signal */
  &PID_LoadCell_Magnet_B.AbsError,     /* 1: Signal */
  &PID_LoadCell_Magnet_B.DerivativePID,/* 2: Signal */
  &PID_LoadCell_Magnet_B.Gain[0],      /* 3: Signal */
  &PID_LoadCell_Magnet_B.Kd,           /* 4: Signal */
  &PID_LoadCell_Magnet_B.Ki,           /* 5: Signal */
  &PID_LoadCell_Magnet_B.Kp,           /* 6: Signal */
  &PID_LoadCell_Magnet_B.Setpoint,     /* 7: Signal */
  &PID_LoadCell_Magnet_B.gain1,        /* 8: Signal */
  &PID_LoadCell_Magnet_B.IntegratorPID,/* 9: Signal */
  &PID_LoadCell_Magnet_B.Merge,        /* 10: Signal */
  &PID_LoadCell_Magnet_B.Saturation,   /* 11: Signal */
  &PID_LoadCell_Magnet_B.LoadCell,     /* 12: Signal */
  &PID_LoadCell_Magnet_B.AnalogFilterDesign,/* 13: Signal */
  &PID_LoadCell_Magnet_B.AnalogFilterDesign1,/* 14: Signal */
  &PID_LoadCell_Magnet_B.ErrorSigal,   /* 15: Signal */
  &PID_LoadCell_Magnet_B.Sum4,         /* 16: Signal */
  &PID_LoadCell_Magnet_B.Switch1,      /* 17: Signal */
  &PID_LoadCell_Magnet_B.Merge,        /* 18: Signal */
  &PID_LoadCell_Magnet_B.Merge,        /* 19: Signal */
  &PID_LoadCell_Magnet_B.angular_positionrelative_countC,/* 20: Signal */
  &PID_LoadCell_Magnet_B.Channel0ofEncoderInputs,/* 21: Signal */
  &PID_LoadCell_Magnet_P.uV_Value,     /* 22: Block Parameter */
  &PID_LoadCell_Magnet_P.Degree_Value, /* 23: Block Parameter */
  &PID_LoadCell_Magnet_P.DegreeErrorThresh_Value,/* 24: Block Parameter */
  &PID_LoadCell_Magnet_P.RateErrorThresh_Value,/* 25: Block Parameter */
  &PID_LoadCell_Magnet_P.magnetOn_Value,/* 26: Block Parameter */
  &PID_LoadCell_Magnet_P.Gain_Gain,    /* 27: Block Parameter */
  &PID_LoadCell_Magnet_P.Kd_Gain,      /* 28: Block Parameter */
  &PID_LoadCell_Magnet_P.Ki_Gain,      /* 29: Block Parameter */
  &PID_LoadCell_Magnet_P.Kp_Gain,      /* 30: Block Parameter */
  &PID_LoadCell_Magnet_P.gain_Gain,    /* 31: Block Parameter */
  &PID_LoadCell_Magnet_P.gain1_Gain,   /* 32: Block Parameter */
  &PID_LoadCell_Magnet_P.IntegratorPID_IC,/* 33: Block Parameter */
  &PID_LoadCell_Magnet_P.Saturation_UpperSat,/* 34: Block Parameter */
  &PID_LoadCell_Magnet_P.Saturation_LowerSat,/* 35: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_m,/* 36: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_k[0],/* 37: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_c[0],/* 38: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_d,/* 39: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_n[0],/* 40: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_g[0],/* 41: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_f,/* 42: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_gv,/* 43: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_gp,/* 44: Block Parameter */
  &PID_LoadCell_Magnet_P.LoadCell_P1,  /* 45: Block Parameter */
  &PID_LoadCell_Magnet_P.LoadCell_P2,  /* 46: Block Parameter */
  &PID_LoadCell_Magnet_P.LoadCell_P3,  /* 47: Block Parameter */
  &PID_LoadCell_Magnet_P.LoadCell_P5,  /* 48: Block Parameter */
  &PID_LoadCell_Magnet_P.LoadCell_P6,  /* 49: Block Parameter */
  &PID_LoadCell_Magnet_P.LoadCell_P7,  /* 50: Block Parameter */
  &PID_LoadCell_Magnet_P.AnalogFilterDesign_A,/* 51: Block Parameter */
  &PID_LoadCell_Magnet_P.AnalogFilterDesign_B,/* 52: Block Parameter */
  &PID_LoadCell_Magnet_P.AnalogFilterDesign_C,/* 53: Block Parameter */
  &PID_LoadCell_Magnet_P.AnalogFilterDesign_X0,/* 54: Block Parameter */
  &PID_LoadCell_Magnet_P.AnalogFilterDesign1_A,/* 55: Block Parameter */
  &PID_LoadCell_Magnet_P.AnalogFilterDesign1_B,/* 56: Block Parameter */
  &PID_LoadCell_Magnet_P.AnalogFilterDesign1_C,/* 57: Block Parameter */
  &PID_LoadCell_Magnet_P.AnalogFilterDesign1_X0,/* 58: Block Parameter */
  &PID_LoadCell_Magnet_P.Switch1_Threshold,/* 59: Block Parameter */
  &PID_LoadCell_Magnet_P.angular_positionrelative_countC,/* 60: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P1,/* 61: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P2,/* 62: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P3,/* 63: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P4,/* 64: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P5,/* 65: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P6,/* 66: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P7,/* 67: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P8,/* 68: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P9,/* 69: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P10,/* 70: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P11,/* 71: Block Parameter */
  &PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P12,/* 72: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  4,                                   /* 2 */
  1,                                   /* 3 */
  1,                                   /* 4 */
  2                                    /* 5 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0, 0.001
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[0],
    0, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[0],
    1, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 22,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 51,
    rtModelParameters, 0 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1949849595U,
    2973596363U,
    3982496661U,
    1949736578U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  PID_LoadCell_Magnet_GetCAPIStaticMap()
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void PID_LoadCell_Magnet_InitializeDataMapInfo(RT_MODEL_PID_LoadCell_Magnet_T *
  const PID_LoadCell_Magnet_M)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(PID_LoadCell_Magnet_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(PID_LoadCell_Magnet_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(PID_LoadCell_Magnet_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(PID_LoadCell_Magnet_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(PID_LoadCell_Magnet_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  PID_LoadCell_Magnet_M->DataMapInfo.mmi.InstanceMap.rtpAddress =
    rtmGetDefaultParam(PID_LoadCell_Magnet_M);
  PID_LoadCell_Magnet_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_PID_LoadCell_Magnet_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(PID_LoadCell_Magnet_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(PID_LoadCell_Magnet_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(PID_LoadCell_Magnet_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void PID_LoadCell_Magnet_host_InitializeDataMapInfo
    (PID_LoadCell_Magnet_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: PID_LoadCell_Magnet_capi.c */
