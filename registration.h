#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<anderconio.h>

int display2(int n){
    switch(n){
        case 1:
          system("clear");
          printf("Invalid password to long or short\n");
          printf("\e[7;34mEnter a new password\n\e[m");
          printf("Quit\n");
          break;
        case 2:
          system("clear");
          printf("Invalid password to long or short\n");
          printf("Enter a new password\n");
           printf("\e[7;34mQuit\n\e[m");
          break;
        default:
        break;
    }
}
int registration(char Uname[10]){
    char name[10],passwd[8],buff[25];
    char loc[60]="DB/";
    char loc2[60]="DB/user";
    char loc6[60]="DB/User_list";
    FILE *fp,*fps;
    int na_test=0,c,i=0,check=1,pa_test=0,count=1;
    char user_na[10]="user";
    char user_list[10]="User_list";
    printf("Enter a user name:");
    scanf("%s",name);
    Decryption(user_na);
    fp = fopen(loc2,"r+");
    while(getc(fp) != EOF ){//check if user donot exist already
        fscanf(fp,"%s",buff);
        if(strcmp(buff,name)==0){
            na_test=1;
        }
    }
    fclose(fp);
    Encryption(user_na);
    if(na_test == 0){
        c=getch();
        do{
            system("clear");
            printf("Enter a password(passwd is 5 charater):");//Enter password
        do{
            c=getch();
            if(c == 127){
                if(i > 0){
                    i--;
                    printf("\b");
                    printf(" ");
                    printf("\b");
                    passwd[i-1]=' ';
                }
            }else if(c == 10){
            
            }else{
                passwd[i]=c;//if key is no backspace it is store in passwd
                printf("*");//* display to tell that a key is enter
                i++;
            }
         }while(c != 10);
         if(i == 5){
            Decryption(user_na);
            fp = fopen(loc2,"a+");
            fprintf(fp,"\n");
            fprintf(fp,"%s",name);//store the username in user info file
            fprintf(fp,"  %s\n",passwd);//store the passwd in the user info file
            strcat(loc,name);//concatenaing main folder location and user to have user file location
            fps = fopen(loc,"w");//create the user file
            fclose(fps);
            pa_test=1;
            count = 2;
            Decryption(user_list);
            fps = fopen(loc6,"a+");
            fprintf(fps,"\n");
            fprintf(fps,"%s",name);//store the username in user list file
            fclose(fps);
            Encryption(user_list);
        }else{
            i=0;
            do{
            display2(count);
            c=getch();
            if(c == 119){
                count--;
            }
            if(c == 115){
                count++;
            }
            if(count == 0)
            count=2;
            if(count == 3)
            count=1;
                        
           }while(c != 10);
        } 
        }while(count != 2);
        if(pa_test == 1){
            strcpy(Uname,name);
            fclose(fp);
            Encryption(user_na);
            printf("\nLOADING\e[6m...\e[m\n");
            sleep(2);
            printf("Connected successfully\n");
            sleep(2);
            return 1;
        }else{
            fclose(fp);
            Encryption(user_na);
            printf("Impossible to connect\n");
            sleep(2);
            return 0;
        }
    }else{
        printf("LOADING\e[6m...\e[m\n");
        sleep(2);
        printf("user name already used!\n");
        sleep(2);
        fclose(fp);
        return 0;
    }   
}