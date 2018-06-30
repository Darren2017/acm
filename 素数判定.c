#include<stdio.h>
#include<math.h>

int pre(int x, int y);
int pr(int x);
int express(int n);

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    while(!(x == 0 && y == 0)){
        if(pre(x, y)){
            printf("OK\n");
        }else{
            printf("Sorry\n");
        }
        scanf("%d %d", &x, &y);
    }

    return 0;
}

int pre(int x, int y){
    int r = 0, i;
    for(i = x; i <= y; i++){
        if(pr(express(i))){
            r = 1;
        }else{
            r = 0;
            return r;
        }
    }
    return r;
}

int pr(int x){
    if(x == 1)  return 0;
    int k = 2;
    while(k <= (int)sqrt(x)){
        if(x % k == 0){
            return 0;
        }
        k++;
    }
    return 1;
}

int express(int n){
    return n * n + n + 41;
}