#include <stdio.h>

int main(void)
{
    int a[10][10];
    int m, n;

    printf("M: ");
    scanf("%i", &m);
    printf("N: ");
    scanf("%i", &n);


    int i, j;
    for (i = 0; i < m; ++i) {
        printf("%i : \n", i + 1);
        for (j = 0; j < n; ++j) {
            printf("%i : ", j + 1);
            scanf("%i", &a[i][j]);
        }
    }

    int max, min;

    for (j = 0; j < n; ++j) {
        max = min = 0;
        for (i = 1; i < m; ++i) {
            if (a[i][j] > a[max][j]) max = i;
            if (a[i][j] < a[min][j]) min = i;
        }
        a[min][j] = a[max][j] + a[min][j];
        a[max][j] = a[min][j] - a[max][j];
        a[min][j] = a[min][j] - a[max][j];
    }

    for (i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) printf(" : %i", a[i][j]);
        printf(" : \n");
    }
    return 0;
}
