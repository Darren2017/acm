#include<stdio.h>

int p(int x);

int main()
{
    int m, n, i;
    while((scanf("%d %d", &m, &n)) != EOF){
        int cnt = 0;
        for(i = m; i <= n; i++){
            if(p(i)){
                if(cnt == 0){   
                    cnt++;
                    printf("%d", i);    
                }else{
                    printf(" %d", i);
                }
            }
        }
        if(cnt == 0){
            printf("no\n");
        }else{
            printf("\n");
        }
    }

    return 0;
}

int p(int x){
    int xx = x;
    int a = x % 10;
    x /= 10;
    int b = x % 10;
    x /= 10;
    int c = x;
    if(a*a*a + b*b*b + c*c*c == xx){
        return 1;
    }
    return 0;
}