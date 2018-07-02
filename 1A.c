#include<stdio.h>

int main()
{
    int a[101], m, n;
    scanf("%d %d", &n, &m);
    while(n != 0 && m != 0){
        int i, j = n;
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        i = 0;
        while(m > a[i]){
            i++;
        }
        while(j > i){
            a[j] = a[j - 1];
            j--;
        }
        a[i] = m;
        for(i = 0; i < n; i++){
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n]);
        scanf("%d %d", &n, &m);
    }

    return 0;
}