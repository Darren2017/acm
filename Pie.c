#include<stdio.h>
#include<math.h>

const double PI = 3.141592653589792;
double a[10004] = {0.0}, max;
int m, n, f, t;

void find();
int check(double mid);

int main()
{
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        max = 0.0;
        scanf("%d %d", &n, &f);
        f++;
        int r;
        for(int j = 0; j < n; j++){
            scanf("%d", &r);
            a[j] = r * r * PI;
            // printf("%.4lf\n", a[j]);
            if(max < a[j]){
                max = a[j];
            }
        }
        // printf("__________%lf\n",max);
        find();
    }
    return 0;
}

void find(){
    double l = 0.0, r = max;
    // printf("%lf\n", fabs(l-r));
    while(fabs(l - r) > 0.0000001){
        // printf("l----%lf--------r-------%lf\n", l, r);
        double mid = (l + r) / 2;
        if(check(mid) == 1){
            r = mid;
        }else{
            l = mid;
        }
    }
    printf("%.4lf\n", l);
}

int check(double mid){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        double aa = a[i];
        while(aa >= mid){
            aa -= mid;
            cnt++;
        }
    }
    if(cnt < f){
        return 1;
    }else{
        return 0;
    }
}