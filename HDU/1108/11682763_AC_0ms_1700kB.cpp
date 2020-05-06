/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-23 15:05:12
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int a, b, x, y;
	while (cin >> a >> b) {
		x = a;
		y = b;
		while (y != 0) {
			x %= y;
			swap(x, y);
		}
		cout << a*b / x << endl;
	}
	return 0;
}
