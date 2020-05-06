/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-23 16:59:09
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	//x+y=a x-y=b (x>y) => 2x=a+b y=x-b
	int n, a, b, y;
	double x;
	cin >> n;
	while (n--) {
		cin >> a >> b;
		x = (a + b) / 2.0;
		if (x != (int)x)
			x = (int)x + 1;
		y = x - b;
		if (y < 0 || x + y != a)
			cout << "impossible" << endl;
		else
			cout << x << " " << y << endl;
	}
	return 0;
}