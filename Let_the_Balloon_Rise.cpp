#include<iostream>
#include<map>
#include<string>

using namespace std;

string color;

int main()
{
    int N, max = 0;
    cin >> N;
    while(N != 0){
        max = 0;
        map<string, int> m;
        for(int i = 0; i < N; i++){
            cin >> color;
            m[color]+=1;
            if(max < m[color]){
                max = m[color];
            }
        }
        map<string, int>::iterator iter;
        for(iter = m.begin(); iter != m.end(); iter++){
            // cout << "color--" << iter -> first << "--count--" << iter -> second << endl;
            // cout << iter -> first << endl;
            if(iter -> second == max){
                cout << iter -> first << endl;
                break;
            }
        }
        cin >> N;
    }
    return 0;
}