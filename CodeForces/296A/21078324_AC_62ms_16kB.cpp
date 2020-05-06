/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-05 14:00:57
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

const int maxN = 105;

int n;
int arr[1005];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	int maxVal = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		arr[tmp]++;
	}
	for (int i = 0; i < 1005; i++)
		maxVal = max(maxVal, arr[i]);
	if (n - maxVal >= maxVal - 1)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}