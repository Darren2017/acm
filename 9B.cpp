#include<iostream>
#include<stdio.h>

using namespace std;

int x[] = {1, 0, -1, 0};
int y[] = {0, -1, 0, 1};
int a[20][20] = {0}, H, W, nx, ny, sum;
char tem;

bool isafe(int nnx, int nny);
void dfs(int nnx, int nny);

int main()
{   
    while((scanf("%d %d", &W, &H)) != EOF && (W || H)){
        sum = 0;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                cin >> tem;
                if(tem == '.'){
                    a[i][j] = 1;
                }else if(tem == '#'){
                    a[i][j] = 0;
                }else{
                    a[i][j] = 1;
                    nx =j, ny = i;
                }
            }
        }
        dfs(nx, ny); 
        // for(int i = 0; i < H; i++) {
        //     for (int j = 0; j < W; j++) {
        //         cout << a[i][j] << " ";
        //     }
        //     cout << endl;
        // }      
        printf("%d\n", sum);  
    }
    return 0;
}

void dfs(int nnx, int nny){
    if(isafe(nnx, nny) && a[nny][nnx] == 1){
        sum++;
        a[nny][nnx] = 2;
        int mx, my;
        for(int i = 0; i < 4; i++){
            mx = nnx + x[i], my = nny + y[i];
            dfs(mx, my);
        }
    }
}

bool isafe(int nnx, int nny){
    if(nnx < 0 || nnx >= W || nny < 0 || nny >= H){
        return false;
    }
    return true;
}