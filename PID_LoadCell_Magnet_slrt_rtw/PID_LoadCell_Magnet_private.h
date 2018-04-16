/*
 * PID_LoadCell_Magnet_private.h
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "PID_LoadCell_Magnet".
 *
 * Model version              : 1.128
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Apr 16 11:54:45 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PID_LoadCell_Magnet_private_h_
#define RTW_HEADER_PID_LoadCell_Magnet_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "PID_LoadCell_Magnet.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern void encquanserq8(SimStruct *rts);
extern void daquanserq8(SimStruct *rts);
extern void adquanserq8(SimStruct *rts);
extern void PID_LoadCell_Magnet_IfSubsystem(real_T rtu_In1, real_T *rty_Out1);

/* private model entry point functions */
extern void PID_LoadCell_Magnet_derivatives(void);

#endif                                 /* RTW_HEADER_PID_LoadCell_Magnet_private_h_ */
