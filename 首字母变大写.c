#include<stdio.h>
#include<string.h>

int main()
{
    char str[101];
    while((gets(str))){
        int len = strlen(str);
        int p = 0, i;
        str[0] -= 32;
        for(i = 0; i < len; i++){
            if(str[i] == ' '){
                str[i+1] -= 32;
            }
        }
        printf("%s\n", str);
    }
    return 0;
}