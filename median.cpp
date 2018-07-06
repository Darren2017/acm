#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

long long a[100005], t, m, n, k, l1, r1, l2, r2, n1, n2, n3, m1, m2, m3;

void solve();

int main()
{
    scanf("%lld", &t);
    while(t--){
        scanf("%lld %lld", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%lld %lld %lld %lld", &l1, &r1, &l2, &r2);
            if(l1 > l2){
                swap(l1, l2);
                swap(r1, r2);
            }
            if(r1 < l2){
                n1 = r1 - l1 + 1;
                n2 = 0;
                n3 = r2 - l2 + 1;
                m1 = l1;
                m2 = r1;
                m3 = l2;
                k = n1 + n2 + n3;
            }else{
                if(r1 > r2){
                    swap(r1, r2);
                }
                n1 = l2 - l1;
                n2 = r1 - l2 + 1;
                n3 = r2 - r1;
                n2 *= 2;
                m1 = l1;
                m2 = l2;
                m3 = r1 + 1;
                k = n1 + n2 + n3;
            }
            solve();
        }
    }
    return 0;
}

void solve(){
    int mid1, mid2;
    //printf("m---%d   n--%d, t--%d, k---%d, l1--%d, r1--%d, l2---%d, r2--%d, n1---%d, n2---%d, n3---%d, m1----%d, m2---%d, m3---%d\n",m, n, t, k, l1, r1, l2, r2, n1, n2, n3, m1, m2, m3);
    if(k & 1){
        mid1 = (k >> 1) + 1;
        if(mid1 <= n1){
            printf("%lld.0\n", a[m1 + mid1 - 1]);
        }else if(mid1 > n1 && mid1 <= n2 + n1){
            mid1 -= n1;
            printf("%lld.0\n", a[m2 + ((mid1 + 1) >> 1) - 2]);
        }else{
            mid1 -= (n1 + n2);
            printf("%lld.0\n", a[m3 + mid1 - 1]);
        }
    }else{
        mid1 = (k >> 1) + 1;
        mid2 = (k >> 1);
        if(mid1 <= n1){
            mid1 = a[m1 + mid1 - 2];
        }else if(mid1 > n1 && mid1 <= n2 + n1){
            mid1 -= n1;
            mid1 =  a[m2 + ((mid1 + 1) >> 1) - 2];
        }else{
            mid1 -= (n1 + n2);
            mid1 =  a[m3 + mid1 - 2];
        }
        if(mid2 <= n1){
            mid2 = a[m1 + mid2 - 2];
        }else if(mid2 > n1 && mid2 <= n2 + n1){
            mid2 -= n1;
            mid2 =  a[m2 + ((mid2 + 1) >> 1) - 2];
        }else{
            mid2 -= (n1 + n2);
            mid2 =  a[m3 + mid2 - 2];
        }
        printf("%.1lf\n", ((double )mid1 + mid2) / 2);
    }
}