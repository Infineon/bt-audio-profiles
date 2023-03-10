/*
 * Copyright 2016-2023, Cypress Semiconductor Corporation (an Infineon company)
 * SPDX-License-Identifier: Apache-2.0
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/** @file
 *
 * This file has the encoder function declaration.
 */


#ifndef SBC_FUNCDECLARE_H
#define SBC_FUNCDECLARE_H

#include "sbc_encoder.h"
/* Global data
*/
#if (IS_64_MULT_IN_WINDOW_ACCU == FALSE)
extern const SINT16 gas32CoeffFor4SBs[];
extern const SINT16 gas32CoeffFor8SBs[];
#else
extern const SINT32 gas32CoeffFor4SBs[];
extern const SINT32 gas32CoeffFor8SBs[];
#endif

/* Global functions*/

extern void sbc_enc_bit_alloc_mono(SBC_ENC_PARAMS *CodecParams);
extern void sbc_enc_bit_alloc_ste(SBC_ENC_PARAMS *CodecParams);

extern void SbcAnalysisInit (void);

extern void SbcAnalysisFilter4(SBC_ENC_PARAMS *strEncParams);
extern void SbcAnalysisFilter8(SBC_ENC_PARAMS *strEncParams);

extern void SBC_FastIDCT8 (SINT32 *pInVect, SINT32 *pOutVect);
extern void SBC_FastIDCT4 (SINT32 *x0, SINT32 *pOutVect);

extern void EncPacking(SBC_ENC_PARAMS *strEncParams);
extern void EncQuantizer(SBC_ENC_PARAMS *);
#if (SBC_C5402_OPT==TRUE)
    void SBC_Multiply_32_16_Simplified(SINT32 s32In2Temp,SINT32 s32In1Temp ,SINT32 *s32OutLow);
#endif
#endif

