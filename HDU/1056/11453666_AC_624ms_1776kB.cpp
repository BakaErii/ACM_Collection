/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-07 20:05:57
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int  i;
	double n, tmp;
	while (cin >> n && n != 0) {
		i = 2;
		tmp = 0;
		while (tmp < n ) {
			tmp += 1 / (double)i;
			i++;
		}
		printf("%d card(s)\n", i - 2 );
	}
	return 0;
}