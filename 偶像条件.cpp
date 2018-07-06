#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int N, M, L, index1, index2, d1, d2, d3, aa, bb, cc, md = 0x3f3f3f3f;
int a[100004] = {0}, b[100004] = {0}, c[100004] = {0};

int main()
{
    scanf("%d %d %d", &N, &M, &L);

    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < M; i++){
        scanf("%d", &b[i]);
    }
    for(int i = 0; i < L; i++){
        scanf("%d", &c[i]);
    }
    sort(a, a+N);
    sort(b, b+M);
    sort(c, c+L);
    for(int i = 0; i < N; i++){
        index1 = lower_bound(b, b + M, a[i]) - b;
        index2 = lower_bound(c, c + L, a[i]) - c;
        if(abs(a[i] - b[index1]) > abs(a[i] - b[index1 - 1]) && index1 - 1 >= 0){
            bb = b[index1 - 1];
        }else{
            bb = b[index1];
        }
        if(abs(a[i] - c[index2]) > abs(a[i] - c[index2 - 1]) && index2 - 1 >= 0){
            cc = c[index2 - 1];
        }else{
            cc = c[index2];
        }
        // bb = abs(a[i] - b[index1]) > abs(a[i] - b[index1 - 1]) ? b[index1 - 1] : b[index1];
        // cc = abs(a[i] - c[index2]) > abs(a[i] - c[index2 - 1]) ? c[index2 - 1] : c[index2];
        d1 = abs(a[i] - bb), d2 = abs(a[i] - cc), d3 = abs(bb - cc);
        // printf("%d %d %d\n", a[i], bb, cc);
        if(md > d1 + d2 + d3){
            md = d1 + d2 + d3;
        }
    }
    printf("%d\n", md);
    return 0;
}