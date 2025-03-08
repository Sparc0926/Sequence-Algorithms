#include <stdio.h>

int n, a, psum, max;

int main()
{
    scanf("%d%d", &n, &psum);
    max = psum;
    for (int i = 1; i < n; i++) {
        if (psum & 0x80000000)  scanf("%d", &psum);
        else {
            scanf("%d", &a);
            psum += a;
        }
        if (psum > max)  max = psum;
    }
    printf("%d\n", max);

    return 0;
}