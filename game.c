#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include "variables.h"
void cicle(int *probeli1, int a)
{
    int stock,s=0;
    int other, some=0;
    if(a==1) //варіант програми з одним словом
    {
        other=rand()%(probeli-1);
        stock=other+1;
    }
    else if(a==2)  //варіант програми з рядом слів
    {
        stock=probeli-1;
        other=0;
    }
    for(int i=other; i<stock;i++)
    {
        if(s>=15)  //перевірка чи кількість балів впала до 0 з 15
        {
            break;
        }
        int pro=probeli1[i]+1;
        int letters=0;
        rewind(fil);
        fseek(fil, sizeof(char)*pro, SEEK_SET); //встановлюємо вказівник на поточне слово
        while(fread(&ch,sizeof(ch),1,fil) && ch!=' ')//знайдемо кількість літер у слові для розміру масиву зі словом
        {
            letters++;
        }

        if(letters<2)
        {
            break;
        }
        if(some>0)
        {
            system("cls");
        }
        printf("\n\n%d) word:\n", i+1);
        //printf("letters is %d", letters);
        rewind(fil);
        fseek(fil, sizeof(char)*pro, SEEK_SET);
        char mas[letters]; int var=0;
        mas[var]=ch;
        while(fread(&ch,sizeof(ch),1,fil) && ch!=' ')
        {
            var++;
            mas[var]=ch;
        }
        char m;
        char mas1[strlen(mas)];
        int cic;

        if(letters<5)
        {
            cic=strlen(mas)-1;
        }
        else
        {
            cic=strlen(mas);
        }

        for(int i=0, j=0;i<cic;i++) // заповнення масива з невідомим словом, де замість літер штрихи
        {
            if(mas[i]!="\0")
            {
                if(mas[i]!=' ')
                {
                    mas1[j]='|';     //заповнення додаткового масива прочерками
                    //printf("%c", mas1[j]);
                    j++;
                }
                //printf("%c", mas[i]);
            }
            else
            {
                break;
            }
        }

        printf("\n");

        int dop=strlen(mas1);

        for(int i=0;i<strlen(mas1);i++)
        {
            printf("%c", mas1[i]);
        }

        for(int i=0, flag=0;i<dop;)  //цикл для перевірки введеної летери на її місце в масиві
        {
            printf("\n");gets(&m);
            if(s>=15)
            {
                break;
            }

            int f1=0;
            printf("\n");
            for(int j=1;j<=dop;j++)
            {
                if(m==mas[j] && mas1[j-1]!=m)
                {
                    mas1[j-1]=m;
                    i++;
                    flag=1;
                }
            }

            if(flag==1)
            {
                for(int i1=0;i1<dop;i1++)
                {
                    printf("%c", mas1[i1]);
                }
                flag=0;
            }
            else
            {
                s++;
            }
        }
        some++;
    }
    return 0;
}
