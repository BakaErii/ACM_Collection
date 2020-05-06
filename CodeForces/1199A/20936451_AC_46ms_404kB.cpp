/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-30 22:40:00
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

const int maxN = 100005;

int arr[maxN];
int n,x,y;

bool Check(int idx){
  int fptr=idx,pptr=idx;
  for(int i=0;i<x;i++){
    if(--fptr>=0&&arr[fptr]<arr[idx])
      return false;
  }
  for(int i=0;i<y;i++){
    if(++pptr<n&&arr[pptr]<arr[idx])
      return false;
  }
  return true;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
  scanf("%d %d %d",&n,&x,&y);
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  for(int i=0;i<n;i++)
    if(Check(i)==true){
      printf("%d\n",i+1);
      return 0;
    }
  printf("%d\n",n);
	return 0;
}