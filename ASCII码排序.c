#include<stdio.h>


void output(char in[]);
int main()
{
    char input[4];
    while(scanf("%s", input) != EOF){
        output(input);
        getchar();
    }

    return 0;
}

void output(char in[]){
    int i, j;
    for(i = 0; i < 3; i++){
        for(j = i + 1; j < 3; j++){
            if(in[i] > in[j]){
                char tem = in[i];
                in[i] = in[j];
                in[j] = tem;
            }
        }
    }
    printf("%c %c %c\n", in[0], in[1], in[2]);
}