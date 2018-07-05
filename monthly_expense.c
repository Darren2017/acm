#include<stdio.h>

int a[1000003] = {0}, n, m, max = 0;

void find();
int check(int mid);

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        if(max < a[i]){
            max = a[i];
        }
    }
    find();
    return 0;
}

void find(){
    int l = max, r = n * max;
    while(l < r){
        int mid = (l + r) / 2;
        if(check(mid) == 1){
            r = mid;
        }else{
            l = mid + 1;
        }
    }
    printf("%d\n", l);
}

int check(int mid){
    int sum = 0, cnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > mid){
            return 0;
        }else if(sum + a[i] > mid){
            sum = a[i];
            cnt++;
        }else{
            sum += a[i];
        }
    }
    if(sum != 0){
        cnt++;
    }
    if(cnt <= m){
        return 1;
    }else{
        return 0;
    }
}