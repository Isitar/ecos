#pragma once
#include <stdio.h>
#include <time.h> 

#include "ecos.h"
#include <ecos_bb.h>
#include "result.h"

idxint ilp_BELL5(const idxint);
idxint ilp_FLUGPL(const idxint);
idxint ilp_gen_ip054(const idxint);
idxint ilp_LPA_ILP(const idxint);
result* ilp_markshare_4_0(enum BRANCHING_STRATEGY, idxint);
idxint ilp_noswot(const idxint);
idxint ilp_Prob1(const idxint);
idxint lp_AFIRO(const idxint);
idxint lp_LPA(const idxint);
idxint lp_LPA2(const idxint);
idxint lp_Prob1(const idxint);



