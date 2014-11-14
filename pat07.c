#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

typedef struct _seq
{
    int first;
    int last;
    int sum;
}seq;

int getFirstPosIndex(int *arr, int len)
{
    int i = 0, flag = 0, posFlag = 0, ret;
        
    for( i = 0; i < len; i++ )
    {
         if( arr[i] > 0 )
         {
         	posFlag = i;
         	
         	if( posFlag == 0 )
         	{
         		return posFlag;
         	}
         	
         	for( i = 0; i < posFlag; i++ )
         	{
         		if( arr[posFlag - i - 1] < 0 )
         		{
         			return (posFlag - i) ;
         		}
         		else if( arr[posFlag - i - 1] == 0 && (posFlag - 1 - i) == 0 )
         		{
         			return 0;
         		}

         	}
         }
         
         if( arr[i] == 0 )
         {
             flag = 1;
         }
         
    } 
    
    if( flag == 0 )
    {
        printf("0 %d %d\n", arr[0], arr[len-1]);
    }
    else
    {
        printf("0 0 0\n");
    }
    
    return -1;    
}

int getPosSeq(seq *posSeq, int startPosFlag, int *curIndex, int *arr, int arrLen)
{
    int i = 0, flag = 0;
    
    if( startPosFlag >= arrLen )
    {
        return -1;
    }
    
    posSeq->sum = 0;
    posSeq->first = arr[startPosFlag];
    for( i = startPosFlag; i < arrLen; i++ )
    {
        if( arr[i] == 0 && flag == 0 )
        {
            continue;
        }
        
        if( (arr[i] == 0 && flag == 1) 
        	|| arr[i] < 0 )
        {
        	break;
        }
        
        if( flag == 0 && arr[i] > 0 )
    	 {
    	 	flag = 1;
    	 }
    	 
        if( arr[i] > 0 )
        {
            posSeq->sum += arr[i];  
        }
           
    }
    
    posSeq->last = arr[i-1];
    *curIndex = i;
    return 0;
}

int getNegSeq(seq *negSeq, int startNegFlag, int *curIndex, int *arr, int arrLen)
{
    int i = 0, flag = 0;
    
    if( startNegFlag >= arrLen )
    {
        return -1;
    }
    
    negSeq->sum = 0;
    negSeq->first = arr[startNegFlag];
    for( i = startNegFlag; i < arrLen; i++ )
    {
         if( arr[i] == 0 && flag == 0 )
         {
             continue;
         }
         
        if( (arr[i] == 0 && flag == 1) 
        	|| arr[i] > 0 )
        {
        	break;
        }
        
        if( flag == 0 && arr[i] < 0 )
    	 {
    	 	flag = 1;
    	 }
    	 
        if( arr[i] < 0 )
        {
            negSeq->sum += arr[i];  
        }           
    }
    
    negSeq->last = arr[i-1];
    *curIndex = i;
    return 0;
}

int procs(int *arr, int len)
{
    int i = 0, firstPosFlag = -1, curIndex = 0, flag = 0, start = 0;
    int lastStart = 0, lastEnd = 0,speFlag = 0;
    seq minPosSeq, tempPosSeq, tempNegSeq, lastPosSeq, lastNegSeq;
    
    memset(&minPosSeq, 0, sizeof(seq));
    memset(&tempPosSeq, 0, sizeof(seq));
    memset(&tempNegSeq, 0, sizeof(seq));
    memset(&lastNegSeq, 0, sizeof(seq));
    memset(&lastPosSeq, 0, sizeof(seq));
    
    if( (firstPosFlag = getFirstPosIndex(arr, len)) < 0 )
    {
        return 0;
    }
    
    getPosSeq(&minPosSeq, firstPosFlag, &curIndex, arr, len);
    
    while( curIndex < len )
    {
        getNegSeq(&tempNegSeq, curIndex, &curIndex, arr, len);
        //printf("temp neg:%d %d %d\n", tempNegSeq.first, tempNegSeq.last, tempNegSeq.sum);
        if( curIndex == len )
    	 {
    	 	break;
    	 }
        getPosSeq(&tempPosSeq, curIndex, &curIndex, arr, len);
        //printf("temp pos:%d %d %d\n", tempPosSeq.first, tempPosSeq.last, tempPosSeq.sum);
        
        if( !start )
        {
        	memcpy(&lastPosSeq, &minPosSeq, sizeof(seq));
        	start = 1;
        }
    
        if( 0 == flag )
    	 {
            if( tempPosSeq.sum + tempNegSeq.sum > 0 )
            {
                if( tempNegSeq.sum + lastPosSeq.sum > 0 )
                {
                    minPosSeq.last = tempPosSeq.last;
                    minPosSeq.sum += (tempPosSeq.sum + tempNegSeq.sum);
                }
                else if( tempNegSeq.sum + lastPosSeq.sum < 0 )
                {
            	    memcpy(&minPosSeq, &tempPosSeq, sizeof(seq));
                }
                else if( tempNegSeq.sum + lastPosSeq.sum == 0 )
                {
                    minPosSeq.first = lastPosSeq.first;
                    minPosSeq.last = tempPosSeq.last;
                    minPosSeq.sum = tempPosSeq.sum;                    
                }
            }        
            else if( tempPosSeq.sum > minPosSeq.sum )
            {
                   memcpy(&minPosSeq, &tempPosSeq, sizeof(seq));           
            }
            else if( tempPosSeq.sum + tempNegSeq.sum == 0 )
            {
                 lastStart = minPosSeq.first;
                 lastEnd = minPosSeq.last;
                 speFlag = 2;    //+c -A +A -B +B+n
            }
            else
            {
               flag = 1;
               //start = 1;
            }	           	 	
    	 }
    	 else
        {
            if( lastPosSeq.sum + tempNegSeq.sum > 0 
            	&& lastPosSeq.sum + tempNegSeq.sum + tempPosSeq.sum > minPosSeq.sum)
            {
                minPosSeq.first = lastPosSeq.first;
                minPosSeq.last = tempPosSeq.last;
                minPosSeq.sum = tempPosSeq.sum + tempNegSeq.sum + lastPosSeq.sum;
                flag = 0;
            }
            else if( lastPosSeq.sum + tempNegSeq.sum < 0 
            	&& tempPosSeq.sum > minPosSeq.sum )
        	 {
                memcpy(&minPosSeq, &tempPosSeq, sizeof(seq)); 
                flag = 0;       	 	
        	 }
            else if( lastPosSeq.sum + tempNegSeq.sum == 0
                 && tempPosSeq.sum > minPosSeq.sum )
             {
                 minPosSeq.first = lastPosSeq.first;
                 minPosSeq.last = tempPosSeq.last;
                 minPosSeq.sum = tempPosSeq.sum;
                 flag = 0;
             }	 	
        }
        
        if( flag == 0 )
        {
            memcpy(&lastPosSeq, &minPosSeq, sizeof(seq));
        }
        else
        {
            memcpy(&lastPosSeq, &tempPosSeq, sizeof(seq));
        }
  	    //memcpy(&lastPosSeq, &tempPosSeq, sizeof(seq));
	    memcpy(&lastNegSeq, &tempNegSeq, sizeof(seq));
	    //printf("%d %d %d\n", minPosSeq.sum, minPosSeq.first, minPosSeq.last);
    }
    
    printf("%d %d %d\n", minPosSeq.sum, minPosSeq.first, minPosSeq.last);
    
    return 0;
}

int main()
{
    int num, i;
    int *arr = NULL;
    
    scanf("%d", &num);
    arr = (int *)malloc( sizeof(int) * num );
    
    for( i = 0; i < num; i++ )
    {
         scanf("%d", arr+i);
    }
    
    procs(arr, num);
    //while(1);
    return 0;
}
