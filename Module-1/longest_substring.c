#include <stdio.h>
#define n 8

int main() {
    char s[n] = "abcabcbb";
    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < n - 1; i++) {
        int visited[256] = {0};

        for (int j = i; j < n - 1; j++) {
            if (visited[s[j]] == 1) {
                break;
            }

            visited[s[j]] = 1;

            int len = j - i + 1;
            if (len > maxLen) {
                maxLen = len;
                start = i;
            }
        }
    }

    printf("Length: %d\n", maxLen);

    printf("Substring: ");
    for (int i = start; i < start + maxLen; i++) {
        printf("%c", s[i]);
    }

    printf("\n");

    return 0;
}