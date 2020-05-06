/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-07 22:52:55
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int pm(int num, int times);

int main(void) {
	int a, b;
	while (cin >> a >> b) {
		cout << pm(a, b) << endl;
	}
	return 0;
}

int pm(int num, int times) {
	int tmp = 1;
	num %= 10;
	while (times > 0) {
		if (times % 2 == 1)
			tmp = (tmp * num) % 10;
		times /= 2;
		num = (num * num) % 10;
	}
	return tmp;
}