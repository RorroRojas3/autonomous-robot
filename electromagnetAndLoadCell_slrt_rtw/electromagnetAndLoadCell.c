/*
 * electromagnetAndLoadCell.c
 *
 * Academic Student License -- for use by students to meet course
 * requirements and perform academic research at degree granting
 * institutions only.  Not for government, commercial, or other
 * organizational use.
 *
 * Code generation for model "electromagnetAndLoadCell".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Apr 05 13:12:03 2018
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "electromagnetAndLoadCell_capi.h"
#include "electromagnetAndLoadCell.h"
#include "electromagnetAndLoadCell_private.h"

/* Block signals (auto storage) */
B_electromagnetAndLoadCell_T electromagnetAndLoadCell_B;

/* Block states (auto storage) */
DW_electromagnetAndLoadCell_T electromagnetAndLoadCell_DW;

/* Real-time model */
RT_MODEL_electromagnetAndLoadCell_T electromagnetAndLoadCell_M_;
RT_MODEL_electromagnetAndLoadCell_T *const electromagnetAndLoadCell_M =
  &electromagnetAndLoadCell_M_;

/* Model output function */
static void electromagnetAndLoadCell_output(void)
{
  /* Constant: '<Root>/DC Input' */
  electromagnetAndLoadCell_B.DCInput = electromagnetAndLoadCell_P.DCInput_Value;

  /* S-Function (daquanserq8): '<Root>/Q4 DA ' */

  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = electromagnetAndLoadCell_M->childSfunctions[0];
    sfcnOutputs(rts,0);
  }

  /* S-Function (scblock): '<S1>/S-Function' */
  /* ok to acquire for <S1>/S-Function */
  electromagnetAndLoadCell_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S2>/S-Function' */
  /* ok to acquire for <S2>/S-Function */
  electromagnetAndLoadCell_DW.SFunction_IWORK_n.AcquireOK = 1;

  /* S-Function (adquanserq8): '<Root>/Q4 AD' */

  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = electromagnetAndLoadCell_M->childSfunctions[1];
    sfcnOutputs(rts,0);
  }
}

/* Model update function */
static void electromagnetAndLoadCell_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++electromagnetAndLoadCell_M->Timing.clockTick0)) {
    ++electromagnetAndLoadCell_M->Timing.clockTickH0;
  }

  electromagnetAndLoadCell_M->Timing.t[0] =
    electromagnetAndLoadCell_M->Timing.clockTick0 *
    electromagnetAndLoadCell_M->Timing.stepSize0 +
    electromagnetAndLoadCell_M->Timing.clockTickH0 *
    electromagnetAndLoadCell_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void electromagnetAndLoadCell_initialize(void)
{
  /* Start for Constant: '<Root>/DC Input' */
  electromagnetAndLoadCell_B.DCInput = electromagnetAndLoadCell_P.DCInput_Value;

  /* Start for S-Function (daquanserq8): '<Root>/Q4 DA ' */
  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = electromagnetAndLoadCell_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S1>/S-Function' */

  /* S-Function Block: <S1>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,2)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("DC Input"));
        rl32eSetScope(2, 4, 250);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("DC Input"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        rl32eSetTargetScope(2, 1, 3.0);
        rl32eSetTargetScope(2, 11, -1.0);
        rl32eSetTargetScope(2, 10, 1.0);
        xpceScopeAcqOK(2, &electromagnetAndLoadCell_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,2)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(3, 4, 250);
        rl32eSetScope(3, 5, 0);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("Q4 AD"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        rl32eSetTargetScope(3, 11, 0.0);
        rl32eSetTargetScope(3, 10, 0.0);
        xpceScopeAcqOK(3,
                       &electromagnetAndLoadCell_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = electromagnetAndLoadCell_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
static void electromagnetAndLoadCell_terminate(void)
{
  /* Terminate for S-Function (daquanserq8): '<Root>/Q4 DA ' */
  /* Level2 S-Function Block: '<Root>/Q4 DA ' (daquanserq8) */
  {
    SimStruct *rts = electromagnetAndLoadCell_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (adquanserq8): '<Root>/Q4 AD' */
  /* Level2 S-Function Block: '<Root>/Q4 AD' (adquanserq8) */
  {
    SimStruct *rts = electromagnetAndLoadCell_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  electromagnetAndLoadCell_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  electromagnetAndLoadCell_update();
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
  electromagnetAndLoadCell_initialize();
}

void MdlTerminate(void)
{
  electromagnetAndLoadCell_terminate();
}

/* Registration function */
RT_MODEL_electromagnetAndLoadCell_T *electromagnetAndLoadCell(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)electromagnetAndLoadCell_M, 0,
                sizeof(RT_MODEL_electromagnetAndLoadCell_T));
  rtsiSetSolverName(&electromagnetAndLoadCell_M->solverInfo,"FixedStepDiscrete");
  electromagnetAndLoadCell_M->solverInfoPtr =
    (&electromagnetAndLoadCell_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = electromagnetAndLoadCell_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    electromagnetAndLoadCell_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    electromagnetAndLoadCell_M->Timing.sampleTimes =
      (&electromagnetAndLoadCell_M->Timing.sampleTimesArray[0]);
    electromagnetAndLoadCell_M->Timing.offsetTimes =
      (&electromagnetAndLoadCell_M->Timing.offsetTimesArray[0]);

    /* task periods */
    electromagnetAndLoadCell_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    electromagnetAndLoadCell_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(electromagnetAndLoadCell_M,
             &electromagnetAndLoadCell_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = electromagnetAndLoadCell_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    electromagnetAndLoadCell_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(electromagnetAndLoadCell_M, -1);
  electromagnetAndLoadCell_M->Timing.stepSize0 = 0.001;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    electromagnetAndLoadCell_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(electromagnetAndLoadCell_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(electromagnetAndLoadCell_M->rtwLogInfo, (NULL));
    rtliSetLogT(electromagnetAndLoadCell_M->rtwLogInfo, "tout");
    rtliSetLogX(electromagnetAndLoadCell_M->rtwLogInfo, "");
    rtliSetLogXFinal(electromagnetAndLoadCell_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(electromagnetAndLoadCell_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(electromagnetAndLoadCell_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(electromagnetAndLoadCell_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(electromagnetAndLoadCell_M->rtwLogInfo, 1);
    rtliSetLogY(electromagnetAndLoadCell_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(electromagnetAndLoadCell_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(electromagnetAndLoadCell_M->rtwLogInfo, (NULL));
  }

  electromagnetAndLoadCell_M->solverInfoPtr =
    (&electromagnetAndLoadCell_M->solverInfo);
  electromagnetAndLoadCell_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&electromagnetAndLoadCell_M->solverInfo, 0.001);
  rtsiSetSolverMode(&electromagnetAndLoadCell_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  electromagnetAndLoadCell_M->blockIO = ((void *) &electromagnetAndLoadCell_B);
  (void) memset(((void *) &electromagnetAndLoadCell_B), 0,
                sizeof(B_electromagnetAndLoadCell_T));

  /* parameters */
  electromagnetAndLoadCell_M->defaultParam = ((real_T *)
    &electromagnetAndLoadCell_P);

  /* states (dwork) */
  electromagnetAndLoadCell_M->dwork = ((void *) &electromagnetAndLoadCell_DW);
  (void) memset((void *)&electromagnetAndLoadCell_DW, 0,
                sizeof(DW_electromagnetAndLoadCell_T));

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  electromagnetAndLoadCell_InitializeDataMapInfo(electromagnetAndLoadCell_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &electromagnetAndLoadCell_M->NonInlinedSFcns.sfcnInfo;
    electromagnetAndLoadCell_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (electromagnetAndLoadCell_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &electromagnetAndLoadCell_M->Sizes.numSampTimes);
    electromagnetAndLoadCell_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (electromagnetAndLoadCell_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,
                   electromagnetAndLoadCell_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(electromagnetAndLoadCell_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(electromagnetAndLoadCell_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (electromagnetAndLoadCell_M));
    rtssSetStepSizePtr(sfcnInfo, &electromagnetAndLoadCell_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (electromagnetAndLoadCell_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &electromagnetAndLoadCell_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &electromagnetAndLoadCell_M->zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &electromagnetAndLoadCell_M->blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &electromagnetAndLoadCell_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &electromagnetAndLoadCell_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &electromagnetAndLoadCell_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &electromagnetAndLoadCell_M->solverInfoPtr);
  }

  electromagnetAndLoadCell_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)
                  &electromagnetAndLoadCell_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  2*sizeof(SimStruct));
    electromagnetAndLoadCell_M->childSfunctions =
      (&electromagnetAndLoadCell_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    electromagnetAndLoadCell_M->childSfunctions[0] =
      (&electromagnetAndLoadCell_M->NonInlinedSFcns.childSFunctions[0]);
    electromagnetAndLoadCell_M->childSfunctions[1] =
      (&electromagnetAndLoadCell_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: electromagnetAndLoadCell/<Root>/Q4 DA  (daquanserq8) */
    {
      SimStruct *rts = electromagnetAndLoadCell_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &electromagnetAndLoadCell_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, electromagnetAndLoadCell_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &electromagnetAndLoadCell_M->
                           NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &electromagnetAndLoadCell_M->
                           NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &electromagnetAndLoadCell_M->
                           NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &electromagnetAndLoadCell_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &electromagnetAndLoadCell_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &electromagnetAndLoadCell_B.DCInput;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 DA ");
      ssSetPath(rts, "electromagnetAndLoadCell/Q4 DA ");
      ssSetRTModel(rts,electromagnetAndLoadCell_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 9);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)electromagnetAndLoadCell_P.Q4DA_P9_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &electromagnetAndLoadCell_DW.Q4DA_RWORK[0]);
      ssSetIWork(rts, (int_T *) &electromagnetAndLoadCell_DW.Q4DA_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 16);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &electromagnetAndLoadCell_DW.Q4DA_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &electromagnetAndLoadCell_DW.Q4DA_IWORK);
      }

      /* registration */
      daquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: electromagnetAndLoadCell/<Root>/Q4 AD (adquanserq8) */
    {
      SimStruct *rts = electromagnetAndLoadCell_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts,
                         &electromagnetAndLoadCell_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, electromagnetAndLoadCell_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &electromagnetAndLoadCell_M->
                           NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &electromagnetAndLoadCell_M->
                           NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &electromagnetAndLoadCell_M->
                           NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &electromagnetAndLoadCell_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &electromagnetAndLoadCell_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &electromagnetAndLoadCell_B.Q4AD));
        }
      }

      /* path info */
      ssSetModelName(rts, "Q4 AD");
      ssSetPath(rts, "electromagnetAndLoadCell/Q4 AD");
      ssSetRTModel(rts,electromagnetAndLoadCell_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)electromagnetAndLoadCell_P.Q4AD_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)electromagnetAndLoadCell_P.Q4AD_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)electromagnetAndLoadCell_P.Q4AD_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)electromagnetAndLoadCell_P.Q4AD_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)electromagnetAndLoadCell_P.Q4AD_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)electromagnetAndLoadCell_P.Q4AD_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)electromagnetAndLoadCell_P.Q4AD_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &electromagnetAndLoadCell_DW.Q4AD_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &electromagnetAndLoadCell_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &electromagnetAndLoadCell_DW.Q4AD_IWORK[0]);
      }

      /* registration */
      adquanserq8(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  electromagnetAndLoadCell_M->Sizes.numContStates = (0);/* Number of continuous states */
  electromagnetAndLoadCell_M->Sizes.numY = (0);/* Number of model outputs */
  electromagnetAndLoadCell_M->Sizes.numU = (0);/* Number of model inputs */
  electromagnetAndLoadCell_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  electromagnetAndLoadCell_M->Sizes.numSampTimes = (1);/* Number of sample times */
  electromagnetAndLoadCell_M->Sizes.numBlocks = (5);/* Number of blocks */
  electromagnetAndLoadCell_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  electromagnetAndLoadCell_M->Sizes.numBlockPrms = (48);/* Sum of parameter "widths" */
  return electromagnetAndLoadCell_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
