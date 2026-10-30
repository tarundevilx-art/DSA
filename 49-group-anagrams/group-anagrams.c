#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

char*** groupAnagrams(char** strs, int strsSize,
                      int* returnSize, int** returnColumnSizes) {

    char ***result = malloc(strsSize * sizeof(char**));
    char **keys = malloc(strsSize * sizeof(char*));

    *returnColumnSizes = calloc(strsSize, sizeof(int));

    int groupCount = 0;

    for (int i = 0; i < strsSize; i++) {

        char *temp = malloc(strlen(strs[i]) + 1);
        strcpy(temp, strs[i]);

        qsort(temp, strlen(temp), sizeof(char), cmp);

        int found = -1;

        for (int j = 0; j < groupCount; j++) {
            if (strcmp(keys[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found == -1) {

            found = groupCount++;

            keys[found] = temp;

            result[found] = malloc(strsSize * sizeof(char*));

        } else {
            free(temp);
        }

        int col = (*returnColumnSizes)[found];

        result[found][col] = strs[i];

        (*returnColumnSizes)[found]++;
    }

    *returnSize = groupCount;

    for (int i = 0; i < groupCount; i++) {
        free(keys[i]);
    }

    free(keys);

    return result;
}