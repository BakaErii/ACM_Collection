/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-13 22:09:04
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

int arr[maxN];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, E = 0, S = 0;
	int maxAns = -1;
	int nowE, nowS;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1)
			E++;
		else
			S++;
	}
	for (int i = 0; i < k; i++) {
		nowE = E;
		nowS = S;
		for (int j = i; j < n; j += k)
			if (arr[j] == 1)
				nowE--;
			else
				nowS--;
		maxAns = max(maxAns, abs(nowE - nowS));
	}
	printf("%d\n",maxAns );
	return 0;
}