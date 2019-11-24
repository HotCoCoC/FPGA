// ==============================================================
// File generated on Sat Nov 09 16:33:14 CST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XBLACKBOXJAM_H
#define XBLACKBOXJAM_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xblackboxjam_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XBlackboxjam_Config;
#endif

typedef struct {
    u32 Control_BaseAddress;
    u32 IsReady;
} XBlackboxjam;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XBlackboxjam_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XBlackboxjam_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XBlackboxjam_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XBlackboxjam_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XBlackboxjam_Initialize(XBlackboxjam *InstancePtr, u16 DeviceId);
XBlackboxjam_Config* XBlackboxjam_LookupConfig(u16 DeviceId);
int XBlackboxjam_CfgInitialize(XBlackboxjam *InstancePtr, XBlackboxjam_Config *ConfigPtr);
#else
int XBlackboxjam_Initialize(XBlackboxjam *InstancePtr, const char* InstanceName);
int XBlackboxjam_Release(XBlackboxjam *InstancePtr);
#endif

void XBlackboxjam_Start(XBlackboxjam *InstancePtr);
u32 XBlackboxjam_IsDone(XBlackboxjam *InstancePtr);
u32 XBlackboxjam_IsIdle(XBlackboxjam *InstancePtr);
u32 XBlackboxjam_IsReady(XBlackboxjam *InstancePtr);
void XBlackboxjam_EnableAutoRestart(XBlackboxjam *InstancePtr);
void XBlackboxjam_DisableAutoRestart(XBlackboxjam *InstancePtr);

void XBlackboxjam_Set_in1_V(XBlackboxjam *InstancePtr, u64 Data);
u64 XBlackboxjam_Get_in1_V(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_in2_V(XBlackboxjam *InstancePtr, u64 Data);
u64 XBlackboxjam_Get_in2_V(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_out_V(XBlackboxjam *InstancePtr, u64 Data);
u64 XBlackboxjam_Get_out_V(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_doInit(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_doInit(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_layerType(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_layerType(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_KernelDim(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_KernelDim(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_Stride(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_Stride(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_IFMCh(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_IFMCh(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_OFMCh(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_OFMCh(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_IFMDim(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_IFMDim(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_PaddedDim(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_PaddedDim(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_OFMDim(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_OFMDim(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_PoolInDim(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_PoolInDim(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_PoolOutDim(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_PoolOutDim(XBlackboxjam *InstancePtr);
void XBlackboxjam_Set_PoolStride(XBlackboxjam *InstancePtr, u32 Data);
u32 XBlackboxjam_Get_PoolStride(XBlackboxjam *InstancePtr);

void XBlackboxjam_InterruptGlobalEnable(XBlackboxjam *InstancePtr);
void XBlackboxjam_InterruptGlobalDisable(XBlackboxjam *InstancePtr);
void XBlackboxjam_InterruptEnable(XBlackboxjam *InstancePtr, u32 Mask);
void XBlackboxjam_InterruptDisable(XBlackboxjam *InstancePtr, u32 Mask);
void XBlackboxjam_InterruptClear(XBlackboxjam *InstancePtr, u32 Mask);
u32 XBlackboxjam_InterruptGetEnabled(XBlackboxjam *InstancePtr);
u32 XBlackboxjam_InterruptGetStatus(XBlackboxjam *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
