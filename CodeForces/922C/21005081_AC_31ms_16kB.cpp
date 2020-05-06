/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-02 16:03:57
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

LL n, k;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i <= k; i++)
		if (n % i != i - 1) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}