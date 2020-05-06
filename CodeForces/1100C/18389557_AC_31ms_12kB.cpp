/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-15 11:34:00
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	const double PI = 3.1415926535;
	double n, r, tmp, ans;
	scanf("%lf %lf", &n, &r);
	tmp = sin(PI / n);
	ans = (r * tmp) / (1 - tmp);
	printf("%.7lf\n", ans);
	return 0;
}