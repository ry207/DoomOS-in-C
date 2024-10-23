#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char message[] = "Type ? for a list of commands";
char name[] = "DoomOS";
char infocheck[] = "info";
char lscheck[] = "ls";
char exitcheck[] = "exit";
char cdcheck[] = "cd";
char cdotcheck[] = "cd..";
char helpcheck[] = "help";
char calcheck[] = "calc";
char echocheck[] = "echo";
char clearcheck[] = "clear";

char info[] = "\n\033[1;37m==========\n| DoomOS |\n==========\nWelcome to DoomOS!\033[0;37m\n\n";
char ls1[] = "\033[0;34mConfig  \033[1;37mconf  \033[0;34mDpkg  \033[1;37missue  \033[0;34mNginx  \033[1;37mshells  \033[0;34mSsh  User\033[0;37m\n";
char ls2[] = "\033[0;34mArduino projects  \033[1;37mATC-sim.conf  \033[0;34mBin  \033[1;37minfo.txt  \033[0;34mProjects  \033[1;37mimage_01.jpg  \033[0;34mPython  Cruise\033[0;37m\n";
char help[] = "\nCommands: ls, cd, cd.., info, echo, calc, help, clear, exit\n\n";

void calculator(){
    int a;
    int b;
    char choice[1];
    fputs("Enter a: ",stdout);
    scanf("%d", &a);
    fputs("Enter b: ",stdout);
    scanf("%d", &b);
    printf("1.add 2.sub 3.mult 4.div\n Enter 1-4:  ");
    scanf("%31s", &choice);
    if(!strcmp("1", choice)){
        int c = (a+b);
        printf("%d + %d = %d\n", a, b, c);
    }
    else if(!strcmp("2", choice)){
        int c = (a-b);
        printf("%d - %d = %d\n", a, b, c);
    }
    else if(!strcmp("3", choice)){
        int c = (a*b);
        printf("%d x %d = %d\n", a, b, c);
    }
    else if(!strcmp("4", choice)){
        float c = (a/b);
        printf("%d / %d = %.2f\n", a, b, c);
    }
    else{
        printf("Not a choice");
    }
}
void helprint(){
    printf("%s", help);
}
void infoprint(){
    printf("%s", info);
}
void lsprint1(){
    printf("%s", ls1);
}
void lsprint2(){
    printf("%s", ls2);
}

void cd(){
    char s2[25];
    for (;;){
        fputs("\033[0;34mDoomOS@User \033[1;37m$ ", stdout);
        scanf("%31s", s2);
        if (!strcmp(infocheck, s2)){
            infoprint();
        }
        else if(!strcmp(lscheck, s2)){
            lsprint2();
        }
        else if(!strcmp(cdotcheck, s2)){
            break;
        }
        else if(!strcmp(exitcheck, s2)){
            break;
        }
        else if(!strcmp(clearcheck, s2)){
            system("clear");
            printf("Type help for a list of commands\n");
        }
        else{
            puts("Not a command");
        }
    }
}

int main( void ){
    system("clear");
    char s2[25];
    char echo[25];
    printf("Type help for a list of commands\n");
    for(;;){
        fputs("\033[0;34mDoomOS \033[1;37m$ ", stdout);
        scanf("%31s", s2);

        if (!strcmp(infocheck, s2))
            infoprint();
        else if(!strcmp(lscheck, s2)){
            lsprint1();
        }
        else if(!strcmp(exitcheck, s2)){
            break;
        }
        else if(!strcmp(cdotcheck, s2)){
            printf("In root directory\n");
        }
        else if(!strcmp(cdcheck, s2)){
            cd();
        }
        else if(!strcmp(helpcheck, s2)){
            helprint();
        }
        else if(!strcmp(calcheck, s2)){
            calculator();
        }
        else if(!strcmp(echocheck, s2)){
            printf("\033[1;37m > ");
            scanf("%s", echo);
            printf("%s\n", echo);
        }
        else if(!strcmp(clearcheck, s2)){
            system("clear");
            printf("Type help for a list of commands\n");
        }
        else
            puts("Not a command");

    }
return 0;
}

