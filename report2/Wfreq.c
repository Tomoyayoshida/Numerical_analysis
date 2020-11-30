#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	FILE *fp1, *fp2;
	double b=0,n = 0,w[256];
	char fname[256],t;

	printf("FILE name:");
	scanf("%s",fname);
	
	fp1 = fopen(fname,"r");
	fp2 = fopen("Wfreq.txt","w");
	
	if(fp1 == NULL){
		printf("Can not find file\n");
		exit(1);
	}
	if(fp2 == NULL){
		printf("Can not find Wfreq.txt\n");
		exit(1);
	}

	while(fscanf(fp1,"%c",&t) != EOF){
		if('a' <= t && t <= 'z'){
			w[t]++;
		}else if('A' <= t && t <= 'Z'){
			t = tolower(t);
			w[t]++;
		}else if(isblank(t)){
			b++;//空白数
		}n++;//全体数
	}
	for(t='a';t <= 'z';t++){
		printf("%c:%.0f:%.2f%%\n",t,w[t],(w[t]/n)*100);
		fprintf(fp2,"%c:%.0f:%.0f%%\n",t,w[t],(w[t]/n)*100);
	}
	printf("blank:%.0f:%.1f%%\n",b,(b/n)*100);
	printf("all w:%.0f\n",n);
	fprintf(fp2,"blank:%.0f:%.1f%%\n",b,(b/n)*100);
	fprintf(fp2,"all w:%.0f\n",n);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
