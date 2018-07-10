#include<iostream>
#include<string.h>
#include<stdio.h>

using namespace std;

struct node{
    char f, l;
}node[1000004];
int cnt = 0;
bool flag = false;
int v[1000004];

void dfs(int a);

int main()
{
    char str[100004];
    while((scanf("%s", str)) != EOF){
        flag = false;
        if(str[0] == '0'){
            printf("No.\n");
            continue;
        }
        int i = 0;
        node[i].f = str[0];
        node[i++].l = str[strlen(str) - 1];
        // memset(v, 1, sizeof(v));
    //    for(int i = 0; i < 100; i++){
    //        printf("%d ", v[i]);
    //    }
        while((scanf("%s", str)) != EOF){
            if(str[0] == '0'){
                break;
            }
            node[i].f = str[0];
            node[i++].l = str[strlen(str) - 1];
        }
        cnt = i;
        for(i = 0; i < cnt; i++){
            if(node[i].f == 'b'){
                memset(v, 0, sizeof(v));
                v[i] = 1;
                dfs(i);
            }
            if(flag){
                break;
            }
        }
        if(!flag){
            printf("No.\n");
        }else{
            printf("Yes.\n");
        }
    }
    return 0;
}

void dfs(int a){
    if(node[a].l == 'm'){
        flag = true;
        return;
    }else{
        for(int i = 0; i < cnt; i++){
            if(node[i].f == node[a].l && v[i] == 0){
                v[i] = 1;
                dfs(i);
                v[i] = 0;
            }
        }
    }
}
