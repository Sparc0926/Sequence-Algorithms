#include <stdio.h>
#include <stdlib.h>

int n, a[100000], hash[100001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        hash[a[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i] = hash[a[i]];
    }
    int* length = (int*)malloc(n * sizeof(int));
    int* least_tail = (int*)malloc((n + 1) * sizeof(int));
    int max_len = 0;
    least_tail[0] = -0x7fffffff;
    for (int i = 0; i < n; i++) {
        length[i] = 0, least_tail[i + 1] = 0x7fffffff;
        int r = max_len;
        while (length[i] < r) {
            int mid = (length[i] + r) >> 1;
            if (least_tail[mid] < a[i])  length[i] = mid + 1;
            else  r = mid;
        }
        if (a[i] < least_tail[length[i]])  least_tail[length[i]] = a[i];
    }
    for (int i = 0; i < n; i++)
        if (max_len < length[i])  max_len = length[i];
    printf("%d\n", max_len);

    return 0;
}