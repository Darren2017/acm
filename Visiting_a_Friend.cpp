// #include<iostream>
// #include<stdlib.h>

// using namespace std;

// struct tele{
//     int x;
//     int y;
// }tele[103];
// int n, m, v[103] = {0};

// bool solve(int now);

// int main()
// {
//     scanf("%d %d", &n, &m);
//     for(int i = 0; i < n; i++){
//         scanf("%d %d", &tele[i].x, &tele[i].y);
//     }
//     v[0] = 1;
//     if(solve(0)){
//         printf("YES\n");
//     }else{
//         printf("NO\n");
//     }

//     return 0;
// }

// bool solve(int now){
//     if(tele[now].x <= m && tele[now].y >= m){
//         printf("YES\n");
//         exit(0);
//     }else{
//         for(int i = now + 1; i < n && tele[i].x <= tele[now].y && v[i] == 0; i++){
//             v[i] = 1;
//             solve(i);
//         }
//     }
//     return false;
// }


#include<iostream>

using namespace std;

int v[104] = {0};

int main()
{
    int n, m, x, y;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        if(y == m){
            v[y] = 1;
        }
        for(int i = x; i < y; i++){
            v[i] = 1;
        }
    }
    for(int i = 0; i <= m; i++){
        if(v[i] == 0){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;

}