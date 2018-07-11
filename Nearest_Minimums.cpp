#include<iostream>

using namespace std;

int n, mdis = 99999999;
long long num[100006], mmin = 1000000400;

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &num[i]);
        mmin = min(mmin, num[i]);
    }
    int r, l;
    for(int i = 0; i < n; i++){
        if(num[i] == mmin){
            r = i;
            l = i;
            break;
        }
    }
    for(int i = l + 1; i < n; i++){
        if(num[i] == mmin){
            r = i;
            mdis = min(mdis, r - l);
            l = r;
            r++;
        }
    }
    cout << mdis << endl;

    return 0;
}