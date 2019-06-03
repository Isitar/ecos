#pragma once
#include <stdio.h>
#include <time.h> 

#include "ecos.h"
#include <ecos_bb.h>
#include "result.h"



result* ilp_BELL5(settings_bb* settings);
result* ilp_FLUGPL(enum BRANCHING_STRATEGY, idxint);
result* ilp_gen_ip054(settings_bb* settings);
idxint ilp_LPA_ILP(const idxint);
result* ilp_markshare_4_0(settings_bb* settings);
idxint ilp_noswot(const idxint);
idxint ilp_Prob1(const idxint);
idxint lp_AFIRO(const idxint);
idxint lp_LPA(const idxint);
idxint lp_LPA2(const idxint);
idxint lp_Prob1(const idxint);
result* ilp_qiu(enum BRANCHING_STRATEGY, idxint);
result* ilp_PP08ACUTS(settings_bb* settings);
result* ilp_issue_166(settings_bb* settings);
result* ilp_ILPHS18(enum BRANCHING_STRATEGY, idxint);
result* ilp_VPM2(enum BRANCHING_STRATEGY, idxint);
result* ilp_misc07(enum BRANCHING_STRATEGY, idxint);
