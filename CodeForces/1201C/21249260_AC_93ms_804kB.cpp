/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-05 01:22:42
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

int n, k;
int arr[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	int nowPtr = n / 2;
	int nowCnt = 1;
	for (int i = nowPtr + 1; i < n; i++) {
		int op = min(k / nowCnt, arr[i] - arr[nowPtr]);
		if (k / nowCnt == 0) {
			printf("%d\n", arr[nowPtr]);
			return 0;
		}
		k -= op * nowCnt;
		arr[nowPtr] += op;
		nowCnt++;
	}
	arr[nowPtr] += k / nowCnt;
	printf("%d\n", arr[nowPtr]);
	return 0;
}