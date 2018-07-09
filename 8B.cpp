#include<iostream>

using namespace std;

int sum[1000009] = {0}, sum1[1000009] ={0}, mysum;;

int main()
{
    int a, b;
    sum[1] = 1;
    sum1[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        sum1[i] = sum1[i / 10] + sum1[i % 10];
        sum[i] += (sum1[i / 10] + sum1[i % 10] + sum[i -1]);
        // cout << i << "-----" << sum[i] << endl;
    }
    while((scanf("%d %d", &a, &b)) != EOF){
        if(a > b){
            swap(a, b);
        }
        mysum = sum[b] - sum[a - 1];
        cout << mysum << endl;
        // for(int i = 0; i < 120; i++){
        //     cout << i << "--" << sum[i] << endl;
        // }
    }

    return 0;
}