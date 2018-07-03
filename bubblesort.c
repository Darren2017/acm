#include<stdio.h>

void swap(int s[], int i, int j);

int cnt = 0;

int main()
{
    int n, a[101];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j >= i + 1; j--){
            if(a[j] < a[j - 1]){
                swap(a, j - 1, j);
            }
        }
    }
    for(int i = 0; i < n; i++){
        if(i == 0){
            printf("%d", a[i]);
        }else{
            printf(" %d", a[i]);
        }
    }
    printf("\n");
    printf("%d\n", cnt);
    return 0;
}

void swap(int s[], int i, int j){
    cnt++;
    int temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}