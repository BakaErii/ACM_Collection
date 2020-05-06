/*
*@Author:   STZG
*@Language: C++
*/
#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<deque>
#include<stack>
#include<cmath>
#include<list>
#include<map>
#include<set>
//#define DEBUG
#define RI register int
#define endl "\n"
using namespace std;
typedef long long ll;
//typedef __int128 lll;
const int N=100000+10;
const int M=100000+10;
const int MOD=1e9+7;
const double PI = acos(-1.0);
const double EXP = 1E-8;
const int INF = 0x3f3f3f3f;
int t,n,m,k,p,l,r,u,v;
int ans,cnt,flag,temp,sum;
int main()
{
#ifdef DEBUG
	freopen("input.in", "r", stdin);
	//freopen("output.out", "w", stdout);
#endif
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    scanf("%d",&t);
    while(t--){
        int b,w;
        cin>>b>>w;
        if(b>3*w+1||w>3*b+1){
            cout<<"NO"<<"\n";
        }else {
            cout<<"YES"<<endl;
            int x = min(b,w);
            for(int i=0;i<2*x;i++){
                printf("%d %d\n",2,i+2);
            }
            b-=x;
            w-=x;
            for(int i=0;i<w;i++){
                if(i<x)printf("%d %d\n",1,2*i+3);
                else if(i<2*x)printf("%d %d\n",3,2*i+3-2*x);
                else printf("2 %d\n",2*x+2);
            }
            for(int i=0;i<b;i++){
                if(i<x)printf("%d %d\n",1,2*i+2);
                else if(i<2*x)printf("%d %d\n",3,2*i+2-2*x);
                else printf("2 1\n");
            }
        }
    }
 
#ifdef DEBUG
	printf("Time cost : %lf s\n",(double)clock()/CLOCKS_PER_SEC);
#endif
    //cout << "Hello world!" << endl;
    return 0;
}