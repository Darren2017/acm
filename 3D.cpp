#include<iostream>
#include <string>

using namespace std;

string num;
int len, cnt = 2147483647;
bool pre = false;

void handle(char a, char b);

int main()
{
    cin >> num;
    len = num.length();
    handle('0', '0');
    handle('2', '5');
    handle('7', '5');
    handle('5', '0');
    if(pre){
        cout << cnt << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}

void handle(char a, char b){
    string tem = num;
    int flag = 0, cnt1 = 0;
    for(int i = len - 1; i >= 0; i--){
        if(tem[i] == b){
            flag++;
            for(int j = i; j < len - 1; j++){
                swap(tem[j], tem[j + 1]);
                cnt1++;
            }
            break;
        }
    } 
    for(int i = len - 2; i >= 0; i--){
        if(tem[i] == a){
            flag++;
            for(int j = i; j < len - 2; j++){
                swap(tem[j], tem[j + 1]);
                cnt1++;
            }
            break;
        }
    }
    if(flag == 2){
        if(tem[0] == '0'){
            for(int i = 1; i< len - 2; i++){
                if(tem[i] != '0'){
                    cnt1 += i;
                    pre = true;
                    if(cnt > cnt1){
                        cnt = cnt1;
                    }
                }
            }
        }else{
            pre = true;
            if(cnt > cnt1){
                cnt = cnt1;
            }
        }
    }
}