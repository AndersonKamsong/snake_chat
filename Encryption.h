#include<stdio.h>

void Encryption(char Uname[10]){
    char ch;
    FILE *fps,*fpt;
    char loc[60]="DB/";//loc is main folder location 
    char loc2[60]="DB/user";//loc2 is user info file
    char loc3[60]="DB/temp";//loc3 temp file for Encryption and Decryption
    strcat(loc,Uname);
    fps = fopen(loc,"r");
    fpt = fopen(loc3,"w");
    ch =fgetc(fps);
    while(ch != EOF){
        ch = ch+100;
        fputc(ch,fpt);
        ch=fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(loc,"w");
    fpt = fopen(loc3,"r");;
    ch =fgetc(fpt);
    while(ch != EOF){
        ch =fputc(ch,fps);
        ch =fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
}

void Decryption(char Uname[10]){
    char ch;
    FILE *fps,*fpt;
    char loc[60]="DB/";//loc is main folder location 
    char loc2[60]="DB/user";//loc2 is user info file
    char loc3[60]="DB/temp";//loc3 temp file for Encryption and Decryption
    strcat(loc,Uname);
    fps = fopen(loc,"r");
    fpt = fopen(loc3,"w");
    ch =fgetc(fps);
    while(ch != EOF){
        ch = ch-100;
        fputc(ch,fpt);
        ch=fgetc(fps);
    }
    fclose(fps);
    fclose(fpt);
    fps = fopen(loc,"w");
    fpt = fopen(loc3,"r");;
    ch =fgetc(fpt);
    while(ch != EOF){
        ch =fputc(ch,fps);
        ch =fgetc(fpt);
    }
    fclose(fps);
    fclose(fpt);
}