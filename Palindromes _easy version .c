#include<stdio.h>
#include<string.h>

int main()
{
    int n, i, j, len, p;
    char a[1000];
    scanf("%d", &n);
    getchar();
    for(i = 0; i < n; i++){
        p = 1;
        scanf("%s", a);
        getchar();
        len = strlen(a);
        for(j = 0; j < len / 2; j++){
            if(a[j] != a[len - j - 1]){
                printf("no\n");
                p = 0;
                break;
            }
        }
        if(p){
            printf("yes\n");    
        }
    }

    return 0;
}