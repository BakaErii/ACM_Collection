/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-03  19:54:17
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

const int maxN = 200005;

int len;
int ansX,ansY;
int arrX[maxN];
int arrY[maxN];
char str[maxN];

bool isOK(int s){
	for(int i=1;i+s-1<=len;i++){
		int xSection = arrX[len]-arrX[i+s-1]+arrX[i-1];
		int ySection = arrY[len]-arrY[i+s-1]+arrY[i-1];
		int weight = abs(ansX - xSection)+abs(ansY-ySection);
		if(weight<=s&&(s-weight)%2==0)
			return true;
	}
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d",&len);
	scanf("%s",str+1);
	scanf("%d %d",&ansX,&ansY);
	for(int i=1;i<=len;i++){
		switch(str[i]){
			case 'L':
				arrX[i]=arrX[i-1]-1;
				arrY[i]=arrY[i-1];
			break;
			case 'R':
				arrX[i]=arrX[i-1]+1;
				arrY[i]=arrY[i-1];
			break;
			case 'U':
				arrX[i]=arrX[i-1];
				arrY[i]=arrY[i-1]+1;
			break;
			case 'D':
				arrX[i]=arrX[i-1];
				arrY[i]=arrY[i-1]-1;
			break;
		}
	}
	// BiSearch
	int left = 0;
	int right = len;
	int ans = -1;
	while(left<=right){
		int mid = (left+right)>>1;
		if(isOK(mid)==true){
			ans=mid;
			right=mid-1;
		}else
			left = mid+1;
	}
	printf("%d\n",ans);
	return 0;
}