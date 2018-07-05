#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int a[200005], in[100005], l1, r1, l2, r2;

double handle();
void pre();

int main()
{
    int T, m, n;
    scanf("%d", &T);
    for(int k = 0; k < T; k++){
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < m; i++){
            scanf("%d %d %d %d",&l1, &r1, &l2, &r2);
            printf("%.1lf\n", handle());
        }
    }

    return 0;
}

double handle(){
    pre();
    if(r1 <= l2){
        int sum1 = r1 - l1, sum2 = r2 - l2;
        if(sum1 > sum2){
            return a[l1 + sum2 - 1];
        }else if(sum2 > sum1){
            return a[r2 - sum1 - 1];
        }else{
            return (a[r1 - 1] + a[l2 - 1]) * 1.0 / 2;
        }
    }else{
        if(r2 - r1 > l2 - l1){
            printf("_______");
            int r = r2 - (l2 - l1);
            int sum = 2 * (r1 - l2 + 1) + r - r1;
            if(sum % 2 == 0){
                return (a[l2 + sum / 2] + a[l2 + sum/ 2 + 1]) * 1.0 / 2;
            }
        }
    }
    return 1;
}

double handle1(){
    // int lr = l1 > l2 ? l1 : l2, ll = l1 < l2 ? l1 : l2, rr = r1 > r2 ? r1 : r2, rl = r1 < r2 ? r1 : r2;
    // printf("lr--%d  rl---%d", lr, rl);
    // if(lr < rl){
    //     int suml = lr - ll, sumr = rr - rl;
    //     if(suml > sumr){
    //         int l = ll + sumr;
    //         return a[l - 1];
    //     }if(sumr > suml){
    //         int r = rr - suml;
    //         return a[r - 1];
    //     }else{
    //         return a[(lr + rl) / 2 - 1];
    //     }
    // }
    // int m1 = abs(l1 - l2), m2 = abs(r1 - r2), sum = r1 < r2 ? r1 : r2 - l2 > l1 ? l2 : l1;
    // sum *= 2;
    // if(m1 > m2){
    //     int l = l1 < l2 ? l1 : l2;
    //     int sum1 = l1 > l2 ? l1 : l2 - l;
    //     if(sum1 > sum){
    //         return a[l + sum - 1];
    //     }else if(sum > sum1){
    //         int r = r1 < r2 ? r1 : r2 - (sum - sum1);
    //     }
    //     l += m2;

    // }else if(m2 > m1){
    //     sum += m2 - m1;
    //     int r = r1 < r2 ? r1 : r2;
    // }else{
    //     return a[sum / 4];
    // }
    // int cnt = 0;
    // for(int i = l1; i <= r1; i++){
    //     a[cnt++] = in[i - 1];
    // }
    // for(int i = l2; i <= r2; i++){
    //     a[cnt++] = in[i - 1];
    // }
    // sort(a, a + cnt);
    // if(cnt % 2){
    //     median = a[cnt / 2];
    // }else{
    //     median = (a[cnt / 2] + a[cnt / 2 - 1]) * 1.0 / 2;
    // }
    printf("--------");
    return 1;
}

void pre(){
    if(l2 <= l1 && r2 <= l1){
        int t = l1;
        l1 = l2;
        l2 = t;
        t = r1;
        r1 = r2;
        r2 =t;
    }
}
