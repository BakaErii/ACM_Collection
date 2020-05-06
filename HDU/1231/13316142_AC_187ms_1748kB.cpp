/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-04-04 12:40:50
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

int arr[10001];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int i, k, nowSum, maxSum, frontPtr, eleNum, maxFrontPtr, maxEleNum;
	bool isSpecial;
	while (~scanf("%d", &k) && k != 0) {
		//Init
		isSpecial = true;
		nowSum = 0;
		maxSum = -1;
		frontPtr = 0;
		eleNum = 0;
		maxFrontPtr = 0;
		maxEleNum = 0;
		//In
		for (i = 0; i < k; i++) {
			scanf("%d", &arr[i]);
			if (arr[i] >= 0)
				isSpecial = false;
		}
		//SpecialJudge
		if (isSpecial == true) {
			printf("0 %d %d\n", arr[0], arr[k - 1] );
			continue;
		}
		//Solve
		for (i = 0; i < k; i++) {
			nowSum += arr[i];
			if (nowSum > maxSum) {
				//UpdateStatus
				maxFrontPtr = frontPtr;
				maxEleNum = eleNum;
				maxSum = nowSum;
			}
			frontPtr++;
			eleNum++;
			if (nowSum < 0) {
				nowSum = 0;
				eleNum = 0;
			}
		}
		printf("%d %d %d\n", maxSum, arr[maxFrontPtr - maxEleNum], arr[maxFrontPtr] );
	}
	return 0;
}