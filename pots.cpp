#include<iostream>
#include<stdio.h>
#include<queue>
#include<string>
#include<string.h>

using namespace std;

struct pot{
    int a;      //A 中的容量
    int b;      //B 中的容量
    int pace;   //记录步数
    string step;
} p, tp;
int A, B, C, v[103][103] = {0};
string out[] = {"FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};

void bfs();
int main()
{
    while((scanf("%d %d %d", &A, &B, &C)) != EOF){
        memset(v, 0, sizeof(v));
        bfs();
    }
    return 0;
}

void bfs(){
    queue<struct pot> q;
    p.a = 0, p.b = 0, p.pace = 0, p.step = "";
    q.push(p);
    v[0][0] = 1;
    while(!q.empty()){
        p = q.front();
        q.pop();
        if(p.a == C || p.b == C){
            cout << p.pace << endl;
            int len = p.step.length();
            for(int i = 0; i < len; i++){
                cout << out[p.step[i] - '0'] << endl;
            }
            return;
        }
        if(!v[A][p.b]){         //FILL(1);
            tp.a = A;
            tp.b = p.b;
            tp.pace = p.pace + 1;
            tp.step = p.step +  "0";
            q.push(tp);
            v[tp.a][tp.b] = 1;
        }
        if(!v[p.a][B]){        //FILL(2);
            tp.a = p.a;
            tp.b = B;
            tp.pace = p.pace + 1;
            tp.step = p.step + '1';
            q.push(tp);
            v[tp.a][tp.b] = 1;
        }
        if(!v[0][p.b]){              //DROP(1)
            tp.a = 0;
            tp.b = p.b;
            tp.pace = p.pace + 1;
            tp.step = p.step + '2';
            q.push(tp);
            v[tp.a][tp.b] = 1;
        }
        if(!v[p.a][0]){             //DROP(2);
            tp.a = p.a;
            tp.b = 0;
            tp.pace = p.pace + 1;
            tp.step = p.step +  '3';
            q.push(tp);
            v[tp.a][tp.b] = 1;
        }
        if(p.a >= (B - p.b)){         //POUR(1, 2)
            tp.b = B;
            tp.a = p.a - (B - p.b);
            if(!v[tp.a][tp.b]){
                tp.pace = p.pace + 1;
                tp.step = p.step +  '4';
                q.push(tp);
                v[tp.a][tp.b] = 1;
            }
        }else{
            tp.b = p.a + p.b;
            tp.a = 0;
            if(!v[tp.a][tp.b]){
                tp.pace = p.pace + 1;
                tp.step = p.step +  '4';
                q.push(tp);
                v[tp.a][tp.b] = 1;
            }
        }
        if(p.b >= (A - p.a)){           //POUR(2,1)
            tp.a = A;
            tp.b = p.b - (A - p.a);
            if(!v[tp.a][tp.b]){
                tp.pace = p.pace + 1;
                tp.step = p.step +  '5';
                q.push(tp);
                v[tp.a][tp.b] = 1;
            }
        }else{
            tp.a = p.b + p.a;
            tp.b = 0;
            if(!v[tp.a][tp.b]){
                tp.pace = p.pace + 1;
                tp.step = p.step +  '5';
                q.push(tp);
                v[tp.a][tp.b] = 1;
            }
        }
    }
    printf("impossible\n");
}