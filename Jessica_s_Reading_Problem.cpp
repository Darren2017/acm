#include<iostream>
#include<map>
#include<set>
#include<stdio.h>

using namespace std;

int a[1000008];

int main()
{
    int P;
    while((scanf("%d", &P)) != EOF){
        map<int, int> m;
        set<int> s;
        // memset(a, 0, sizeof(a));
        for(int i = 0; i < P; i++){
            scanf("%d", &a[i]);
            s.insert(a[i]);
        }
        int l = 0, r = 0, sum = 0, re = P, n = s.size();
        while(1){
            while(r < P && sum < n){
                if(m[a[r++]]++ == 0){
                    sum++;
                }
            }
            if(sum < n){
                break;
            }
            re = min(re, r - l);
            if(--m[a[l++]] == 0){
                sum--;
            }
        }
        printf("%d\n", re);
    }
    return 0;
}