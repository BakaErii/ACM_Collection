/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-19 18:23:53
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int 	a, b, i;
	while (cin >> a >> b) {
		i = 0;
		while (a >= 0 && b >= 0) {
			if (i % 2 == 0)
				a -= ++i;
			else
				b -= ++i;
		}
		if (i % 2 == 0)
			cout << "Valera" << endl;
		else
			cout << "Vladik" << endl;
	}
	return 0;
}