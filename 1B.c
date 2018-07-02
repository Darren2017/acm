#include<stdio.h>

int main()
{
    int a, b, i, t;
    scanf("%d %d", &a, &b);
    while(a != 0 && b != 0){
        int aa = a * 100;
        int cnt = 0;
        for(i = 0;i < 100; i++){
            if((aa + i) % b == 0){
                if(cnt == 0){
                    printf("%02d", i);
                    cnt++;
                }else{
                    printf(" %02d", i);
                }
            } 
        }
        printf("\n");
        scanf("%d %d", &a, &b);
    }
    
    return 0;
}