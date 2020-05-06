/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-11 21:14:08
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

const int maxN = 105;

int n, m, k, t;
int arr[maxN];
LL bagLeft;
bool isOK;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int op, change;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d %d", &n, &m, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		bagLeft = m;
		isOK = false;
		for (int i = 1; i < n; i++) {
			op = arr[i] - arr[i - 1];
			if (op > k) {
				change = op - k;
				if (change > bagLeft) {
					isOK = true;
					break;
				}
				bagLeft -= change;
			} else {
				op = arr[i] - k;
				op = min(arr[i - 1] - op, arr[i - 1]);
				bagLeft += op;
			}
		}
		if (isOK == true)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}