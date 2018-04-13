/*
 * PID_LoadCell_Magnet_data.c
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "PID_LoadCell_Magnet".
 *
 * Model version              : 1.121
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Fri Apr 13 17:57:45 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_LoadCell_Magnet.h"
#include "PID_LoadCell_Magnet_private.h"

/* Block parameters (auto storage) */
P_PID_LoadCell_Magnet_T PID_LoadCell_Magnet_P = {
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/5V'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Degree'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/gain'
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P1_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P2_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P3_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: initialCount
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P4_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: prescale
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P5_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  4.0,                                 /* Expression: quadrature
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P6_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P7_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: synchronousIndex
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P8_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: indexPolarity
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P9_Size
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: preserveCounts
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P10_Siz
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P11_Siz
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */

  /*  Computed Parameter: Channel0ofEncoderInputs_P12_Siz
   * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<S4>/Channel 0 of  Encoder Inputs '
                                        */
  -0.225,                              /* Expression: -360/1600
                                        * Referenced by: '<S4>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees'
                                        */

  /*  Computed Parameter: LoadCell_P1_Size
   * Referenced by: '<Root>/Load Cell'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Load Cell'
                                        */

  /*  Computed Parameter: LoadCell_P2_Size
   * Referenced by: '<Root>/Load Cell'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Load Cell'
                                        */

  /*  Computed Parameter: LoadCell_P3_Size
   * Referenced by: '<Root>/Load Cell'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: index03
                                        * Referenced by: '<Root>/Load Cell'
                                        */

  /*  Computed Parameter: LoadCell_P4_Size
   * Referenced by: '<Root>/Load Cell'
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: LoadCell_P5_Size
   * Referenced by: '<Root>/Load Cell'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/Load Cell'
                                        */

  /*  Computed Parameter: LoadCell_P6_Size
   * Referenced by: '<Root>/Load Cell'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Load Cell'
                                        */

  /*  Computed Parameter: LoadCell_P7_Size
   * Referenced by: '<Root>/Load Cell'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Load Cell'
                                        */
  3.0,                                 /* Expression: 3
                                        * Referenced by: '<Root>/DegreeErrorThresh'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<Root>/RateErrorThresh'
                                        */
  850.0,                               /* Expression: 850
                                        * Referenced by: '<Root>/Kp'
                                        */
  120.0,                               /* Expression: 120
                                        * Referenced by: '<Root>/Kd'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/IntegratorPID'
                                        */
  4.0,                                 /* Expression: 4
                                        * Referenced by: '<Root>/Ki'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  -5.0,                                /* Expression: -5
                                        * Referenced by: '<Root>/Saturation'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  2500.0,                              /* Expression: 2500
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/magnetDrop'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/magnetOn'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Switch2'
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotorthr
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: boardtype
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_h
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Expression: channel
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Computed Parameter: Channel0Controlsignaltomotort_e
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Expression: range
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { -10.0, -10.0 },

  /*  Computed Parameter: Channel0Controlsignaltomotor_e1
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: simul
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_cz
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Expression: reset
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },

  /*  Computed Parameter: Channel0Controlsignaltomotort_l
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 2.0 },

  /*  Expression: initValue
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 0.0, 0.0 },

  /*  Computed Parameter: Channel0Controlsignaltomotort_b
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: sampleTime
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotort_a
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: pciBus
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */

  /*  Computed Parameter: Channel0Controlsignaltomotor_lv
   * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: pciSlot
                                        * Referenced by: '<Root>/Channel 0 -Control signal to  motor through amplifier '
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Gain'
                                        */
};
