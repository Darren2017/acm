#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cstdio>

using namespace std;

struct local{
    int max;
    int index;
}p;

void reverse(int *num, int n);
int isort(int *a, int n);

int main()
{
    int a[35];
    // int a[30] = {2, 8, 2, 9, 1}, n = 5;
    int max, rcnt, cnt;
    char line[200];

    while(gets(line)){
        cnt = 0;
        // memset(a, 0, 35);
        for(int i=0;i<35;i++) a[i]=0;
        for(int i = 0;line[i];i++){
            if(line[i] == ' '){
                printf("%d ", a[cnt++]);
            }else{
                a[cnt] *= 10;
                a[cnt] += (line[i] - '0');
            }
        }
        printf("%d\n", a[cnt++]);
        rcnt = cnt;
        while(cnt > 0){
            max = 0;
            for(int i = 0; i < cnt; i++){
                if(a[max] < a[i]){
                    max = i;
                }
            }    
            if(max != cnt - 1){
                if(max == 0){
                    reverse(a, cnt);
                    printf("%d ", rcnt - cnt + 1);
                    cnt--;
                    //printf("%d ", rn - n + 1);
                }else{
                    reverse(a, max + 1);
                    //printf("%d ", n - max);
                    // for(int i = 0; i < 5; i++){
                    //     printf("%d ", a[i]);
                    // }
                    printf("%d ", rcnt - max);  
                    reverse(a, cnt);
                    printf("%d ", rcnt - cnt + 1);
                    // for(int i = 0; i < 5; i++){
                    //     printf("%d ", a[i]);
                    // }
                    // printf("\n");  
                    cnt--;
                }
            }else{
                cnt--;
                // for(int i = 0; i < 5; i++){
                //     printf("%d ", a[i]);
                // }
                // printf("\n"); 
            }      
        }
        printf("0\n");
    }
    return 0;
}

void reverse(int *num, int n){
    int len = n;
    int i;
    for(i = 0; i < len / 2; i++){
        int temp = num[i];
        num[i] = num[len - 1 - i];
        num[len - 1 - i] = temp;
    }
}

int isort(int *a, int n){
    for(int i = 0; i < n - 1; i++){
        if(a[i] >= a[i + 1]){
            return 0;
        }
    }
    return 1;
}