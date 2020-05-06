/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-29 13:27:04
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

int calNumber(int n) {
	int i, tmp, tmpcal;
	tmpcal = 0;
	for (i = 2; i < n; i++) {
		tmp = n;
		//转换成i进制
		while (tmp > 0) {
			tmpcal += tmp % i;
			tmp /= i;
		}
	}
	return tmpcal;
}

int calGcd(int a, int b) {
	int tmp;
	while (b != 0) {
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}

int main(void) {
	int m, n, gcd;
	cin >> m;
	n = calNumber(m);
	gcd = calGcd(n, m - 2);
	printf("%d/%d\n", n / gcd, (m - 2) / gcd );
	return 0;
}