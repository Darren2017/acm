#include<iostream>

using namespace std;

long long n, m, k, l, r;

int main()
{
    cin >> n >> m >> k;
    l = 1, r = n * m;
    while(l != r){
        long long sum = 0, mid = (l + r) / 2;
        for(int i = 1; i <= n; i++){
            long long tem = mid / i;
            if(tem <= m){
                sum += tem;
            }else{
                sum += m;
            }
        }
        if(sum < k){
            l = mid + 1;
        }else{
            r = mid;
        }
    }
    cout << l << endl;
    return 0;
}