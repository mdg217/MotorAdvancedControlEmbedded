/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SystemLoopDiscrete_data.c
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

/* Block parameters (default storage) */
P_SystemLoopDiscrete_T SystemLoopDiscrete_P = {
  /* Variable: Ad
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0047878917573229117, 0.89820774936626513,
    -0.15940644240891591, 0.00082621593672226523, 0.22154793690730704,
    0.016035295527858984 },

  /* Variable: Kp
   * Referenced by: '<Root>/Constant'
   */
  { 2.7369003747593719, 0.092482915828312445, 0.023120342185605262 },

  /* Variable: Ts
   * Referenced by:
   *   '<S2>/Ts'
   *   '<S2>/Qudrature Encoder'
   */
  0.005,

  /* Variable: ki
   * Referenced by: '<Root>/Constant1'
   */
  0.031620948744377916,

  /* Expression: [Bd L]
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 0.0002031330115231402, 0.10075804106369085, 0.18268501368951098,
    0.61811125042397108, 0.0084541663792374946, -0.0016016482972191497 },

  /* Expression: eye(3)
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0 },

  /* Expression: [ 0 0; 0 0; 0 0]
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  /* Expression: 0
   * Referenced by: '<Root>/Discrete State-Space'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S2>/Delay1'
   */
  0.0,

  /* Expression: deg2rad(270)
   * Referenced by: '<Root>/Constant2'
   */
  4.71238898038469,

  /* Expression: 0
   * Referenced by: '<Root>/Delay2'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay3'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<Root>/Delay1'
   */
  0.0,

  /* Expression: 3
   * Referenced by: '<Root>/Step1'
   */
  3.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step1'
   */
  0.0,

  /* Expression: 1.2
   * Referenced by: '<Root>/Step1'
   */
  1.2,

  /* Expression: 12
   * Referenced by: '<Root>/Saturation'
   */
  12.0,

  /* Expression: -12
   * Referenced by: '<Root>/Saturation'
   */
  -12.0,

  /* Expression: 100/12
   * Referenced by: '<S2>/Gain'
   */
  8.3333333333333339,

  /* Expression: 100
   * Referenced by: '<S2>/Saturation'
   */
  100.0,

  /* Expression: -100
   * Referenced by: '<S2>/Saturation'
   */
  -100.0,

  /* Expression: 1
   * Referenced by: '<S6>/Constant1'
   */
  1.0,

  /* Expression: 2
   * Referenced by: '<S6>/Constant'
   */
  2.0,

  /* Expression: 1
   * Referenced by: '<S2>/enable'
   */
  1.0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S2>/Delay'
   */
  0U
};

/* Constant parameters (default storage) */
const ConstP_SystemLoopDiscrete_T SystemLoopDiscrete_ConstP = {
  /* Expression: Ad-L*Cd
   * Referenced by: '<Root>/Discrete State-Space'
   */
  { 0.61811125042397108, 0.0084541663792374946, -0.0016016482972191497, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0 }
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
