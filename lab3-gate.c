#include <string.h>
#include "model.h"



float sp2AND(float sp1,float sp2);
float spNOT(float sp1);
float sp2OR(float sp1,float sp2);
float sp2XOR(float sp1,float sp2);
float sp2NAND(float sp1,float sp2);
float sp2NOR(float sp1,float sp2);
float sp2XNOR(float sp1,float sp2);





float sp2AND(float sp1,float sp2){

	return sp1*sp2;

}

float spNOT(float sp1){

	return 1-sp1;
}

float sp2NAND(float sp1,float sp2){

	return 1 - sp2AND(sp1,sp2);
}

float sp2NOR(float sp1,float sp2){

	return (1-sp1)*(1-sp2);
}

float sp2OR(float sp1,float sp2){

	return 1 - sp2NOR(sp1,sp2);
}

float sp2XOR(float sp1,float sp2){

	return sp1*(1-sp2) + sp2*(1-sp1);
}

float sp2XNOR(float sp1,float sp2){

	return 1 - sp2XOR(sp1,sp2);
}