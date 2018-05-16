#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[],char** arg) {
 	int num = atoi(argv[0]);
	int flag = 0;
	int i;
  for(i=2; i<=num/2; ++i)
    {
        
        if(num%i==0)
        {
            flag=1;
            break;
        }
    }

    if (flag==0){
    	printf("%d > asal ",num);
	}
        
    else{
    	printf("%d > asal degil ",num);
	}
        
    
    return 0;
  
    

}


