#include<stdio.h>

int j(int a[]);

int main()
{   
    int a[8], i;
    for(i = 0; i < 6; i++){
        scanf("%d", &a[i]);
    }
    while(j(a)){
        int sum = 0, r2, r1;
        sum = a[5] + a[4] + a[3] + (a[2] + 3) / 4;
        int si[] = {0, 5, 3, 1};
        r2 = 5 * a[3] + si[a[2] % 4];
        if(r2 < a[1]){
            sum += (a[1] - r2 + 8) / 9;
        }
        r1 = 36 * sum - 36 * a[5] - 25 * a[4] - 16 * a[3] - 9 * a[2] - 4 * a[1];
        if(a[0] > r1){
            sum += (a[0] - r1 + 35) / 36;
        }
        printf("%d\n", sum);
        for(i = 0; i < 6; i++){
            scanf("%d", &a[i]);
        }
    }
    return 0;
}

int j(int a[]){
    for(int i = 0; i < 6; i++){
        if(a[i]){
            return 1;
        }
    }
    return 0;
}