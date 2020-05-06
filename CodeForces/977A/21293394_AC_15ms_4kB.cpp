/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-14 14:14:38
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
	int n, k;
	scanf("%d %d", &n, &k);
	while (k--) {
		if (n % 10 == 0)
			n /= 10;
		else
			n--;
	}
	cout << n << endl;
	return 0;
}