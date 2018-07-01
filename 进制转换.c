#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void reverse(int str[]);

int main()
{
    char a[] = "0123456789ABCDEF";
    int re[1000];
    int N, R;
    while((scanf("%d %d", &N, &R)) != EOF){
        int p = N, i;
        N = abs(N);
        memset(re, -1, 1000);
        for(i = 0; N; i++){
            re[i] = N % R;
            N /= R;
        }
        if(p < 0){
            printf("-");
        }
        int len = 0;
        while(re[len] != -1){
            len++;
        }
        for(i = len -1; i >= 0; i--){
            printf("%c", a[re[i]]);
        }
        printf("\n");
    }

    return 0;
}