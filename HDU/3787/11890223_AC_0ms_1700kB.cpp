/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-08 18:00:48
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
	string str1, str2;
	int a, b, i;
	bool flag;
	while (cin >> str1 >> str2) {
		a = 0;
		b = 0;
		flag = false;
		for (i = 0; i < (int)str1.length(); i++) {
			if (str1[i] != ',' && str1[i] != '-')
				a = a * 10 + str1[i] - '0';
			else if (str1[i] == '-')
				flag = true;
		}
		if (flag == true)
			a = -a;
		flag = false;
		for (i = 0; i < (int)str2.length(); i++) {
			if (str2[i] != ',' && str2[i] != '-')
				b = b * 10 + str2[i] - '0';
			else if (str2[i] == '-')
				flag = true;
		}
		if (flag == true)
			b = -b;
		cout << a + b << endl;
	}
	return 0;
}