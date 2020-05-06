/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-30 23:18:53
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

const int maxN = 400005;

int arr[maxN];
int arrT[maxN];
int arrF[maxN];
int n,mem,k,ptr,ans;

map<int,int> mp;

struct Node{
  int num,cnt;
  bool operator < (const Node & n) const{
    return cnt<n.cnt;
  }
}N[400005];

void Solve(){
  return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
  scanf("%d %d",&n,&mem);
  for(int i=0;i<n;i++){
    scanf("%d",&arr[i]);
    mp[arr[i]]++;
  }
  mem*=8;
  k=mem/n;
  for(auto it:mp)
    N[ptr++]={it.first,it.second};
  if(k>=31){
    printf("0\n");
    return 0;
  }
  int mxCnt=1;
  for(int i=0;i<k;i++)
    mxCnt*=2;
  arrF[1]=N[0].cnt;
  arrT[1]=N[ptr-1].cnt;
  for(int i=2;i<=ptr;i++){
    arrF[i]=arrF[i-1]+N[i-1].cnt;
    arrT[i]=arrT[i-1]+N[ptr-i].cnt;
  }
  int opNum = max(0,ptr-mxCnt);
  int minAns = 0x3f3f3f3f;
  for(int i=0;i<opNum;i++)
    minAns=min(minAns,arrF[i]+arrT[opNum-i]);
  printf("%d\n",minAns==0x3f3f3f3f?0:minAns);
	return 0;
}