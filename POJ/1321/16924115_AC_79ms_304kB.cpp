	#include<stdio.h>
	void Change(int j);
	void Back(int j);
	void Find(int i);
	int m=0,n=0,sum=0;
	char MAP[10][10];

	void Change2(int i,int j){
	    for(int k=0;k<m;k++){
	        if(MAP[i][k]=='#')
	        	;
	    }
	    for(int k=0;k<m;k++){
	        if(MAP[k][j]=='#')
	            MAP[k][j]='f';
	    }

	}
	void Back2(int i,int j){
	    for(int k=0;k<m;k++){
	        if(MAP[i][k]=='f')
	            ;
	    }
	    for(int k=0;k<m;k++){
	        if(MAP[k][j]=='f')
	            MAP[k][j]='#';
	    }

	}
	int main(){

	    while(~scanf("%d %d",&m,&n)&&m!=-1&&n!=-1){
	        getchar();
	        sum=0;

	        for(int i=0;i<m;i++)//make_map
	        for(int j=0;j<m;j++){
	            MAP[i][j]=getchar();
	            if(j==m-1)
	                getchar();
	        }
	        Find(-1);
	        printf("%d\n",sum);
	    }

	    return 0;
	}
	void Change(int j){
	    for(int k=0;k<m;k++){
	        if(MAP[k][j]=='#')
	            MAP[k][j]='f';
	    }
	}
	void Back(int j){
	    for(int k=0;k<m;k++){
	        if(MAP[k][j]=='f')
	            MAP[k][j]='#';
	    }
	}
	void Find(int i){
	    static int num=0;
	    for(i=i+1;i<m;i++)
	    for(int j=0;j<m;j++){
	        if(MAP[i][j]=='#'){
	            num++;
	            if(num==n){
	                sum++;
	                num--;
	                continue;
	            }
	            Change2(i,j);
	            //Change(j);*/
	            Find(i);
	            Back2(i,j);
	            //Back(j);*/
	            num--;
	        }
	    }
	}
