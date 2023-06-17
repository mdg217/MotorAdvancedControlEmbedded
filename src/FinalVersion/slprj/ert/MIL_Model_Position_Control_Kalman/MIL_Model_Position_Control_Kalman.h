/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MIL_Model_Position_Control_Kalman.h
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

#ifndef RTW_HEADER_MIL_Model_Position_Control_Kalman_h_
#define RTW_HEADER_MIL_Model_Position_Control_Kalman_h_
#ifndef MIL_Model_Position_Control_Kalman_COMMON_INCLUDES_
#define MIL_Model_Position_Control_Kalman_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                  /* MIL_Model_Position_Control_Kalman_COMMON_INCLUDES_ */

#include "MIL_Model_Position_Control_Kalman_types.h"
#include "rt_nonfinite.h"

/* Block signals for model 'MIL_Model_Position_Control_Kalman' */
typedef struct {
  real_T DiscreteStateSpace[3];        /* '<S2>/Discrete State-Space' */
  real_T xnew[3];
  real_T u_sat;                        /* '<Root>/Saturation' */
  real_T Noise;                        /* '<S2>/Product1' */
  real_T y_noise;                      /* '<S2>/Sum6' */
  real_T u;                            /* '<S1>/Controller' */
  real_T ek;                           /* '<S1>/Controller' */
} B_MIL_Model_Position_Contro_c_T;

/* Block states (default storage) for model 'MIL_Model_Position_Control_Kalman' */
typedef struct {
  real_T DiscreteStateSpace_DSTATE[3]; /* '<S2>/Discrete State-Space' */
  real_T Delay2_DSTATE;                /* '<S1>/Delay2' */
  real_T Delay1_DSTATE;                /* '<S1>/Delay1' */
  real_T NextOutput;                   /* '<S4>/White Noise' */
  uint32_T RandSeed;                   /* '<S4>/White Noise' */
} DW_MIL_Model_Position_Contr_f_T;

/* Parameters (default storage) */
struct P_MIL_Model_Position_Control__T_ {
  real_T WhiteNoise4_Cov;              /* Mask Parameter: WhiteNoise4_Cov
                                        * Referenced by: '<S4>/Output'
                                        */
  real_T WhiteNoise4_seed;             /* Mask Parameter: WhiteNoise4_seed
                                        * Referenced by: '<S4>/White Noise'
                                        */
  real_T DiscreteStateSpace_B[6];      /* Expression: [Bd L_tK]
                                        * Referenced by: '<S2>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C[9];      /* Expression: eye(3)
                                        * Referenced by: '<S2>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D[6];      /* Expression: [ 0 0; 0 0; 0 0]
                                        * Referenced by: '<S2>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_InitialCondi;/* Expression: 0
                                          * Referenced by: '<S2>/Discrete State-Space'
                                          */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Delay2'
                                        */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S1>/Delay1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S4>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S4>/White Noise'
                                        */
  real_T Constant11_Value;             /* Expression: 0.01
                                        * Referenced by: '<S2>/Constant11'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_MIL_Model_Position_Co_T {
  const char_T **errorStatus;
};

typedef struct {
  B_MIL_Model_Position_Contro_c_T rtb;
  DW_MIL_Model_Position_Contr_f_T rtdw;
  RT_MODEL_MIL_Model_Position_C_T rtm;
} MdlrefDW_MIL_Model_Position_C_T;

/* Model block global parameters (default storage) */
extern real_T rtP_Ad[9];               /* Variable: Ad
                                        * Referenced by: '<S2>/Discrete State-Space'
                                        */
extern real_T rtP_Kp[3];               /* Variable: Kp
                                        * Referenced by: '<S1>/Constant'
                                        */
extern real_T rtP_ki;                  /* Variable: ki
                                        * Referenced by: '<S1>/Constant1'
                                        */

/* Model reference registration function */
extern void MIL_Model_Position_C_initialize(const char_T **rt_errorStatus,
  RT_MODEL_MIL_Model_Position_C_T *const MIL_Model_Position_Control_K_M);
extern void MIL_Model_Position_Control_Init(DW_MIL_Model_Position_Contr_f_T
  *localDW);
extern void MIL_Model_Position_Control_Kalm(const real_T *rtu_y, const real_T
  *rtu_r, const real_T *rtu_dist, real_T *rty_ek, real_T *rty_u_sat,
  B_MIL_Model_Position_Contro_c_T *localB, DW_MIL_Model_Position_Contr_f_T
  *localDW);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'MIL_Model_Position_Control_Kalman'
 * '<S1>'   : 'MIL_Model_Position_Control_Kalman/Controller'
 * '<S2>'   : 'MIL_Model_Position_Control_Kalman/Observer'
 * '<S3>'   : 'MIL_Model_Position_Control_Kalman/Controller/Controller'
 * '<S4>'   : 'MIL_Model_Position_Control_Kalman/Observer/White Noise4'
 */
#endif                     /* RTW_HEADER_MIL_Model_Position_Control_Kalman_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
