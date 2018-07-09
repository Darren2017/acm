#include<iostream>

using namespace std;

int T, N, S, l, r, temp, len;

int main()
{
    cin >> T;
    while(T--){
        len = 100000, l = 0, r = 1;
        int sum[100000] = {0};
        cin >> N >> S;
        for(int i = 1; i <= N; i++){
            cin >> temp;
            sum[i] = temp + sum[i - 1];
        }
        if(sum[N] < S){
            cout << 0 << endl;
        }else{
            for(int i = 1; i <= N; i++){
                if(sum[i] - sum[l] >= S){
                    r = i;
                    for(; sum[r] - sum[l] >= S; l++);
                    if(len > r - l + 1){
                        len = r - l + 1;
                    }
                }
            }
            cout << len << endl;
        }
    }

    return 0;
}