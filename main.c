#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "variables.h"
#include <string.h>

int main()
{
    probeli=1;
    fil = fopen("words.txt", "rt");
    if (fil == 0)
    {
        perror("Can’t open file for reading");  //перевірка файл на порожність
    }


    while(fread(&ch,sizeof(ch),1,fil)) //знайдемо кількість пробелів для розміру масиву з місцями пробілів
    {
        if(ch==' ')
        probeli++;
    }


    int probeli1[probeli];  //місця пробілів
    rewind(fil); int mer=0, mer1=0;
    while(fread(&ch,sizeof(ch),1,fil))
    {
        if(ch==' ')
        {
            probeli1[mer1]=mer; // запам'ятовуємо місця пробелів
            mer1++;
        }
        mer++;
    }

//здесь был цикл
    menu(75/2, 10, probeli1); //вивід меню

    return 0;
}
