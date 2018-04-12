/*
 * PID_LoadCell_Magnet.c
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "PID_LoadCell_Magnet".
 *
 * Model version              : 1.119
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Apr 12 18:33:57 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "PID_LoadCell_Magnet_capi.h"
#include "PID_LoadCell_Magnet.h"
#include "PID_LoadCell_Magnet_private.h"

/* Block signals (auto storage) */
B_PID_LoadCell_Magnet_T PID_LoadCell_Magnet_B;

/* Continuous states */
X_PID_LoadCell_Magnet_T PID_LoadCell_Magnet_X;

/* Block states (auto storage) */
DW_PID_LoadCell_Magnet_T PID_LoadCell_Magnet_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_PID_LoadCell_Magnet_T PID_LoadCell_Magnet_Y;

/* Real-time model */
RT_MODEL_PID_LoadCell_Magnet_T PID_LoadCell_Magnet_M_;
RT_MODEL_PID_LoadCell_Magnet_T *const PID_LoadCell_Magnet_M =
  &PID_LoadCell_Magnet_M_;

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
  PID_LoadCell_Magnet_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PID_LoadCell_Magnet_output();
  PID_LoadCell_Magnet_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PID_LoadCell_Magnet_output();
  PID_LoadCell_Magnet_derivatives();

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
 *    '<Root>/If Subsystem'
 *    '<Root>/Else Subsystem'
 */
void PID_LoadCell_Magnet_IfSubsystem(real_T rtu_In1, real_T *rty_Out1)
{
  /* Inport: '<S3>/In1' */
  *rty_Out1 = rtu_In1;
}

/* Model output function */
void PID_LoadCell_Magnet_output(void)
{
  real_T *lastU;
  real_T lastTime;
  int8_T rtAction;
  real_T u1;
  real_T u2;
  if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
    /* set solver stop time */
    if (!(PID_LoadCell_Magnet_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PID_LoadCell_Magnet_M->solverInfo,
                            ((PID_LoadCell_Magnet_M->Timing.clockTickH0 + 1) *
        PID_LoadCell_Magnet_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PID_LoadCell_Magnet_M->solverInfo,
                            ((PID_LoadCell_Magnet_M->Timing.clockTick0 + 1) *
        PID_LoadCell_Magnet_M->Timing.stepSize0 +
        PID_LoadCell_Magnet_M->Timing.clockTickH0 *
        PID_LoadCell_Magnet_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PID_LoadCell_Magnet_M)) {
    PID_LoadCell_Magnet_M->Timing.t[0] = rtsiGetT
      (&PID_LoadCell_Magnet_M->solverInfo);
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(PID_LoadCell_Magnet_DW.IfSubsystem.IfSubsystem_SubsysRanBC);
  if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
    /* Gain: '<Root>/gain' incorporates:
     *  Constant: '<Root>/Degree'
     */
    PID_LoadCell_Magnet_B.Setpoint = PID_LoadCell_Magnet_P.gain_Gain *
      PID_LoadCell_Magnet_P.Degree_Value;

    /* Outport: '<Root>/setpoint_Out' */
    PID_LoadCell_Magnet_Y.setpoint_Out = PID_LoadCell_Magnet_B.Setpoint;

    /* S-Function (encquanserq8): '<S4>/Channel 0 of  Encoder Inputs ' */

    /* Level2 S-Function Block: '<S4>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
    {
      SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[0];
      sfcnOutputs(rts,1);
    }

    /* Gain: '<S4>/angular_position =  [relative_count//COUNTS_PER_REV] *360 degrees' */
    PID_LoadCell_Magnet_B.angular_positionrelative_countC =
      PID_LoadCell_Magnet_P.angular_positionrelative_countC *
      PID_LoadCell_Magnet_B.Channel0ofEncoderInputs;

    /* Sum: '<Root>/Sum1' */
    PID_LoadCell_Magnet_B.ErrorSigal = PID_LoadCell_Magnet_B.Setpoint
      - PID_LoadCell_Magnet_B.angular_positionrelative_countC;

    /* Outport: '<Root>/errorSignal_Out' */
    PID_LoadCell_Magnet_Y.errorSignal_Out = PID_LoadCell_Magnet_B.ErrorSigal;

    /* Outport: '<Root>/motorPos_Out' */
    PID_LoadCell_Magnet_Y.motorPos_Out =
      PID_LoadCell_Magnet_B.angular_positionrelative_countC;

    /* S-Function (adquanserq8): '<Root>/Load Cell' */

    /* Level2 S-Function Block: '<Root>/Load Cell' (adquanserq8) */
    {
      SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[1];
      sfcnOutputs(rts,1);
    }

    /* Outport: '<Root>/loadCell_In' */
    PID_LoadCell_Magnet_Y.loadCell_In = PID_LoadCell_Magnet_B.LoadCell;

    /* Abs: '<Root>/AbsError' */
    PID_LoadCell_Magnet_B.AbsError = fabs(PID_LoadCell_Magnet_B.ErrorSigal);
  }

  /* Derivative: '<Root>/DerivativePID' */
  if ((PID_LoadCell_Magnet_DW.TimeStampA >= PID_LoadCell_Magnet_M->Timing.t[0]) &&
      (PID_LoadCell_Magnet_DW.TimeStampB >= PID_LoadCell_Magnet_M->Timing.t[0]))
  {
    PID_LoadCell_Magnet_B.DerivativePID = 0.0;
  } else {
    lastTime = PID_LoadCell_Magnet_DW.TimeStampA;
    lastU = &PID_LoadCell_Magnet_DW.LastUAtTimeA;
    if (PID_LoadCell_Magnet_DW.TimeStampA < PID_LoadCell_Magnet_DW.TimeStampB) {
      if (PID_LoadCell_Magnet_DW.TimeStampB < PID_LoadCell_Magnet_M->Timing.t[0])
      {
        lastTime = PID_LoadCell_Magnet_DW.TimeStampB;
        lastU = &PID_LoadCell_Magnet_DW.LastUAtTimeB;
      }
    } else {
      if (PID_LoadCell_Magnet_DW.TimeStampA >= PID_LoadCell_Magnet_M->Timing.t[0])
      {
        lastTime = PID_LoadCell_Magnet_DW.TimeStampB;
        lastU = &PID_LoadCell_Magnet_DW.LastUAtTimeB;
      }
    }

    lastTime = PID_LoadCell_Magnet_M->Timing.t[0] - lastTime;
    PID_LoadCell_Magnet_B.DerivativePID = (PID_LoadCell_Magnet_B.ErrorSigal -
      *lastU) / lastTime;
  }

  /* End of Derivative: '<Root>/DerivativePID' */

  /* Abs: '<Root>/AbsDError' */
  PID_LoadCell_Magnet_B.AbsDError = fabs(PID_LoadCell_Magnet_B.DerivativePID);
  if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
    /* Gain: '<Root>/Kp' */
    PID_LoadCell_Magnet_B.Kp = PID_LoadCell_Magnet_P.Kp_Gain *
      PID_LoadCell_Magnet_B.ErrorSigal;
  }

  /* Gain: '<Root>/Kd' */
  PID_LoadCell_Magnet_B.Kd = PID_LoadCell_Magnet_P.Kd_Gain *
    PID_LoadCell_Magnet_B.DerivativePID;

  /* Integrator: '<Root>/IntegratorPID' */
  PID_LoadCell_Magnet_B.IntegratorPID =
    PID_LoadCell_Magnet_X.IntegratorPID_CSTATE;

  /* Gain: '<Root>/Ki' */
  PID_LoadCell_Magnet_B.Ki = PID_LoadCell_Magnet_P.Ki_Gain *
    PID_LoadCell_Magnet_B.IntegratorPID;

  /* Sum: '<Root>/Sum4' */
  PID_LoadCell_Magnet_B.Sum4 = (PID_LoadCell_Magnet_B.Kp +
    PID_LoadCell_Magnet_B.Kd) + PID_LoadCell_Magnet_B.Ki;

  /* If: '<Root>/If' incorporates:
   *  Constant: '<Root>/DegreeErrorThresh'
   *  Constant: '<Root>/RateErrorThresh'
   */
  if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
    rtAction = (int8_T)!((PID_LoadCell_Magnet_B.AbsError >
                          PID_LoadCell_Magnet_P.DegreeErrorThresh_Value) ||
                         (PID_LoadCell_Magnet_B.AbsDError >
                          PID_LoadCell_Magnet_P.RateErrorThresh_Value));
    PID_LoadCell_Magnet_DW.If_ActiveSubsystem = rtAction;
  } else {
    rtAction = PID_LoadCell_Magnet_DW.If_ActiveSubsystem;
  }

  switch (rtAction) {
   case 0:
    /* Outputs for IfAction SubSystem: '<Root>/If Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    PID_LoadCell_Magnet_IfSubsystem(PID_LoadCell_Magnet_B.Sum4,
      &PID_LoadCell_Magnet_B.Merge);
    if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
      srUpdateBC(PID_LoadCell_Magnet_DW.IfSubsystem.IfSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<Root>/If Subsystem' */
    break;

   case 1:
    /* Outputs for IfAction SubSystem: '<Root>/Else Subsystem' incorporates:
     *  ActionPort: '<S2>/Action Port'
     */
    PID_LoadCell_Magnet_IfSubsystem(0.0, &PID_LoadCell_Magnet_B.Merge);
    if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
      srUpdateBC(PID_LoadCell_Magnet_DW.ElseSubsystem.IfSubsystem_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<Root>/Else Subsystem' */
    break;
  }

  /* End of If: '<Root>/If' */

  /* Saturate: '<Root>/Saturation' */
  lastTime = PID_LoadCell_Magnet_B.Merge;
  u1 = PID_LoadCell_Magnet_P.Saturation_LowerSat;
  u2 = PID_LoadCell_Magnet_P.Saturation_UpperSat;
  if (lastTime > u2) {
    PID_LoadCell_Magnet_B.Saturation = u2;
  } else if (lastTime < u1) {
    PID_LoadCell_Magnet_B.Saturation = u1;
  } else {
    PID_LoadCell_Magnet_B.Saturation = lastTime;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Sin: '<Root>/Sine Wave' */
  PID_LoadCell_Magnet_B.SineWave = sin(PID_LoadCell_Magnet_P.SineWave_Freq *
    PID_LoadCell_Magnet_M->Timing.t[0] + PID_LoadCell_Magnet_P.SineWave_Phase) *
    PID_LoadCell_Magnet_P.SineWave_Amp + PID_LoadCell_Magnet_P.SineWave_Bias;
  if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/5V'
     *  Constant: '<Root>/magnetOn'
     */
    if (PID_LoadCell_Magnet_P.magnetOn_Value >
        PID_LoadCell_Magnet_P.Switch1_Threshold) {
      PID_LoadCell_Magnet_B.Switch1 = PID_LoadCell_Magnet_P.uV_Value;
    } else {
      PID_LoadCell_Magnet_B.Switch1 = 0.0;
    }

    /* End of Switch: '<Root>/Switch1' */
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  Constant: '<Root>/magnetDrop'
   */
  if (PID_LoadCell_Magnet_P.magnetDrop_Value >
      PID_LoadCell_Magnet_P.Switch2_Threshold) {
    PID_LoadCell_Magnet_B.Switch2 = PID_LoadCell_Magnet_B.SineWave;
  } else {
    PID_LoadCell_Magnet_B.Switch2 = PID_LoadCell_Magnet_B.Switch1;
  }

  /* End of Switch: '<Root>/Switch2' */
  if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
    /* S-Function (daquanserq8): '<Root>/Channel 0 -Control signal to  motor through amplifier ' */

    /* Level2 S-Function Block: '<Root>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
    {
      SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[2];
      sfcnOutputs(rts,1);
    }

    /* S-Function (scblock): '<S1>/S-Function' */
    /* ok to acquire for <S1>/S-Function */
    PID_LoadCell_Magnet_DW.SFunction_IWORK.AcquireOK = 1;

    /* S-Function (scblock): '<S5>/S-Function' */
    /* ok to acquire for <S5>/S-Function */
    PID_LoadCell_Magnet_DW.SFunction_IWORK_i.AcquireOK = 1;

    /* S-Function (scblock): '<S6>/S-Function' */
    /* ok to acquire for <S6>/S-Function */
    PID_LoadCell_Magnet_DW.SFunction_IWORK_it.AcquireOK = 1;

    /* S-Function (scblock): '<S7>/S-Function' */
    /* ok to acquire for <S7>/S-Function */
    PID_LoadCell_Magnet_DW.SFunction_IWORK_n.AcquireOK = 1;

    /* Gain: '<Root>/Gain' */
    PID_LoadCell_Magnet_B.Gain[0] = PID_LoadCell_Magnet_P.Gain_Gain *
      PID_LoadCell_Magnet_B.Setpoint;
    PID_LoadCell_Magnet_B.Gain[1] = PID_LoadCell_Magnet_P.Gain_Gain *
      PID_LoadCell_Magnet_B.angular_positionrelative_countC;
    PID_LoadCell_Magnet_B.Gain[2] = PID_LoadCell_Magnet_P.Gain_Gain *
      PID_LoadCell_Magnet_B.ErrorSigal;
    PID_LoadCell_Magnet_B.Gain[3] = PID_LoadCell_Magnet_P.Gain_Gain *
      PID_LoadCell_Magnet_B.LoadCell;
  }
}

/* Model update function */
void PID_LoadCell_Magnet_update(void)
{
  real_T *lastU;

  /* Update for Derivative: '<Root>/DerivativePID' */
  if (PID_LoadCell_Magnet_DW.TimeStampA == (rtInf)) {
    PID_LoadCell_Magnet_DW.TimeStampA = PID_LoadCell_Magnet_M->Timing.t[0];
    lastU = &PID_LoadCell_Magnet_DW.LastUAtTimeA;
  } else if (PID_LoadCell_Magnet_DW.TimeStampB == (rtInf)) {
    PID_LoadCell_Magnet_DW.TimeStampB = PID_LoadCell_Magnet_M->Timing.t[0];
    lastU = &PID_LoadCell_Magnet_DW.LastUAtTimeB;
  } else if (PID_LoadCell_Magnet_DW.TimeStampA <
             PID_LoadCell_Magnet_DW.TimeStampB) {
    PID_LoadCell_Magnet_DW.TimeStampA = PID_LoadCell_Magnet_M->Timing.t[0];
    lastU = &PID_LoadCell_Magnet_DW.LastUAtTimeA;
  } else {
    PID_LoadCell_Magnet_DW.TimeStampB = PID_LoadCell_Magnet_M->Timing.t[0];
    lastU = &PID_LoadCell_Magnet_DW.LastUAtTimeB;
  }

  *lastU = PID_LoadCell_Magnet_B.ErrorSigal;

  /* End of Update for Derivative: '<Root>/DerivativePID' */
  if (rtmIsMajorTimeStep(PID_LoadCell_Magnet_M)) {
    rt_ertODEUpdateContinuousStates(&PID_LoadCell_Magnet_M->solverInfo);
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
  if (!(++PID_LoadCell_Magnet_M->Timing.clockTick0)) {
    ++PID_LoadCell_Magnet_M->Timing.clockTickH0;
  }

  PID_LoadCell_Magnet_M->Timing.t[0] = rtsiGetSolverStopTime
    (&PID_LoadCell_Magnet_M->solverInfo);

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
    if (!(++PID_LoadCell_Magnet_M->Timing.clockTick1)) {
      ++PID_LoadCell_Magnet_M->Timing.clockTickH1;
    }

    PID_LoadCell_Magnet_M->Timing.t[1] =
      PID_LoadCell_Magnet_M->Timing.clockTick1 *
      PID_LoadCell_Magnet_M->Timing.stepSize1 +
      PID_LoadCell_Magnet_M->Timing.clockTickH1 *
      PID_LoadCell_Magnet_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Derivatives for root system: '<Root>' */
void PID_LoadCell_Magnet_derivatives(void)
{
  XDot_PID_LoadCell_Magnet_T *_rtXdot;
  _rtXdot = ((XDot_PID_LoadCell_Magnet_T *) PID_LoadCell_Magnet_M->derivs);

  /* Derivatives for Integrator: '<Root>/IntegratorPID' */
  _rtXdot->IntegratorPID_CSTATE = PID_LoadCell_Magnet_B.ErrorSigal;
}

/* Model initialize function */
void PID_LoadCell_Magnet_initialize(void)
{
  /* Start for S-Function (encquanserq8): '<S4>/Channel 0 of  Encoder Inputs ' */
  /* Level2 S-Function Block: '<S4>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (adquanserq8): '<Root>/Load Cell' */
  /* Level2 S-Function Block: '<Root>/Load Cell' (adquanserq8) */
  {
    SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for If: '<Root>/If' */
  PID_LoadCell_Magnet_DW.If_ActiveSubsystem = -1;

  /* Start for S-Function (daquanserq8): '<Root>/Channel 0 -Control signal to  motor through amplifier ' */
  /* Level2 S-Function Block: '<Root>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[2];
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
        rl32eAddSignal(3, rl32eGetSignalNo("Gain/s4"));
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s1"),
          "Setpoint        %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s2"),
          "Motor Position  %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s3"),
          "Error Signal    %3.2f");
        rl32eSetTargetScopeSigFt(3,rl32eGetSignalNo("Gain/s4"),
          "Load Cell (V)    %4.3f");
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
        xpceScopeAcqOK(3, &PID_LoadCell_Magnet_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (scblock): '<S5>/S-Function' */

  /* S-Function Block: <S5>/S-Function (scblock) */
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
        xpceScopeAcqOK(2, &PID_LoadCell_Magnet_DW.SFunction_IWORK_i.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function (scblock) */
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
        xpceScopeAcqOK(7, &PID_LoadCell_Magnet_DW.SFunction_IWORK_it.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(7);
    }
  }

  /* Start for S-Function (scblock): '<S7>/S-Function' */

  /* S-Function Block: <S7>/S-Function (scblock) */
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
        xpceScopeAcqOK(1, &PID_LoadCell_Magnet_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* InitializeConditions for Derivative: '<Root>/DerivativePID' */
  PID_LoadCell_Magnet_DW.TimeStampA = (rtInf);
  PID_LoadCell_Magnet_DW.TimeStampB = (rtInf);

  /* InitializeConditions for Integrator: '<Root>/IntegratorPID' */
  PID_LoadCell_Magnet_X.IntegratorPID_CSTATE =
    PID_LoadCell_Magnet_P.IntegratorPID_IC;
}

/* Model terminate function */
void PID_LoadCell_Magnet_terminate(void)
{
  /* Terminate for S-Function (encquanserq8): '<S4>/Channel 0 of  Encoder Inputs ' */
  /* Level2 S-Function Block: '<S4>/Channel 0 of  Encoder Inputs ' (encquanserq8) */
  {
    SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (adquanserq8): '<Root>/Load Cell' */
  /* Level2 S-Function Block: '<Root>/Load Cell' (adquanserq8) */
  {
    SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (daquanserq8): '<Root>/Channel 0 -Control signal to  motor through amplifier ' */
  /* Level2 S-Function Block: '<Root>/Channel 0 -Control signal to  motor through amplifier ' (daquanserq8) */
  {
    SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[2];
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
  PID_LoadCell_Magnet_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  PID_LoadCell_Magnet_update();
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
  PID_LoadCell_Magnet_initialize();
}

void MdlTerminate(void)
{
  PID_LoadCell_Magnet_terminate();
}

/* Registration function */
RT_MODEL_PID_LoadCell_Magnet_T *PID_LoadCell_Magnet(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PID_LoadCell_Magnet_M, 0,
                sizeof(RT_MODEL_PID_LoadCell_Magnet_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PID_LoadCell_Magnet_M->solverInfo,
                          &PID_LoadCell_Magnet_M->Timing.simTimeStep);
    rtsiSetTPtr(&PID_LoadCell_Magnet_M->solverInfo, &rtmGetTPtr
                (PID_LoadCell_Magnet_M));
    rtsiSetStepSizePtr(&PID_LoadCell_Magnet_M->solverInfo,
                       &PID_LoadCell_Magnet_M->Timing.stepSize0);
    rtsiSetdXPtr(&PID_LoadCell_Magnet_M->solverInfo,
                 &PID_LoadCell_Magnet_M->derivs);
    rtsiSetContStatesPtr(&PID_LoadCell_Magnet_M->solverInfo, (real_T **)
                         &PID_LoadCell_Magnet_M->contStates);
    rtsiSetNumContStatesPtr(&PID_LoadCell_Magnet_M->solverInfo,
      &PID_LoadCell_Magnet_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PID_LoadCell_Magnet_M->solverInfo,
      &PID_LoadCell_Magnet_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PID_LoadCell_Magnet_M->solverInfo,
      &PID_LoadCell_Magnet_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PID_LoadCell_Magnet_M->solverInfo,
      &PID_LoadCell_Magnet_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PID_LoadCell_Magnet_M->solverInfo,
                          (&rtmGetErrorStatus(PID_LoadCell_Magnet_M)));
    rtsiSetRTModelPtr(&PID_LoadCell_Magnet_M->solverInfo, PID_LoadCell_Magnet_M);
  }

  rtsiSetSimTimeStep(&PID_LoadCell_Magnet_M->solverInfo, MAJOR_TIME_STEP);
  PID_LoadCell_Magnet_M->intgData.y = PID_LoadCell_Magnet_M->odeY;
  PID_LoadCell_Magnet_M->intgData.f[0] = PID_LoadCell_Magnet_M->odeF[0];
  PID_LoadCell_Magnet_M->intgData.f[1] = PID_LoadCell_Magnet_M->odeF[1];
  PID_LoadCell_Magnet_M->intgData.f[2] = PID_LoadCell_Magnet_M->odeF[2];
  PID_LoadCell_Magnet_M->contStates = ((real_T *) &PID_LoadCell_Magnet_X);
  rtsiSetSolverData(&PID_LoadCell_Magnet_M->solverInfo, (void *)
                    &PID_LoadCell_Magnet_M->intgData);
  rtsiSetSolverName(&PID_LoadCell_Magnet_M->solverInfo,"ode3");
  PID_LoadCell_Magnet_M->solverInfoPtr = (&PID_LoadCell_Magnet_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = PID_LoadCell_Magnet_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    PID_LoadCell_Magnet_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    PID_LoadCell_Magnet_M->Timing.sampleTimes =
      (&PID_LoadCell_Magnet_M->Timing.sampleTimesArray[0]);
    PID_LoadCell_Magnet_M->Timing.offsetTimes =
      (&PID_LoadCell_Magnet_M->Timing.offsetTimesArray[0]);

    /* task periods */
    PID_LoadCell_Magnet_M->Timing.sampleTimes[0] = (0.0);
    PID_LoadCell_Magnet_M->Timing.sampleTimes[1] = (0.001);

    /* task offsets */
    PID_LoadCell_Magnet_M->Timing.offsetTimes[0] = (0.0);
    PID_LoadCell_Magnet_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(PID_LoadCell_Magnet_M, &PID_LoadCell_Magnet_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = PID_LoadCell_Magnet_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    PID_LoadCell_Magnet_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(PID_LoadCell_Magnet_M, -1);
  PID_LoadCell_Magnet_M->Timing.stepSize0 = 0.001;
  PID_LoadCell_Magnet_M->Timing.stepSize1 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    PID_LoadCell_Magnet_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(PID_LoadCell_Magnet_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(PID_LoadCell_Magnet_M->rtwLogInfo, (NULL));
    rtliSetLogT(PID_LoadCell_Magnet_M->rtwLogInfo, "tout");
    rtliSetLogX(PID_LoadCell_Magnet_M->rtwLogInfo, "");
    rtliSetLogXFinal(PID_LoadCell_Magnet_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(PID_LoadCell_Magnet_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(PID_LoadCell_Magnet_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(PID_LoadCell_Magnet_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(PID_LoadCell_Magnet_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &PID_LoadCell_Magnet_Y.setpoint_Out,
        &PID_LoadCell_Magnet_Y.errorSignal_Out,
        &PID_LoadCell_Magnet_Y.motorPos_Out,
        &PID_LoadCell_Magnet_Y.loadCell_In
      };

      rtliSetLogYSignalPtrs(PID_LoadCell_Magnet_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "Setpoint",
        "Error Sigal",
        "Motor Position",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "PID_LoadCell_Magnet/setpoint_Out",
        "PID_LoadCell_Magnet/errorSignal_Out",
        "PID_LoadCell_Magnet/motorPos_Out",
        "PID_LoadCell_Magnet/loadCell_In" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          4,
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

      rtliSetLogYSignalInfo(PID_LoadCell_Magnet_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
    }

    rtliSetLogY(PID_LoadCell_Magnet_M->rtwLogInfo, "yout");
  }

  PID_LoadCell_Magnet_M->solverInfoPtr = (&PID_LoadCell_Magnet_M->solverInfo);
  PID_LoadCell_Magnet_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&PID_LoadCell_Magnet_M->solverInfo, 0.001);
  rtsiSetSolverMode(&PID_LoadCell_Magnet_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  PID_LoadCell_Magnet_M->blockIO = ((void *) &PID_LoadCell_Magnet_B);
  (void) memset(((void *) &PID_LoadCell_Magnet_B), 0,
                sizeof(B_PID_LoadCell_Magnet_T));

  /* parameters */
  PID_LoadCell_Magnet_M->defaultParam = ((real_T *)&PID_LoadCell_Magnet_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &PID_LoadCell_Magnet_X;
    PID_LoadCell_Magnet_M->contStates = (x);
    (void) memset((void *)&PID_LoadCell_Magnet_X, 0,
                  sizeof(X_PID_LoadCell_Magnet_T));
  }

  /* states (dwork) */
  PID_LoadCell_Magnet_M->dwork = ((void *) &PID_LoadCell_Magnet_DW);
  (void) memset((void *)&PID_LoadCell_Magnet_DW, 0,
                sizeof(DW_PID_LoadCell_Magnet_T));

  /* external outputs */
  PID_LoadCell_Magnet_M->outputs = (&PID_LoadCell_Magnet_Y);
  (void) memset((void *)&PID_LoadCell_Magnet_Y, 0,
                sizeof(ExtY_PID_LoadCell_Magnet_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  PID_LoadCell_Magnet_InitializeDataMapInfo(PID_LoadCell_Magnet_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &PID_LoadCell_Magnet_M->NonInlinedSFcns.sfcnInfo;
    PID_LoadCell_Magnet_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(PID_LoadCell_Magnet_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &PID_LoadCell_Magnet_M->Sizes.numSampTimes);
    PID_LoadCell_Magnet_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (PID_LoadCell_Magnet_M)[0]);
    PID_LoadCell_Magnet_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (PID_LoadCell_Magnet_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,PID_LoadCell_Magnet_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(PID_LoadCell_Magnet_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(PID_LoadCell_Magnet_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (PID_LoadCell_Magnet_M));
    rtssSetStepSizePtr(sfcnInfo, &PID_LoadCell_Magnet_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(PID_LoadCell_Magnet_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &PID_LoadCell_Magnet_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &PID_LoadCell_Magnet_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &PID_LoadCell_Magnet_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &PID_LoadCell_Magnet_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &PID_LoadCell_Magnet_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &PID_LoadCell_Magnet_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &PID_LoadCell_Magnet_M->solverInfoPtr);
  }

  PID_LoadCell_Magnet_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)
                  &PID_LoadCell_Magnet_M->NonInlinedSFcns.childSFunctions[0], 0,
                  3*sizeof(SimStruct));
    PID_LoadCell_Magnet_M->childSfunctions =
      (&PID_LoadCell_Magnet_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    PID_LoadCell_Magnet_M->childSfunctions[0] =
      (&PID_LoadCell_Magnet_M->NonInlinedSFcns.childSFunctions[0]);
    PID_LoadCell_Magnet_M->childSfunctions[1] =
      (&PID_LoadCell_Magnet_M->NonInlinedSFcns.childSFunctions[1]);
    PID_LoadCell_Magnet_M->childSfunctions[2] =
      (&PID_LoadCell_Magnet_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: PID_LoadCell_Magnet/<S4>/Channel 0 of  Encoder Inputs  (encquanserq8) */
    {
      SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &PID_LoadCell_Magnet_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, PID_LoadCell_Magnet_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &PID_LoadCell_Magnet_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &PID_LoadCell_Magnet_B.Channel0ofEncoderInputs));
        }
      }

      /* path info */
      ssSetModelName(rts, "Channel 0 of \nEncoder Inputs ");
      ssSetPath(rts,
                "PID_LoadCell_Magnet/Real motor/Channel 0 of  Encoder Inputs ");
      ssSetRTModel(rts,PID_LoadCell_Magnet_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 12);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P10_Siz);
        ssSetSFcnParam(rts, 10, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P11_Siz);
        ssSetSFcnParam(rts, 11, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0ofEncoderInputs_P12_Siz);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &PID_LoadCell_Magnet_DW.Channel0ofEncoderInputs_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &PID_LoadCell_Magnet_DW.Channel0ofEncoderInputs_IWORK[0]);
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

    /* Level2 S-Function Block: PID_LoadCell_Magnet/<Root>/Load Cell (adquanserq8) */
    {
      SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &PID_LoadCell_Magnet_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, PID_LoadCell_Magnet_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &PID_LoadCell_Magnet_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &PID_LoadCell_Magnet_B.LoadCell));
        }
      }

      /* path info */
      ssSetModelName(rts, "Load Cell");
      ssSetPath(rts, "PID_LoadCell_Magnet/Load Cell");
      ssSetRTModel(rts,PID_LoadCell_Magnet_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)PID_LoadCell_Magnet_P.LoadCell_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)PID_LoadCell_Magnet_P.LoadCell_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)PID_LoadCell_Magnet_P.LoadCell_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)PID_LoadCell_Magnet_P.LoadCell_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)PID_LoadCell_Magnet_P.LoadCell_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)PID_LoadCell_Magnet_P.LoadCell_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)PID_LoadCell_Magnet_P.LoadCell_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &PID_LoadCell_Magnet_DW.LoadCell_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &PID_LoadCell_Magnet_DW.LoadCell_IWORK[0]);
      }

      /* registration */
      adquanserq8(rts);
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

    /* Level2 S-Function Block: PID_LoadCell_Magnet/<Root>/Channel 0 -Control signal to  motor through amplifier  (daquanserq8) */
    {
      SimStruct *rts = PID_LoadCell_Magnet_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &PID_LoadCell_Magnet_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, PID_LoadCell_Magnet_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &PID_LoadCell_Magnet_M->
                           NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &PID_LoadCell_Magnet_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.UPtrs0;
          sfcnUPtrs[0] = &PID_LoadCell_Magnet_B.Saturation;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.UPtrs1;
          sfcnUPtrs[0] = &PID_LoadCell_Magnet_B.Switch2;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts,
                     "Channel 0 -Control signal to \nmotor through amplifier ");
      ssSetPath(rts,
                "PID_LoadCell_Magnet/Channel 0 -Control signal to  motor through amplifier ");
      ssSetRTModel(rts,PID_LoadCell_Magnet_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotorthr);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_h);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_e);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_e1);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_cz);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_l);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_b);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotort_a);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       PID_LoadCell_Magnet_P.Channel0Controlsignaltomotor_lv);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &PID_LoadCell_Magnet_DW.Channel0Controlsignaltomotorthr[0]);
      ssSetIWork(rts, (int_T *)
                 &PID_LoadCell_Magnet_DW.Channel0Controlsignaltomotort_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &PID_LoadCell_Magnet_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &PID_LoadCell_Magnet_DW.Channel0Controlsignaltomotorthr[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &PID_LoadCell_Magnet_DW.Channel0Controlsignaltomotort_l);
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
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  PID_LoadCell_Magnet_M->Sizes.numContStates = (1);/* Number of continuous states */
  PID_LoadCell_Magnet_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  PID_LoadCell_Magnet_M->Sizes.numY = (4);/* Number of model outputs */
  PID_LoadCell_Magnet_M->Sizes.numU = (0);/* Number of model inputs */
  PID_LoadCell_Magnet_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  PID_LoadCell_Magnet_M->Sizes.numSampTimes = (2);/* Number of sample times */
  PID_LoadCell_Magnet_M->Sizes.numBlocks = (39);/* Number of blocks */
  PID_LoadCell_Magnet_M->Sizes.numBlockIO = (19);/* Number of block outputs */
  PID_LoadCell_Magnet_M->Sizes.numBlockPrms = (108);/* Sum of parameter "widths" */
  return PID_LoadCell_Magnet_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
