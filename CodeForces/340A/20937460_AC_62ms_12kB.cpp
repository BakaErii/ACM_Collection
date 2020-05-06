/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-31 14:34:35
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

int x, y, a, b;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d %d %d", &x, &y, &a, &b);
	int lcm = (x * y) / __gcd(x, y);
	printf("%d\n", b / lcm - (a - 1) / lcm);
	return 0;
}