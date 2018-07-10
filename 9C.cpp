#include<iostream>
#include<stdio.h>

using namespace std;

int a[101][101] = {-1}, m, n, nx, ny, cnt = 0;
int x[] = {1, 0, -1, 0, 1, 1, -1, -1};
int y[] = {0, -1, 0, 1, 1, -1, -1, 1};
char tem;

bool isafe(int nnx, int nny);
void dfs(int nnx, int nny);

int main()
{
    while((scanf("%d %d", &m, &n)) != EOF && (m || n)){
        cnt = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> tem;
                if(tem == '*'){
                    a[i][j] = -1;
                }else{
                    a[i][j] = 0;
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(a[i][j] == 0){
                    cnt++;
                    dfs(j, i);
                }
            }
        }
        cout << cnt << endl;
    }

    return 0;
}


void dfs(int nnx, int nny){
    if(isafe(nnx, nny) && a[nny][nnx] == 0){
        a[nny][nnx] = 2;
        int mx, my;
        for(int i = 0; i < 8; i++){
            mx = nnx + x[i], my = nny + y[i];
            dfs(mx, my);
        }
    }
}

bool isafe(int nnx, int nny){
    if(nnx < 0 || nnx >= n || nny < 0 || nny >= m){
        return false;
    }
    return true;
}