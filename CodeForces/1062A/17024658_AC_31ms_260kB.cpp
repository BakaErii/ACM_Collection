/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-15 19:26:07
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

int arr[1005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, ans = 0, cnt = 1, maxAns = 0, iBegin, iEnd, tmp;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] + 1 == arr[i]) {
			cnt++;
			iEnd = arr[i];
		}
		else
			cnt = 1;
		ans = max(ans, cnt);
		if (ans > 1) {
			iBegin = iEnd - cnt + 1;
			tmp = cnt - 2;
			if (iBegin == 1 || iEnd == 1000)
				tmp = cnt - 1;
			maxAns = max(maxAns, tmp);
		}
	}
	cout << maxAns << endl;
	return 0;
}