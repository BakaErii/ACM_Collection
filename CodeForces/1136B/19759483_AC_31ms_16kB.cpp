/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-16 09:56:43
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

int n, k;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &k);
	printf("%d\n", 3 * n + min(k - 1, n - k));
	return 0;
}