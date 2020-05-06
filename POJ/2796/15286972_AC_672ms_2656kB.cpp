/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-08-08 14:38:55
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
int arrLeft[maxN];
int arrStack[maxN];	//存储对应元素在arr中的下标
int topPtr;
long long int arrSum[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	long long int ans = -1, tmp;
	int n, ansLeft, ansRight;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		arrSum[i] = arrSum[i - 1] + arr[i];
	}
	arr[++n] = -1;
	topPtr = 0;
	for (int i = 1; i <= n; i++) {
		//当栈中无元素或者当前入栈元素大于栈顶元素(满足单调) 元素入栈
		if (topPtr == 0 || arr[i] > arr[arrStack[topPtr - 1]]) {
			arrStack[topPtr++] = i;
			arrLeft[i] = i;
			continue;
		}
		//当栈顶元素和入栈元素相等时 不影响 不入栈
		if (arr[i] == arr[arrStack[topPtr - 1]])
			continue;
		//当栈中存在元素且当前入栈元素大于栈顶元素(不满足单调) 先出栈 后入栈 保持单调性
		while (topPtr >= 1 && arr[i] < arr[arrStack[topPtr - 1]]) {
			//指针回退到有元素的位置上
			topPtr--;
			//计算当前答案
			tmp = arr[arrStack[topPtr]] * (arrSum[i - 1] - arrSum[arrLeft[arrStack[topPtr]] - 1]);
			//cerr << tmp << endl;
			//更新答案
			if (tmp > ans) {
				ansLeft = arrLeft[arrStack[topPtr]];
				ansRight = i - 1;
				ans = tmp;
			}
		}
		//更新出栈元素的区间
		arrLeft[i] = arrLeft[arrStack[topPtr]];
		arrStack[topPtr++] = i;
	}
	printf("%lld\n", ans );
	printf("%d %d\n", ansLeft, ansRight);
	return 0;
}