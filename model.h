#ifndef __MODEL_H__
#define __MODEL_H__

struct Element
{
	char* type;
	float* inputs[2];
	float* output;
	char sum_signals[3];
};


struct Signal
{
	float value;
	int mark;

	

};

struct Input
{
	float* value;
	char name;
	int* mark;

};


float sp2AND(float sp1,float sp2);
float spNOT(float sp1);
float sp2OR(float sp1,float sp2);
float sp2XOR(float sp1,float sp2);
float sp2NAND(float sp1,float sp2);
float sp2NOR(float sp1,float sp2);
float sp2XNOR(float sp1,float sp2);






#endif