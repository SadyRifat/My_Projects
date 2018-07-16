#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void print_Board(char board[3]);
int corner_move(int a,int b,int c,int d,int e,int f,int g,int h, int i,int pt);
int middle_move(int a,int b,int c,int d,int e,int f,int g,int h, int i,int pt);
int even_move(int a,int b,int c,int d,int e,int f,int g,int h, int i,int pt);
void win_game(char board[3],int u,int v);
void draw_game(char board[3],int u);
int terms_condition(int menu);
int shortcut(char board[3],int m,int n);
char name[25];
char board[10] = {'\0'};


int main()
{
    char board[10] = {'\0'};
    int pt,choice,menu=0,restart;

    system("COLOR 0A");
    printf("\n\n\n\n\n\n\n\t\tWelcome  to  TIK  TAC  TOE  game...");
    getch();
    system("cls");

    printf("\n\n\n          Enter player's name:::  ");
    gets(name);
    system("cls");

    menu:{
    printf("MENU:::\n\t\t<1> Play Game.\n\n\t\t<2> Terms and condition.\n\n\t\tAny key to exit\n\nEnter your choice:  ");
    choice=getch();
    system("cls");
    }
    if(choice =='1') {
            goto play;
    }
    else if (choice =='2') {
        menu=terms_condition(menu);
        if (menu =='1') goto menu;
    }
    else goto exit;

    play:{
    print_Board(board);
    printf("%s's turn: ",name);
    scanf("%d",&pt);
    switch (pt)
    {
        case 1: {
            int a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8,i=9;
            corner_move(a,b, c, d, e,f, g, h, i,pt);
            break;
        }
        case 2: {
                int a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8,i=9;
                even_move(a,b, c, d, e,f, g, h, i,pt);
                break;
            }
        case 3: {
            int a=3,b=6,c=9,d=2,e=5,f=8,g=1,h=4,i=7;
            corner_move(a,b, c, d, e,f, g, h, i,pt);
            break;
        }
        case 4: {
                int a=7,b=4,c=1,d=8,e=5,f=2,g=9,h=6,i=3;
                even_move(a,b, c, d, e,f, g, h, i,pt);
                break;
            }
        case 5: {
            int a=1,b=2,c=3,d=4,e=5,f=6,g=7,h=8,i=9;
            middle_move(a,b, c, d, e,f, g, h, i,pt);
            break;
            }
        case 6: {
                int a=3,b=6,c=9,d=2,e=5,f=8,g=1,h=4,i=7;
                even_move(a,b, c, d, e,f, g, h, i,pt);
                break;
            }
        case 7: {
            int a=7,b=4,c=1,d=8,e=5,f=2,g=9,h=6,i=3;
            corner_move(a,b, c, d, e,f, g, h, i,pt);
            break;
            }
        case 8: {
                int a=9,b=8,c=7,d=6,e=5,f=4,g=3,h=2,i=1;
                even_move(a,b, c, d, e,f, g, h, i,pt);
                break;
            }
        case 9: {
            int a=9,b=8,c=7,d=6,e=5,f=4,g=3,h=2,i=1;
            corner_move(a,b, c, d, e,f, g, h, i,pt);
            break;
            }
    }
    printf("\n\n\nPress  <1>  for play again.\n\nPress  <2>  for back to the menu\n\nPress any key to exit.");
    printf("\n\nEnter your choice:   ");
    restart = getch();
    printf("\n");
    if(restart == '1'){ goto play; system("cls");}
    else if(restart == '2') {goto menu;  system("cls");}
    else goto exit;
    }
    exit:{}

}//main

void print_Board(char board[3])
{
    system("cls");
    printf("\n\n\n\n\n\t\t\t  %c  |  %c  |  %c\n", board[1], board[2], board[3]);
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t-----|-----|-----\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c\n", board[4], board[5], board[6]);
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t-----|-----|-----\n");
    printf("\t\t\t     |     |     \n");
    printf("\t\t\t  %c  |  %c  |  %c\n\n", board[7], board[8], board[9]);

}

int corner_move(int a,int b,int c,int d,int e,int f,int g,int h, int i,int pt)
{
    char board[10] = {'\0'};
    pt=shortcut(board,a,e);
    if(pt==i){
            pt=shortcut(board,i,b);

            if(pt!=h) win_game(board,pt,h);

            else if(pt==h){
                    pt=shortcut(board,h,g);

            if(pt!=c) win_game(board,pt,c);

            else if(pt==c){
                pt=shortcut(board,c,f);
                draw_game(board,d);
                board[c]='X';
            }
        }
    }//pt 9
    else if(pt==b) {
            pt=shortcut(board,b,c);
        if(pt!=g) win_game(board,pt,g);

        else if(pt==g) {
            pt=shortcut(board,g,d);

            if(pt!=f) win_game(board,pt,f);

            else if(pt==f) {
                pt=shortcut(board,f,i);
                draw_game(board,h);
            }
        }
    }//pt 2
     else if(pt==c) {
        pt=shortcut(board,c,b);
        if(pt!=h) win_game(board,pt,h);
        else if(pt==h) {
           pt=shortcut(board,h,f);
            if(pt!=d) win_game(board,pt,d);
            else if(pt==d) {
                pt=shortcut(board,d,g);
                draw_game(board,i);
            }
        }
    }
    else if(pt==d) {
        pt=shortcut(board,d,g);
            if(pt!=c) win_game(board,pt,c);

        else if(pt==c) {
            pt=shortcut(board,c,b);
            if(pt!=h) win_game(board,pt,h);

            else if(pt==h) {
                pt=shortcut(board,h,i);
                draw_game(board,f);
            }
        }
    }
    else if(pt==g) {
        pt=shortcut(board,g,d);
        if(pt!=f) win_game(board,pt,f);

        else if(pt==f) {
           pt=shortcut(board,f,b);
            if(pt!=h) win_game(board,pt,h);

            else if(pt==h) {
                pt=shortcut(board,h,i);
                draw_game(board,c);
            }
        }
    }

    else if(pt==f) {
        pt=shortcut(board,f,i);
        if(pt==b) {
            pt=shortcut(board,b,c);
            if(pt!=g){
                win_game(board,pt,g);
            }
            else if(pt==g) {
                pt=shortcut(board,g,h);
                draw_game(board,d);
            }
        }
        else if(pt==c) {
            pt=shortcut(board,c,b);
            if(pt!=h){
                win_game(board,pt,h);
            }
            else if(pt==h) {
                pt=shortcut(board,h,d);
                draw_game(board,g);
            }
         }
         else if(pt==d) {
            pt=shortcut(board,d,g);
            if(pt!=h) win_game(board,pt,h);
            else if(pt==h) win_game(board,pt,c);
        }
    }
     else if(pt==h) {
        pt=shortcut(board,h,i);
        if(pt==b) {
            pt=shortcut(board,b,c);
            if(pt!=g){
                win_game(board,pt,g);
            }
            else if(pt==g) {
                win_game(board,g,f);
            }
         }
         else if(pt==c) {
            pt=shortcut(board,c,b);
            if((pt==f)||(pt==g)){
                pt=shortcut(board,pt,d);
                draw_game(board,pt);
            }
            else if(pt==d){
                pt=shortcut(board,d,g);
                draw_game(board,f);
            }
         }
         else if(pt==d) {
            pt=shortcut(board,d,g);
            if(pt!=c) win_game(board,pt,c);
            else if(pt==c) {
                pt=shortcut(board,c,b);
                if(pt!=h)  win_game(board,pt,h);
                else if(pt==h){
                    pt=shortcut(board,h,i);
                    draw_game(board,f);
                }
            }
        }
    }
}



int even_move(int a,int b,int c,int d,int e,int f,int g,int h, int i,int pt)
{
    char board[10] = {'\0'};
    pt=shortcut(board,b,e);
    if(pt==a){
    pt=shortcut(board,a,c);
    if(pt!=g) win_game(board,pt,g);
        else if(pt==g){
        pt=shortcut(board,g,d);
        if(pt!=f) win_game(board,pt,f);
            else if(pt==f) {
            pt= shortcut(board,pt,h);
            draw_game(board,pt);
            }
        }
    }
    else if(pt==c){
        pt=shortcut(board,c,a);
        if(pt!=i) win_game(board,pt,i);
        else if(pt==i){
            pt=shortcut(board,i,f);
            if(pt!=d) win_game(board,pt,d);
            else if(pt==d) {
                pt= shortcut(board,pt,h);
                draw_game(board,pt);
            }
        }
    }
    else if(pt==g){
        pt=shortcut(board,g,a);
        if(pt!=i) win_game(board,pt,i);
        else if (pt==i){
            pt=shortcut(board,pt,h);
            if(pt==f) {
                pt=shortcut(board,f,c);
                draw_game(board,pt);
            }
            else if((pt==d)||(pt==c)){
                pt=shortcut(board,pt,f);
                draw_game(board,pt);
            }
        }
    }
    else if(pt==i){
        pt=shortcut(board,i,c);
        if(pt!=g)  win_game(board,pt,g);
        else if (pt==g){
            pt=shortcut(board,pt,h);
            if(pt==d) {
               pt=shortcut(board,d,a);
                draw_game(board,pt);
            }
            else if((pt==f)||(pt==a)){
                pt=shortcut(board,pt,d);
                draw_game(board,pt);
            }
        }
    }
    else if(pt==d){
         pt=shortcut(board,d,a);
         if(pt!=i) win_game(board,pt,i);
         else if(pt==i){
            pt=shortcut(board,i,c);
            if(pt!=g){
                win_game(board,pt,g);
            }
            else if(pt==g){
                pt=shortcut(board,g,h);
                draw_game(board,f);
            }
        }
    }
    else if(pt==f){
        pt=shortcut(board,f,c);
        if(pt!=g) win_game(board,pt,g);
        else if(pt==g){
            pt=shortcut(board,g,a);
            if(pt!=i) win_game(board,pt,i);
            else if(pt==i){
                pt=shortcut(board,i,h);
                draw_game(board,d);
            }
        }
    }
    else if(pt==h){
        pt=shortcut(board,h,d);
        if(pt!=f)win_game(board,pt,f);
        else if(pt==f){
            pt=shortcut(board,f,a);
            if(pt==i)  win_game(board,pt,f);
            else win_game(board,pt,i);
        }
    }
}


int middle_move(int a,int b,int c,int d,int e,int f,int g,int h, int i,int pt)
{
    char board[10] = {'\0'};
    pt=shortcut(board,e,a);
    if(pt==b){
        jump:{
            pt=shortcut(board,b,h);
            if(pt==c){
                pt=shortcut(board,c,g);
                if(pt!=i)   win_game(board,pt,i);
                else if (pt==i) win_game(board,pt,d);
            }
            else if(pt==d){
                pt=shortcut(board,d,f);
                if(pt==c){
                    pt=shortcut(board,c,g);
                    draw_game(board,i);
                }
                else if(pt==g) {
                    pt=shortcut(board,g,c);
                    draw_game(board,i);
                }
                else if(pt==i){
                    pt=shortcut(board,i,c);
                    draw_game(board,g);
                }
            }
            else if(pt==f){
                pt=shortcut(board,f,d);
                if(pt!=g)  win_game(board,pt,g);
                else if(pt==g){
                    pt=shortcut(board,g,c);
                    if(pt!=b){
                    draw_game(board,pt);
                }
            }
        }
        else if(pt==g){
            pt=shortcut(board,g,c);
            if(pt!=f){
                pt=shortcut(board,pt,f);
                draw_game(board,pt);
            }
            else{
                pt=shortcut(board,pt,d);
                draw_game(board,pt);
            }
        }
        else if(pt==i){
            pt=shortcut(board,i,d);
            if(pt!=g){
                win_game(board,pt,g);
            }
            else if(pt==g){
                pt=shortcut(board,g,c);
                draw_game(board,f);
                }
            }
        }
    }
    else if(pt==d){
        d=2;g=3;b=4;h=6;c=7;f=8;
        goto jump;
    }
    else if(pt==c){
        jump2:{
            pt=shortcut(board,c,g);
            if(pt!=d)  win_game(board,pt,d);
            else if(pt==d){
                pt=shortcut(board,d,f);
                if(pt!=h){
                pt=shortcut(board,pt,h);
                draw_game(board,pt);
                }
                else if(pt==h){
                    pt=shortcut(board,h,b);
                    draw_game(board,pt);
                }
            }
        }
    }
    else if(pt==g){
        d=2;g=3;b=4;h=6;c=7;f=8;
        goto jump2;
    }
    else if(pt==f){
        jump3:{
            pt=shortcut(board,f,d);
            if(pt!=g) win_game(board,pt,g);
            else if(pt==g){
                pt=shortcut(board,g,c);
                if(pt!=b)  win_game(board,pt,b);
                else if(pt==b){
                    pt=shortcut(board,b,h);
                    draw_game(board,i);
                }
            }
        }
    }
    else if(pt==h){
        d=2;g=3;b=4;h=6;c=7;f=8;
        goto jump3;
    }
    else if(pt==i){
        pt=shortcut(board,i,c);
        if(pt!=b)    win_game(board,pt,b);
        else if(pt==b){
            pt=shortcut(board,b,h);
            if(pt!=f){
                pt=shortcut(board,pt,f);
               draw_game(board,pt);
            }
            else if(pt==f){
                pt=shortcut(board,pt,d);
                draw_game(board,pt);
            }
        }
    }
}
void draw_game(char board[3],int u)
{
    board[u]='0';
    print_Board(board);
    printf("Game draw...!!!\n\n");
}
void win_game(char board[3],int u,int v)
{
    board[u]='0';
    board[v]='X';
    print_Board(board);
    printf("Computer win...!!!\n\n");
}



int shortcut(char board[3],int m,int n)
{
    int pt;
    board[m]='0';
    board[n]='X';
    print_Board(board);
    printf("%s's turn:  ",name);
    scanf("%d",&pt);
    return pt;
}

int terms_condition(int menu)
{
    printf("\n  1..  Don't overwrite on fill-up blocks.\n  2.. You will play with '0' symbol\n\n");
    printf("(If player move in the fill up blocks player may be loose or game terminated.)");
    printf("\n\n\n  Game format:\n");
    printf("\n\t\t 1 | 2 | 3\n");
    printf("\t\t---|---|---\n");
    printf("\t\t 4 | 5 | 6 \n");
    printf("\t\t---|---|---\n");
    printf("\t\t 7 | 8 | 9\n\n");
    printf("\n\nPress  <1>  for back to the menu.\n\nAny to exit.  ");
    menu=getch();
    system("cls");
    return menu;
}




