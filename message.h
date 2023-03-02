#include<stdio.h>
#include<string.h>
#include<Encryption.h>
#include<stdlib.h>

int messagebox(char Uname[10]){
     FILE *fp;
    char buff[255];
    int i=0,m=1,pos;
    char loc4[60]="DB/";
    printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
    strcat(loc4,Uname);
    Decryption(Uname);
    fp = fopen(loc4,"r+");
    while(getc(fp) != EOF){
        pos=ftell(fp);
        fseek(fp,pos-1,SEEK_SET);
           fgets(buff,255,fp);
           printf("%d:%s",i,buff);
           i++;
           sleep(1);
    }
    fclose(fp);
    Encryption(Uname);
    printf("press any key to leave!");
    i=getch();
    return 1;
}

int sending(char Uname[10]){
    char loc4[60]="DB/";
    char loc2[60]="DB/user";
    char loc3[60]="DB/temp";
    char loc5[60]="DB/Mtemp";
    FILE *fp,*fps;
    char str[255][255],reciever[10],buff[255];
    int i=0,na_test=0;
    char user_na[10]="user";
    char mes_temp[10]="Mtemp";
    printf("USERNAME:\e[7;33m%s\n\e[m",Uname);
    printf("Enter the name of recevier:");
    scanf("%s",&reciever);
    Decryption(user_na);
    fp = fopen(loc2,"r+");
    while(getc(fp) != EOF ){//check if user donot exist already
        fscanf(fp,"%s",buff);
        if(strcmp(buff,reciever) == 0){
            na_test=1;
        }
    }
    fclose(fp);
    Encryption(user_na);
    if(na_test == 1){
        sleep(2);
    printf("Enter you message(message end with 'end'):\n");
    strcat(loc4,reciever);
    Decryption(mes_temp);
    fp = fopen(loc5, "w+");
    fprintf(fp,"\n");
    do{//loop to enter elts in str 
        i++;
        fgets(str[i], sizeof(str[i]), stdin);
        if((strcmp(str[i],"end")) == 10){
            break;
        }
        fprintf(fp,"%s",str[i]); 
    }while((strcmp(str[i],"end")) != 10);
    fprintf(fp,"From %s",Uname);
    fclose(fp);
    Encryption(mes_temp);
    sleep(1);
    int count =1,c;
    char ch;
    do{
            display11(count);
            c=getch();
            if(c == 97){
                count--;
            }
            if(c == 100){
                count++;
            }
            if(count == 0)
            count=2;
            if(count == 3)
            count=1;   
    }while(c != 10);
    if(count == 1){
        Decryption(mes_temp);
        fp = fopen(loc5,"r+");
        Decryption(reciever);
        fps = fopen(loc4,"a+");
        ch =fgetc(fp);
        while(ch != EOF){
            fputc(ch,fps);
            ch=fgetc(fp);
        }
        fclose(fps);
        Encryption(reciever);
        fclose(fp);
        Encryption(mes_temp);
        printf("Message sent successfully\n");
        sleep(1);
        printf("Enter to continue!!\n");
        i=getch();
        return 1;
    }else{
        printf("Message not send!\n");
        sleep(2);
        return 1;
    }

    }else{
        printf("\nThis accout does not exist!\n");
        sleep(2);
        return menu5();
    }
}

int display11(int n){
    switch(n){
        case 1:
          system("clear");
          printf("Do you want to send this message\n");
          printf("\e[7;34mYES\e[m     NO\n");
          break;
        case 2:
          system("clear");
          printf("Do you want to send this message\n");
          printf("YES     \e[7;34mNO\n\e[m");
          break;
        default:
        break;
    }
}
int display9(int n){
    switch(n){
        case 1:
          system("clear");
          printf("Do you want log out\n");
          printf("\e[7;34mYES\n\e[m");
          printf("NO\n");
          break;
        case 2:
          system("clear");
          printf("Do you want log out\n");
          printf("YES\n");
           printf("\e[7;34mNO\n\e[m");
          break;
        default:
        break;
    }
}
int Quit2(){
    int c,count=2;
    do{
            display9(count);
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
    printf("LOADING OUT\e[6m...\e[m\n");
    sleep(2);
    return 0;
    }else{
        return 1;
    }
}

int Quit3(){
    sleep(1);
    return 1;
}

int display5(int n){
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

int menu5(){
    int c,count=1;
    do{
        display5(count);
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
        return 1;
          break; 
          case 2:
        return 11;
          break;
        default:
        break;
    }
}