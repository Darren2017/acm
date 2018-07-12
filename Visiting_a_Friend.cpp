#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int n, a, b[1000006], v[1000006], mcnt, len;
bool flag;

bool cmp(int a, int b);
void dfs(int x, int cnt);

int main()
{
    int T;
    cin >> T;
    while(T--){
        mcnt = 9999999, flag = false;
        memset(v, 0, sizeof(v));
        cin >> n >> a;
        for(len = 0; len < n; len++){
            scanf("%d", &b[len]);
        }
        sort(b, b + len, cmp);
        v[0] = 1;
        dfs(a, 0);
        if(flag){
            printf("%d\n", mcnt);
        }else{
            printf("-1\n");
        }
    }
    return 0;
}

bool cmp(int a, int b){
    if(a > b){
        return true;
    }else{
        return false;
    }
}

void dfs(int x, int cnt){
    if(x == 0){
        mcnt = min(mcnt, cnt);
        flag = true;
    }else{
        int i;
        for(i = 0; i < len; i++){
            if(b[i] <= x){
                break;
            }
        }
        for(; i < len; i++){
            cnt++;
            dfs((x % b[i]), cnt);
            cnt--;
        }
    }
}