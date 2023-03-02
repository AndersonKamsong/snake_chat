#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<anderconio.h>
int display8(int n){
    switch(n){
        case 1:
          system("clear");
          printf("Do you want to delect your account\n");
          printf("\e[7;34mYES\n\e[m");
          printf("NO\n");
          break;
        case 2:
          system("clear");
          printf("Do you want to delect your account\n");
          printf("YES\n");
           printf("\e[7;34mNO\n\e[m");
          break;
        default:
        break;
    }
}

int deleteacc(char Uname[10]){
    char loc4[60]="DB/";
    char loc2[60]="DB/user";
    char loc3[60]="DB/temp";
    FILE *fp;
    char buff[255];
    int i=0,na_test=0,pos,count=2,c;
    char user_na[10]="user";

    do{
            display8(count);
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

    if(count == 1){
      Decryption(user_na);
      fp = fopen(loc2,"r+");//mode "r" is just to read in the file
      while(getc(fp) != EOF ){//to check if name enter exist
        fscanf(fp,"%s",buff);//navigating in the file
        pos=ftell(fp);
        if(strcmp(buff,Uname) == 0){//instruction to follow if name is found
            pos=pos-strlen(Uname);//2
            fseek(fp,pos,SEEK_SET);//2
            for(i=0;i<(strlen(Uname)+7);i++)
            fprintf(fp," ");//2:delect user detail in the user info file
            na_test=1;
            fseek(fp,EOF,SEEK_SET);// set pointer to EOF
        }
    }
    fclose(fp);
    Encryption(user_na);
    
    strcat(loc4,Uname);
    if(na_test == 1){
        remove(loc4);
        printf("LOADING\e[6m...\e[m\n");
        sleep(2);
        printf("The account is deleted successfully\n");
        sleep(2);
        return 10;
    }else{
        printf("The account is not delected\n");
        sleep(4);
        return 1;
    }
    }else{
        return 1;
    }
}

int display7(int n){
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

int changepasswd(char Uname[10]){
    char loc4[60]="DB/";
    char loc2[60]="DB/user";
    char loc3[60]="DB/temp";
    FILE *fp;
    char buff[255];
    int i=0,pa_test=0,c,count=1;
    char user_na[10]="user",passwd[8];

    do{
            display8(count);
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
    if(count == 1){
      do{
            system("clear");
            printf("Enter a new password(passwd is 5 charater):");//Enter password
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
            fp = fopen(loc2,"r+");
            while(getc(fp) != EOF ){//check if user donot exist already
                fscanf(fp,"%s",buff);
                if(strcmp(buff,Uname)==0){
                    fprintf(fp,"  %s",passwd);
                    fseek(fp,EOF,SEEK_SET);// set pointer to EOF
                }
            }
            fclose(fp);
            Encryption(user_na);
            printf("\nLOADING\e[6m...\e[m\n");
            sleep(2);
            printf("password change successfully\n");
            sleep(2);
            return 10;
        }else{
            i=0;
            do{
            display7(count);
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
            printf("Impossible to change password\n");
            sleep(2);
            return 1;
        }else{
            return 1;
        }
}

int display10(int n){
    switch(n){
        case 1:
          system("clear");
          printf("Do you want to change your Username account\n");
          printf("\e[7;34mYES\n\e[m");
          printf("NO\n");
          break;
        case 2:
          system("clear");
          printf("Do you want to change your Username account\n");
          printf("YES\n");
           printf("\e[7;34mNO\n\e[m");
          break;
        default:
        break;
    }
}

int changename(char Uname[10]){
    char loc4[60]="DB/";
    char loc5[60]="DB/";
    char loc2[60]="DB/user";
    char loc3[60]="DB/temp";
    char loc6[60]="DB/User_list";
    FILE *fp,*fps;
    char buff[255],Nname[10];
    int i=0,na_test=0,c,count=2,pos;
    char user_na[10]="user",user_list[10]="User_list",pass_test[8];

    do{
            display10(count);
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
    if(count == 1){    
        system("clear");
        printf("Enter a new User name:");//Enter password
        scanf("%s",Nname);

        Decryption(user_na);
        fp = fopen(loc2,"r+");
        while(getc(fp) != EOF ){//check if user donot exist already
            fscanf(fp,"%s",buff);
            if(strcmp(buff,Nname)==0){
                na_test=1;
            }
        }
        fclose(fp);
        Encryption(user_na);
        if(na_test == 0){        
            Decryption(user_na);
            Decryption(user_list);
            fp = fopen(loc2,"r+");
            while(getc(fp) != EOF ){//check if user donot exist already
                fscanf(fp,"%s",buff);
                if(strcmp(buff,Uname)==0){
                    fscanf(fp,"%s",pass_test);
                    fseek(fp,EOF,SEEK_SET);// set pointer to EOF
                }
            }
            fclose(fp);
            fp = fopen(loc2,"r+");//mode "r" is just to read in the file
            while(getc(fp) != EOF ){//to check if name enter exist
                fscanf(fp,"%s",buff);//navigating in the file
                pos=ftell(fp);
                if(strcmp(buff,Uname) == 0){//instruction to follow if name is found
                    pos=pos-strlen(Uname);//2
                    fseek(fp,pos,SEEK_SET);//2
                    for(i=0;i<(strlen(Uname)+7);i++)
                        fprintf(fp," ");//2:delect user detail in the user info file
                    na_test=1;
                    fseek(fp,EOF,SEEK_SET);// set pointer to EOF
                }
            }
            fclose(fp);
            fps = fopen(loc6,"r+");//mode "r" is just to read in the file
            while(getc(fps) != EOF ){//to check if name enter exist
                fscanf(fps,"%s",buff);//navigating in the file
                pos=ftell(fps);
                if(strcmp(buff,Uname) == 0){//instruction to follow if name is found
                    pos=pos-strlen(Uname);//2
                    fseek(fps,pos,SEEK_SET);//2
                    for(i=0;i<(strlen(Uname)+7);i++)
                        fprintf(fps," ");//2:delect user detail in the user info file
                    na_test=1;
                    fseek(fps,EOF,SEEK_SET);// set pointer to EOF
                }
            }
            fclose(fps);

            fp = fopen(loc2,"a+");
            while(getc(fp) != EOF ){//to check if name enter exist
                    fprintf(fp,"\n\n");
                    fprintf(fp,"%s",Nname);
                    fprintf(fp,"  %s",pass_test);
                    break;
            }
            fclose(fp);
            fps = fopen(loc6,"a+");
            while(getc(fps) != EOF ){//to check if name enter exist
                fprintf(fps,"\n");
                fprintf(fps,"%s",Nname);
                break;
            }
            fclose(fps);
            Encryption(user_na);
            Encryption(user_list);
            strcat(loc4,Uname);
            strcat(loc5,Nname);
            rename(loc4,loc5);
            printf("\nLOADING\e[6m...\e[m\n");
            sleep(2);
            printf("Username change successfully\n");
            sleep(2);
            c=getch();
            return 10;

        }else{
            printf("LOADING\e[6m...\e[m\n");
            sleep(2);
            printf("user name already used!\n");
            sleep(2);
            c=getch();
            return 11;
        }   
    }else{
            printf("Impossible to change Username\n");
            sleep(2);
            c=getch();
            return 11;
    }
}

int user_list(){
    char loc6[60]="DB/User_list";
    FILE *fp;
    char user_list[10]="User_list",buff[255],buff2[255];
    int pos,i=1;
    Decryption(user_list);
    fp=fopen(loc6,"r+");
    while(getc(fp) != EOF){
       // pos=ftell(fp);
        //fseek(fp,pos-1,SEEK_SET);
        fscanf(fp,"%s",buff);
        printf("%d:%s\n",i,buff);
        //fscanf(fp,"%s",buff2);
        //printf("%d:%s best snake sorce:%s\n",i,buff,buff2);
        i++;
        sleep(1);
    }
    fclose(fp);
    Encryption(user_list);
    printf("\npress any key to leave!");
    i=getch();
    return 1;
    }        
        
