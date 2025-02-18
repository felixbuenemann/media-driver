/*
* Copyright (c) 2011-2019, Intel Corporation
*
* Permission is hereby granted, free of charge, to any person obtaining a
* copy of this software and associated documentation files (the "Software"),
* to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense,
* and/or sell copies of the Software, and to permit persons to whom the
* Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
* OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*/

//!
//! \file     mos_util_user_interface_g12.cpp
//! \brief    Common user feature interface on Gen12 platform
//!

#include "mos_utilities.h"
#include "mos_util_user_interface_g12.h"

MOS_USER_FEATURE_VALUE MOSUserFeatureValueDescFields_g12[MOS_NUM_USER_FEATURE_VALUES_G12] =
{
    MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_FORCE_VEBOX_ID_G12,
     "Force VEBOX",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "VP",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "0",
     "Force the VEBox to be used. (Default 0: FORCE_VEBOX_NONE "),
    MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_ENABLE_VEBOX_SCALABILITY_MODE_ID_G12,
     "Enable Vebox Scalability",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "VP",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0",
     "TRUE for Enabling Vebox Scalability. (Default FALSE: disabled"),
    MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_VEBOX_SPLIT_RATIO_ID_G12,
     "Vebox Split Ratio",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "VP",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "50",
     "Vebox Scalability Split Ratio. (Default 50: 50 percent"),
    /* codec gen11 based */
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HCP_DECODE_MODE_SWITCH_THRESHOLD1_ID_G12,
     "HCP Decode Mode Switch TH1",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Decode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "0",
     "Hcp Decode mode switch single pipe <-> 2 pipe"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HCP_DECODE_MODE_SWITCH_THRESHOLD2_ID_G12,
     "HCP Decode Mode Switch TH2",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Decode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "0",
     "Hcp Decode mode switch single pipe <-> 2/3 pipe"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_DISABLE_HEVC_REALTILE_DECODE_ID_G12,
     "Disable HEVC Real Tile Decode",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Decode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "0",
     "Disable HEVC real tile decode mode. Default is not disabled"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_ENABLE_HEVC_REALTILE_MULTI_PHASE_DECODE_ID_G12,
     "Enable HEVC Real Tile Multi Phase Decode",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Decode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "1",
     "Enable HEVC real tile multi-phase decode mode. Default is enabled"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_ENCODE_ENABLE_VE_DEBUG_OVERRIDE_G12,
     "Enable VE Debug Override",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT64,
     "0",
     "Enable VE Debug Override."),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VDENC_TILEREPLAY_ENABLE_ID_G12,
     "HEVC VDEnc TileReplay Enable",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Enable TileReplay for HEVC VDEnc"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VDENC_RGB_ENCODING_ENABLE_ID_G12,
     "HEVC VDEnc RGB Encoding Enable",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Enable RGB Encoding for HEVC VDEnc"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VDENC_CAPTURE_MODE_ENABLE_ID_G12,
     "HEVC VDEnc Capture Mode Enable",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Enable Capture Mode for HEVC VDEnc"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_ENCODE_ENABLE_HW_SEMAPHORE_G12,
     "Enable HW Semaphore",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "1",
     "Enable HW Semaphore."),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_ENCODE_ENABLE_VDBOX_HW_SEMAPHORE_G12,
     "Enable HEVC Per VDBOX HW Semaphore in GEN11",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "1",
     "Enable HEVC Per VDBOX HW Semaphore in GEN11."),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_ENCODE_ENABLE_HW_STITCH_G12,
     "HEVC Encode Enable HW Stitch",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "1",
     "HEVC Encode Enable HW Stitch."),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_ENCODE_SUBTHREAD_NUM_ID_G12,
     "HEVC Encode SubThread Number",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "3",
     "Used to enable HEVC ENCODE SubThread Number in the ENC kernel."),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_ENCODE_PAK_ONLY_ID_G12,
     "HEVC PAK Only Mode",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_STRING,
     "",
     "Set the PAK command/CU record folder name for HEVC encoder"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_ENCODE_LOAD_KERNEL_INPUT_ID_G12,
     "Load HEVC Kernel Input",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_STRING,
     "",
     "Set fodler name for HEVC encoder kernel input loading"), 
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VME_ENCODE_SSE_ENABLE_ID_G12,
     "HEVC Encode SSE Enable",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Used to enable HEVC VME ENCODE SSE.(default 0: disabled)"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_ENCODE_DISABLE_SCALABILITY_G12,
     "Disable Media Encode Scalability",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Disable Media Encode Scalability."),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_ENCODE_RDOQ_PERF_DISABLE_ID_G12,
     "Disable HEVC RDOQ Perf",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "1",
     "HEVC"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_WATCHDOG_TIMER_THRESHOLD_G12,
     "Watchdog Timer Threshold",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Decode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "120",
     "Used to override default watchdogtimer threshold"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_ENABLE_DECODE_VIRTUAL_ENGINE_ID_G12,
     "Enable Decode VE",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "1",
     "TRUE for Enabling Decode Virtual Engine. (Default TRUE: enabled"), 
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_ENABLE_DECODE_VE_CTXSCHEDULING_ID_G12,
     "Enable Decode VE CtxBasedScheduling",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0",
     "TRUE for Enabling Decode Virtual Engine context based scheduling. (Default false: disabled"), 
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_ENABLE_ENCODE_VIRTUAL_ENGINE_ID_G12,
     "Enable Encode VE",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "1",
     "TRUE for Enabling Encode Virtual Engine. (Default TRUE: enabled"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_ENABLE_ENCODE_VE_CTXSCHEDULING_ID_G12,
     "Enable Encode VE CtxBasedScheduling",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0",
     "TRUE for Enabling Encode Virtual Engine context based scheduling. (Default false: disabled"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_ENABLE_VE_DEBUG_OVERRIDE_ID_G12,
     "Enable VE Debug Override",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0",
     "TRUE for Enabling KMD Virtual Engine Debug Override. (Default FALSE: not override"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HCP_DECODE_ALWAYS_FRAME_SPLIT_ID_G12,
     "HCP Decode Always Frame Split",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0",
     "HCP Decode always does frame split instead of make decision based on LZ table. (Default 0: using LZ table "),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HCP_DECODE_USER_PIPE_NUM_ID_G12,
        "HCP Decode User Pipe Num",
        __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
        __MEDIA_USER_FEATURE_SUBKEY_REPORT,
        "Codec",
        MOS_USER_FEATURE_TYPE_USER,
        MOS_USER_FEATURE_VALUE_TYPE_UINT32,
        "2",
        "When vdbox >= 4, pipe num equals to the value set by user. (Default 2: use 2 pipes "), //This is WA for scalability when vdbox num >= 4 because of kmd not ready
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_SCALABILITY_OVERRIDE_SPLIT_WIDTH_IN_MINCB_G12,
        "Scalability Split Width In MinCb",
        __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
        __MEDIA_USER_FEATURE_SUBKEY_REPORT,
        "Codec",
        MOS_USER_FEATURE_TYPE_USER,
        MOS_USER_FEATURE_VALUE_TYPE_UINT32,
        "0",
        "Override virtual tile scalability width. (Default 0: not overroded "),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_SCALABILITY_FE_SEPARATE_SUBMISSION_ENABLED_ID_G12,
     "FE Separate Submission Enabled",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0", //Disable FE separate submission by default. Will change it to "Enable" after proving it has performance enhancement.
     "Enable FE separate submission in Scalability decode. (Default 0: Disable FE separate submission "),
    MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_SCALABILITY_FE_SEPARATE_SUBMISSION_IN_USE_ID_G12,
     "FE Separate Submission In Use",
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Report",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "0",
     "Report FE separate submission is in use in Scalability decode. (Default 0: Disable FE separate submission "),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VME_BRC_LTR_ENABLE_ID_G12,
     "HEVC VME BRC LTR Enable",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0", 
     "Enable long term reference in hevc vme brc. (Default 0: Disable"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VME_BRC_LTR_INTERVAL_ID_G12,
     "HEVC VME BRC LTR Interval",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0", 
     "HEVC Vme encode BRC Long term reference interval. (Default 0: interval=0"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VME_FORCE_SCALABILITY_ID_G12,
     "HEVC VME Force Scalability For Low Size",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0", 
     "HEVC Vme encode force scalability for low (< 4K) resolution. (Default 0"),    
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VDENC_FORCE_SCALABILITY_ID_G12,
     "HEVC VDEnc Force Scalability For Low Size",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Codec",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_BOOL,
     "0",
     "HEVC VDEnc encode force scalability for low (< 4K) resolution. (Default 0"),
    /* codec gen12 based */
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_VDENC_ULTRA_MODE_ENABLE_ID_G12,
     "VDEnc Ultra Mode Enable",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Encode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "0",
     "Enables/Disables VDEnc Ultra Mode feature. Starting from TGL for AVC VDEnc."),
     MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_ENABLE_HEVC_DECODE_RT_FRAME_COUNT_ID_G12,
     "RT Decoded Count",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Report",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Reports out real tile decoded frame count."),
     MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_ENABLE_HEVC_DECODE_VT_FRAME_COUNT_ID_G12,
     "VT Decoded Count",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Report",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Reports out virtual tile decoded frame count."),
     MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_ENABLE_HEVC_DECODE_SP_FRAME_COUNT_ID_G12,
     "SP Decoded Count",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Report",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Reports out single pipe decoded frame count."),
     MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_HEVC_DECODE_HISTOGRAM_DEBUG_ID_G12,
     "HEVC SFC Histogram Debug",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "Decode",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Enable HEVC SFC Histogram StreamOut debug. 0:Disable, 1:Enable"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VME_DISABLE_PANIC_MODE_ID_G12,
        "HEVC VME Disable Panic Mode",
        __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
        __MEDIA_USER_FEATURE_SUBKEY_REPORT,
        "Codec",
        MOS_USER_FEATURE_TYPE_USER,
        MOS_USER_FEATURE_VALUE_TYPE_BOOL,
        "0",
        "HEVC Vme encode disable panic mode. (Default 0"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VME_NUM_MEDIA_HWWALKER_INUSE_ID_G12,
        "HEVC VME Media HW Walker Number In Use",
        __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
        __MEDIA_USER_FEATURE_SUBKEY_REPORT,
        "Codec",
        MOS_USER_FEATURE_TYPE_USER,
        MOS_USER_FEATURE_VALUE_TYPE_INT32,
        "1",
        "HEVC Vme encode media hw walker number in use. (Default 1"),
    MOS_DECLARE_UF_KEY_DBGONLY(__MEDIA_USER_FEATURE_VALUE_HEVC_VME_BREAK12_ID_G12,
        "HEVC VME Break12",
        __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
        __MEDIA_USER_FEATURE_SUBKEY_REPORT,
        "Encode",
        MOS_USER_FEATURE_TYPE_USER,
        MOS_USER_FEATURE_VALUE_TYPE_INT32,
        "1",
        "HEVC Vme encode break12 setting:[0, 3]. (Default 1"),        
    /* VP gen12 based */
    MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_SFC_OUTPUT_CENTERING_DISABLE_ID_G12,
     "SFC Output Centering Disable",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "VP",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_INT32,
     "0",
     "Disabling SFC Centering output. 1: Disable, 0: Enable."),
     MOS_DECLARE_UF_KEY(__MEDIA_USER_FEATURE_VALUE_SFC_OUTPUT_DTR_DISABLE_ID_G12,
     "Disable SFC DTR",
     __MEDIA_USER_FEATURE_SUBKEY_INTERNAL,
     __MEDIA_USER_FEATURE_SUBKEY_REPORT,
     "VP",
     MOS_USER_FEATURE_TYPE_USER,
     MOS_USER_FEATURE_VALUE_TYPE_UINT32,
     "1",
     "Disabling SFC DTR output. 1: Disable, 0: Enable."),
};

MosUtilUserInterface_g12::MosUtilUserInterface_g12()
{

    MOS_STATUS eStatus = MOS_DeclareUserFeatureKeysFromDescFields(
        MOSUserFeatureValueDescFields_g12,
        MOS_NUM_USER_FEATURE_VALUES_G12,
        __MOS_USER_FEATURE_KEY_G12_MAX_ID,
        nullptr);

    m_defaultValueChanged = true;

    if (MOS_FAILED(eStatus))
    {
        MOS_OS_ASSERTMESSAGE("MOS util G12 user feature key init error");
    }

}

MosUtilUserInterface_g12::~MosUtilUserInterface_g12()
{

    MOS_STATUS eStatus = MOS_DestroyUserFeatureKeysFromDescFields(
        MOSUserFeatureValueDescFields_g12,
        MOS_NUM_USER_FEATURE_VALUES_G12,
        __MOS_USER_FEATURE_KEY_G12_MAX_ID,
        nullptr);

    if (MOS_FAILED(eStatus))
    {
        MOS_OS_ASSERTMESSAGE("MOS util G12 user feature key destroy error");
    }

}


