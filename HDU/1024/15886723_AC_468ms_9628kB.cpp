/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date	2018-09-11 07:51:41
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

const int maxN = 1000005;
const int INF = -(~0u >> 1);
int arr[maxN], arrDp[maxN], arrMax[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	int maxSum;
	while(~scanf("%d %d", &m, &n)) {
		//INIT
		memset(arrDp, 0, sizeof(arrDp));
		memset(arrMax, 0, sizeof(arrMax));
		for(int i = 1; i <= n; i++)
			scanf("%d", &arr[i]);
		for(int i = 1; i <= m; i++) {
			maxSum = INF;
			for(int j = i; j <= n; j++) {
				arrDp[j] = max(arrDp[j - 1] + arr[j], arrMax[j - 1] + arr[j]);
				arrMax[j - 1] = maxSum;
				maxSum = max(maxSum, arrDp[j]);
			}
		}
		cout << maxSum << endl;
	}
	return 0;
}