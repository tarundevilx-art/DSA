/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 #include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    
    int capacity = 100;
    int **result = malloc(capacity * sizeof(int *));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;

    // Sort the array
    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize - 3; i++) {

        // Skip duplicate first elements
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < numsSize - 2; j++) {

            // Skip duplicate second elements
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int left = j + 1;
            int right = numsSize - 1;

            while (left < right) {

                long long sum = (long long)nums[i] + nums[j]
                              + nums[left] + nums[right];

                if (sum == target) {

                    if (*returnSize >= capacity) {
                        capacity *= 2;
                        result = realloc(result, capacity * sizeof(int *));
                        *returnColumnSizes = realloc(
                            *returnColumnSizes,
                            capacity * sizeof(int)
                        );
                    }

                    result[*returnSize] = malloc(4 * sizeof(int));

                    result[*returnSize][0] = nums[i];
                    result[*returnSize][1] = nums[j];
                    result[*returnSize][2] = nums[left];
                    result[*returnSize][3] = nums[right];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
    }

    return result;
}