/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-09 19:31:05
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

int table[5843];

int main(void) {
	table[1] = 1;
	int i, num, tmp, p2, p3, p5, p7;
	p2 = p3 = p5 = p7 = 1;
	//递推打表
	for (i = 2; i < 5843; i++) {
		while (table[p2] * 2 <= table[i - 1])
			p2++;
		while (table[p3] * 3 <= table[i - 1])
			p3++;
		while (table[p5] * 5 <= table[i - 1])
			p5++;
		while (table[p7] * 7 <= table[i - 1])
			p7++;
		tmp = table[p2] * 2;
		if (table[p3] * 3 < tmp)
			tmp = table[p3] * 3;
		if (table[p5] * 5 < tmp)
			tmp = table[p5] * 5;
		if (table[p7] * 7 < tmp)
			tmp = table[p7] * 7;
		table[i] = tmp;
	}
	while (cin >> num && num != 0) {
		tmp = num;
		while (tmp > 100)
			tmp %= 100;
		if (!(tmp >= 11 && tmp <= 13))
			tmp %= 10;
		cout << "The ";
		switch (tmp) {
		case 1: cout << num << "st"; break;
		case 2: cout << num << "nd"; break;
		case 3: cout << num << "rd"; break;
		default: cout << num << "th"; break;
		}
		cout << " humble number is " << table[num] << "." << endl;
	}
	return 0;
}