#include<stdio.h>
#include<math.h>
#include<stdlib.h>

void bubblesort(int a[], int n);

int main()
{
    int a[100], n;
    scanf("%d", &n);
    while(n){
        int i;
        for(i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        bubblesort(a, n);
        scanf("%d", &n);
    }

    return 0;
}

void bubblesort(int a[], int n){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(abs(a[i]) < abs(a[j])){
                int tem = a[i];
                a[i] = a[j];
                a[j] = tem;
            }
        }
    }

    for(i = 0; i < n - 1; i++){
        printf("%d ", a[i]);
    }
    printf("%d\n", a[i]);
}