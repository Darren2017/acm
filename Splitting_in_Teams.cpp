#include<iostream>
#include<map>

using namespace std;

map<int, int> m;

int main()
{   
    int n, tem, cnt = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &tem);
        m[tem]++;
    }
    while(m[2] > 0 && m[1] > 0){
        cnt++;
        m[2]--;
        m[1]--;
    }
    while(m[1] >= 3){
        cnt++;
        m[1] -= 3;
    }
    printf("%d\n", cnt);

    return 0;
}