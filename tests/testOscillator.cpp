#include <stdio.h>
#include "Oscillator.h"
#include "gen.h"
#include "scl.h"

#define DO(fnc)\
printf("\n%s:\n", #fnc);\
for(int i=0; i<n; ++i){\
	float v = fnc; \
	printf("\t% 6.3f ", v); scl::printPlot(v, 32); printf("\n");\
}

using namespace gam;

int main(int argc, char* argv[]){
	
	const int n = 16;
	Sync::master().spu(n);
	
	Accum<> accum(1);
	AccumPhase<> accumPhase(1);
	Impulse<> impulse(1.);
	LFO<> lfo(1, 0, 0.25);
	Osc<> osc(1); osc << tup(1,1,0);
	Quadra<> quadra(1);
	Saw<> saw(1);
	Sine<> sine(1);
	SineD<> sineD(1,1,2,0.25);
	SineDs<> sineDs(4); for(int i=0; i<sineDs.size(); ++i) sineDs.set(i, i+1, 1./(i+1), 2.);
	SineR<> sineR(1);
	SineRs<> sineRs(4); for(int i=0; i<sineRs.size(); ++i) sineRs.set(i, i+1, 1./(i+1));
	Square<> square(1);
	TableSine<> tableSine(1);
	
	DO(accum.phase(); accum())
	DO(accumPhase.nextPhase()/M_PI)
	DO(impulse())
	DO(impulse.odd())
	DO(lfo.cos())
	DO(lfo.down())
	DO(lfo.even3())
	DO(lfo.even5())
	DO(lfo.line2(); lfo.mod(0.00))
	DO(lfo.line2(); lfo.mod(0.25))
	DO(lfo.line2(); lfo.mod(0.50))
	DO(lfo.line2(); lfo.mod(0.75))
	DO(lfo.line2(); lfo.mod(0.99999))
	//printf("%x\n", lfo.modi);
//	DO(lfo.stair())
//	DO(lfo.sqr())
//	DO(lfo.tri())
//	DO(lfo.up())
//	DO(osc())
//	DO(quadra()[1])
//	DO(saw())
//	DO(sine())
//	DO(sineD())
//	DO(sineDs())
//	DO(sineR())
//	DO(sineRs())
//	DO(square())
//	DO(tableSine())
	
	
	//sine.phase(0.25);		DO(sine())
	//sine.set(0.5, 0.25);	DO(sine())
	
	//SineAM<> sineAM(0., 1., 0.25, 0.25);
	//DO(sineAM())

	//SineRes<double, Synced1> sineRes(1./n);
	
//
//	gen::RSin<> rsin(1./n);	DO(rsin())

	return 0;
}

