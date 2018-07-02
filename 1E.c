#include<stdio.h>

int main()
{
    int a[15], cnt = 0, i, j, count = 0;
    scanf("%d", &a[cnt++]);
    while(a[cnt - 1]){
        scanf("%d", &a[cnt++]);
    }
    for(i = 0; i < cnt-1; i++){
        for(j = 0; j < cnt-1; j++){
            if(a[j] * 2 == a[i]){
                count++;
            }
        }
    }
    printf("%d", count);

    return 0;
}