#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

#define TOPLAM "toplam"  // program içerisinde i,ı harfleri Türkçe karakter sıkıntısına
#define ASAL "asal"      // yol açmasın ve okurken büyük harfler daha rahat okunduğu için
#define PALINDROM "palindrom" // kolaylık olması açısından kullanacağım ana kavramları tekrar defineledim
#define EXIT "exit"
#define CLEAR "clear"
#define CAT "cat"

// bazı hazır metotları kullanmak yerine kendi metodlarımı implement ettim.
int myOwnLenCounter(const char *str); // len
char* myOwnStrcpy(char * dest_ptr, const char * src_ptr); // strcpy
int myOwnStrccmp( const char *s1, const char *s2 ); // strcmp




void main(int argc,char* argv[],char** envp){
    char* command=NULL;
    
    do{       // do while döngüsü yardımıyla exit girilene , exitControl 1 olana kadar 
        printf("myshell>>"); // program devam eder.
        gets(&command); // gets komutu yardımıyla klavyeden girilen komut cümlesini okudum.
		int count=0; // komut sayısı ve sayma işlemleri için counter belirledim.
		char* temp; // program içerisinde string bölmesi yaparken kullanacağım değişken
		int i; // for döngüsünün parametresi.
		int exitControl=0;
		int len=myOwnLenCounter(&command); // komutun uzunluğunu len isimli değişkene atadım
	char* cmd1=calloc(len + 1, 1);  char* cmd2=calloc(len + 1, 1); // calloc yardımıyla hafızada dinamik bellek ayrımı yaptım 
        //her hangi bir sıkıntı olmaması acısından len +1 dedim
	
		
		
	myOwnStrcpy(cmd1,&command);  // commanddaki komutları cmd1ye kopyalar
	myOwnStrcpy(cmd2,&command); // commanddaki komutları cmd2ye kopyalar

	temp=strtok(cmd1,"&");// cmd1 i & ye göre böldük 2 komut birden girileceği için 
    if(cmd1 != NULL){ // eğer cmd1 boşsa yani üst satırlardaki kopyalama işlemi yapılmadıysa perrorla hata döndürür
        while(temp!=NULL){ // eğer hata yoksa & işaretinin sayısına göre kaç adet komut olduğunu hesaplıyor.
		count++; // Komut  sayısını hesaplıyor her & için 1 artıyor klasik sayaç.
		
            
		temp=strtok(NULL,"&");// sonraki komuta geçip komutu whileye yolluyor
        
        
    }
    }else{
            perror("Cmd1 atama işleminde bir problem meydana geldi");
            // cmd1 e komutu kopyalama işleminde hata çıkarsa bu kısım devreye giriyor.
        }
        
	
	char* cmdArray[count]; // komut sayısı uzunlugunda array olusturuyor.
	int arrcount=count; // arrcountu komut sayısına eşitledi
        // örnek cat a b & toplam 3 5
	temp=strtok(cmd2,"&"); // ilk komutu aldı cat 2 3  
	count=0; // sayaç kullanılmak için tekrar 0 landı 
        if(cmd1 != NULL){
	while(temp!=NULL){
		cmdArray[count]=temp;// komutları tek tek arraya attı cat a b  , toplam 3 5 vs
		count++; // cmdArrayın sonraki indexine geçildi.
		
            
		temp=strtok(NULL,"&");// sonraki komuta geçip komutu whileye yolluyor toplam 3 5 gibi
        }
            }
        else{
            perror("Cmd1 atama işleminde bir problem meydana geldi");
            
        }
		
	
	count=0; // count kullanılmak üzere tekrar sıfırlandı.
    for(i=0; i<arrcount ;i++){
		count=0;
		len=myOwnLenCounter(cmdArray[i]); // komutların oldugu arrayde i. indexin uzunluğu atıldı
        
		char * com1 = calloc (len + 1, 1); char * com2 = calloc (len + 1, 1); char * com3 = calloc (len + 1, 1);
		//  3 kere kullanacağım için 3 defa yarattım.
		myOwnStrcpy(com1,cmdArray[i]);  myOwnStrcpy(com2,cmdArray[i]); myOwnStrcpy(com3,cmdArray[i]);// 1. komutu attı com1e
		
	
		
		
		char *takenCom; // Alınan komut için 
		char* divideCom; // bölünüp parçalanan komut için
		
		
		takenCom=strtok(com1," "); // com1de suan toplam 2 3 var
		while(takenCom!=NULL){
            if(com1 != NULL){
                
			takenCom=strtok(NULL," ");
			count++;
            }
            else{
             perror("Com1 null değerine eşit hata");   
            }
		}
		char* cmd[count];
        
		divideCom=strtok(com2," ");
		int l=0; // indexler arasında ilerleme
		while(divideCom!=NULL){
		    cmd[l]=divideCom; // verilen diziye aktarılması işlemi için 
		    divideCom=strtok(NULL," ");
		    l++;
		}
		
		if(myOwnStrccmp(cmd[0],EXIT)==0){ // gelen komut exit ise exit ile cıkıs.
		    i=arrcount;
		    exitControl=1;
		}else if(myOwnStrccmp(cmd[0],CAT)==0){ // Gelen komut cat ise , cat ile gelen kelimeleri yazdırma
		    printf("cat:");
		    divideCom=strtok(com3," ");
		    divideCom=strtok(NULL," ");
		    while(divideCom!=NULL){
		    	printf("%s",divideCom); // cat ile gelen kelimelerin yazdırılması.
		    	divideCom=strtok(NULL," ");
			if(divideCom!=NULL){
				printf(" ");
			}
		    }
		    printf("\n");
		}else if(myOwnStrccmp(cmd[0],CLEAR)==0){//Eğer gelen komut Clear ise 
		    system("clear");  // ekranı temizle
		}else if(myOwnStrccmp(cmd[0],TOPLAM)==0){// Eğer gelen komut toplam ise 
                                        
			int lenght=sizeof(cmd)/sizeof(cmd[0]); // dizinin boyutunu bulmak için , cmdnin size ofunu , indexin sizesine böldük.
			if(lenght==3){   // girilenlerin sayısının kontrolü toplam 3 5  = 3 adet
				int f=fork();// driver-download prog20 de yapılanlar
				int k=0;
				if(f==0){
					char* argv[2]; // driver-download prog20 de yapılanlar
					argv[0]=cmd[1];
					argv[1]=cmd[2];
					argv[2]=NULL;
					k=execve(TOPLAM,argv,envp);
					perror("execve failed");
				}else{
					wait(&k); // Alt programların bitmesi beklenir.
				}
			}else{
				printf("invalid command!\n");
			}
			
		}else if(myOwnStrccmp(cmd[0],ASAL)==0){ // Gelen komut asal ise 
			int lenght=sizeof(cmd)/sizeof(cmd[0]);
			if(lenght==2){  // girilenlerin sayısının kontrolü asal 2 = 2 adet
				int f=fork();// driver-download prog20 de yapılanlar
				int k=0;
				if(f==0){
					char* argv[1];// driver-download prog20 de yapılanlar
					argv[0]=cmd[1];
					argv[1]=NULL;
					k=execve(ASAL,argv,envp);
					perror("execve failed");
				}else{
					wait(&k); // Alt programların bitmesi beklenir.
				}
			}else{
				printf("invalid command!\n");
			}
			
		}else if(myOwnStrccmp(cmd[0],PALINDROM)==0){  // Gelen komut palindrom ise
			int lenght=sizeof(cmd)/sizeof(cmd[0]);
			if(lenght==2){ // girilenlerin sayısının kontrolü palindrom ahmet = 2 
				int f=fork();// driver-download prog20 de yapılanlar
				int k=0;
				if(f==0){
					char* argv[1];// driver-download prog20 de yapılanlar
					argv[0]=cmd[1];
					argv[1]=NULL;
					k=execve(PALINDROM,argv,envp);
					perror("execve failed");
				}
			}else{
				printf("invalid command!\n");
			}		
		}else{
		    printf("invalid command!\n");
		}
	}
	if(exitControl==1){ // exit geldiği anda exitCOntrol = 1 oluyor ve break işlemi uygulanıyor
		break;
	}
    }while(1);
}


// bu satırdan sonrası implementasyonlar.



int myOwnLenCounter(const char *str)

{

    int count=0;

    while(*str!= '\0')

    {

        count++;

        str++;

    }

    return(count);

}

char* myOwnStrcpy(char * dest_ptr, const char * src_ptr)
	 {
  	   char* strresult = dest_ptr;
 	   if((NULL != dest_ptr) && (NULL != src_ptr))
  	   {
 	     
  	     while (NULL != *src_ptr)
  	     {
 	       *dest_ptr++ = *src_ptr++;
 	     }
  	    
  	     *dest_ptr = NULL;
  	   }
  	   return strresult;
     }

int myOwnStrccmp( const char *s1, const char *s2 )
{
    const unsigned char *p1 = ( const unsigned char * )s1;
    const unsigned char *p2 = ( const unsigned char * )s2;

    while ( *p1 && *p1 == *p2 ) ++p1, ++p2;

    return ( *p1 > *p2 ) - ( *p2  > *p1 );
}
         
