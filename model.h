#ifndef __MODEL_H__
#define __MODEL_H__

struct Element
{
	char* type;
	float* inputs[2];
	float* output;
};


struct Signal
{
	float value;
};


extern struct Element ELementsTable[];
extern struct Signal SignalsTable[];
void GivenInputs();
void circuit();
float sp2AND(float sp1,float sp2);
float spNOT(float sp1);





#endif