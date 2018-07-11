#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int P[60] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0 };
int a[23], v[23] = {0}, N;
void handle(int n);

int main()
{
    int cnt = 0;
    while((scanf("%d", &N)) != EOF){
        memset(v, 0, sizeof(v));
        cnt++;
        for(int i = 0; i < N; i++){
            a[i] = i + 1;
        }
        printf("Case %d:\n", cnt);
        handle(1);
        printf("\n");
    }
    return 0;
}

void handle(int n){
    if(n == N && P[a[0] + a[n - 1]]){
        printf("%d", a[0]);
        for(int i = 1; i < N; i++){
            printf(" %d", a[i]);
        }
        printf("\n");
    }else{
        for(int i = 2; i <= N; i++){
            if(v[i] == 0 && P[i + a[n - 1]]){
                a[n] = i;
                v[i] = 1;
                handle(n + 1);
                v[i] = 0;
            }
        }
    }
}