/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SystemLoopDiscrete_types.h
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

#ifndef RTW_HEADER_SystemLoopDiscrete_types_h_
#define RTW_HEADER_SystemLoopDiscrete_types_h_
#include "rtwtypes.h"
#include "MW_SVD.h"

/* Custom Type definition for MATLABSystem: '<S2>/IN2B' */
#include "MW_SVD.h"
#ifndef struct_tag_KxFW01GBdhqk5JOEHU3GlD
#define struct_tag_KxFW01GBdhqk5JOEHU3GlD

struct tag_KxFW01GBdhqk5JOEHU3GlD
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_DIGITALIO_HANDLE;
};

#endif                                 /* struct_tag_KxFW01GBdhqk5JOEHU3GlD */

#ifndef typedef_mbed_DigitalWrite_SystemLoopD_T
#define typedef_mbed_DigitalWrite_SystemLoopD_T

typedef struct tag_KxFW01GBdhqk5JOEHU3GlD mbed_DigitalWrite_SystemLoopD_T;

#endif                             /* typedef_mbed_DigitalWrite_SystemLoopD_T */

#ifndef struct_tag_UndvUYqhBVOhRRpUse3fWF
#define struct_tag_UndvUYqhBVOhRRpUse3fWF

struct tag_UndvUYqhBVOhRRpUse3fWF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_UndvUYqhBVOhRRpUse3fWF */

#ifndef typedef_mbed_PWMOutput_SystemLoopDisc_T
#define typedef_mbed_PWMOutput_SystemLoopDisc_T

typedef struct tag_UndvUYqhBVOhRRpUse3fWF mbed_PWMOutput_SystemLoopDisc_T;

#endif                             /* typedef_mbed_PWMOutput_SystemLoopDisc_T */

#ifndef struct_tag_sGWFgQTjADKFs5f99dqloH
#define struct_tag_sGWFgQTjADKFs5f99dqloH

struct tag_sGWFgQTjADKFs5f99dqloH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T SampleTime;
};

#endif                                 /* struct_tag_sGWFgQTjADKFs5f99dqloH */

#ifndef typedef_soc_stm_QEP_SystemLoopDiscret_T
#define typedef_soc_stm_QEP_SystemLoopDiscret_T

typedef struct tag_sGWFgQTjADKFs5f99dqloH soc_stm_QEP_SystemLoopDiscret_T;

#endif                             /* typedef_soc_stm_QEP_SystemLoopDiscret_T */

/* Parameters (default storage) */
typedef struct P_SystemLoopDiscrete_T_ P_SystemLoopDiscrete_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_SystemLoopDiscrete_T RT_MODEL_SystemLoopDiscrete_T;

#endif                              /* RTW_HEADER_SystemLoopDiscrete_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
