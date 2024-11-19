#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"


float sp2AND(float sp1,float sp2);
float spNOT(float sp1);
struct Element ELementsTable[3]; 
struct Signal SignalsTable[6]; 
float* TopInputs[3];



float sp2AND(float sp1,float sp2){

	return sp1*sp2;

}

float spNOT(float sp1){

	return 1-sp1;
}

void circuit(){


	struct Element E1,E2,E3;
	ELementsTable[0] = E1;
	ELementsTable[1] = E2;
	ELementsTable[2] = E3;

	struct Signal s1,s2,s3,s4,s5,s6;
	SignalsTable[0] = s1;
	SignalsTable[1] = s2;
	SignalsTable[2] = s3;
	SignalsTable[3] = s4;
	SignalsTable[4] = s5;
	SignalsTable[5] = s6;


	TopInputs[0] = &(SignalsTable[0].value);
	TopInputs[1] = &(SignalsTable[1].value);
	TopInputs[2] = &(SignalsTable[2].value);


	for(int i=0;i<3;i++){

		if(i==0){
			ELementsTable[i].type = "AND";
			ELementsTable[i].inputs[0] = &(SignalsTable[i].value); 
			ELementsTable[i].inputs[1] = &(SignalsTable[i+1].value);
			ELementsTable[i].output = &(SignalsTable[i+4].value);
		}
		else if(i==1){
			ELementsTable[i].type = "NOT";
			ELementsTable[i].inputs[0] = &(SignalsTable[i+1].value); 
			ELementsTable[i].output = &(SignalsTable[i+4].value);
		}else{
			ELementsTable[i].type = "AND";
			ELementsTable[i].inputs[0] = &(SignalsTable[i+2].value); 
			ELementsTable[i].inputs[1] = &(SignalsTable[i+3].value);
			ELementsTable[i].output = &(SignalsTable[i+1].value);
		}

	}
}
void GivenInputs(){
	
	for(int i=0;i<3;i++){
		printf("Input for argument number %d\n",i+1);
		scanf("%f",TopInputs[i]);
	}
	
	for(int i=0;i<3;i++){
		if(strcmp(ELementsTable[i].type,"AND") == 0){
			*(ELementsTable[i].output) = sp2AND(*(ELementsTable[i].inputs[0]),*(ELementsTable[i].inputs[1]));
			printf("And Gate output for inputs %f %f is %f\n",*(ELementsTable[i].inputs[0]),*(ELementsTable[i].inputs[1]),*(ELementsTable[i].output));
		}else{
			*(ELementsTable[i].output) = spNOT(*(ELementsTable[i].inputs[0]));
			printf("NOT Gate output for inputs %f is %f\n",*(ELementsTable[i].inputs[0]),*(ELementsTable[i].output));
		}
	}
}

int main(){

	circuit();
	GivenInputs();
}
