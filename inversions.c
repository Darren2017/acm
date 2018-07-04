#include<stdio.h>

void merger(int a[], int L, int M, int R);
void mergsort(int a[], int L, int R);

long long cnt = 0;

int main()
{
    int a[65538], n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    cnt = 0;
    mergsort(a, 0, n - 1);
    // for(int i = 0; i < n; i++){
    //     printf("%d ", a[i]);
    // }
    printf("%lld", cnt);
    return 0;
}


void mergsort(int a[], int L, int R){
    if(R == L){
        return;
    }else{
        int M = (L + R) / 2;
        mergsort(a, L, M);
        mergsort(a, M + 1, R);
        merger(a, L, M, R);
    }
}

void merger(int a[], int L, int M, int R){
    int temp[65538], i = L, j = M + 1, k = L;
    while(i <= M && j <= R){
        if(a[i] <= a[j]){
            temp[k++] = a[i++];
        }else{
            //printf("%d---%d\n", cnt, i);
            cnt += M - i + 1;
            temp[k++] = a[j++];
        }
    }
    while(i <= M){
        temp[k++] = a[i++]; 
    }
    while(j <= R){
        temp[k++] = a[j++];
    }
    for(i = L; i <= R; i++){
        a[i] = temp[i];
    }
}