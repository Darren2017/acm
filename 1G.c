#include<stdio.h>

int j(int a[]);

int main()
{   
    int a[8], i;
    for(i = 0; i < 6; i++){
        scanf("%d", &a[i]);
    }
    while(j(a)){
        int sum = 0;
        sum = a[5] + a[4] + a[3];                  //4 5 6的产品直接占据一个箱子
        while(a[2] >= 4){                       //3的产品四个占据一个箱子
            sum++;
            a[2] -= 4;
        } 
        if(a[2] > 0){                           //不足四个的3产品占据一个箱子
            sum++;
        }
        while(a[4]){                            //为5产品的箱子填装1产品
            if(a[0] > 11){
                a[0] -= 11;
                a[4]--;
            }else{   
                a[0] = 0;
                a[4]--;
            }
        }       
        while(a[3]){                            //为4产品的箱子填装1 2产品
            if(a[1] > 4){
                a[1] -= 4;
                a[3]--;
            }else{
                a[3]--;
                int rest = 36 * a[3] + 16 - a[1] * 4;
                a[1] = 0;
                if(a[0] < rest){
                    a[0] = 0;
                }else{
                    a[0] -= rest;
                }
            }
        }
        if(a[2] == 0){
            int t = 0;
            
            while(a[1] >= 9){
                a[1] -= 9;
                sum++;
            }
            if(a[1] > 0){
                t = 36 - 4 * a[1];
                sum++;
                if(a[0] < t){
                    a[0] = 0;
                }else{
                    a[0] -= t;
                    while(a[0] > 0){
                        a[0] -= 36;
                        sum++;
                    }
                }
            }else{
                while(a[0] > 0){
                    a[0] -= 36;
                    sum++;
                }
            }
        }
        if(a[2] == 3){
            if(a[1] >= 1){
                a[1]--;
                if(a[0] > 5){
                    a[0] -= 5;
                }else{
                    a[0] = 0;
                }
            }else{
                if(a[0] > 9){
                    a[0] -= 9;
                }else{
                    a[0] = 0;
                }
            }
            int t = 0;
            while(a[1] >= 9){
                a[1] -= 9;
                sum++;
            }
            if(a[1] > 0){
                t = 36 - 4 * a[1];
                sum++;
                if(a[0] < t){
                    a[0] = 0;
                }else{
                    a[0] -= t;
                    while(a[0] > 0){
                        a[0] -= 36;
                        sum++;
                    }
                }
            }else{
                while(a[0] > 0){
                    a[0] -= 36;
                    sum++;
                }
            }
        }
        if(a[2] == 2){ 
            if(a[1] >= 3){
                a[1] -= 3;
                if(a[0] > 6){
                    a[0] -= 6;
                }else{
                    a[0] = 0;
                }
            }else{
                if(a[0] > 18){
                    a[0] -= 18;
                }else{
                    a[0] = 0;
                }
            }
            int t = 0;
            while(a[1] >= 9){
                a[1] -= 9;
                sum++;
            } 
            if(a[1] > 0){
                t = 36 - 4 * a[1];
                sum++;
                if(a[0] < t){
                    a[0] = 0;
                }else{
                    a[0] -= t;
                    while(a[0] > 0){
                        a[0] -= 36;
                        sum++;
                    }
                }
            }else{
                while(a[0] > 0){
                    a[0] -= 36;
                    sum++;
                }
            }
        }
        if(a[2] == 1){
            if(a[1] >= 5){
                a[1] -= 5;
                if(a[0] > 7){
                    a[0] -= 7;
                }else{
                    a[0] = 0;
                }
            }else{
                if(a[0] > 27){
                    a[0] -= 27;
                }else{
                    a[0] = 0;
                }
            }
            int t = 0;
            while(a[1] >= 9){
                a[1] -= 9;
                sum++;
            }
            if(a[1] > 0){
                t = 36 - 4 * a[1];
                sum++;
                if(a[0] < t){
                    a[0] = 0;
                }else{
                    a[0] -= t;
                    while(a[0] > 0){
                        a[0] -= 36;
                        sum++;
                    }
                }
            }else{
                while(a[0] > 0){
                    a[0] -= 36;
                    sum++;
                }
            }
        }
        printf("%d\n", sum);
        for(i = 0; i < 6; i++){
            scanf("%d", &a[i]);
        }
    }
    return 0;
}

int j(int a[]){
    for(int i = 0; i < 6; i++){
        if(a[i]){
            return 1;
        }
    }
    return 0;
}