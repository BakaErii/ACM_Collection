/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-11 20:57:19
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

LL n, m, q;
LL a[3];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int r1, r2;
	LL c1, c2;
	cin >> a[1] >> a[2] >> q;
	LL seq = __gcd(a[1], a[2]);
	while (q--) {
		cin >> r1 >> c1 >> r2 >> c2;
		c1--;
		c2--;
		LL sq1 = c1 / (a[r1] / seq);
		LL sq2 = c2 / (a[r2] / seq);
		if (sq1 == sq2)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}