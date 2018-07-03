#include<stdio.h>

void swap(int s[], int i, int j);
int brainman(int a[], int n);

int main()
{
    int n[1001], aa[1001], m, a[1001], j, i;
    scanf("%d", &m);
    for(j = 0; j < m; j++){
        scanf("%d", &n[j]);
        for(i = 0; i < n[j]; i++){
            scanf("%d", &a[i]);
        }
        int cnt = brainman(a, n[j]);

        printf("Scenario #%d:\n%d\n\n", j + 1, cnt);
    }

    return 0;
}

int brainman(int a[], int n){
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        int flag = 0;
        for(int j = n - 1; j >= i + 1; j--){
            if(a[j] < a[j - 1]){
                swap(a, j - 1, j);
                cnt++;
                flag = 1;
            }
        }
        if(!flag){
            break;
        }
    }
    return cnt;
}

void swap(int s[], int i, int j){
    int temp;
    temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}