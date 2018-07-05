#include<stdio.h>

int main()
{
    int n, a[103]={0}, max, t;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &t);
        a[t]++;
    }
    max = a[0];
    for(int i = 0; i < 102; i++){
        if(max < a[i]){
            max = a[i];
        }
    }
    printf("%d", max);

    return 0;
}