/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MIL_Model_Position_Control_Kalman.c
 *
 * Code generated for Simulink model 'MIL_Model_Position_Control_Kalman'.
 *
 * Model version                  : 1.16
 * Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
 * C/C++ source code generated on : Fri Jun 16 22:05:31 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "MIL_Model_Position_Control_Kalman.h"
#include "rtwtypes.h"
#include "MIL_Model_Position_Control_Kalman_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "rt_nrand_Upu32_Yd_f_pw_snf.h"

P_MIL_Model_Position_Control__T MIL_Model_Position_Control_Ka_P = {
  /* Mask Parameter: WhiteNoise4_Cov
   * Referenced by: '<S4>/Output'
   */
  2.0,

  /* Mask Parameter: WhiteNoise4_seed
   * Referenced by: '<S4>/White Noise'
   */
  213132.0,

  /* Expression: [Bd L_tK]
   * Referenced by: '<S2>/Discrete State-Space'
   */
  { 0.0002031330115231402, 0.10075804106369085, 0.18268501368951098,
    0.095158380621913771, 0.00069868017575852224, -0.000131541452688349 },

  /* Expression: eye(3)
   * Referenced by: '<S2>/Discrete State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [ 0 0; 0 0; 0 0]
   * Referenced by: '<S2>/Discrete State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<S2>/Discrete State-Space'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S1>/Delay1'
   */
  0.0,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<Root>/Saturation'
   */
  -12.0,

  /* Expression: 0
   * Referenced by: '<S4>/White Noise'
   */
  0.0,

  /* Computed Parameter: WhiteNoise_StdDev
   * Referenced by: '<S4>/White Noise'
   */
  1.0,

  /* Expression: 0.01
   * Referenced by: '<S2>/Constant11'
   */
  0.01
};

/* System initialize for referenced model: 'MIL_Model_Position_Control_Kalman' */
void MIL_Model_Position_Control_Init(DW_MIL_Model_Position_Contr_f_T *localDW)
{
  real_T tmp;
  int32_T r;
  int32_T t;
  uint32_T tseed;

  /* InitializeConditions for DiscreteStateSpace: '<S2>/Discrete State-Space' */
  localDW->DiscreteStateSpace_DSTATE[0] =
    MIL_Model_Position_Control_Ka_P.DiscreteStateSpace_InitialCondi;
  localDW->DiscreteStateSpace_DSTATE[1] =
    MIL_Model_Position_Control_Ka_P.DiscreteStateSpace_InitialCondi;
  localDW->DiscreteStateSpace_DSTATE[2] =
    MIL_Model_Position_Control_Ka_P.DiscreteStateSpace_InitialCondi;

  /* InitializeConditions for Delay: '<S1>/Delay2' */
  localDW->Delay2_DSTATE =
    MIL_Model_Position_Control_Ka_P.Delay2_InitialCondition;

  /* InitializeConditions for Delay: '<S1>/Delay1' */
  localDW->Delay1_DSTATE =
    MIL_Model_Position_Control_Ka_P.Delay1_InitialCondition;

  /* InitializeConditions for RandomNumber: '<S4>/White Noise' */
  tmp = floor(MIL_Model_Position_Control_Ka_P.WhiteNoise4_seed);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
  r = (int32_T)(tseed >> 16U);
  t = (int32_T)(tseed & 32768U);
  localDW->RandSeed = ((((tseed - ((uint32_T)r << 16U)) + (uint32_T)t) << 16U) +
                       (uint32_T)t) + (uint32_T)r;
  if (localDW->RandSeed < 1U) {
    localDW->RandSeed = 1144108930U;
  } else if (localDW->RandSeed > 2147483646U) {
    localDW->RandSeed = 2147483646U;
  }

  localDW->NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&localDW->RandSeed) *
    MIL_Model_Position_Control_Ka_P.WhiteNoise_StdDev +
    MIL_Model_Position_Control_Ka_P.WhiteNoise_Mean;

  /* End of InitializeConditions for RandomNumber: '<S4>/White Noise' */
}

/* Output and update for referenced model: 'MIL_Model_Position_Control_Kalman' */
void MIL_Model_Position_Control_Kalm(const real_T *rtu_y, const real_T *rtu_r,
  const real_T *rtu_dist, real_T *rty_ek, real_T *rty_u_sat,
  B_MIL_Model_Position_Contro_c_T *localB, DW_MIL_Model_Position_Contr_f_T
  *localDW)
{
  real_T DiscreteStateSpace_DSTATE;
  real_T DiscreteStateSpace_DSTATE_0;
  real_T DiscreteStateSpace_DSTATE_1;
  int_T i;

  /* DiscreteStateSpace: '<S2>/Discrete State-Space' */
  DiscreteStateSpace_DSTATE = localDW->DiscreteStateSpace_DSTATE[1];
  DiscreteStateSpace_DSTATE_0 = localDW->DiscreteStateSpace_DSTATE[0];
  DiscreteStateSpace_DSTATE_1 = localDW->DiscreteStateSpace_DSTATE[2];
  for (i = 0; i < 3; i++) {
    /* DiscreteStateSpace: '<S2>/Discrete State-Space' */
    localB->DiscreteStateSpace[i] =
      (MIL_Model_Position_Control_Ka_P.DiscreteStateSpace_C[i + 3] *
       DiscreteStateSpace_DSTATE +
       MIL_Model_Position_Control_Ka_P.DiscreteStateSpace_C[i] *
       DiscreteStateSpace_DSTATE_0) +
      MIL_Model_Position_Control_Ka_P.DiscreteStateSpace_C[i + 6] *
      DiscreteStateSpace_DSTATE_1;
  }

  /* End of DiscreteStateSpace: '<S2>/Discrete State-Space' */
  /* MATLAB Function: '<S1>/Controller' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Delay: '<S1>/Delay1'
   *  Delay: '<S1>/Delay2'
   */
  localB->ek = *rtu_r - localB->DiscreteStateSpace[0];
  if (((!(localDW->Delay2_DSTATE > 12.0)) || (!(localB->ek > 0.0))) &&
      ((!(localDW->Delay2_DSTATE < -12.0)) || (!(localB->ek < 0.0)))) {
    localDW->Delay1_DSTATE += localB->ek;
    localB->u = ((-rtP_Kp[0] * localB->DiscreteStateSpace[0] - rtP_Kp[1] *
                  localB->DiscreteStateSpace[1]) - rtP_Kp[2] *
                 localB->DiscreteStateSpace[2]) + rtP_ki *
      localDW->Delay1_DSTATE;
  } else {
    localB->u = ((-rtP_Kp[0] * localB->DiscreteStateSpace[0] - rtP_Kp[1] *
                  localB->DiscreteStateSpace[1]) - rtP_Kp[2] *
                 localB->DiscreteStateSpace[2]) + rtP_ki *
      localDW->Delay1_DSTATE;
  }

  /* End of MATLAB Function: '<S1>/Controller' */

  /* RandomNumber: '<S4>/White Noise' incorporates:
   *  Sum: '<Root>/Sum'
   */
  localB->u_sat = *rtu_dist + localB->u;

  /* Saturate: '<Root>/Saturation' */
  if (localB->u_sat > MIL_Model_Position_Control_Ka_P.Saturation_UpperSat) {
    /* RandomNumber: '<S4>/White Noise' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    localB->u_sat = MIL_Model_Position_Control_Ka_P.Saturation_UpperSat;
  } else if (localB->u_sat < MIL_Model_Position_Control_Ka_P.Saturation_LowerSat)
  {
    /* RandomNumber: '<S4>/White Noise' incorporates:
     *  Saturate: '<Root>/Saturation'
     */
    localB->u_sat = MIL_Model_Position_Control_Ka_P.Saturation_LowerSat;
  }

  /* End of Saturate: '<Root>/Saturation' */

  /* Product: '<S2>/Product1' incorporates:
   *  Constant: '<S2>/Constant11'
   *  Gain: '<S4>/Output'
   *  RandomNumber: '<S4>/White Noise'
   */
  localB->Noise = sqrt(MIL_Model_Position_Control_Ka_P.WhiteNoise4_Cov) /
    0.070710678118654752 * localDW->NextOutput *
    MIL_Model_Position_Control_Ka_P.Constant11_Value;

  /* Sum: '<S2>/Sum6' */
  localB->y_noise = *rtu_y + localB->Noise;

  /* SignalConversion generated from: '<Root>/u_sat' */
  *rty_u_sat = localB->u_sat;

  /* SignalConversion generated from: '<Root>/ek' */
  *rty_ek = localB->ek;

  /* Update for DiscreteStateSpace: '<S2>/Discrete State-Space' incorporates:
   *  SignalConversion generated from: '<S2>/Discrete State-Space'
   */
  DiscreteStateSpace_DSTATE = localDW->DiscreteStateSpace_DSTATE[1];
  DiscreteStateSpace_DSTATE_0 = localDW->DiscreteStateSpace_DSTATE[0];
  DiscreteStateSpace_DSTATE_1 = localDW->DiscreteStateSpace_DSTATE[2];
  for (i = 0; i < 3; i++) {
    localB->xnew[i] = ((((rtP_Ad[i + 3] - rtCP_DiscreteStateSpace_rtw_col[i + 3])
                         * DiscreteStateSpace_DSTATE + (rtP_Ad[i] -
      rtCP_DiscreteStateSpace_rtw_col[i]) * DiscreteStateSpace_DSTATE_0) +
                        (rtP_Ad[i + 6] - rtCP_DiscreteStateSpace_rtw_col[i + 6])
                        * DiscreteStateSpace_DSTATE_1) +
                       MIL_Model_Position_Control_Ka_P.DiscreteStateSpace_B[i] *
                       localB->u_sat) +
      MIL_Model_Position_Control_Ka_P.DiscreteStateSpace_B[i + 3] *
      localB->y_noise;
  }

  localDW->DiscreteStateSpace_DSTATE[0] = localB->xnew[0];
  localDW->DiscreteStateSpace_DSTATE[1] = localB->xnew[1];
  localDW->DiscreteStateSpace_DSTATE[2] = localB->xnew[2];

  /* End of Update for DiscreteStateSpace: '<S2>/Discrete State-Space' */

  /* Update for Delay: '<S1>/Delay2' */
  localDW->Delay2_DSTATE = localB->u;

  /* Update for RandomNumber: '<S4>/White Noise' */
  localDW->NextOutput = rt_nrand_Upu32_Yd_f_pw_snf(&localDW->RandSeed) *
    MIL_Model_Position_Control_Ka_P.WhiteNoise_StdDev +
    MIL_Model_Position_Control_Ka_P.WhiteNoise_Mean;
}

/* Model initialize function */
void MIL_Model_Position_C_initialize(const char_T **rt_errorStatus,
  RT_MODEL_MIL_Model_Position_C_T *const MIL_Model_Position_Control_K_M)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(MIL_Model_Position_Control_K_M, rt_errorStatus);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
