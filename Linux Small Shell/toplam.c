#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[],char** arg) {
	int i;
	int sonuc = 0;
	int num1=atoi(argv[0]);
	int num2=atoi(argv[1]);
	for(i=num1;i<=num2;i++){
		if(i == num2){
			printf("%d ", i);
		}else{
			printf("%d + ", i);
		}
			
	
		sonuc += i;
	}
	printf("= %d ",sonuc);
	return 0;

}
