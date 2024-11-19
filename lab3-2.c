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



void GivenInputs(){

	
	FILE *fp;
	fp = fopen("test.txt","r");
	char *ElementTypes[] = {"AND","OR","XOR","NOT","NAND","NOR","XNOR"};
	char c;
	char *d = (char *) malloc(5 * sizeof(char));
	output = (char *) malloc(20 * sizeof(char));
	int count=0;
	int El_count=0; 
	int count_output = 0;
	int count_input = 0;
	flag = false;
	char type[3];
	int i_type=0;
	for(int i=0;i<20;i++){
		TopInputs[i].mark = (int *) malloc(1*sizeof(int));
	}
	/*for(int i=0;i<20;i++){
		ELementsTable[i].type = (char *) malloc(5*sizeof(int));
	}*/
	for(int i=0;i<20;i++){
		ELementsTableSorted[i].type = (char *) malloc(5*sizeof(int));
	}
	while(fscanf(fp,"%c",&c) != -1){
		if(c == 't'){
			fscanf(fp,"%s",d);
			if(strcmp(d,"op")==0){
				char a;
				int i=0;
				while(c!='\n'){
					fscanf(fp,"%c",&a);
					if(isspace(c)==0){
						TopInputs[i].name = a;
						TopInputs[i].value = &(SignalsTable[i].value); 
						//TopInputs[i].mark = (int *) malloc(1*sizeof(int));
						TopInputs[i].mark = &(SignalsTable[i].mark);
						printf("%d",SignalsTable[i].mark);
						i++;	
					}
				}
			}
			flag = true;
		}else if(isupper(c)){
			type[i_type] = c;
			i_type++;
			if(i_type==3){
				for(int i=0;i<7;i++){
					if(strcmp(ElementTypes[i],type)==0){
						ELementsTable[El_count].type = type;

					}
				}
				char x,y,z;
				if(strcmp(type,"NOT")==0){
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
				i_type = 0;
				El_count++;
				fscanf(fp,"%c",&c);
				if(isspace(c)!=0){
					continue;
				}
			}
		}
	}
	fclose(fp);	
}			
		
	

	
		
	


void circuit(){
	
	int i=0;
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
	}

	
	for(int j=0;j<20;j++){
		if(isalpha(input[j])){
			// /printf("%c",TopInputs[input[i]-'a'].name);
			TopInputs[input[j]-'a'].value = &(SignalsTable[input[j]-'a'].value);
			//TopInputs[input[i]-'a'].mark = (int *) malloc(4*sizeof(int));
			TopInputs[input[j]-'a'].mark = &(SignalsTable[input[j]-'a'].mark);
			//printf("%d",SignalsTable[i].mark);
		}
	}
	
	/*for(int i=0;i<20;i++){
		if(strlen(ELementsTable[i].type)==0){
			break;
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

	}*/

	
	for(int i=0;i<20;i++){
	
		*(TopInputs[i].mark) = 1;
		//printf("%d",SignalsTable[i].mark);
	
	}


	
	
	for(int j=0;j<20;j++){
		printf("%s\n",ELementsTable[i].type);
	}	

}
	
		




int main(){


	GivenInputs();
	circuit();
	


}

