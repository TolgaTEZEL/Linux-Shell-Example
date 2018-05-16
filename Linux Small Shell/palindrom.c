#include <stdio.h>
#include <string.h>




int main(int argc,char* argv[], char** arg) {
	char* str = argv[0];
 	int flag = 0;
	int i, length;
 	
	length = strlen(str);
    
    for(i=0;i < length ;i++){
        if(str[i] != str[length-i-1]){
            flag = 1;
            break;
	   }
	}
    
    if (flag) {
        printf("%s palindrom degil", str);
    }    
    else {
        printf("%s palindrom", str);
    }
    return 0;
   	

}


