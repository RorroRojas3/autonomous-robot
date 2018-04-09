/*
 * PIDcontrol.c
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

#include "rt_logging_mmi.h"
#include "PIDcontrol_capi.h"
#include "PIDcontrol.h"
#include "PIDcontrol_private.h"

/* Block signals (auto storage) */
B_PIDcontrol_T PIDcontrol_B;

/* Continuous states */
X_PIDcontrol_T PIDcontrol_X;

/* Block states (auto storage) */
DW_PIDcontrol_T PIDcontrol_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_PIDcontrol_T PIDcontrol_Y;

/* Real-time model */
RT_MODEL_PIDcontrol_T PIDcontrol_M_;
RT_MODEL_PIDcontrol_T *const PIDcontrol_M = &PIDcontrol_M_;

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 1;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PIDcontrol_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PIDcontrol_output();
  PIDcontrol_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PIDcontrol_output();
  PIDcontrol_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/*
 * Output and update for action system:
 *    '<Root>/If1 Subsystem'
 *    '<Root>/Else1 Subsystem'
 *    '<Root>/If2 Subsystem'
 *    '<Root>/Else2 Subsystem'
 */
void PIDcontrol_If1Subsystem(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S4>/In1' */
  *rty_Out1 = rtu_In1;
}

/* Model output function */
void PIDcontrol_output(void)
{
  real_T *lastU;
  real_T lastTime;
  int8_T rtAction;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(PIDcontrol_M)) {
    /* set solver stop time */
    if (!(PIDcontrol_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PIDcontrol_M->solverInfo,
                            ((PIDcontrol_M->Timing.clockTickH0 + 1) *
        PIDcontrol_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PIDcontrol_M->solverInfo,
                            ((PIDcontrol_M->Timing.clockTick0 + 1) *
        PIDcontrol_M->Timing.stepSize0 + PIDcontrol_M->Timing.clockTickH0 *
        PIDcontrol_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PIDcontrol_M)) {
    PIDcontrol_M->Timing.t[0] = rtsiGetT(&PIDcontrol_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(PIDcontrol_DW.If1Subsystem.If1Subsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(PIDcontrol_M)) {
    /* Gain: '<Root>/gain' incorporates:
     *  Constant: '<Root>/Degree'
     */
    PIDcontrol_B.Setpoint = PIDcontrol_P.gain_Gain * PIDcontrol_P.Degree_Value;

    /* Outport: '<Root>/setpoint_Out' */
    PIDcontrol_Y.setpoint_Out = PIDcontrol_B.Setpoint;

    /* S-Function (encquanserq8): '<S6>/Channel 0 of  Encoder Inputs ' */

    /* Level2 S-Function Block: '<S6>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
    {
      SimStruct *rts = PIDcontrol_M->childSfunctions[0];
      sfcnOutputs(rts,1);
    }

    /* Gain: '<S6>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    PIDcontrol_B.angular_positionrelative_countC =
      PIDcontrol_P.angular_positionrelative_countC *
      PIDcontrol_B.Channel0ofEncoderInputs;

    /* Sum: '<Root>/Sum1' */
    PIDcontrol_B.ErrorSigal = PIDcontrol_B.Setpoint
      - PIDcontrol_B.angular_positionrelative_countC;

    /* Outport: '<Root>/errorSignal_Out' */
    PIDcontrol_Y.errorSignal_Out = PIDcontrol_B.ErrorSigal;

    /* Outport: '<Root>/motorPos_Out' */
    PIDcontrol_Y.motorPos_Out = PIDcontrol_B.angular_positionrelative_countC;

    /* S-Function (scblock): '<S1>/S-Function' */
    /* ok to acquire for <S1>/S-Function */
    PIDcontrol_DW.SFunction_IWORK.AcquireOK = 1;

    /* S-Function (scblock): '<S7>/S-Function' */
    /* ok to acquire for <S7>/S-Function */
    PIDcontrol_DW.SFunction_IWORK_i.AcquireOK = 1;

    /* S-Function (scblock): '<S8>/S-Function' */
    /* ok to acquire for <S8>/S-Function */
    PIDcontrol_DW.SFunction_IWORK_it.AcquireOK = 1;

    /* S-Function (scblock): '<S9>/S-Function' */
    /* ok to acquire for <S9>/S-Function */
    PIDcontrol_DW.SFunction_IWORK_n.AcquireOK = 1;
  }

  /* Derivative: '<Root>/DerivativePID' */
  if ((PIDcontrol_DW.TimeStampA >= PIDcontrol_M->Timing.t[0]) &&
      (PIDcontrol_DW.TimeStampB >= PIDcontrol_M->Timing.t[0])) {
    PIDcontrol_B.DerivativePID = 0.0;
  } else {
    lastTime = PIDcontrol_DW.TimeStampA;
    lastU = &PIDcontrol_DW.LastUAtTimeA;
    if (PIDcontrol_DW.TimeStampA < PIDcontrol_DW.TimeStampB) {
      if (PIDcontrol_DW.TimeStampB < PIDcontrol_M->Timing.t[0]) {
        lastTime = PIDcontrol_DW.TimeStampB;
        lastU = &PIDcontrol_DW.LastUAtTimeB;
      }
    } else {
      if (PIDcontrol_DW.TimeStampA >= PIDcontrol_M->Timing.t[0]) {
        lastTime = PIDcontrol_DW.TimeStampB;
        lastU = &PIDcontrol_DW.LastUAtTimeB;
      }
    }

    lastTime = PIDcontrol_M->Timing.t[0] - lastTime;
    PIDcontrol_B.DerivativePID = (PIDcontrol_B.ErrorSigal - *lastU) / lastTime;
  }

  /* End of Derivative: '<Root>/DerivativePID' */

  /* Abs: '<Root>/AbsDError' */
  PIDcontrol_B.AbsDError = fabs(PIDcontrol_B.DerivativePID);
  if (rtmIsMajorTimeStep(PIDcontrol_M)) {
    /* Abs: '<Root>/AbsError1' */
    PIDcontrol_B.AbsError1 = fabs(PIDcontrol_B.ErrorSigal);

    /* Abs: '<Root>/AbsError2' */
    PIDcontrol_B.AbsError2 = fabs(PIDcontrol_B.ErrorSigal);

    /* If: '<Root>/If1' incorporates:
     *  Constant: '<Root>/NullConstant1'
     *  Constant: '<Root>/SmallDegree1'
     *  Constant: '<Root>/SmallDegree2'
     */
    if (rtmIsMajorTimeStep(PIDcontrol_M)) {
      rtAction = (int8_T)!((PIDcontrol_B.AbsError1 >
                            PIDcontrol_P.SmallDegree1_Value) ||
                           (PIDcontrol_B.AbsError1 <
                            PIDcontrol_P.SmallDegree2_Value));
      PIDcontrol_DW.If1_ActiveSubsystem = rtAction;
    } else {
      rtAction = PIDcontrol_DW.If1_ActiveSubsystem;
    }

    switch (rtAction) {
     case 0:
      /* Outputs for IfAction SubSystem: '<Root>/If1 Subsystem' incorporates:
       *  ActionPort: '<S4>/Action Port'
       */
      PIDcontrol_If1Subsystem(PIDcontrol_P.NullConstant1_Value,
        &PIDcontrol_B.Merge1);
      if (rtmIsMajorTimeStep(PIDcontrol_M)) {
        srUpdateBC(PIDcontrol_DW.If1Subsystem.If1Subsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<Root>/If1 Subsystem' */
      break;

     case 1:
      /* Outputs for IfAction SubSystem: '<Root>/Else1 Subsystem' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      PIDcontrol_If1Subsystem(PIDcontrol_B.ErrorSigal, &PIDcontrol_B.Merge1);
      if (rtmIsMajorTimeStep(PIDcontrol_M)) {
        srUpdateBC(PIDcontrol_DW.Else1Subsystem.If1Subsystem_SubsysRanBC);
      }

      /* End of Outputs for SubSystem: '<Root>/Else1 Subsystem' */
      break;
    }

    /* End of If: '<Root>/If1' */

    /* Gain: '<Root>/KpSmall' */
    PIDcontrol_B.KpSmall = PIDcontrol_P.KpSmall_Gain * PIDcontrol_B.Merge1;

    /* Gain: '<Root>/KiSmall' */
    PIDcontrol_B.KiSmall = PIDcontrol_P.KiSmall_Gain * PIDcontrol_B.Merge1;

    /* Gain: '<Root>/Kp' */
    PIDcontrol_B.Kp = PIDcontrol_P.Kp_Gain * PIDcontrol_B.ErrorSigal;
  }

  /* Gain: '<Root>/Kd' */
  PIDcontrol_B.Kd = PIDcontrol_P.Kd_Gain * PIDcontrol_B.DerivativePID;

  /* Integrator: '<Root>/IntegratorPID' */
  PIDcontrol_B.IntegratorPID = PIDcontrol_X.IntegratorPID_CSTATE;

  /* Gain: '<Root>/Ki' */
  PIDcontrol_B.Ki = PIDcontrol_P.Ki_Gain * PIDcontrol_B.IntegratorPID;

  /* Sum: '<Root>/Sum4' */
  PIDcontrol_B.Sum4 = (PIDcontrol_B.Kp + PIDcontrol_B.Kd) + PIDcontrol_B.Ki;

  /* Sum: '<Root>/Sum2' */
  PIDcontrol_B.Sum2 = (PIDcontrol_B.KpSmall + PIDcontrol_B.KiSmall) +
    PIDcontrol_B.Sum4;

  /* If: '<Root>/If2' incorporates:
   *  Constant: '<Root>/DegreeErrorThresh'
   *  Constant: '<Root>/NullConstant2'
   *  Constant: '<Root>/RateErrorThresh'
   */
  if (rtmIsMajorTimeStep(PIDcontrol_M)) {
    rtAction = (int8_T)!((PIDcontrol_B.AbsError2 >
                          PIDcontrol_P.DegreeErrorThresh_Value) ||
                         (PIDcontrol_B.AbsDError >
                          PIDcontrol_P.RateErrorThresh_Value));
    PIDcontrol_DW.If2_ActiveSubsystem = rtAction;
  } else {
    rtAction = PIDcontrol_DW.If2_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/If2 Subsystem' incorporates:
     *  ActionPort: '<S5>/Action Port'
     */
    PIDcontrol_If1Subsystem(PIDcontrol_B.Sum2, &PIDcontrol_B.Merge2);
    if (rtmIsMajorTimeStep(PIDcontrol_M)) {
      srUpdateBC(PIDcontrol_DW.If2Subsystem.If1Subsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<Root>/If2 Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Else2 Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    PIDcontrol_If1Subsystem(PIDcontrol_P.NullConstant2_Value,
      &PIDcontrol_B.Merge2);
    if (rtmIsMajorTimeStep(PIDcontrol_M)) {
      srUpdateBC(PIDcontrol_DW.Else2Subsystem.If1Subsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<Root>/Else2 Subsystem' */
    break;
  }

  /* End of If: '<Root>/If2' */
  if (rtmIsMajorTimeStep(PIDcontrol_M)) {
    /* Gain: '<Root>/Gain' */
    PIDcontrol_B.Gain[0] = PIDcontrol_P.Gain_Gain * PIDcontrol_B.Setpoint;
    PIDcontrol_B.Gain[1] = PIDcontrol_P.Gain_Gain *
      PIDcontrol_B.angular_positionrelative_countC;
    PIDcontrol_B.Gain[2] = PIDcontrol_P.Gain_Gain * PIDcontrol_B.ErrorSigal;
  }

  /* Saturate: '<S6>/Saturation' */
  lastTime = PIDcontrol_B.Merge2;
  u1 = PIDcontrol_P.Saturation_LowerSat;
  u2 = PIDcontrol_P.Saturation_UpperSat;
  if (lastTime > u2) {
    PIDcontrol_B.Saturation = u2;
  } else if (lastTime < u1) {
    PIDcontrol_B.Saturation = u1;
  } else {
    PIDcontrol_B.Saturation = lastTime;
  }

  /* End of Saturate: '<S6>/Saturation' */
  if (rtmIsMajorTimeStep(PIDcontrol_M)) {
    /* S-Function (daquanserq8): '<S6>/Channel 0 -Control signal to  motor through amplifier ' */

    /* Level2 S-Function Block: '<S6>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
    {
      SimStruct *rts = PIDcontrol_M->childSfunctions[1];
      sfcnOutputs(rts,1);
    }
  }
}

/* Model update function */
void PIDcontrol_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/DerivativePID' */
  if (PIDcontrol_DW.TimeStampA == (rtInf)) {
    PIDcontrol_DW.TimeStampA = PIDcontrol_M->Timing.t[0];
    lastU = &PIDcontrol_DW.LastUAtTimeA;
  } else if (PIDcontrol_DW.TimeStampB == (rtInf)) {
    PIDcontrol_DW.TimeStampB = PIDcontrol_M->Timing.t[0];
    lastU = &PIDcontrol_DW.LastUAtTimeB;
  } else if (PIDcontrol_DW.TimeStampA < PIDcontrol_DW.TimeStampB) {
    PIDcontrol_DW.TimeStampA = PIDcontrol_M->Timing.t[0];
    lastU = &PIDcontrol_DW.LastUAtTimeA;
  } else {
    PIDcontrol_DW.TimeStampB = PIDcontrol_M->Timing.t[0];
    lastU = &PIDcontrol_DW.LastUAtTimeB;
  }

  *lastU = PIDcontrol_B.ErrorSigal;

  /* End of Update for Derivative: '<Root>/DerivativePID' */
  if (rtmIsMajorTimeStep(PIDcontrol_M)) {
    rt_ertODEUpdateContinuousStates(&PIDcontrol_M->solverInfo);
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++PIDcontrol_M->Timing.clockTick0)) {
    ++PIDcontrol_M->Timing.clockTickH0;
  }

  PIDcontrol_M->Timing.t[0] = rtsiGetSolverStopTime(&PIDcontrol_M->solverInfo);

  {
    /* Update absolute timer for sample time: [0.001s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PIDcontrol_M->Timing.clockTick1)) {
      ++PIDcontrol_M->Timing.clockTickH1;
    }

    PIDcontrol_M->Timing.t[1] = PIDcontrol_M->Timing.clockTick1 *
      PIDcontrol_M->Timing.stepSize1 + PIDcontrol_M->Timing.clockTickH1 *
      PIDcontrol_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void PIDcontrol_derivatives(void)
{
  XDot_PIDcontrol_T *_rtXdot;
  _rtXdot = ((XDot_PIDcontrol_T *) PIDcontrol_M->derivs);

  /* Derivatives for Integrator: '<Root>/IntegratorPID' */
  _rtXdot->IntegratorPID_CSTATE = PIDcontrol_B.ErrorSigal;
}

/* Model initialize function */
void PIDcontrol_initialize(void)
{
  /* Start for S-Function (encquanserq8): '<S6>/Channel 0 of  Encoder Inputs ' */
  /* Level2 S-Function Block: '<S6>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = PIDcontrol_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S1>/S-Function' */

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s2"));
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s3"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s1"),
          "Setpoint        %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s2"),
          "Motor Position  %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s3"),
          "Error Signal    %3.2f");
        rl32eSetScope(3, 4, 200);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 10);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Gain/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 1, 0.0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 170.0);
        xpceScopeAcqOK(3, &PIDcontrol_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (scblock): '<S7>/S-Function' */

  /* S-Function Block: <S7>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Sum1"));
        rl32eSetScope(2, 4, 500);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 10);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Sum1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 3.0);
        rl32eSetTargetScope(2, 11, -180.0);
        rl32eSetTargetScope(2, 10, 180.0);
        xpceScopeAcqOK(2, &PIDcontrol_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S8>/S-Function' */

  /* S-Function Block: <S8>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(7)) == 0) {
      if ((i = rl32eDefScope(7,2)) != 0) {
        printf("Error creating scope 7\n");
      } else {
        rl32eAddSignal(7, rl32eGetSignalNo(
          "Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees"));
        rl32eSetScope(7, 4, 500);
        rl32eSetScope(7, 5, 0);
        rl32eSetScope(7, 6, 10);
        rl32eSetScope(7, 0, 0);
        rl32eSetScope(7, 3, rl32eGetSignalNo(
          "Real motor/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees"));
        rl32eSetScope(7, 1, 0.0);
        rl32eSetScope(7, 2, 0);
        rl32eSetScope(7, 9, 0);
        rl32eSetTargetScope(7, 1, 3.0);
        rl32eSetTargetScope(7, 11, -180.0);
        rl32eSetTargetScope(7, 10, 180.0);
        xpceScopeAcqOK(7, &PIDcontrol_DW.SFunction_IWORK_it.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* Start for S-Function (scblock): '<S9>/S-Function' */

  /* S-Function Block: <S9>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,2)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("gain"));
        rl32eSetScope(1, 4, 500);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 10);
        rl32eSetScope(1, 0, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("gain"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        rl32eSetTargetScope(1, 1, 3.0);
        rl32eSetTargetScope(1, 11, -180.0);
        rl32eSetTargetScope(1, 10, 180.0);
        xpceScopeAcqOK(1, &PIDcontrol_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for If: '<Root>/If1' */
  PIDcontrol_DW.If1_ActiveSubsystem = -1;

  /* Start for If: '<Root>/If2' */
  PIDcontrol_DW.If2_ActiveSubsystem = -1;

  /* Start for S-Function (daquanserq8): '<S6>/Channel 0 -Control signal to  motor through amplifier ' */
  /* Level2 S-Function Block: '<S6>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = PIDcontrol_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Derivative: '<Root>/DerivativePID' */
  PIDcontrol_DW.TimeStampA = (rtInf);
  PIDcontrol_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<Root>/IntegratorPID' */
  PIDcontrol_X.IntegratorPID_CSTATE = PIDcontrol_P.IntegratorPID_IC;
}

/* Model terminate function */
void PIDcontrol_terminate(void)
{
  /* Terminate for S-Function (encquanserq8): '<S6>/Channel 0 of  Encoder Inputs ' */
  /* Level2 S-Function Block: '<S6>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = PIDcontrol_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (daquanserq8): '<S6>/Channel 0 -Control signal to  motor through amplifier ' */
  /* Level2 S-Function Block: '<S6>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = PIDcontrol_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  PIDcontrol_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  PIDcontrol_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  PIDcontrol_initialize();
}

void MdlTerminate(void)
{
  PIDcontrol_terminate();
}

/* Registration function */
RT_MODEL_PIDcontrol_T *PIDcontrol(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PIDcontrol_M, 0,
                sizeof(RT_MODEL_PIDcontrol_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PIDcontrol_M->solverInfo,
                          &PIDcontrol_M->Timing.simTimeStep);
    rtsiSetTPtr(&PIDcontrol_M->solverInfo, &rtmGetTPtr(PIDcontrol_M));
    rtsiSetStepSizePtr(&PIDcontrol_M->solverInfo,
                       &PIDcontrol_M->Timing.stepSize0);
    rtsiSetdXPtr(&PIDcontrol_M->solverInfo, &PIDcontrol_M->derivs);
    rtsiSetContStatesPtr(&PIDcontrol_M->solverInfo, (real_T **)
                         &PIDcontrol_M->contStates);
    rtsiSetNumContStatesPtr(&PIDcontrol_M->solverInfo,
      &PIDcontrol_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PIDcontrol_M->solverInfo,
      &PIDcontrol_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PIDcontrol_M->solverInfo,
      &PIDcontrol_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PIDcontrol_M->solverInfo,
      &PIDcontrol_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PIDcontrol_M->solverInfo, (&rtmGetErrorStatus
      (PIDcontrol_M)));
    rtsiSetRTModelPtr(&PIDcontrol_M->solverInfo, PIDcontrol_M);
  }

  rtsiSetSimTimeStep(&PIDcontrol_M->solverInfo, MAJOR_TIME_STEP);
  PIDcontrol_M->intgData.y = PIDcontrol_M->odeY;
  PIDcontrol_M->intgData.f[0] = PIDcontrol_M->odeF[0];
  PIDcontrol_M->intgData.f[1] = PIDcontrol_M->odeF[1];
  PIDcontrol_M->intgData.f[2] = PIDcontrol_M->odeF[2];
  PIDcontrol_M->contStates = ((real_T *) &PIDcontrol_X);
  rtsiSetSolverData(&PIDcontrol_M->solverInfo, (void *)&PIDcontrol_M->intgData);
  rtsiSetSolverName(&PIDcontrol_M->solverInfo,"ode3");
  PIDcontrol_M->solverInfoPtr = (&PIDcontrol_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PIDcontrol_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    PIDcontrol_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PIDcontrol_M->Timing.sampleTimes = (&PIDcontrol_M->Timing.sampleTimesArray[0]);
    PIDcontrol_M->Timing.offsetTimes = (&PIDcontrol_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PIDcontrol_M->Timing.sampleTimes[0] = (0.0);
    PIDcontrol_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    PIDcontrol_M->Timing.offsetTimes[0] = (0.0);
    PIDcontrol_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(PIDcontrol_M, &PIDcontrol_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PIDcontrol_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    PIDcontrol_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PIDcontrol_M, -1);
  PIDcontrol_M->Timing.stepSize0 = 0.001;
  PIDcontrol_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    PIDcontrol_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PIDcontrol_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PIDcontrol_M->rtwLogInfo, (NULL));
    rtliSetLogT(PIDcontrol_M->rtwLogInfo, "tout");
    rtliSetLogX(PIDcontrol_M->rtwLogInfo, "");
    rtliSetLogXFinal(PIDcontrol_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(PIDcontrol_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(PIDcontrol_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(PIDcontrol_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(PIDcontrol_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &PIDcontrol_Y.setpoint_Out,
        &PIDcontrol_Y.errorSignal_Out,
        &PIDcontrol_Y.motorPos_Out
      };

      rtliSetLogYSignalPtrs(PIDcontrol_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "Setpoint",
        "Error Sigal",
        "Motor Position" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "PIDcontrol/setpoint_Out",
        "PIDcontrol/errorSignal_Out",
        "PIDcontrol/motorPos_Out" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          3,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(PIDcontrol_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
    }

    rtliSetLogY(PIDcontrol_M->rtwLogInfo, "yout");
  }

  PIDcontrol_M->solverInfoPtr = (&PIDcontrol_M->solverInfo);
  PIDcontrol_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&PIDcontrol_M->solverInfo, 0.001);
  rtsiSetSolverMode(&PIDcontrol_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PIDcontrol_M->blockIO = ((void *) &PIDcontrol_B);
  (void) memset(((void *) &PIDcontrol_B), 0,
                sizeof(B_PIDcontrol_T));

  /* parameters */
  PIDcontrol_M->defaultParam = ((real_T *)&PIDcontrol_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PIDcontrol_X;
    PIDcontrol_M->contStates = (x);
    (void) memset((void *)&PIDcontrol_X, 0,
                  sizeof(X_PIDcontrol_T));
  }

  /* states (dwork) */
  PIDcontrol_M->dwork = ((void *) &PIDcontrol_DW);
  (void) memset((void *)&PIDcontrol_DW, 0,
                sizeof(DW_PIDcontrol_T));

  /* external outputs */
  PIDcontrol_M->outputs = (&PIDcontrol_Y);
  (void) memset((void *)&PIDcontrol_Y, 0,
                sizeof(ExtY_PIDcontrol_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  PIDcontrol_InitializeDataMapInfo(PIDcontrol_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &PIDcontrol_M->NonInlinedSFcns.sfcnInfo;
    PIDcontrol_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(PIDcontrol_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &PIDcontrol_M->Sizes.numSampTimes);
    PIDcontrol_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(PIDcontrol_M)[0]);
    PIDcontrol_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(PIDcontrol_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,PIDcontrol_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(PIDcontrol_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(PIDcontrol_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(PIDcontrol_M));
    rtssSetStepSizePtr(sfcnInfo, &PIDcontrol_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(PIDcontrol_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo, &PIDcontrol_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &PIDcontrol_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &PIDcontrol_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &PIDcontrol_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &PIDcontrol_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &PIDcontrol_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &PIDcontrol_M->solverInfoPtr);
  }

  PIDcontrol_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)&PIDcontrol_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    PIDcontrol_M->childSfunctions =
      (&PIDcontrol_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    PIDcontrol_M->childSfunctions[0] =
      (&PIDcontrol_M->NonInlinedSFcns.childSFunctions[0]);
    PIDcontrol_M->childSfunctions[1] =
      (&PIDcontrol_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: PIDcontrol/<S6>/Channel 0 of  Encoder Inputs  (encquanserq8) */
    {
      SimStruct *rts = PIDcontrol_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = PIDcontrol_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = PIDcontrol_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = PIDcontrol_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &PIDcontrol_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, PIDcontrol_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &PIDcontrol_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &PIDcontrol_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &PIDcontrol_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &PIDcontrol_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &PIDcontrol_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &PIDcontrol_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &PIDcontrol_B.Channel0ofEncoderInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "Channel 0 of \nEncoder Inputs ");
      ssSetPath(rts, "PIDcontrol/Real motor/Channel 0 of  Encoder Inputs ");
      ssSetRTModel(rts,PIDcontrol_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &PIDcontrol_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P10_Siz);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P11_Siz);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       PIDcontrol_P.Channel0ofEncoderInputs_P12_Siz);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &PIDcontrol_DW.Channel0ofEncoderInputs_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &PIDcontrol_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &PIDcontrol_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &PIDcontrol_DW.Channel0ofEncoderInputs_IWORK[0]);
      }

      /* registration */
      encquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: PIDcontrol/<S6>/Channel 0 -Control signal to  motor through amplifier  (daquanserq8) */
    {
      SimStruct *rts = PIDcontrol_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = PIDcontrol_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = PIDcontrol_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = PIDcontrol_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &PIDcontrol_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, PIDcontrol_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &PIDcontrol_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &PIDcontrol_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &PIDcontrol_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &PIDcontrol_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &PIDcontrol_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &PIDcontrol_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &PIDcontrol_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &PIDcontrol_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "Channel 0 -Control signal to \nmotor through amplifier ");
      ssSetPath(rts,
                "PIDcontrol/Real motor/Channel 0 -Control signal to  motor through amplifier ");
      ssSetRTModel(rts,PIDcontrol_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &PIDcontrol_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotorthr);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotort_h);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotort_e);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotor_e1);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotor_cz);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotort_l);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotort_b);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotort_a);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       PIDcontrol_P.Channel0Controlsignaltomotor_lv);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &PIDcontrol_DW.Channel0Controlsignaltomotorthr
                 [0]);
      ssSetIWork(rts, (int_T *) &PIDcontrol_DW.Channel0Controlsignaltomotort_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &PIDcontrol_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &PIDcontrol_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &PIDcontrol_DW.Channel0Controlsignaltomotorthr[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &PIDcontrol_DW.Channel0Controlsignaltomotort_l);
      }

      /* registration */
      daquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  PIDcontrol_M->Sizes.numContStates = (1);/* Number of continuous states */
  PIDcontrol_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  PIDcontrol_M->Sizes.numY = (3);      /* Number of model outputs */
  PIDcontrol_M->Sizes.numU = (0);      /* Number of model inputs */
  PIDcontrol_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PIDcontrol_M->Sizes.numSampTimes = (2);/* Number of sample times */
  PIDcontrol_M->Sizes.numBlocks = (42);/* Number of blocks */
  PIDcontrol_M->Sizes.numBlockIO = (20);/* Number of block outputs */
  PIDcontrol_M->Sizes.numBlockPrms = (81);/* Sum of parameter "widths" */
  return PIDcontrol_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
