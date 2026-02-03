#include "three_sum_sorted.h"

int three_sum_zero_sorted_one(const int* nums, int n, int* out_i, int* out_j, int* out_k) {
    if (!nums || !out_i || !out_j || !out_k || n < 3) return 0;

    for(int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if(nums[j] + nums[i] + nums[k] == 0)
                {
                    *out_i = i;
                    *out_j = j;
                    *out_k = k;
                    return 1;
                }
            }
        }
    }    

    return 0;
}
