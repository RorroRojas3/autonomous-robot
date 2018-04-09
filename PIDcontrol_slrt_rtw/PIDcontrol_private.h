/*
 * PIDcontrol_private.h
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "PIDcontrol".
 *
 * Model version              : 1.108
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Mon Apr 09 13:43:26 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PIDcontrol_private_h_
#define RTW_HEADER_PIDcontrol_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "PIDcontrol.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern void encquanserq8(SimStruct *rts);
extern void daquanserq8(SimStruct *rts);
extern void PIDcontrol_If1Subsystem(real_T rtu_In1, real_T *rty_Out1);

/* private model entry point functions */
extern void PIDcontrol_derivatives(void);

#endif                                 /* RTW_HEADER_PIDcontrol_private_h_ */
