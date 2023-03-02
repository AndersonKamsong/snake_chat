#include<stdio.h>
#include<sys/stat.h>
#include<menu.h>

int main(){
    int i=0;
    char name[10];
    char user_na[10]="user";
    char loc[60]="DB/";//loc is main folder location 
    char loc2[60]="DB/user";//loc2 is user info file
    char loc3[60]="DB/temp";//loc3 temp file for Encryption and Decryption
    char loc5[60]="DB/Mtemp";//loc3 temp file for message sending
    char loc6[60]="DB/User_list";
    mkdir(loc,0777);//create the main folder
    FILE *fp;
    fp = fopen(loc2,"a+");//mode "a+" is create the user info file 
    fclose(fp);
    fp = fopen(loc3,"a+");//mode "a+" is create the temp file
    fclose(fp);
    fp = fopen(loc5,"w");//mode "w" is create the Message temp file
    fclose(fp);
    fp = fopen(loc6,"a+");//mode "a+" is create the file contain user all list of user 
    fclose(fp);
    display_cover();
    do{
    switch(i){
        case 0:
        i=menu1(name);
        break;
        case 1:
        i=menu2(name);
        break;
        case 3:
        i=menu1(name);
        break;
        case 4:
        i=menu2(name);
        break;
        default:
        break;
    }
    if(i==10)
    i=3;
    if(i==11)
    i=4;
    }while(i != 9);
}