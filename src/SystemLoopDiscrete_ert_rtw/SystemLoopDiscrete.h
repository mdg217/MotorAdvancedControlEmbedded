/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: SystemLoopDiscrete.h
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

#ifndef RTW_HEADER_SystemLoopDiscrete_h_
#define RTW_HEADER_SystemLoopDiscrete_h_
#ifndef SystemLoopDiscrete_COMMON_INCLUDES_
#define SystemLoopDiscrete_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "MW_MbedPinInterface.h"
#include "MW_digitalIO.h"
#include "MW_PWM.h"
#include "soc_stm_encoder.h"
#endif                                 /* SystemLoopDiscrete_COMMON_INCLUDES_ */

#include "SystemLoopDiscrete_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&(rtm)->Timing.taskTime0)
#endif

/* Block signals (default storage) */
typedef struct {
  real_T DiscreteStateSpace[3];        /* '<Root>/Discrete State-Space' */
  real_T ref;                          /* '<Root>/Constant2' */
  real_T Step1;                        /* '<Root>/Step1' */
  real_T ing;                          /* '<Root>/Sum' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T position;                     /* '<S2>/MATLAB Function3' */
  real_T last_ticks_star;              /* '<S2>/MATLAB Function2' */
  real_T u;                            /* '<Root>/Controller' */
  uint16_T HiddenRateTransitionForToWks_In;
  /* '<S2>/HiddenRateTransitionForToWks_InsertedFor_TAQSigLogging_InsertedFor_Qudrature Encoder_at_outport_0_at_inport_0' */
} B_SystemLoopDiscrete_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  soc_stm_QEP_SystemLoopDiscret_T obj; /* '<S2>/Qudrature Encoder' */
  mbed_DigitalWrite_SystemLoopD_T obj_e;/* '<S2>/EN_A' */
  mbed_PWMOutput_SystemLoopDisc_T obj_n;/* '<S2>/IN2B' */
  mbed_PWMOutput_SystemLoopDisc_T obj_g;/* '<S2>/IN2A' */
  real_T DiscreteStateSpace_DSTATE[3]; /* '<Root>/Discrete State-Space' */
  real_T Delay1_DSTATE;                /* '<S2>/Delay1' */
  real_T Delay2_DSTATE;                /* '<Root>/Delay2' */
  real_T Delay3_DSTATE;                /* '<Root>/Delay3' */
  real_T Delay1_DSTATE_l;              /* '<Root>/Delay1' */
  uint16_T Delay_DSTATE;               /* '<S2>/Delay' */
  uint8_T is_active_c7_SystemLoopDiscrete;/* '<S2>/MATLAB Function3' */
  uint8_T is_active_c4_SystemLoopDiscrete;/* '<S2>/MATLAB Function2' */
  uint8_T is_active_c3_SystemLoopDiscrete;/* '<S2>/MATLAB Function' */
  uint8_T is_active_c2_SystemLoopDiscrete;/* '<Root>/Controller' */
  boolean_T doneDoubleBufferReInit;    /* '<S2>/MATLAB Function3' */
  boolean_T doneDoubleBufferReInit_h;  /* '<S2>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_e;  /* '<S2>/MATLAB Function' */
  boolean_T doneDoubleBufferReInit_l;  /* '<Root>/Controller' */
} DW_SystemLoopDiscrete_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Expression: Ad-L*Cd
   * Referenced by: '<Root>/Discrete State-Space'
   */
  real_T DiscreteStateSpace_rtw_collapse[9];
} ConstP_SystemLoopDiscrete_T;

/* Parameters (default storage) */
struct P_SystemLoopDiscrete_T_ {
  real_T Ad[9];                        /* Variable: Ad
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  real_T Kp[3];                        /* Variable: Kp
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T Ts;                           /* Variable: Ts
                                        * Referenced by:
                                        *   '<S2>/Ts'
                                        *   '<S2>/Qudrature Encoder'
                                        */
  real_T ki;                           /* Variable: ki
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T DiscreteStateSpace_B[6];      /* Expression: [Bd L]
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_C[9];      /* Expression: eye(3)
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_D[6];      /* Expression: [ 0 0; 0 0; 0 0]
                                        * Referenced by: '<Root>/Discrete State-Space'
                                        */
  real_T DiscreteStateSpace_InitialCondi;/* Expression: 0
                                          * Referenced by: '<Root>/Discrete State-Space'
                                          */
  real_T Delay1_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<S2>/Delay1'
                                        */
  real_T Constant2_Value;              /* Expression: deg2rad(270)
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Delay2_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Delay2'
                                        */
  real_T Delay3_InitialCondition;      /* Expression: 0
                                        * Referenced by: '<Root>/Delay3'
                                        */
  real_T Delay1_InitialCondition_f;    /* Expression: 0
                                        * Referenced by: '<Root>/Delay1'
                                        */
  real_T Step1_Time;                   /* Expression: 3
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 1.2
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -12
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain_Gain;                    /* Expression: 100/12
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Saturation_UpperSat_a;        /* Expression: 100
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Saturation_LowerSat_h;        /* Expression: -100
                                        * Referenced by: '<S2>/Saturation'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S6>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S6>/Constant'
                                        */
  real_T enable_Value;                 /* Expression: 1
                                        * Referenced by: '<S2>/enable'
                                        */
  uint16_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S2>/Delay'
                                    */
};

/* Real-time Model Data Structure */
struct tag_RTM_SystemLoopDiscrete_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_SystemLoopDiscrete_T SystemLoopDiscrete_P;

/* Block signals (default storage) */
extern B_SystemLoopDiscrete_T SystemLoopDiscrete_B;

/* Block states (default storage) */
extern DW_SystemLoopDiscrete_T SystemLoopDiscrete_DW;

/* Constant parameters (default storage) */
extern const ConstP_SystemLoopDiscrete_T SystemLoopDiscrete_ConstP;

/* Model entry point functions */
extern void SystemLoopDiscrete_initialize(void);
extern void SystemLoopDiscrete_step(void);
extern void SystemLoopDiscrete_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SystemLoopDiscrete_T *const SystemLoopDiscrete_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'SystemLoopDiscrete'
 * '<S1>'   : 'SystemLoopDiscrete/Controller'
 * '<S2>'   : 'SystemLoopDiscrete/Real System1'
 * '<S3>'   : 'SystemLoopDiscrete/Real System1/MATLAB Function'
 * '<S4>'   : 'SystemLoopDiscrete/Real System1/MATLAB Function2'
 * '<S5>'   : 'SystemLoopDiscrete/Real System1/MATLAB Function3'
 * '<S6>'   : 'SystemLoopDiscrete/Real System1/Subsystem'
 */
#endif                                 /* RTW_HEADER_SystemLoopDiscrete_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
