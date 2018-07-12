#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<map>

using namespace std;

pair<int, int> p, tp;
int nex[] = {2, 1, -1, -2, -2, -1, 1, 2};
int ney[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int N, l, sx, sy, ex, ey, v[304][304] = {0}, s[304][304];

int bfs(int x, int y);
bool isafe(int x, int y);

int main()
{
    scanf("%d", &N);
    while(N--){
        memset(v, 0, sizeof(v));
        scanf("%d", &l);
        scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
        int cnt = bfs(sx, sy);
        cout << cnt << endl;
    }
    return 0;
}

int bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    v[y][x] = 1;
    s[y][x] = 0;
    while(!q.empty()){
        tp = q.front();
        q.pop();
        if(tp.first == ex && tp.second == ey){
            return s[tp.second][tp.first];
        }
        int nx, ny;
        for(int i = 0; i < 8; i++){
            nx = tp.first + nex[i];
            ny = tp.second + ney[i];
            if(isafe(nx, ny)){
                q.push(make_pair(nx, ny));
                v[ny][nx] = 1;
                s[ny][nx] = s[tp.second][tp.first] + 1;
            }
        }
    }
    return 0;
}

bool isafe(int x, int y){
    if(x < 0 || x >= l || v[y][x] || y < 0 || y >= l){
        return false;
    }
    return true;
}