#include <stdlib.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

void backtrack(int *nums, int numsSize, int *used,
               int *current, int **result,
               int *returnSize, int *col, int depth) {
    if (depth == numsSize) {
        result[*returnSize] = malloc(numsSize * sizeof(int));
        memcpy(result[*returnSize], current,
               numsSize * sizeof(int));
        col[*returnSize] = numsSize;
        (*returnSize)++;
        return;
    }

    for (int i = 0; i < numsSize; i++) {
        if (used[i]) continue;

        // Skip duplicate choices at the same level
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
            continue;

        used[i] = 1;
        current[depth] = nums[i];

        backtrack(nums, numsSize, used, current,
                  result, returnSize, col, depth + 1);

        used[i] = 0;
    }
}

int** permuteUnique(int* nums, int numsSize,
                    int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;

    int maxPermutations = 1;
    for (int i = 2; i <= numsSize; i++)
        maxPermutations *= i;

    int **result = malloc(maxPermutations * sizeof(int *));
    int *col = malloc(maxPermutations * sizeof(int));
    int *used = calloc(numsSize, sizeof(int));
    int *current = malloc(numsSize * sizeof(int));

    qsort(nums, numsSize, sizeof(int), compare);

    backtrack(nums, numsSize, used, current,
              result, returnSize, col, 0);

    free(used);
    free(current);

    *returnColumnSizes = col;
    return result;
}