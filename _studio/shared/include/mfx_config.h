// Copyright (c) 2017-2018 Intel Corporation
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#ifndef _MFX_CONFIG_H_
#define _MFX_CONFIG_H_

#include "mfxdefs.h"

#define CMAPIUPDATE
#define MFX_ENABLE_VPP_COMPOSITION
//#define MFX_ENABLE_VPP_FRC
#define MFX_ENABLE_VPP_ROTATION
#define MFX_ENABLE_VPP_VIDEO_SIGNAL




    #if defined(LINUX32) || defined(LINUX64)
        #undef  MFX_VA_LINUX
        #define MFX_VA_LINUX


    #endif // #if defined(LINUX32) || defined(LINUX64)

#if defined(AS_HEVCD_PLUGIN) || defined(AS_HEVCE_PLUGIN)
    #if defined(HEVCE_EVALUATION)
        #define MFX_MAX_ENCODE_FRAMES 1000
    #endif
    #if defined(HEVCD_EVALUATION)
        #define MFX_MAX_DECODE_FRAMES 1000
    #endif
#endif

#if !defined(LINUX_TARGET_PLATFORM)
    #if defined(ANDROID)
        #include "mfx_android_defs.h"
    #endif // #if defined(ANDROID)
#else // LINUX_TARGET_PLATFORM
    #if defined(LINUX_TARGET_PLATFORM_CFL)      // PRE_SI_GEN == 9
        #include "mfx_common_linux_cfl.h"
    #elif defined(LINUX_TARGET_PLATFORM_BXTMIN) // PRE_SI_GEN == 9
        #include "mfx_common_linux_bxtmin.h"
    #elif defined(LINUX_TARGET_PLATFORM_BXT)    // PRE_SI_GEN == 9
        #include "mfx_common_linux_bxt.h"
    #elif defined(LINUX_TARGET_PLATFORM_BDW)    // PRE_SI_GEN == 9
        #include "mfx_common_linux_bdw.h"
    #else
        #error "Target platform should be specified!"
    #endif
#endif // LINUX_TARGET_PLATFORM






#define MFX_ENABLE_HEVCE_INTERLACE


#endif // _MFX_CONFIG_H_
