#include<stdio.h>
#include<string.h>

int mp(char str[]);
int ms(char str[]);
int rp(char str[]);

int main()
{
    char str[25];
    while((scanf("%s", str)) != EOF){
        getchar();
        if(mp(str)){
            printf("%s -- is a mirrored palindrome.\n\n", str);
            continue;
        }
        if(ms(str)){
            printf("%s -- is a mirrored string.\n\n" , str);
            continue;
        }
        if(rp(str)){
            printf("%s -- is a regular palindrome.\n\n", str);
            continue;
        }
        printf("%s -- is not a palindrome.\n\n", str);
    }

    return 0;
}

int mp(char str[]){
    if(ms(str) && rp(str)){
        return 1;
    }
    return 0;
}

int ms(char str[]){
    char a[300];
    memset(a, 0, 300);
    a['A'] = 'A', a['E'] = '3', a['H'] = 'H', a['I'] = 'I', a['J'] = 'L', a['L'] = 'J', a['M'] = 'M', a['O'] = 'O';
    a['S'] = '2', a['T'] = 'T', a['U'] = 'U', a['V'] = 'V', a['W'] = 'W', a['X'] = 'X', a['Y'] = 'Y', a['Z'] = '5';
    a['1'] = '1', a['2'] = 'S', a['3'] = 'E', a['5'] = 'Z', a['8'] = '8';
    int len = strlen(str), p = 1;
    for(int j = 0; j < len / 2; j++){
        if(str[j] != a[str[len - j - 1]]){
            p = 0;
            break;
        }
    }
    if(len % 2 == 1){
        if(str[len / 2] != a[str[len / 2]]){
            p = 0;
        }
    }
    if(p){
        return 1;   
    }
    return 0;
}

int rp(char str[]){
    int len = strlen(str), p = 1;
    for(int j = 0; j < len / 2; j++){
        if(str[j] != str[len - j - 1]){
            p = 0;
            break;
        }
    }
    if(p){
        return 1;   
    }
    return 0;
}