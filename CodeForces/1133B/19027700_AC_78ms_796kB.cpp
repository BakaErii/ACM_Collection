/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-01 07:59:41
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

const int maxK = 105;
const int maxN = 200005;

int n, k, ans;
int arr[maxN];
int arrLeft[maxK];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		arrLeft[arr[i] % k]++;
	}
	ans += arrLeft[0] / 2;
	for(int i = 1; i <= k / 2; i++) {
		if(i == k - i)
			tmp = arrLeft[i] / 2;
		else
			tmp = min(arrLeft[i], arrLeft[k - i]);
		ans += tmp;
	}
	printf("%d\n", ans * 2);
	return 0;
}