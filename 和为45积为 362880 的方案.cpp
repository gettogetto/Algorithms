
//九个 1~9 的数可重复取，使其和为 45、积为 362880 的方案有几种？
#include <stdio.h>

void f(int* a, int sum, int product, int n) {
    if (n == 9) {
        if (sum == 45 && product == 362880) {
            for (int i = 0; i < 9; i++)
                printf("%d ", a[i]);
            printf("\n");
        }
    }
    else
        for (a[n] = (n == 0) ? 1 : a[n - 1]; a[n] <= 9; a[n]++)
            f(a, sum + a[n], product * a[n], n + 1);
}

int main() {
    int a[9];
    f(a, 0, 1, 0);
}


