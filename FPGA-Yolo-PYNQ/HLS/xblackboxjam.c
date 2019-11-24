// ==============================================================
// File generated on Sat Nov 09 16:33:14 CST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xblackboxjam.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XBlackboxjam_CfgInitialize(XBlackboxjam *InstancePtr, XBlackboxjam_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XBlackboxjam_Start(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_AP_CTRL) & 0x80;
    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XBlackboxjam_IsDone(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XBlackboxjam_IsIdle(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XBlackboxjam_IsReady(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XBlackboxjam_EnableAutoRestart(XBlackboxjam *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XBlackboxjam_DisableAutoRestart(XBlackboxjam *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_AP_CTRL, 0);
}

void XBlackboxjam_Set_in1_V(XBlackboxjam *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IN1_V_DATA, (u32)(Data));
    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IN1_V_DATA + 4, (u32)(Data >> 32));
}

u64 XBlackboxjam_Get_in1_V(XBlackboxjam *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IN1_V_DATA);
    Data += (u64)XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IN1_V_DATA + 4) << 32;
    return Data;
}

void XBlackboxjam_Set_in2_V(XBlackboxjam *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IN2_V_DATA, (u32)(Data));
    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IN2_V_DATA + 4, (u32)(Data >> 32));
}

u64 XBlackboxjam_Get_in2_V(XBlackboxjam *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IN2_V_DATA);
    Data += (u64)XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IN2_V_DATA + 4) << 32;
    return Data;
}

void XBlackboxjam_Set_out_V(XBlackboxjam *InstancePtr, u64 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_OUT_V_DATA, (u32)(Data));
    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_OUT_V_DATA + 4, (u32)(Data >> 32));
}

u64 XBlackboxjam_Get_out_V(XBlackboxjam *InstancePtr) {
    u64 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_OUT_V_DATA);
    Data += (u64)XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_OUT_V_DATA + 4) << 32;
    return Data;
}

void XBlackboxjam_Set_doInit(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_DOINIT_DATA, Data);
}

u32 XBlackboxjam_Get_doInit(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_DOINIT_DATA);
    return Data;
}

void XBlackboxjam_Set_layerType(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_LAYERTYPE_DATA, Data);
}

u32 XBlackboxjam_Get_layerType(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_LAYERTYPE_DATA);
    return Data;
}

void XBlackboxjam_Set_KernelDim(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_KERNELDIM_DATA, Data);
}

u32 XBlackboxjam_Get_KernelDim(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_KERNELDIM_DATA);
    return Data;
}

void XBlackboxjam_Set_Stride(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_STRIDE_DATA, Data);
}

u32 XBlackboxjam_Get_Stride(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_STRIDE_DATA);
    return Data;
}

void XBlackboxjam_Set_IFMCh(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IFMCH_DATA, Data);
}

u32 XBlackboxjam_Get_IFMCh(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IFMCH_DATA);
    return Data;
}

void XBlackboxjam_Set_OFMCh(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_OFMCH_DATA, Data);
}

u32 XBlackboxjam_Get_OFMCh(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_OFMCH_DATA);
    return Data;
}

void XBlackboxjam_Set_IFMDim(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IFMDIM_DATA, Data);
}

u32 XBlackboxjam_Get_IFMDim(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IFMDIM_DATA);
    return Data;
}

void XBlackboxjam_Set_PaddedDim(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_PADDEDDIM_DATA, Data);
}

u32 XBlackboxjam_Get_PaddedDim(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_PADDEDDIM_DATA);
    return Data;
}

void XBlackboxjam_Set_OFMDim(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_OFMDIM_DATA, Data);
}

u32 XBlackboxjam_Get_OFMDim(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_OFMDIM_DATA);
    return Data;
}

void XBlackboxjam_Set_PoolInDim(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_POOLINDIM_DATA, Data);
}

u32 XBlackboxjam_Get_PoolInDim(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_POOLINDIM_DATA);
    return Data;
}

void XBlackboxjam_Set_PoolOutDim(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_POOLOUTDIM_DATA, Data);
}

u32 XBlackboxjam_Get_PoolOutDim(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_POOLOUTDIM_DATA);
    return Data;
}

void XBlackboxjam_Set_PoolStride(XBlackboxjam *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_POOLSTRIDE_DATA, Data);
}

u32 XBlackboxjam_Get_PoolStride(XBlackboxjam *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_POOLSTRIDE_DATA);
    return Data;
}

void XBlackboxjam_InterruptGlobalEnable(XBlackboxjam *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_GIE, 1);
}

void XBlackboxjam_InterruptGlobalDisable(XBlackboxjam *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_GIE, 0);
}

void XBlackboxjam_InterruptEnable(XBlackboxjam *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IER);
    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IER, Register | Mask);
}

void XBlackboxjam_InterruptDisable(XBlackboxjam *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IER);
    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IER, Register & (~Mask));
}

void XBlackboxjam_InterruptClear(XBlackboxjam *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XBlackboxjam_WriteReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_ISR, Mask);
}

u32 XBlackboxjam_InterruptGetEnabled(XBlackboxjam *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_IER);
}

u32 XBlackboxjam_InterruptGetStatus(XBlackboxjam *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XBlackboxjam_ReadReg(InstancePtr->Control_BaseAddress, XBLACKBOXJAM_CONTROL_ADDR_ISR);
}

