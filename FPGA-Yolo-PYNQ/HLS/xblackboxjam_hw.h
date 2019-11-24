// ==============================================================
// File generated on Sat Nov 09 16:33:14 CST 2019
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// control
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of in1_V
//        bit 31~0 - in1_V[31:0] (Read/Write)
// 0x14 : Data signal of in1_V
//        bit 31~0 - in1_V[63:32] (Read/Write)
// 0x18 : reserved
// 0x1c : Data signal of in2_V
//        bit 31~0 - in2_V[31:0] (Read/Write)
// 0x20 : Data signal of in2_V
//        bit 31~0 - in2_V[63:32] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of out_V
//        bit 31~0 - out_V[31:0] (Read/Write)
// 0x2c : Data signal of out_V
//        bit 31~0 - out_V[63:32] (Read/Write)
// 0x30 : reserved
// 0x34 : Data signal of doInit
//        bit 0  - doInit[0] (Read/Write)
//        others - reserved
// 0x38 : reserved
// 0x3c : Data signal of layerType
//        bit 31~0 - layerType[31:0] (Read/Write)
// 0x40 : reserved
// 0x44 : Data signal of KernelDim
//        bit 31~0 - KernelDim[31:0] (Read/Write)
// 0x48 : reserved
// 0x4c : Data signal of Stride
//        bit 31~0 - Stride[31:0] (Read/Write)
// 0x50 : reserved
// 0x54 : Data signal of IFMCh
//        bit 31~0 - IFMCh[31:0] (Read/Write)
// 0x58 : reserved
// 0x5c : Data signal of OFMCh
//        bit 31~0 - OFMCh[31:0] (Read/Write)
// 0x60 : reserved
// 0x64 : Data signal of IFMDim
//        bit 31~0 - IFMDim[31:0] (Read/Write)
// 0x68 : reserved
// 0x6c : Data signal of PaddedDim
//        bit 31~0 - PaddedDim[31:0] (Read/Write)
// 0x70 : reserved
// 0x74 : Data signal of OFMDim
//        bit 31~0 - OFMDim[31:0] (Read/Write)
// 0x78 : reserved
// 0x7c : Data signal of PoolInDim
//        bit 31~0 - PoolInDim[31:0] (Read/Write)
// 0x80 : reserved
// 0x84 : Data signal of PoolOutDim
//        bit 31~0 - PoolOutDim[31:0] (Read/Write)
// 0x88 : reserved
// 0x8c : Data signal of PoolStride
//        bit 31~0 - PoolStride[31:0] (Read/Write)
// 0x90 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XBLACKBOXJAM_CONTROL_ADDR_AP_CTRL         0x00
#define XBLACKBOXJAM_CONTROL_ADDR_GIE             0x04
#define XBLACKBOXJAM_CONTROL_ADDR_IER             0x08
#define XBLACKBOXJAM_CONTROL_ADDR_ISR             0x0c
#define XBLACKBOXJAM_CONTROL_ADDR_IN1_V_DATA      0x10
#define XBLACKBOXJAM_CONTROL_BITS_IN1_V_DATA      64
#define XBLACKBOXJAM_CONTROL_ADDR_IN2_V_DATA      0x1c
#define XBLACKBOXJAM_CONTROL_BITS_IN2_V_DATA      64
#define XBLACKBOXJAM_CONTROL_ADDR_OUT_V_DATA      0x28
#define XBLACKBOXJAM_CONTROL_BITS_OUT_V_DATA      64
#define XBLACKBOXJAM_CONTROL_ADDR_DOINIT_DATA     0x34
#define XBLACKBOXJAM_CONTROL_BITS_DOINIT_DATA     1
#define XBLACKBOXJAM_CONTROL_ADDR_LAYERTYPE_DATA  0x3c
#define XBLACKBOXJAM_CONTROL_BITS_LAYERTYPE_DATA  32
#define XBLACKBOXJAM_CONTROL_ADDR_KERNELDIM_DATA  0x44
#define XBLACKBOXJAM_CONTROL_BITS_KERNELDIM_DATA  32
#define XBLACKBOXJAM_CONTROL_ADDR_STRIDE_DATA     0x4c
#define XBLACKBOXJAM_CONTROL_BITS_STRIDE_DATA     32
#define XBLACKBOXJAM_CONTROL_ADDR_IFMCH_DATA      0x54
#define XBLACKBOXJAM_CONTROL_BITS_IFMCH_DATA      32
#define XBLACKBOXJAM_CONTROL_ADDR_OFMCH_DATA      0x5c
#define XBLACKBOXJAM_CONTROL_BITS_OFMCH_DATA      32
#define XBLACKBOXJAM_CONTROL_ADDR_IFMDIM_DATA     0x64
#define XBLACKBOXJAM_CONTROL_BITS_IFMDIM_DATA     32
#define XBLACKBOXJAM_CONTROL_ADDR_PADDEDDIM_DATA  0x6c
#define XBLACKBOXJAM_CONTROL_BITS_PADDEDDIM_DATA  32
#define XBLACKBOXJAM_CONTROL_ADDR_OFMDIM_DATA     0x74
#define XBLACKBOXJAM_CONTROL_BITS_OFMDIM_DATA     32
#define XBLACKBOXJAM_CONTROL_ADDR_POOLINDIM_DATA  0x7c
#define XBLACKBOXJAM_CONTROL_BITS_POOLINDIM_DATA  32
#define XBLACKBOXJAM_CONTROL_ADDR_POOLOUTDIM_DATA 0x84
#define XBLACKBOXJAM_CONTROL_BITS_POOLOUTDIM_DATA 32
#define XBLACKBOXJAM_CONTROL_ADDR_POOLSTRIDE_DATA 0x8c
#define XBLACKBOXJAM_CONTROL_BITS_POOLSTRIDE_DATA 32

