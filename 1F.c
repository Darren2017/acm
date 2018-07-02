#include<stdio.h>
#include<string.h>

int p(int x);

int main()
{
    int N;
    scanf("%d", &N);
    while(N){
        if(p(N)){
            printf("%d is a Sky Number.\n", N);
        }
        else{
            printf("%d is not a Sky Number.\n", N);
        }
        scanf("%d", &N);
    }

    return 0;
}

int p(int x){
    int xx = x, xxx = x, sum1 = 0, sum2 = 0, sum3 = 0;
    while(x){
        sum1 += x % 16;
        x /= 16;
    }
    while(xx){
        sum2 += xx % 12;
        xx /= 12;
    }
    while(xxx){
        sum3 += xxx % 10;
        xxx /= 10;
    }
    if(sum1 == sum2 && sum2 == sum3){
        return 1;
    }
    return 0;
}