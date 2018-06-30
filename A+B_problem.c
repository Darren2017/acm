// #include<stdio.h>
// #include<string.h>
// #define M 1000

// int p = 0;
// void reverse(char *str);
// void add(char *sum, char a, char b, int n);

// int main()
// {
//     char A[M], B[M], sum[M + 1];
//     memset(A, 0, M);
//     memset(B, 0, M);

//     scanf("%s", A);
//     getchar();
//     scanf("%s", B);

//     reverse(A);
//     reverse(B);

//     int i = 0, j = 0, lenA = strlen(A), lenB = strlen(B);
//     while(i < lenA && j < lenB && A[i] && B[j]){
//         add(sum, A[i], B[j], i);
//         i++;
//         j++;
//     }
//     while(i < lenA && A[i]){
//         add(sum, A[i], '0', i);
//         i++;
//     }
//     while(j < lenB && B[j]){
//         add(sum, '0', B[j], i);
//         j++;
//     }
//     reverse(sum);
//     printf("%s", sum);

//     return 0;

// }

// void reverse(char *str){
//     int len = strlen(str);
//     int i;
//     for(i = 0; i < len / 2; i++){
//         char temp = str[i];
//         str[i] = str[len - 1 - i];
//         str[len - 1 - i] = temp;
//     }
// }

// void add(char *sum, char a, char b, int n){
//     int temp = a - '0' + b - '0' + p;
//     if(temp >= 10){
//         temp -= 10;
//         p = 1;
//     }else{
//         p = 0;
//     }
//     sum[n] = temp + '0';
// }

#include<stdio.h>

int main()
{
    int A, B;
    while(scanf("%d %d", &A, &B) != EOF){
        printf("%d\n", A + B);
    }
    return 0;
}