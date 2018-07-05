#include<stdio.h>
#include<string.h>

int main()
{
    char num[1007];
    scanf("%s", num);
    int len = strlen(num), sum = 0;
    for(int i = 0; i < len; i++){
        sum += num[i] - '0';
    }
    while(sum >= 10){
        int tem = sum;
        sum = 0;
        while(tem){
            sum += tem % 10;
            tem /= 10;
        }
    }
    printf("%d", sum);

    return 0;
}