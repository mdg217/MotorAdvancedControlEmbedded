/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SystemLoopDiscrete.c
 *
 * Code generated for Simulink model 'SystemLoopDiscrete'.
 *
 * Model version                  : 1.18
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Wed Jun 14 12:14:25 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SystemLoopDiscrete.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "SystemLoopDiscrete_types.h"
#include "SystemLoopDiscrete_private.h"

/* Block signals (default storage) */
B_SystemLoopDiscrete_T SystemLoopDiscrete_B;

/* Block states (default storage) */
DW_SystemLoopDiscrete_T SystemLoopDiscrete_DW;

/* Real-time model */
static RT_MODEL_SystemLoopDiscrete_T SystemLoopDiscrete_M_;
RT_MODEL_SystemLoopDiscrete_T *const SystemLoopDiscrete_M =
  &SystemLoopDiscrete_M_;

/* Model step function */
void SystemLoopDiscrete_step(void)
{
  real_T xnew[3];
  real_T DiscreteStateSpace_DSTATE;
  real_T rtb_Abs;
  real_T sum;
  int_T i;
  uint16_T b_varargout_1;
  uint16_T b_varargout_2;

  /* DiscreteStateSpace: '<Root>/Discrete State-Space' */
  sum = SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[1];
  rtb_Abs = SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[0];
  DiscreteStateSpace_DSTATE = SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[2];
  for (i = 0; i < 3; i++) {
    /* DiscreteStateSpace: '<Root>/Discrete State-Space' */
    SystemLoopDiscrete_B.DiscreteStateSpace[i] =
      (SystemLoopDiscrete_P.DiscreteStateSpace_C[i + 3] * sum +
       SystemLoopDiscrete_P.DiscreteStateSpace_C[i] * rtb_Abs) +
      SystemLoopDiscrete_P.DiscreteStateSpace_C[i + 6] *
      DiscreteStateSpace_DSTATE;
  }

  /* End of DiscreteStateSpace: '<Root>/Discrete State-Space' */
  /* MATLABSystem: '<S2>/Qudrature Encoder' */
  if (SystemLoopDiscrete_DW.obj.SampleTime != SystemLoopDiscrete_P.Ts) {
    SystemLoopDiscrete_DW.obj.SampleTime = SystemLoopDiscrete_P.Ts;
  }

  /* 		%% Define output properties */
  /*  Call C-function implementing device output */
  b_varargout_1 = getEncoderCount();
  getIndexCount(&b_varargout_2);

  /* MATLAB Function: '<S2>/MATLAB Function2' incorporates:
   *  Delay: '<S2>/Delay1'
   */
  SystemLoopDiscrete_B.last_ticks_star = SystemLoopDiscrete_DW.Delay1_DSTATE;

  /* MATLAB Function: '<S2>/MATLAB Function' incorporates:
   *  Constant: '<S2>/Ts'
   *  Delay: '<S2>/Delay'
   *  MATLABSystem: '<S2>/Qudrature Encoder'
   */
  i = b_varargout_1 - SystemLoopDiscrete_DW.Delay_DSTATE;
  if (!(fabs((real_T)i) <= ceil(8400.0 * SystemLoopDiscrete_P.Ts))) {
    if (SystemLoopDiscrete_DW.Delay_DSTATE > b_varargout_1) {
      i += 65535;
    } else {
      i -= 65535;
    }
  }

  /* MATLAB Function: '<S2>/MATLAB Function2' incorporates:
   *  MATLAB Function: '<S2>/MATLAB Function'
   */
  sum = SystemLoopDiscrete_B.last_ticks_star + (real_T)i;
  rtb_Abs = fabs(sum);
  if (rtIsNaN(sum)) {
    sum = (rtNaN);
  } else if (sum < 0.0) {
    sum = -1.0;
  } else {
    sum = (sum > 0.0);
  }

  if (rtIsNaN(rtb_Abs)) {
    rtb_Abs = (rtNaN);
  } else if (rtIsInf(rtb_Abs)) {
    rtb_Abs = (rtNaN);
  } else if (rtb_Abs == 0.0) {
    rtb_Abs = 0.0;
  } else {
    rtb_Abs = fmod(rtb_Abs, 89796.0);
  }

  SystemLoopDiscrete_B.last_ticks_star = sum * rtb_Abs;

  /* MATLAB Function: '<S2>/MATLAB Function3' */
  SystemLoopDiscrete_B.position = 6.2831853071795862 *
    SystemLoopDiscrete_B.last_ticks_star / 3591.84;

  /* Constant: '<Root>/Constant2' */
  SystemLoopDiscrete_B.ref = SystemLoopDiscrete_P.Constant2_Value;

  /* MATLAB Function: '<Root>/Controller' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Delay: '<Root>/Delay1'
   *  Delay: '<Root>/Delay2'
   *  Delay: '<Root>/Delay3'
   */
  sum = SystemLoopDiscrete_B.ref - SystemLoopDiscrete_DW.Delay3_DSTATE;
  if (((!(SystemLoopDiscrete_DW.Delay2_DSTATE > 12.0)) || (!(sum > 0.0))) &&
      ((!(SystemLoopDiscrete_DW.Delay2_DSTATE < -12.0)) || (!(sum < 0.0)))) {
    SystemLoopDiscrete_DW.Delay1_DSTATE_l += sum;
    SystemLoopDiscrete_B.u = ((-SystemLoopDiscrete_P.Kp[0] *
      SystemLoopDiscrete_B.DiscreteStateSpace[0] - SystemLoopDiscrete_P.Kp[1] *
      SystemLoopDiscrete_B.DiscreteStateSpace[1]) - SystemLoopDiscrete_P.Kp[2] *
      SystemLoopDiscrete_B.DiscreteStateSpace[2]) + SystemLoopDiscrete_P.ki *
      SystemLoopDiscrete_DW.Delay1_DSTATE_l;
  } else {
    SystemLoopDiscrete_B.u = ((-SystemLoopDiscrete_P.Kp[0] *
      SystemLoopDiscrete_B.DiscreteStateSpace[0] - SystemLoopDiscrete_P.Kp[1] *
      SystemLoopDiscrete_B.DiscreteStateSpace[1]) - SystemLoopDiscrete_P.Kp[2] *
      SystemLoopDiscrete_B.DiscreteStateSpace[2]) + SystemLoopDiscrete_P.ki *
      SystemLoopDiscrete_DW.Delay1_DSTATE_l;
  }

  /* End of MATLAB Function: '<Root>/Controller' */

  /* Step: '<Root>/Step1' */
  if (SystemLoopDiscrete_M->Timing.taskTime0 < SystemLoopDiscrete_P.Step1_Time)
  {
    /* Step: '<Root>/Step1' */
    SystemLoopDiscrete_B.Step1 = SystemLoopDiscrete_P.Step1_Y0;
  } else {
    /* Step: '<Root>/Step1' */
    SystemLoopDiscrete_B.Step1 = SystemLoopDiscrete_P.Step1_YFinal;
  }

  /* End of Step: '<Root>/Step1' */

  /* Sum: '<Root>/Sum' */
  SystemLoopDiscrete_B.ing = SystemLoopDiscrete_B.Step1 + SystemLoopDiscrete_B.u;

  /* Saturate: '<Root>/Saturation' */
  if (SystemLoopDiscrete_B.ing > SystemLoopDiscrete_P.Saturation_UpperSat) {
    /* Saturate: '<Root>/Saturation' */
    SystemLoopDiscrete_B.Saturation = SystemLoopDiscrete_P.Saturation_UpperSat;
  } else if (SystemLoopDiscrete_B.ing < SystemLoopDiscrete_P.Saturation_LowerSat)
  {
    /* Saturate: '<Root>/Saturation' */
    SystemLoopDiscrete_B.Saturation = SystemLoopDiscrete_P.Saturation_LowerSat;
  } else {
    /* Saturate: '<Root>/Saturation' */
    SystemLoopDiscrete_B.Saturation = SystemLoopDiscrete_B.ing;
  }

  /* End of Saturate: '<Root>/Saturation' */
  /* Gain: '<S2>/Gain' */
  SystemLoopDiscrete_B.Gain = SystemLoopDiscrete_P.Gain_Gain *
    SystemLoopDiscrete_B.Saturation;

  /* Saturate: '<S2>/Saturation' */
  if (SystemLoopDiscrete_B.Gain > SystemLoopDiscrete_P.Saturation_UpperSat_a) {
    sum = SystemLoopDiscrete_P.Saturation_UpperSat_a;
  } else if (SystemLoopDiscrete_B.Gain <
             SystemLoopDiscrete_P.Saturation_LowerSat_h) {
    sum = SystemLoopDiscrete_P.Saturation_LowerSat_h;
  } else {
    sum = SystemLoopDiscrete_B.Gain;
  }

  /* Abs: '<S2>/Abs' incorporates:
   *  Saturate: '<S2>/Saturation'
   */
  rtb_Abs = fabs(sum);

  /* Signum: '<S6>/Sign' */
  if (rtIsNaN(SystemLoopDiscrete_B.Gain)) {
    sum = (rtNaN);
  } else if (SystemLoopDiscrete_B.Gain < 0.0) {
    sum = -1.0;
  } else {
    sum = (SystemLoopDiscrete_B.Gain > 0.0);
  }

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/Constant'
   *  Constant: '<S6>/Constant1'
   *  Signum: '<S6>/Sign'
   *  Sum: '<S6>/Sum'
   */
  sum = (sum + SystemLoopDiscrete_P.Constant1_Value) /
    SystemLoopDiscrete_P.Constant_Value;

  /* MATLABSystem: '<S2>/IN2B' incorporates:
   *  Product: '<S2>/Product1'
   */
  MW_PWM_SetDutyCycle(SystemLoopDiscrete_DW.obj_n.MW_PWM_HANDLE, rtb_Abs * sum);

  /* MATLABSystem: '<S2>/IN2A' incorporates:
   *  Logic: '<S2>/Logical Operator'
   *  Product: '<S2>/Product'
   */
  MW_PWM_SetDutyCycle(SystemLoopDiscrete_DW.obj_g.MW_PWM_HANDLE, rtb_Abs *
                      (real_T)!(sum != 0.0));

  /* RateTransition generated from: '<S2>/Qudrature Encoder' incorporates:
   *  MATLABSystem: '<S2>/Qudrature Encoder'
   */
  SystemLoopDiscrete_B.HiddenRateTransitionForToWks_In = b_varargout_1;

  /* MATLABSystem: '<S2>/EN_A' incorporates:
   *  Constant: '<S2>/enable'
   */
  MW_digitalIO_write(SystemLoopDiscrete_DW.obj_e.MW_DIGITALIO_HANDLE,
                     SystemLoopDiscrete_P.enable_Value != 0.0);

  /* Update for DiscreteStateSpace: '<Root>/Discrete State-Space' incorporates:
   *  SignalConversion generated from: '<Root>/Discrete State-Space'
   */
  sum = SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[1];
  rtb_Abs = SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[0];
  DiscreteStateSpace_DSTATE = SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[2];
  for (i = 0; i < 3; i++) {
    xnew[i] = ((((SystemLoopDiscrete_P.Ad[i + 3] -
                  SystemLoopDiscrete_ConstP.DiscreteStateSpace_rtw_collapse[i +
                  3]) * sum + (SystemLoopDiscrete_P.Ad[i] -
      SystemLoopDiscrete_ConstP.DiscreteStateSpace_rtw_collapse[i]) * rtb_Abs) +
                (SystemLoopDiscrete_P.Ad[i + 6] -
                 SystemLoopDiscrete_ConstP.DiscreteStateSpace_rtw_collapse[i + 6])
                * DiscreteStateSpace_DSTATE) +
               SystemLoopDiscrete_P.DiscreteStateSpace_B[i] *
               SystemLoopDiscrete_B.Saturation) +
      SystemLoopDiscrete_P.DiscreteStateSpace_B[i + 3] *
      SystemLoopDiscrete_B.position;
  }

  SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[0] = xnew[0];
  SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[1] = xnew[1];
  SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[2] = xnew[2];

  /* End of Update for DiscreteStateSpace: '<Root>/Discrete State-Space' */

  /* Update for Delay: '<S2>/Delay1' */
  SystemLoopDiscrete_DW.Delay1_DSTATE = SystemLoopDiscrete_B.last_ticks_star;

  /* Update for Delay: '<S2>/Delay' incorporates:
   *  MATLABSystem: '<S2>/Qudrature Encoder'
   */
  SystemLoopDiscrete_DW.Delay_DSTATE = b_varargout_1;

  /* Update for Delay: '<Root>/Delay2' */
  SystemLoopDiscrete_DW.Delay2_DSTATE = SystemLoopDiscrete_B.u;

  /* Update for Delay: '<Root>/Delay3' */
  SystemLoopDiscrete_DW.Delay3_DSTATE = SystemLoopDiscrete_B.DiscreteStateSpace
    [0];

  {                                    /* Sample time: [0.005s, 0.0s] */
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  SystemLoopDiscrete_M->Timing.taskTime0 =
    ((time_T)(++SystemLoopDiscrete_M->Timing.clockTick0)) *
    SystemLoopDiscrete_M->Timing.stepSize0;
}

/* Model initialize function */
void SystemLoopDiscrete_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));
  rtmSetTFinal(SystemLoopDiscrete_M, 50.0);
  SystemLoopDiscrete_M->Timing.stepSize0 = 0.005;

  /* External mode info */
  SystemLoopDiscrete_M->Sizes.checksums[0] = (4227313624U);
  SystemLoopDiscrete_M->Sizes.checksums[1] = (1603159129U);
  SystemLoopDiscrete_M->Sizes.checksums[2] = (3829998838U);
  SystemLoopDiscrete_M->Sizes.checksums[3] = (2023418879U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    SystemLoopDiscrete_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(SystemLoopDiscrete_M->extModeInfo,
      &SystemLoopDiscrete_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(SystemLoopDiscrete_M->extModeInfo,
                        SystemLoopDiscrete_M->Sizes.checksums);
    rteiSetTPtr(SystemLoopDiscrete_M->extModeInfo, rtmGetTPtr
                (SystemLoopDiscrete_M));
  }

  {
    uint32_T pinname;
    mbed_DigitalWrite_SystemLoopD_T *obj_0;
    mbed_PWMOutput_SystemLoopDisc_T *obj;

    /* Start for Constant: '<Root>/Constant2' */
    SystemLoopDiscrete_B.ref = SystemLoopDiscrete_P.Constant2_Value;

    /* InitializeConditions for DiscreteStateSpace: '<Root>/Discrete State-Space' */
    SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[0] =
      SystemLoopDiscrete_P.DiscreteStateSpace_InitialCondi;
    SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[1] =
      SystemLoopDiscrete_P.DiscreteStateSpace_InitialCondi;
    SystemLoopDiscrete_DW.DiscreteStateSpace_DSTATE[2] =
      SystemLoopDiscrete_P.DiscreteStateSpace_InitialCondi;

    /* InitializeConditions for Delay: '<S2>/Delay1' */
    SystemLoopDiscrete_DW.Delay1_DSTATE =
      SystemLoopDiscrete_P.Delay1_InitialCondition;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    SystemLoopDiscrete_DW.Delay_DSTATE =
      SystemLoopDiscrete_P.Delay_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay2' */
    SystemLoopDiscrete_DW.Delay2_DSTATE =
      SystemLoopDiscrete_P.Delay2_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay3' */
    SystemLoopDiscrete_DW.Delay3_DSTATE =
      SystemLoopDiscrete_P.Delay3_InitialCondition;

    /* InitializeConditions for Delay: '<Root>/Delay1' */
    SystemLoopDiscrete_DW.Delay1_DSTATE_l =
      SystemLoopDiscrete_P.Delay1_InitialCondition_f;

    /* Start for MATLABSystem: '<S2>/Qudrature Encoder' */
    /*  Constructor */
    SystemLoopDiscrete_DW.obj.matlabCodegenIsDeleted = false;
    SystemLoopDiscrete_DW.obj.SampleTime = SystemLoopDiscrete_P.Ts;
    SystemLoopDiscrete_DW.obj.isInitialized = 1;

    /* 		%% Define output properties */
    /*  Call C-function implementing device initialization */
    initEncoder();
    SystemLoopDiscrete_DW.obj.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/IN2B' */
    SystemLoopDiscrete_DW.obj_n.matlabCodegenIsDeleted = false;
    obj = &SystemLoopDiscrete_DW.obj_n;
    SystemLoopDiscrete_DW.obj_n.isInitialized = 1;
    pinname = 5;
    obj->MW_PWM_HANDLE = MW_PWM_Open(pinname, 2000.0, 50.0);
    MW_PWM_Start(SystemLoopDiscrete_DW.obj_n.MW_PWM_HANDLE);
    SystemLoopDiscrete_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/IN2A' */
    SystemLoopDiscrete_DW.obj_g.matlabCodegenIsDeleted = false;
    obj = &SystemLoopDiscrete_DW.obj_g;
    SystemLoopDiscrete_DW.obj_g.isInitialized = 1;
    pinname = 4;
    obj->MW_PWM_HANDLE = MW_PWM_Open(pinname, 2000.0, 50.0);
    MW_PWM_Start(SystemLoopDiscrete_DW.obj_g.MW_PWM_HANDLE);
    SystemLoopDiscrete_DW.obj_g.isSetupComplete = true;

    /* Start for MATLABSystem: '<S2>/EN_A' */
    SystemLoopDiscrete_DW.obj_e.matlabCodegenIsDeleted = false;
    obj_0 = &SystemLoopDiscrete_DW.obj_e;
    SystemLoopDiscrete_DW.obj_e.isInitialized = 1;
    pinname = 2;
    obj_0->MW_DIGITALIO_HANDLE = MW_digitalIO_open(pinname, 1);
    SystemLoopDiscrete_DW.obj_e.isSetupComplete = true;
  }
}

/* Model terminate function */
void SystemLoopDiscrete_terminate(void)
{
  /* Terminate for MATLABSystem: '<S2>/Qudrature Encoder' */
  if (!SystemLoopDiscrete_DW.obj.matlabCodegenIsDeleted) {
    SystemLoopDiscrete_DW.obj.matlabCodegenIsDeleted = true;
    if ((SystemLoopDiscrete_DW.obj.isInitialized == 1) &&
        SystemLoopDiscrete_DW.obj.isSetupComplete) {
      /*  Call C-function implementing device termination */
      releaseEncoder();
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/Qudrature Encoder' */
  /* Terminate for MATLABSystem: '<S2>/IN2B' */
  if (!SystemLoopDiscrete_DW.obj_n.matlabCodegenIsDeleted) {
    SystemLoopDiscrete_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((SystemLoopDiscrete_DW.obj_n.isInitialized == 1) &&
        SystemLoopDiscrete_DW.obj_n.isSetupComplete) {
      MW_PWM_Stop(SystemLoopDiscrete_DW.obj_n.MW_PWM_HANDLE);
      MW_PWM_Close(SystemLoopDiscrete_DW.obj_n.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN2B' */

  /* Terminate for MATLABSystem: '<S2>/IN2A' */
  if (!SystemLoopDiscrete_DW.obj_g.matlabCodegenIsDeleted) {
    SystemLoopDiscrete_DW.obj_g.matlabCodegenIsDeleted = true;
    if ((SystemLoopDiscrete_DW.obj_g.isInitialized == 1) &&
        SystemLoopDiscrete_DW.obj_g.isSetupComplete) {
      MW_PWM_Stop(SystemLoopDiscrete_DW.obj_g.MW_PWM_HANDLE);
      MW_PWM_Close(SystemLoopDiscrete_DW.obj_g.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/IN2A' */
  /* Terminate for MATLABSystem: '<S2>/EN_A' */
  if (!SystemLoopDiscrete_DW.obj_e.matlabCodegenIsDeleted) {
    SystemLoopDiscrete_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((SystemLoopDiscrete_DW.obj_e.isInitialized == 1) &&
        SystemLoopDiscrete_DW.obj_e.isSetupComplete) {
      MW_digitalIO_close(SystemLoopDiscrete_DW.obj_e.MW_DIGITALIO_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S2>/EN_A' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
