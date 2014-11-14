#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100

char *Convert_Int_To_Char(char *str, long int num)
{
        char *p = str;
        char temp;
        int choice = 0;
        int count = 0, i;
        
        memset(p, 0, sizeof(char) * MAXLINE);
        if(p == NULL)
        {
                //printf("creat pointer err\n");
                return NULL;
        }

        do
        {
            choice = num % 10;
            switch(choice)
            {
                case 0:
                        strcat(p, "0");
                        count++;
                        break;
                case 1:
                        strcat(p, "1");
                        count++;
                        break;
                case 2:
                        strcat(p, "2");
                        count++;
                        break;
                case 3:
                        strcat(p, "3");
                        count++;
                        break;
                case 4:
                        strcat(p, "4");
                        count++;
                        break;
                case 5:
                        strcat(p, "5");
                        count++;
                        break;
                case 6:
                        strcat(p, "6");
                        count++;
                        break;
                case 7:
                        strcat(p, "7");
                        count++;
                        break;
                case 8:
                        strcat(p, "8");
                        count++;
                        break;
                case 9:
                        strcat(p, "9");
                        count++;
                        break;
                default:
                        break;

            }
        }while((num = num / 10) > 0);

        for(i = 0; i < count/2; i++)
        {
            temp = p[i];
            p[i] = p[count - 1 - i];
            p[count - 1 - i] = temp;
        }
                        
        p[count] = '\0';
        return p;
        
}

int printChar(char *str)
{
    int len = strlen(str);
    int i = 0;

    for(i = 0; i < len; i++)
    {
            switch(str[i])
            {
                case '0':
                        printf("zero");
                        break;
                case '1':
                        printf("one");
                        break;
                case '2':
                        printf("two");
                        break;
                case '3':
                        printf("three");
                        break;
                case '4':
                        printf("four");
                        break;
                case '5':
                        printf("five");
                        break;
                case '6':
                        printf("six");
                        break;
                case '7':
                        printf("seven");
                        break;
                case '8':
                        printf("eight");
                        break;
                case '9':
                        printf("nine");
                        break;
                default:
                        break;

            }       

            if(i != len - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
    }

    return 0;
}

int main()
{
    char str[MAXLINE];
    char strSum[MAXLINE];
    int i = 0, len = 0, sum = 0;

    scanf("%s", str);

    len= strlen(str);

    for( i = 0; i < len; i++)
    {
        sum += str[i] - '0';
    }

    Convert_Int_To_Char( strSum, sum);
    printChar(strSum);

    return 0;
}


