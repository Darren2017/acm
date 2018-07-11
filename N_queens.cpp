#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int a[12] = {0}, b[12] = {0}, i, sum;

bool isafe(int x);
void find(int x);

int main()
{
    int N;
    for(i = 1; i <= 10; i++){
        memset(a, 0, sizeof(a));
        sum = 0;
        find(0);
        b[i] = sum;
    }
    while((scanf("%d", &N)) != EOF && N){
        printf("%d\n",b[N]);
    }
    return 0;
}

void find(int x){
    if(x == i){
        sum++;
    }else{
        for(int j = 0; j < i; j++){
            a[x] = j;
            if(isafe(x) == false){
                continue;
            }
            find(x + 1);
        }
    }
}

bool isafe(int x){
    for(int i = 0; i < x; i++){
        if(a[x] == a[i] || abs(x - i) == abs(a[x] - a[i])){
            return false;
        }
    }
    return true;
}