#include<iostream>

using namespace std;

int main()
{
    int n, mmin = 0, na, nb, a, b;
    scanf("%d %d %d", &n, &a, &b);
    for(int i = 1; i < n; i++){
        mmin = max(mmin, a / i < b / (n - i) ? a / i : b / (n - i));
    }
    printf("%d\n", mmin);
    return 0;
}