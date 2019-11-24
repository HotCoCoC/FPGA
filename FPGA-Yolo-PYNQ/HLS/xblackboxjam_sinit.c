// ==============================================================
// File generated on Sat Nov 09 16:33:14 CST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xblackboxjam.h"

extern XBlackboxjam_Config XBlackboxjam_ConfigTable[];

XBlackboxjam_Config *XBlackboxjam_LookupConfig(u16 DeviceId) {
	XBlackboxjam_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XBLACKBOXJAM_NUM_INSTANCES; Index++) {
		if (XBlackboxjam_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XBlackboxjam_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XBlackboxjam_Initialize(XBlackboxjam *InstancePtr, u16 DeviceId) {
	XBlackboxjam_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XBlackboxjam_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XBlackboxjam_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

