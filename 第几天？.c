#include<stdio.h>

int main()
{
    int mo1[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mo2[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int year, month, day;
    while((scanf("%d/%d/%d", &year, &month, &day)) != EOF){
        int *p, sum = 0, i;
        if(year % 4 == 0){
            if(year % 100 == 0){
                p = mo1;
                if(year % 400 == 0){
                    p = mo2;
                }
            }else{
                p = mo2;
            }
        }else{
            p = mo1;
        }
        for(i = 0; i < month - 1; i++){
            sum += p[i];
        }
        sum += day;
        printf("%d\n", sum);
    }

    return 0;
}