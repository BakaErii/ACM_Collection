
#include<stdio.h>

int main(void)
{
    int n,i,m,j;
    char c;
    int x = 1;
    int y = 1;

    while(scanf("%c %d",&c,&n)!=EOF){
        getchar();
        if(c=='@'){
            break;
        }else{
            if(y!=1){
                printf("\n");
            }
            y = 2;
            for(i=n-1;i>0;i--){
                for(j = i;j>0;j--){
                    printf(" ");
                }
                printf("%c",c);

                if(i!=(n-1)){
                    for(m=0;m<x;m++){
                        printf(" ");
                    }
                    x+=2;
                    printf("%c",c);
                }
                printf("\n");
            }
            for(i=0;i<(2*n-1);i++){
                printf("%c",c);
            }
            printf("\n");
            x = 1;
        }
    }
}
