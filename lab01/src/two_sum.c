#include "two_sum.h"

int two_sum(const int* nums, int n, int target, int* out_i, int* out_j) {
    if (!nums || n < 2 || !out_i || !out_j)
    {
        return 0;
    }
    
    for(int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(nums[j] + nums[i] == target)
            {
                *out_i = i;
                *out_j = j;
                return 1;
            }
        }
    }    
    //  - find i < j such that nums[i] + nums[j] == target
    //  - store indices in *out_i and *out_j
    //  - return 1 if found; otherwise return 0

    return 0;
}

//think about the time complexity and space complexity of your solution
