#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<anderconio.h>


int login(char Uname[10]){
    char name[10],passwd[8],pass_test[8],buff[25];
    /*name is use store the username during execution
    passwd is use store the userpassword during enter by user
    pass-test contain the actually password of user and is being compare with passwd
    buff to navigate between file*/
    char loc2[60]="DB/user";
    int na_test=0,check=3,c=0,i=0,pa_test=0;
    char user_na[10]="user";
    /*check is the No of time one can enter an incorrect passwd
    na_test boolean true(1) if name is in use file else false(0)
    c temporary store the ASNII of the character when passwd is being entered
    i is the index which manipulate passwd*/
    FILE *fp;
    printf("Enter your user name:");
    scanf("%s",&name);//enter a username
    Decryption(user_na);
    fp = fopen(loc2,"r");//mode "r" is just to read in the file

    while(getc(fp) != EOF ){//to check if name enter exist
        fscanf(fp,"%s",buff);//navigating in the file
        if(strcmp(buff,name)==0){//instruction to follow if name is found
            fscanf(fp,"%s",pass_test);
            na_test=1;
        }
    }
    fclose(fp);
    Encryption(user_na);

    if(na_test == 1){//checking user name 
     c=getch();//for the password
        do{
            printf("Enter your password:");//Enter a password
            i=0;
        do{
            c=getch();//hidden the enter input
            if(c == 127){//delect a * use backspace 
                if(i > 0){
                    i--;
                    printf("\b");//1
                    printf(" ");//1
                    printf("\b");//1
                    passwd[i-1]=' ';//1:Deleted * on console
                }
            }else if(c == 10){
                break;
            }else{
                passwd[i]=c;//if key is no backspace it is store in passwd
                printf("*");//* display to tell that a key is enter
                i++;
            }
         }while(i != 5);//do loop enter if the enter key is Eneter
        if(strcmp(passwd,pass_test) == 0){//checking the password
            printf("\nCorrect password\n");
            check=0;
            pa_test=1;
        }else{
            system("clear");
            check--;
            printf("Incorrect password %d chance live\n",check);
            strcpy(passwd," ");
        }
        }while(check > 0);
        if(pa_test == 1){
            printf("LOADING\e[6m...\e[m\n");
            sleep(2);
            printf("Connected successfully\n");
            sleep(1);
            strcpy(Uname,name);
            return 1;
        }else{
            printf("LOADING\e[6m...\e[m\n");
            sleep(2);
            printf("Incorrect password\n");
            sleep(2);
            return 10;
        }
    }else{
        printf("LOADING\e[6m...\e[m\n");
        sleep(2);
        printf("Invalid user name\n");
        sleep(2);
        return menu4();
    }
}

int Quit1(){
    printf("LOADING\e[6m...\e[m\n");
    sleep(3);
    printf("BYE BYE!\n");
    exit(0);
}

int display4(int n){
    switch(n){
        case 1:
          system("clear");
          printf("Invalid user name\n");
           printf("\e[7;34mContinue\n\e[m");
           printf("Quit\n");
          break;
        case 2:
          system("clear");
          printf("Invalid user name\n");
           printf("Continue\n");
           printf("\e[7;34mQuit\n\e[m");
          break;
        default:
        break;
    }
}

int menu4(){
    int c,count=1;
    do{
        display4(count);
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
    system("clear");
    switch(count){
        case 1:
        return 0;
          break; 
          case 2:
        return 10;
          break;
        default:
        break;
    }
}