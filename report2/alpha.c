#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	FILE *fp1, *fp2;
	double n = 0;
	char fname[256],t;

	printf("FILE name:");
	scanf("%s",fname);
	
	fp1 = fopen(fname,"r");
	fp2 = fopen("changeF.txt","w");
	
	if(fp1 == NULL){
		printf("Can not find file\n");
		exit(1);
	}
	if(fp2 == NULL){
		printf("Can not find changeF.txt\n");
		exit(1);
	}

	while(fscanf(fp1,"%c",&t) != EOF){
		if(isalpha(t)){
			printf("%c",t);
			fprintf(fp2,"%c",t);
		}else if(isblank(t)){
			printf("%c",t);
			fprintf(fp2,"%c",t);
		}else{
		}
	}
	
	printf("\n");

	fclose(fp1);
	fclose(fp2);

	return 0;
}
