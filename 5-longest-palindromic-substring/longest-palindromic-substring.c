#include <stdlib.h>
#include <string.h>

// Expands outward from (left, right) while characters match.
// Writes the resulting palindrome's bounds into *outStart, *outEnd.
void expand(const char *s, int len, int left, int right, int *outStart, int *outEnd) {
    while (left >= 0 && right < len && s[left] == s[right]) {
        left--;
        right++;
    }
    *outStart = left + 1;
    *outEnd = right - 1;
}

// Returns a newly malloc'd string containing the longest palindromic substring.
// Caller is responsible for freeing it.
char *longestPalindrome(const char *s) {
    int len = strlen(s);
    if (len == 0) {
        char *empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    int start = 0, end = 0;

    for (int i = 0; i < len; i++) {
        int l1, r1, l2, r2;

        // Odd-length palindrome centered at i
        expand(s, len, i, i, &l1, &r1);
        if (r1 - l1 > end - start) {
            start = l1;
            end = r1;
        }

        // Even-length palindrome centered between i and i+1
        expand(s, len, i, i + 1, &l2, &r2);
        if (r2 - l2 > end - start) {
            start = l2;
            end = r2;
        }
    }

    int resultLen = end - start + 1;
    char *result = malloc(resultLen + 1);
    strncpy(result, s + start, resultLen);
    result[resultLen] = '\0';

    return result;
}