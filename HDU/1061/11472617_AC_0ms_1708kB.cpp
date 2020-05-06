/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-07 21:56:02
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int pm(int a);

int main(void) {
	int T, n,i;
	while (cin >> T)
		for (i = 0; i < T; i++) {
			cin >> n;
			cout << pm(n) << endl;
		}
	return 0;
}

int pm(int a) {
	int tmp = 1;
	int times = a;
	a %= 10;
	while (times > 0) {
		if (times % 2 == 1)
			tmp = (tmp * a) % 10;
		times /= 2;
		a = (a * a) % 10;
	}
	return tmp;
}