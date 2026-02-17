#include "Student.h"
#include <stdlib.h>
#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int* ans = (int*)malloc((size_t)digitsSize * sizeof(int));
    for (int i = 0; i < digitsSize; i++)
    {
        ans[i] = digits[i];
    }
    

    for (int i = 1; i <= digitsSize; i++)
    {
        if((ans[digitsSize - i]) < 9)
        {
            ans[digitsSize - i] += 1;
            *returnSize = digitsSize;
            return ans;
        }
        else
            ans[digitsSize - i] = 0;
    }
    digitsSize += 1;
    *returnSize = digitsSize;
    int* digits2 = (int*)malloc(*returnSize *sizeof(int));
    digits2[0] = 1;
    for (int i = 1; i < digitsSize; i++)
    {
        digits2[digitsSize - i] = 0;
    }
    return digits2;
}