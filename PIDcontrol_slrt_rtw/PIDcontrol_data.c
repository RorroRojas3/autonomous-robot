/*
 * PIDcontrol_data.c
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

#include "PIDcontrol.h"
#include "PIDcontrol_private.h"

/* Block parameters (auto storage) */
P_PIDcontrol_T PIDcontrol_P = {
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Degree'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/gain'
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P1_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P2_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P3_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initialCount
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P4_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: prescale
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P5_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: quadrature
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P6_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P7_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: synchronousIndex
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P8_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: indexPolarity
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P9_Size
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: preserveCounts
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P10_Siz
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P11_Siz
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P12_Siz
   * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S6>/Channel 0 of  Encoder Inputs '
                                        */
  -0.225,                              /* Expression: -360/1600
                                        * Referenced by: '<S6>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                                        */
  0.75,                                /* Expression: 0.75
                                        * Referenced by: '<Root>/DegreeErrorThresh'
                                        */
  25.0,                                /* Expression: 25
                                        * Referenced by: '<Root>/SmallDegree1'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/SmallDegree2'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NullConstant1'
                                        */
  0.25,                                /* Expression: 0.25
                                        * Referenced by: '<Root>/RateErrorThresh'
                                        */
  0.1,                                 /* Expression: 0.1
                                        * Referenced by: '<Root>/KpSmall'
                                        */
  0.125,                               /* Expression: 0.125
                                        * Referenced by: '<Root>/KiSmall'
                                        */
  0.05,                                /* Expression: 0.05
                                        * Referenced by: '<Root>/Kp'
                                        */
  0.0125,                              /* Expression: 0.0125
                                        * Referenced by: '<Root>/Kd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/IntegratorPID'
                                        */
  0.025,                               /* Expression: 0.025
                                        * Referenced by: '<Root>/Ki'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/NullConstant2'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<S6>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<S6>/Saturation'
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotorthr
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_h
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_e
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  -10.0,                               /* Expression: range
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_e1
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_cz
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_l
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initValue
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_b
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_a
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_lv
   * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  -1.0                                 /* Expression: pciSlot
                                        * Referenced by: '<S6>/Channel 0 -Control signal to  motor through amplifier '
                                        */
};
