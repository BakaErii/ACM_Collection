/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-09-23 00:36:37
 *
 */

#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

const int maxN=100005;

struct Node{
    int left,right;
}node[maxN];

int arrSum[maxN];
int arrStatus[maxN];
int n,m,tot;
vector<int> G[maxN];

int lowBit(int x){
    return x&(-x);
}

void addNum(int pos,int value){
    while(pos<=n){
        arrSum[pos]+=value;
        pos+=lowBit(pos);
    }
    return;
}

int calSum(int pos){
    int ret=0;
    while(pos>0){
        ret+=arrSum[pos];
        pos-=lowBit(pos);
    }
    return ret;
}

void DFS(int pos,int pre){
    node[pos].left=++tot;
    for(int i=0;i<(int)G[pos].size();i++){
        if(G[pos][i]==pre)
            continue;
        else
            DFS(G[pos][i],pos);
    }
    node[pos].right=tot;
    return;
}

int main(void){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int u,v,m,x;
    char op[5];
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        //CreateGraph
        scanf("%d %d",&u,&v);
        G[u].push_back(v);
    }
    //BuildTreeArray
    for(int i=1;i<=n;i++){
        arrStatus[i]=1;
        addNum(i,1);
    }
    DFS(1,0);
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%s",op);
        scanf("%d",&x);
        switch(op[0]){
            case 'Q':
            //Query
            printf("%d\n",calSum(node[x].right)-calSum(node[x].left-1));
            break;
            case 'C':
            //Change
            if(arrStatus[node[x].left]==1){
                arrStatus[node[x].left]=0;
                addNum(node[x].left,-1);
            }else{
                arrStatus[node[x].left]=1;
                addNum(node[x].left,1);
            }
            break;
        }
    }
    return 0;
}
