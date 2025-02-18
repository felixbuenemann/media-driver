/*
* Copyright (c) 2017-2019, Intel Corporation
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
//! \file     codechal_mmc_decode_avc_g12.cpp
//! \brief    Impelements the public interface for CodecHal Media Memory Compression
//!

#include "codechal_mmc_decode_avc_g12.h"
#include "mos_util_user_interface_g12.h"

CodechalMmcDecodeAvcG12::CodechalMmcDecodeAvcG12(
    CodechalHwInterface    *hwInterface,
    void *standardState):
    CodecHalMmcStateG12(hwInterface)
{
    CODECHAL_DECODE_FUNCTION_ENTER;

    m_avcState = (CodechalDecodeAvc*)standardState;
    CODECHAL_HW_ASSERT(m_avcState);

    InitDecodeMmcEnable(hwInterface);

    m_mmcExtensionEnabled = true;
}

MOS_STATUS CodechalMmcDecodeAvcG12::SetPipeBufAddr(
    PMHW_VDBOX_PIPE_BUF_ADDR_PARAMS pipeBufAddrParams,
    PMOS_COMMAND_BUFFER cmdBuffer)
{
    MOS_STATUS eStatus = MOS_STATUS_SUCCESS;

    CODECHAL_DECODE_FUNCTION_ENTER;

    if (m_mmcEnabled)
    {
        MOS_MEMCOMP_STATE  mmcState = MOS_MEMCOMP_DISABLED;

        CODECHAL_DECODE_CHK_NULL_RETURN(m_avcState);
        CODECHAL_DECODE_CHK_NULL_RETURN(m_avcState->m_avcPicParams);

        CODECHAL_DECODE_CHK_STATUS_RETURN(m_osInterface->pfnGetMemoryCompressionMode(m_osInterface,
            &m_avcState->m_destSurface.OsResource,
            &mmcState));
        if (m_avcState->m_deblockingEnabled)
            pipeBufAddrParams->PostDeblockSurfMmcState = mmcState;
        else
            pipeBufAddrParams->PreDeblockSurfMmcState = mmcState;
    }
    else
    {
        pipeBufAddrParams->PreDeblockSurfMmcState = MOS_MEMCOMP_DISABLED;
        pipeBufAddrParams->PostDeblockSurfMmcState = MOS_MEMCOMP_DISABLED;
    }

    CODECHAL_DEBUG_TOOL(
        m_avcState->m_destSurface.MmcState = m_avcState->m_deblockingEnabled ? pipeBufAddrParams->PostDeblockSurfMmcState : pipeBufAddrParams->PreDeblockSurfMmcState;)

    CODECHAL_DEBUG_TOOL(
        m_avcState->m_destSurface.MmcState = m_avcState->m_deblockingEnabled ? pipeBufAddrParams->PostDeblockSurfMmcState : pipeBufAddrParams->PreDeblockSurfMmcState;)

    return eStatus;
}
