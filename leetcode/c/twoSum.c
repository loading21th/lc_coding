// Source: https://leetcode-cn.com/problems/two-sum


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i = 0, j = 0;
    int *retarr = malloc(2 * sizeof(int));
    for (i = 0; i < numsSize - 1; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                retarr[0] = i;
                retarr[1] = j;
                *returnSize = 2;
                return retarr;
            }
        }
    }
    return NULL;
}
