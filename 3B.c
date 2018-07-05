#include<stdio.h>

char a[1050];

int main()
{
    int n, flag = 0, i;
    scanf("%d", &n);
    scanf("%s", a);
    for(i = 0; i < 3; i++){
        if(a[i] == '1'){
            break;
        }
    }
    if(i == 2 || i == 3){
        printf("No");
        return 0;
    }
    for(; i < n - 3; i++){
        if(a[i] == '1'){
            if(a[i + 1] == '1'){
                printf("No");
                return 0;
            }
            if(a[i + 1] == '0' && a[i + 2] == '0' && a[i + 3] == '0'){
                printf("No");
                return 0;
            }
        }
    }
    if(a[n - 2] == a[n - 1] || (a[n - 2] == a[n - 3] && a[n - 2] == '1')){
        printf("No");
        return 0;
    }
    printf("Yes");
    return 0;
}