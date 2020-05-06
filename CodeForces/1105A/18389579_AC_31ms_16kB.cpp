/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-20 20:08:10
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

const int maxN = 1005;

int arr[maxN];
int n, ansPos, ansCost;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int nowCost;
	scanf("%d", &n);
	ansCost = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i <= 100; i++) {
		nowCost = 0;
		for (int j = 0; j < n; j++)
			if (arr[j] > i)
				nowCost += abs(arr[j] - (i + 1));
			else if (arr[j] < i)
				nowCost += abs((i - 1) - arr[j]);
		if (nowCost < ansCost) {
			ansCost = nowCost;
			ansPos = i;
		}
	}
	printf("%d %d\n", ansPos, ansCost );
	return 0;
}