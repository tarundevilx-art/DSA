#include <stdlib.h>
#include <string.h>

void backtrack(char ***result, char *current,
               int open, int close, int n,
               int *count, int *capacity, int pos) {
    if (pos == 2 * n) {
        current[pos] = '\0';

        if (*count == *capacity) {
            *capacity *= 2;
            *result = realloc(*result,
                              (*capacity) * sizeof(char *));
        }

        (*result)[*count] = malloc((2 * n + 1) * sizeof(char));
        strcpy((*result)[*count], current);
        (*count)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(result, current, open + 1, close, n,
                  count, capacity, pos + 1);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(result, current, open, close + 1, n,
                  count, capacity, pos + 1);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;

    int capacity = 16;
    char **result = malloc(capacity * sizeof(char *));
    char *current = malloc((2 * n + 1) * sizeof(char));

    backtrack(&result, current, 0, 0, n,
              returnSize, &capacity, 0);

    free(current);
    return result;
}