#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include "model.h"


struct Element ELementsTable[20];
struct Element ELementsTableSorted[20];
struct Signal SignalsTable[50];
struct Input TopInputs[20]; 
bool flag;
char* output;
char input[20];
int input_signals;
int El_count;



void GivenInputs(){

	
	FILE *fp;
	fp = fopen("test.txt","r");
	char *ElementTypes[] = {"AND","OR","XOR","NOT","NAND","NOR","XNOR"};
	char c;
	char *d = (char *) malloc(5 * sizeof(char));
	output = (char *) malloc(20 * sizeof(char));
	El_count=0;
	int count_output = 0;
	int count_input = 0;
	flag = false;
	char type[3];
	int i_type=0;
	for(int i=0;i<20;i++){
		TopInputs[i].mark = (int *) malloc(1*sizeof(int));
	}
	for(int i=0;i<20;i++){
		ELementsTable[i].type = (char *) malloc(5*sizeof(int));
		ELementsTable[i].output = (float *) malloc(1*sizeof(float));
	}
	for(int i=0;i<20;i++){
		ELementsTableSorted[i].type = (char *) malloc(5*sizeof(int));
	}
	while(fscanf(fp,"%c",&c) != -1){
		if(c == 't'){
			fscanf(fp,"%s",d);
			if(strcmp(d,"op_inputs")==0){
				char a;
				int i=0;
				while(a!='\n'){
					fscanf(fp,"%c",&a);
					if(isalpha(a)){
						TopInputs[i].name = a;
						TopInputs[i].value = &(SignalsTable[i].value); 
						TopInputs[i].mark = &(SignalsTable[i].mark);
						i++;
					}
				}

					/*	
					
				}*/
			}
			flag = true;
		}else if(isupper(c)){
			fseek(fp,-1,SEEK_CUR);
			fscanf(fp,"%s",ELementsTable[El_count].type);
				char x,y,z;
				if(strcmp(ELementsTable[El_count].type,"NOT")==0){
					fscanf(fp," %c %c",&x,&y);
					ELementsTable[El_count].sum_signals[0]=x;
					ELementsTable[El_count].sum_signals[1]=y;
					output[count_output] = x;
					input[count_input] = y;
					count_input++;
				}else{
					fscanf(fp," %c %c %c",&x,&y,&z);
					ELementsTable[El_count].sum_signals[0]=x;
					ELementsTable[El_count].sum_signals[1]=y;
					ELementsTable[El_count].sum_signals[2]=z;
					output[count_output] = x;
					input[count_input] = y;
					input[count_input+1] = z;
					count_input+=2;
				}
				count_output++;
				El_count++;
				fscanf(fp,"%c",&c);
				if(isspace(c)!=0){
					continue;
				}
		}
	}
	fclose(fp);	
}			
		
	

	
		
	


void circuit(){
	
	int i=0;
	input_signals=0;
	if(flag == false){
		while(input[i]!='\0'){
			for(int j=0;j<20;j++){
				if(input[i] == output[j]){
					input[i] = ' ';
					break;
				}
			}
			i++;
		}
		for(int j=0;j<20;j++){
			if(isalpha(input[j])){
				TopInputs[input[j]-'a'].value = &(SignalsTable[input[j]-'a'].value);
				TopInputs[input[j]-'a'].mark = &(SignalsTable[input[j]-'a'].mark);
				input_signals++;
			}
		}
	}else{
		for(int i=0;i<20;i++){
			if(isalpha(TopInputs[i].name)){
				input_signals++;
			}
		}

	}
	

	for(int i=0;i<20;i++){
		if(strlen(ELementsTable[i].type)==0){
			continue;
		}
		else if(strcmp(ELementsTable[i].type,"NOT")==0){
			ELementsTable[i].inputs[0] = &(SignalsTable[(ELementsTable[i].sum_signals[1]) - 'a'].value);
			ELementsTable[i].output = &(SignalsTable[(ELementsTable[i].sum_signals[0]) - 'a'].value);
		}
		else{
			ELementsTable[i].inputs[0] = &(SignalsTable[(ELementsTable[i].sum_signals[1]) - 'a'].value);
			ELementsTable[i].inputs[1] = &(SignalsTable[(ELementsTable[i].sum_signals[2]) - 'a'].value);
			ELementsTable[i].output = &(SignalsTable[(ELementsTable[i].sum_signals[0]) - 'a'].value);
		}

	}

	
	for(int i=0;i<20;i++){
		*(TopInputs[i].mark) = 1;
	}

	
	int p=0;
	int k=0;
	while(p<El_count-1){
		for(int j=0;j<20;j++){
			if(strlen(ELementsTable[j].type)==0){
				break;
			}else if(strcmp(ELementsTable[j].type,"NOT")==0 && SignalsTable[(ELementsTable[j].sum_signals[1]) - 'a'].mark == 1){
				ELementsTableSorted[p] = ELementsTable[j];
				SignalsTable[ELementsTable[j].sum_signals[0]-'a'].mark = 1;
				p++;
			}else if(SignalsTable[(ELementsTable[j].sum_signals[1]) - 'a'].mark == 1 && SignalsTable[(ELementsTable[j].sum_signals[2]) - 'a'].mark == 1){
				ELementsTableSorted[p] = ELementsTable[j];
				SignalsTable[ELementsTable[j].sum_signals[0]-'a'].mark = 1;
				p++;
			}else{
				ELementsTable[El_count+k] = ELementsTable[j];
				k++;
			}
			
		}
	}
	
	
}

	
		




int main(){

	
	GivenInputs();
	circuit();
	float x,y,z,k,l,m,n;
	for(int i=0;i<input_signals;i++){
		printf("Input for argument number %d\n",i+1);
		scanf("%f",TopInputs[i].value);
	}
	for(int i=0;i<20;i++){
		if(strcmp(ELementsTableSorted[i].type,"") == 0){
			break;
			
		}else if(strcmp(ELementsTableSorted[i].type,"AND") == 0){
			*(ELementsTableSorted[i].output) = sp2AND(*(ELementsTableSorted[i].inputs[0]),*(ELementsTableSorted[i].inputs[1]));
			printf("And Gate with output %c for inputs %c=%f and %c=%f is %f\n",ELementsTableSorted[i].sum_signals[0],ELementsTableSorted[i].sum_signals[1],*(ELementsTableSorted[i].inputs[0]),ELementsTableSorted[i].sum_signals[2],*(ELementsTableSorted[i].inputs[1]),*(ELementsTableSorted[i].output));
			x = 2* (*(ELementsTableSorted[i].output)) * (1 - *(ELementsTableSorted[i].output));
			printf("Switching activity for AND gate is %f\n",x);
		}else if(strcmp(ELementsTableSorted[i].type,"NOT") == 0){
			*(ELementsTableSorted[i].output) = spNOT(*(ELementsTableSorted[i].inputs[0]));
			printf("NOT Gate with output %c for input %c=%f is %f\n",ELementsTableSorted[i].sum_signals[0],ELementsTableSorted[i].sum_signals[1],*(ELementsTableSorted[i].inputs[0]),*(ELementsTableSorted[i].output));
			y = 2* (*(ELementsTableSorted[i].output)) * (1 - *(ELementsTableSorted[i].output));
			printf("Switching activity for NOT gate is %f\n",y);
		}else if(strcmp(ELementsTableSorted[i].type,"OR") == 0){
			*(ELementsTableSorted[i].output) = sp2OR(*(ELementsTableSorted[i].inputs[0]),*(ELementsTableSorted[i].inputs[1]));
			printf("OR Gate with output %c for inputs %c=%f and %c=%f is %f\n",ELementsTableSorted[i].sum_signals[0],ELementsTableSorted[i].sum_signals[1],*(ELementsTableSorted[i].inputs[0]),ELementsTableSorted[i].sum_signals[2],*(ELementsTableSorted[i].inputs[1]),*(ELementsTableSorted[i].output));
			z = 2* (*(ELementsTableSorted[i].output)) * (1 - *(ELementsTableSorted[i].output));
			printf("Switching activity for OR gate is %f\n",z);
		}else if(strcmp(ELementsTableSorted[i].type,"XOR") == 0){
			*(ELementsTableSorted[i].output) = sp2XOR(*(ELementsTableSorted[i].inputs[0]),*(ELementsTableSorted[i].inputs[1]));
			printf("XOR Gate with output %c for inputs %c=%f and %c=%f is %f\n",ELementsTableSorted[i].sum_signals[0],ELementsTableSorted[i].sum_signals[1],*(ELementsTableSorted[i].inputs[0]),ELementsTableSorted[i].sum_signals[2],*(ELementsTableSorted[i].inputs[1]),*(ELementsTableSorted[i].output));
			k = 2* (*(ELementsTableSorted[i].output)) * (1 - *(ELementsTableSorted[i].output));
			printf("Switching activity for XOR gate is %f\n",k);
		}else if(strcmp(ELementsTableSorted[i].type,"NAND") == 0){
			*(ELementsTableSorted[i].output) = sp2NAND(*(ELementsTableSorted[i].inputs[0]),*(ELementsTableSorted[i].inputs[1]));
			printf("NAnd Gate with output %c for inputs %c=%f and %c=%f is %f\n",ELementsTableSorted[i].sum_signals[0],ELementsTableSorted[i].sum_signals[1],*(ELementsTableSorted[i].inputs[0]),ELementsTableSorted[i].sum_signals[2],*(ELementsTableSorted[i].inputs[1]),*(ELementsTableSorted[i].output));
			l = 2* (*(ELementsTableSorted[i].output)) * (1 - *(ELementsTableSorted[i].output));
			printf("Switching activity for NAND gate is %f\n",l);
		}else if(strcmp(ELementsTableSorted[i].type,"NOR") == 0){
			*(ELementsTableSorted[i].output) = sp2NOR(*(ELementsTableSorted[i].inputs[0]),*(ELementsTableSorted[i].inputs[1]));
			printf("NOR Gate with output %c for inputs %c=%f and %c=%f is %f\n",ELementsTableSorted[i].sum_signals[0],ELementsTableSorted[i].sum_signals[1],*(ELementsTableSorted[i].inputs[0]),ELementsTableSorted[i].sum_signals[2],*(ELementsTableSorted[i].inputs[1]),*(ELementsTableSorted[i].output));
			m = 2* (*(ELementsTableSorted[i].output)) * (1 - *(ELementsTableSorted[i].output));
			printf("Switching activity for NOR gate is %f\n",m);
		}else if(strcmp(ELementsTableSorted[i].type,"XNOR") == 0){
			*(ELementsTableSorted[i].output) = sp2XNOR(*(ELementsTableSorted[i].inputs[0]),*(ELementsTableSorted[i].inputs[1]));
			printf("Nor Gate with output %c for inputs %c=%f and %c=%f is %f\n",ELementsTableSorted[i].sum_signals[0],ELementsTableSorted[i].sum_signals[1],*(ELementsTableSorted[i].inputs[0]),ELementsTableSorted[i].sum_signals[2],*(ELementsTableSorted[i].inputs[1]),*(ELementsTableSorted[i].output));
			n = 2* (*(ELementsTableSorted[i].output)) * (1 - *(ELementsTableSorted[i].output));
			printf("Switching activity for XNOR gate is %f\n",n);
		}	

	}
	return 1;
	
}
