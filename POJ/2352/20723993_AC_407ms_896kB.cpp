/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-24 12:36:37
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

const int maxX = 32005;
const int maxN = 15005;

int arrLocX[maxX];
int arrLevel[maxN];

int n;

int LowBit(int x) {
	return x & (-x);
}

void Update(int x) {
	for (int i = x; i < maxX; i += LowBit(i))
		arrLocX[i]++;
	return;
}

int Query(int x) {
	int ret = 0;
	for (int i = x; i > 0; i -= LowBit(i))
		ret += arrLocX[i];
	return ret;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d", &n);
	int x, y;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		x++;
		arrLevel[Query(x)]++;
		Update(x);
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", arrLevel[i]);
	return 0;
}