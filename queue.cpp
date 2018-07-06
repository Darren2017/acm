#include<iostream>
#include<queue>
#include <utility>
#include<map>
#include<string>

using namespace std;

queue< pair<string, int> > q;
pair<string, int> pa;

int main()
{
    int n, tp, p;
    string name;
    cin >> n >> p;

    pair <string,double> product1 ("tomatoes",3.25);
    for(int i = 0; i < n; i++){
        cin >> name >> tp;
        pa = make_pair(name, tp);
        q.push(pa);
    }
    int sum = 0;
    while(!q.empty()){
        pa = q.front();
        tp = pa.second;
        if(tp > p){
            pa.second -= p;
            sum += p;
            pair<string, int> pp;
            pp = pa;
            q.pop();
            q.push(pp);
        }else{
            sum += tp;
            cout << pa.first << " " << sum << endl;
            q.pop();
        }
    }
    return 0;
}