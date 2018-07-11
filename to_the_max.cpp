#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
    int N;
    while((scanf("%d", &N)) != EOF){
        int MAX = -9999999, a[102][102], b[102], tem[102] = {0};
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                scanf("%d", &a[i][j]);
            }
        }
        for(int i = 0; i < N; i++){
            memset(tem, 0, sizeof(tem));
            for(int m = i; m < N; m++){
                for(int j = 0; j < N; j++){
                    tem[j] += a[m][j];
                }
                b[0] = tem[0];
                for(int j = 1; j < N; j++){
                    if(b[j - 1] > 0){
                        b[j] = b[j - 1] + tem[j];
                    }else{
                        b[j] = tem[j];
                    }
                    if(b[j] > MAX){
                        MAX = b[j];
                    }
                }
            }
        }
        printf("%d\n", MAX);
    }
    return 0;
}