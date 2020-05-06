#include<stdio.h>

int main() {
    int n, b;
    char ch;
    int tot;
    tot = 0;
    while (scanf("%c", &ch) != EOF) {
        if (tot && ch != '@')
            printf("\n");
        tot++;
        getchar();
        if (ch == '@')
            break;
        scanf("%d", &n);
        getchar();
        b = n;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= b - 1; j++)
                printf(" ");
            printf("%c", ch);
            if (i != 1) {
                for (int j = 1; j <= 2 * i - 3; j++)
                    printf(" ");
                printf("%c", ch);
            }
            printf("\n");
            b--;
        }
        for (int i = 1; i <= 2 * n - 1; i++)
            printf("%c", ch);
        printf("\n");
    }
    return 0;
}
