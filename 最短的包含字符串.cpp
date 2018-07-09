#include<iostream>
#include<string>

using namespace std;

string str, re, st = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int sum = 100000000, l = 0, r = 0;

bool check();

int main()
{
    cin >> str;
    int len = str.length();
//    cout << len << endl;
    for(int i = 0; i < len; i++){
        re = str.substr(l, i + 1 - l);
        if(check()){
            r = i + 1;
            for(; check(); l++) {
                re = str.substr(l, r - l);
//                cout << l << "-----" << r << endl;
            }
            // cout << r - l + 2 << endl;
            if(sum > r - l + 2){
                sum = r - l + 2;
            }
            l--;
        }
    }
    if(sum != 100000000){
        cout << sum << endl;
    }else{
        cout << "No Solution" << endl;
    }
    return 0;
}
bool check(){
//    cout << re << endl;
    for(int i = 0; i < 26; i++){
        if(re.find(st[i]) == re.npos){
            return false;
        }
    }
    return true;
}