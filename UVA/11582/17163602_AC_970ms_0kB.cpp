/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-24 14:58:37
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

const int maxN = 10005;

unsigned long long int fac[maxN];

unsigned long long int pm(unsigned long long int a, unsigned long long int b, unsigned long long int c) {
	unsigned long long int tmp = 1 % c;
	a = a % c;
	while (b > 0) {
		if (b % 2 == 1)
			tmp = (tmp * a) % c;
		b /= 2;
		a = (a * a) % c;
	}
	return tmp;
}

int main(void) {
	unsigned long long int t, n, mod = 0;
	unsigned long long int x, y;
	cin >> t;
	while (t--) {
		cin >> x >> y >> n;
		fac[0] = 0;
		fac[1] = 1 % n;
		for (int i = 2; i < maxN; i++)
			fac[i] = (fac[i - 1] + fac[i - 2]) % n;
		for (int i = 4; i < maxN - 10; i++)
			if (fac[1] == fac[i] && fac[2] == fac[i + 1] && fac[3] == fac[i + 2] && fac[4] == fac[i + 3]){
				mod = i;
				break;
			}
		mod--;
		cout << fac[pm(x, y, mod)] << endl;
	}
	return 0;
}