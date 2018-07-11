#include<iostream>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

struct pace{
    int x;
    int y;
}pace[100];

int a[5][5], v[5][5] = {0}, cnt = 0;
int nx[] = {1, 0, 0, -1};
int ny[] = {0, 1, -1, 0};

void maze(int x, int y);
void print();
bool isafe(int x, int y);

int main()
{
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &a[i][j]);
        }
    }
    v[0][0] = 1;
    pace[cnt].x = 0;
    pace[cnt++].y = 0;
    maze(0, 0);
    return 0;
}

bool isafe(int x, int y){
    if(x < 0 || x > 4 || y < 0 || y > 4 || a[y][x] == 1){
        return false;
    }
    return true;
}

void maze(int x, int y){
    if(x  == 4 && y == 4){
        v[4][4] = 1;
        print();
        exit(0);
    }else{
        for(int i = 0; i < 4; i++){
            int mx = x + nx[i];
            int my = y + ny[i];
            if(!v[my][mx] && isafe(mx, my)){
                v[my][mx] = 1;
                pace[cnt].x = mx;
                pace[cnt++].y = my;
                maze(mx, my);
                v[my][mx] = 0;
                cnt--;
            }
        }
    }
}

void print(){
    for(int i = 0; i < cnt; i++){
        printf("(%d, %d)\n", pace[i].y, pace[i].x);
    }
}