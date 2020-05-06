/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-05 01:29:59
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

typedef long long int LL;

const int maxN = 100005;

int n;
int arr[maxN];
int maxNum = -0x3f3f3f3f;
LL sum = 0;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		maxNum = max(arr[i], maxNum);
		sum += arr[i];
	}
	if (sum % 2 == 0 && sum / 2 >= maxNum)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}