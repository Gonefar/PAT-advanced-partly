#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int initCardOrder(char card[54][4], int num)
{
    int i = 1;

    for( i = 1; i <= 9; i++ )
    {
        card[i-1][0] = 'S';
        card[i-1+13][0] = 'H';
        card[i-1+26][0] = 'C';
        card[i-1+39][0] = 'D';
        
        card[i-1+13][1] = card[i-1+26][1] = card[i-1+39][1] = card[i-1][1] = i+48;
        card[i-1+13][2] = card[i-1+26][2] = card[i-1+39][2] = card[i-1][2] = '\0';
    }

    for( i = 10; i <= 13; i++ )
    {
        card[i-1][0] = 'S';
        card[i-1+13][0] = 'H';
        card[i-1+26][0] = 'C';
        card[i-1+39][0] = 'D';  
        
        card[i-1+13][1] = card[i-1+26][1] = card[i-1+39][1] = card[i-1][1] = '1';
        card[i-1+13][2] = card[i-1+26][2] = card[i-1+39][2] = card[i-1][2] = i +38;
        card[i-1+13][3] = card[i-1+26][3] = card[i-1+39][3] = card[i-1][3] = '\0';
    }

    card[52][0] = card[53][0] = 'J';
    card[52][1] = '1';
    card[53][1] = '2';
    card[52][2] = card[53][2] = '\0';

    return 0;
}

int shuffling(char card[54][4], int order[])
{
    char temp[54][4];
    int i = 0, index;
    
    for( i = 0; i < 54; i++ )
    {
        index= order[i];
        strcpy(temp[index-1], card[i]);
        //printf("(cur-next:%s %s %d %d) ", cur, temp, index, order[index-1]);
    }

    memcpy(card, temp, sizeof(char)*54*4);
    return 0;
}

int showCard(char card[54][4])
{
    int i = 0;

    for(i = 0; i < 54; i++ )
    {
        if( 53 == i )
        {
            printf("%s", card[i]);
        }
        else
        {
            printf("%s ", card[i]);
        }
    }
    printf("\n");

    return 0;
}

int showOrder(int order[])
{
    int i = 0;

    for(i = 0; i < 54; i++ )
    {
        printf("%d ", order[i]);
        if( (i+1) % 10 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");

    return 0;    
}

int main()
{
    int i = 0, repeat;
    int order[54];
    char card[54][4];

    scanf("%d", &repeat);
    
    for( i = 0; i < 54; i++ )
    {
        scanf("%d", order+i);
    }

    //showOrder(order);
    initCardOrder(card, 0);
    //showCard(card);
    for( i = 0; i < repeat; i++ )
    {
        shuffling(card, order);
        //showCard(card);
    }

    showCard(card);
    
    return 0;
}

