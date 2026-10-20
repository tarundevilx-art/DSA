/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void backtrack(int* candidates, int candidatesSize, int target,
               int start, int* path, int pathSize,
               int*** result, int* returnSize, int** returnColumnSizes) {

    if (target == 0) {
        *result = realloc(*result, (*returnSize + 1) * sizeof(int*));
        *returnColumnSizes = realloc(*returnColumnSizes,
                                     (*returnSize + 1) * sizeof(int));

        (*result)[*returnSize] = malloc(pathSize * sizeof(int));
        for (int i = 0; i < pathSize; i++) {
            (*result)[*returnSize][i] = path[i];
        }

        (*returnColumnSizes)[*returnSize] = pathSize;
        (*returnSize)++;
        return;
    }

    for (int i = start; i < candidatesSize; i++) {
        if (candidates[i] > target)
            continue;

        path[pathSize] = candidates[i];

        backtrack(candidates, candidatesSize,
                  target - candidates[i], i,
                  path, pathSize + 1,
                  result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize, int target,
                     int* returnSize, int** returnColumnSizes) {

    int** result = NULL;
    int* path = malloc((target + 1) * sizeof(int));

    *returnSize = 0;
    *returnColumnSizes = NULL;

    backtrack(candidates, candidatesSize, target, 0,
              path, 0, &result, returnSize, returnColumnSizes);

    free(path);
    return result;
}