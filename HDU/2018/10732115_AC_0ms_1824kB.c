#include <stdio.h>

int main(void){
    int ha,haha,hahaha,hahahaha,fuck,i,r;
    //哈哈哈哈哈哈哈哈哈
    while(scanf("%d",&fuck)!=EOF){
        if(fuck!=0){
            ha=1;
            haha=0;
            hahaha=0;
            hahahaha=0;
            for(i=0;i<fuck-1;i++){
                ha=ha+haha;
                haha=hahaha;
                hahaha=hahahaha;
                hahahaha=ha;
            }
            r=ha+haha+hahaha+hahahaha;
            printf("%d\n",r);
        }
    }
    return 0;
}