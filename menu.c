#include "menu.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "variables.h"
void gotoxy(const int X,const int Y) //Встановлює курсор на (Х,Y), Х по горизонталі, Y по вертикальному положенню
{
    HANDLE OutputHandle;
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufInfo;
    OutputHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(OutputHandle,&ScreenBufInfo);
    ScreenBufInfo.dwCursorPosition.X=X;
    ScreenBufInfo.dwCursorPosition.Y=Y;
    SetConsoleCursorPosition(OutputHandle,ScreenBufInfo.dwCursorPosition);
}
void sleep(int ms)  //створює паузу
{
    while (ms -- > 0)
    usleep(1000);
}
void menu(int x, int y, int *probeli1) //програма виводу головного меню
{
    system("cls");//очищення екрана
    const int n=3;
    int i;
    typedef char punkt[50];//введення типу змінної
    punkt k[]= {"1) guess one random word", "2) guess words in a row", "3) exit"};
    gotoxy((x-5), (y-6));
    puts("GUESSING GAME");
    for (i=0; i<=n-1; i++) //цикл для виведення пунктів меню
    {
        gotoxy(x-7, y-2+2*i);
        puts(k[i]);
    }
    sleep(50);
    printf("\n\n\nIf you want to continiue, make your choise(1, 2, or 3) : ");//діалогз користувачем
    scanf("%i",&h);
    system("cls");//очищення екрана
    if(h!=3)
    {
        printf("Game is simple.\n1) You have 15 points for a game. \n");
        printf("2) Every wrong letter is a lost point.\n");
        printf("3) If you lose all the points - the game is over.\n\n");
        if (h==1)
        {
            cicle(probeli1, 1); //функція для одного випадкового слова
        }
        else if (h==2)
        {
            cicle(probeli1, 2); //функція для ряду слів
        }
        sleep(70);
        menu(75/2, 10, probeli1);
    }
    if (h==3)
    {
        printf("End of the program.\n");
    }
    exit(1);//завершення роботи програми
}

