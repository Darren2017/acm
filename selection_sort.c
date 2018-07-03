#include<stdio.h>

void swap(int s[], int i, int j);

int cnt = 0;

int main()
{
    int n, a[101], j, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    for(i = 0; i < n; i++){
        int mini = i;
        for(j = i; j < n; j++){
            if(a[j] < a[mini]){
                mini = j;
            }
        }if(i != mini){
            swap(a, mini, i);
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