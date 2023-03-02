#ifndef __CONIO4LINUX_H
#define __CONIO4LINUX_H

#include <stdio.h>//necesaria
#include <unistd.h>//necesario
#include <fcntl.h>
#include <termios.h>//necesaria


#define BLACK        0
#define BLUE         1
#define GREEN        2
#define CYAN         3
#define RED          4
#define MAGENTA      5
#define BROWN        6
#define LIGHTGRAY    7
#define DARKGRAY     8
#define LIGHTBLUE    9
#define LIGHTGREEN   10
#define LIGHTCYAN    11
#define LIGHTRED     12
#define LIGHTMAGENTA 13
#define YELLOW       14
#define WHITE        15
#define BLINK        128

int bgc=40;

void clreol(){
      printf("\033[K");
      }
      
    void insline(){
      printf( "\x1b[1L");
      }
  
    void delline(){
      printf( "\033[1M");
      }

    void gotoxy(int x,int y){
      printf("\033[%d;%df",y,x);
      }
      
    void clrscr(){
      printf( "\033[%dm\033[2J\033[1;1f",bgc);
      }
      
    void textbackground(int color){
      switch(color%16){
	  case BLACK:          bgc=40;break;
	  case BLUE:           bgc=44;break;
	  case GREEN:          bgc=42;break;
	  case CYAN:           bgc=46;break;
	  case RED:            bgc=41;break;
	  case MAGENTA:        bgc=45;break;
	  case BROWN:          bgc=43;break;
	  case LIGHTGRAY:      bgc=47;break;
	  case DARKGRAY:       bgc=40;break;
	  case LIGHTBLUE:      bgc=44;break;
	  case LIGHTGREEN:     bgc=42;break;
	  case LIGHTCYAN:      bgc=46;break;
	  case LIGHTRED:       bgc=41;break;
	  case LIGHTMAGENTA:   bgc=45;break;
	  case YELLOW:         bgc=43;break;
	  case WHITE:          bgc=47;break;
	}
      }

    void textcolor(short color){  
      switch(color%16){
	  case BLACK:          printf("\033[0;%d;%dm",30,bgc);break;
	  case BLUE:           printf("\033[0;%d;%dm",34,bgc);break;
	  case GREEN:          printf("\033[0;%d;%dm",32,bgc);break;
	  case CYAN:           printf("\033[0;%d;%dm",36,bgc);break;
	  case RED:            printf("\033[0;%d;%dm",31,bgc);break;
	  case MAGENTA:        printf("\033[0;%d;%dm",35,bgc);break;
	  case BROWN:          printf("\033[0;%d;%dm",33,bgc);break;
	  case LIGHTGRAY:      printf("\033[0;%d;%dm",37,bgc);break;
	  case DARKGRAY:       printf("\033[1;%d;%dm",30,bgc);break;
	  case LIGHTBLUE:      printf("\033[1;%d;%dm",34,bgc);break;
	  case LIGHTGREEN:     printf("\033[1;%d;%dm",32,bgc);break;
	  case LIGHTCYAN:      printf("\033[1;%d;%dm",36,bgc);break;
	  case LIGHTRED:       printf("\033[1;%d;%dm",31,bgc);break;
	  case LIGHTMAGENTA:   printf("\033[1;%d;%dm",35,bgc);break;
	  case YELLOW:         printf("\033[1;%d;%dm",33,bgc);break;
	  case WHITE:          printf("\033[1;%d;%dm",37,bgc);break;
	}
      }
    
    int ungetch(int ch){
      return ungetc(ch, stdin);
      }
    
    int getch_echo(int echo){
      struct termios oldt, newt;
      int ch;
      tcgetattr( STDIN_FILENO, &oldt );
      newt = oldt;
      newt.c_lflag &= ~ICANON;
      if(echo)
	      newt.c_lflag &=  ECHO;
      else
	      newt.c_lflag &= ~ECHO;
      tcsetattr( STDIN_FILENO, TCSANOW, &newt );
      ch = getchar();
      tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
      return ch;
      }
      
    int getch(){
      getch_echo(0);
      }
      
    int getche(){
      getch_echo(1);
      }
      
    int wherexy(int x,int y){
      printf("\033[6n");
      if(getch() != '\x1B') return 0;
      if(getch() != '\x5B') return 0;
      int in;
      int ly = 0;
      while((in = getch()) != ';')
      ly = ly * 10 + in - '0';	
      int lx = 0;
      while((in = getch()) != 'R')
      lx = lx * 10 + in - '0';
      x = lx;
      y = ly;
      }

    int wherex(){
      int x=0,y=0;
      wherexy(x,y);
      return x;
      }
      
    int wherey(){
      int x=0,y=0;
      wherexy(x,y);
      return y;
      } 

    int kbhit(){
      struct termios oldt, newt;
      int ch;
      int oldf;    
      tcgetattr(STDIN_FILENO, &oldt);
      newt = oldt;
      newt.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(STDIN_FILENO, TCSANOW, &newt);
      oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
      fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);    
      ch = getchar();    
      tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
      fcntl(STDIN_FILENO, F_SETFL, oldf);    
      if(ch != EOF){
	ungetc(ch, stdin);
	return 1;
	}    
      return 0;
      }
    
    int putch(const char c){
      printf("%c",c);
      return (int)c;
      }
      
    int cputs(const char*str){
      printf(str);
      return 0;
      }
        
    char*getpass(const char*prompt){
      //implementada en unistd.h
      }
      
    
    

    #endif