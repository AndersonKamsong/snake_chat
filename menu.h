#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<anderconio.h>
#include<login.h>
#include<registration.h>
#include<message.h>
#include<accout.h>

void display_cover(){
  system("clear");
  printf("\033[31;44mWelcome to snake_chat                     #\n");
  sleep(1);
  printf("snake_chat is a chat program with a game  #\n");
  sleep(1);
  printf("It enable user to send message to another #\n");
  printf("user or to himself                        #\n");
  sleep(1);
  printf("It also contain a snake game              #\n");
  sleep(1);
  printf("This program was created by:              #\n");
  sleep(1);
  printf("***********                               #\n");
  sleep(1);
  printf("***********                               #\n");
  sleep(1);
  printf("***********                               #\n");
  sleep(1);
  printf("Kamsong Gaston Anderson                   #\n");
  sleep(1);
  printf("***********                               #\n");
  sleep(1);
  printf("***********                               #\n");
  sleep(1);
  printf("press a key to continue!                  #\n");
  printf("###########################################\n\033[0m");
  getch();
}
int display(int n){
    switch(n){
        case 1:
          system("clear");
          printf("\e[7;34mRegistration\n\e[m");
          printf("login\n");
          printf("Quit\n");
          break;
        case 2:
          system("clear");
          printf("Registration\n");
           printf("\e[7;34mlogin\n\e[m");
           printf("Quit\n");
          break;
        case 3:
          system("clear");
          printf("Registration\n");
           printf("login\n");
           printf("\e[7;34mQuit\n\e[m");
          break;
        default:
        break;
    }
}
int menu1(char Uname[10]){
    int j,i,c,count=1;
    char name[10];
    do{
        display(count);
            c=getch();
            if(c == 119){
                count--;
            }
            if(c == 115){
                count++;
            }
            if(count == 0)
            count=3;
            if(count == 4)
            count=1;
                        
    }while(c != 10);
    system("clear");
    switch(count){
        case 1:
          j=registration(name);
          break;
        case 2:
          j=login(name);
          break;
        case 3:
          j=Quit1();
          break;  
        default:
        break;
    }
    return j;
}


int display3(int n,char Uname[10]){
    switch(n){
        case 1:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("\e[7;34mWrite a message\n\e[m");
          printf("message box\n");
          printf("Game\n");
          printf("Account info\n");
          printf("List of User\n");
          printf("Quit\n");
          break;
        case 2:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("Write a message\n");
          printf("\e[7;34mmessage box\n\e[m");
          printf("Game\n");
          printf("Account info\n");
          printf("List of User\n");
          printf("Quit\n");
          break;
        case 3:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("Write a message\n");
          printf("message box\n");
          printf("\e[7;34mGame\n\e[m");
          printf("Account info\n");
          printf("List of User\n");
          printf("Quit\n");
          break;
        case 4:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("Write a message\n");
          printf("message box\n");
          printf("Game\n");
          printf("\e[7;34mAccount info\n\e[m");
          printf("List of User\n");
          printf("Quit\n");
          break;
        case 5:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("Write a message\n");
          printf("message box\n");
          printf("Game\n");
          printf("Account info\n");
          printf("\e[7;34mList of User\n\e[m");
          printf("Quit\n");
          break;
        case 6:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("Write a message\n");
          printf("message box\n");
          printf("Game\n");
          printf("Account info\n");
          printf("List of User\n");
          printf("\e[7;34mQuit\n\e[m");
          break;
        default:
        break;
    }
}

int menu2(char Uname[10]){
    int k,i,c,count=1;
    char name[10];
     do{
        display3(count,name);
            c=getch();
            if(c == 119){
                count--;
            }
            if(c == 115){
                count++;
            }
            if(count == 0)
            count=6;
            if(count == 7)
            count=1;
                        
    }while(c != 10);
    system("clear");
    switch(count){
        case 1:
          k=sending(name);
          break;
        case 2:
          k=messagebox(name);
          break;
        case 4:
          k=menu6(name);
          break;
        case 5:
          k=user_list();
          break;
        case 6:
          k=Quit2();
          break;  
        default:
        break;
    }
    
    return k;
}

int display6(int n,char Uname[10]){
    switch(n){
        case 1:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("\e[7;34mchange name\n\e[m");
          printf("change password\n");
          printf("Delect account\n");
          printf("Quit\n");
          break;
        case 2:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("change name\n");
          printf("\e[7;34mchange password\n\e[m");
          printf("Delect account\n");
          printf("Quit\n");
          break;
        case 3:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("change name\n");
          printf("change password\n");
          printf("\e[7;34mDelect account\n\e[m");
          printf("Quit\n");
          break;
        case 4:
          system("clear");
          printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
          printf("change name\n");
          printf("change password\n");
          printf("Delect account\n");
          printf("\e[7;34mQuit\n\e[m");
          break;
        default:
        break;
    }
}

int menu6(char Uname[10]){
    int j,c,count=1;
    char name[10];
    do{
        display6(count,Uname);
            c=getch();
            if(c == 119){
                count--;
            }
            if(c == 115){
                count++;
            }
            if(count == 0)
            count=4;
            if(count == 5)
            count=1;
                        
    }while(c != 10);
    system("clear");
    
    switch(count){
        case 1:
          j=changename(Uname);
          break;
        case 2:
          j=changepasswd(Uname);
          break;
         case 3:
          j=deleteacc(Uname);
          break; 
        case 4:
          j=1;
          break;  
        default:
        break;
    }
   return j;   
}