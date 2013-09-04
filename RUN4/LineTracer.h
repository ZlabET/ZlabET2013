#if !defined(EA_A4BD4D1A_E40A_4143_A4C5_AC9B36316301__INCLUDED_)
#define EA_A4BD4D1A_E40A_4143_A4C5_AC9B36316301__INCLUDED_


#include "ColorJudgement.h"
#include "BalanceRunner.h"


//‘®«‚ğ•Û‚·‚é‚½‚ß‚Ì\‘¢‘Ì‚Ì’è‹`
typedef struct LineTracer
{
    ColorJudgement *colorJudgement;
    BalanceRunner *balanceRunner;
} LineTracer;

//ŒöŠJ‘€ì
void LineTracer_init(LineTracer* this);
void LineTracer_trace(LineTracer* this);

#endif /*!defined(EA_A4BD4D1A_E40A_4143_A4C5_AC9B36316301__INCLUDED_)*/
