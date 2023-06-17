/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: MIL_Model_Position_Control_Kalman_private.h
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

#ifndef RTW_HEADER_MIL_Model_Position_Control_Kalman_private_h_
#define RTW_HEADER_MIL_Model_Position_Control_Kalman_private_h_
#include "rtwtypes.h"
#include "MIL_Model_Position_Control_Kalman.h"
#include "MIL_Model_Position_Control_Kalman_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm)  (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real_T rtCP_pooled_3QJflqQqJq62[9];

#define rtCP_DiscreteStateSpace_rtw_col rtCP_pooled_3QJflqQqJq62 /* Expression: Ad-L_tK*Cd
                                                                  * Referenced by: '<S2>/Discrete State-Space'
                                                                  */

extern P_MIL_Model_Position_Control__T MIL_Model_Position_Control_Ka_P;

#endif             /* RTW_HEADER_MIL_Model_Position_Control_Kalman_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
