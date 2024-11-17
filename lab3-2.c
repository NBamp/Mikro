#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "model.h"

#ifdef USE_VERSION_1
void GivenInputs(){

	
	FILE *fp;
	fp = fopen("test.txt","r");
	
	char c;
	char *d = (char *) malloc(20 * sizeof(char));
	int count=0;
	bool flag = false;
	while(flag == false && (fscanf(fp,"%c",&c) != -1)){
		if(c=='e'){
			while(c!='('){
				fscanf(fp,"%c",&c);
			}
			if(fscanf(fp,"%f,%f",TopInputs[0],TopInputs[1] ) == 2){
				printf("%f\n",*(ELementsTable[0].inputs[0]));
			}
			fscanf(fp,"%c",&c);
			while(c!='('){
				fscanf(fp,"%c",&c);
			}
			fscanf(fp,"%f",TopInputs[2]);
			flag = true;
		}else if(c == 't'){
			d[count] = c;
			while(c != 's'){
				fscanf(fp,"%c",&c);
				count++;
				d[count] = c;
			}
			if(strcmp(d,"top_inputs")==0){
				if(fscanf(fp,"%f %f %f",TopInputs[0] ,TopInputs[1],TopInputs[2]) == 3){
					flag = true;
				}
			}
		}else
			flag = true;
		
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
	
	fclose(fp);
}

#endif

int main(){

	circuit();
	GivenInputs();

}

