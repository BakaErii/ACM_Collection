/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-13 18:33:45
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
	string str;
	char str1[100];
	char str2[100];
	char num[100];
	int i, n, c, r, len, type, ptr;
	cin >> n;
	getchar();
	while (n--) {
		cin >> str;
		c = 0;
		r = 0;
		len = (int)str.length();
		//当tpye=0时 为RxxCxx
		type = 1;
		if (str[0] == 'R' && len != 2 && str[1] >= '0' && str[1] <= '9')
			for (i = 2; i < len; i++) {
				if (str[i] == 'C') {
					type = 0;
					break;
				}
			}
		switch (type) {
		case 0:
			for (i = 1; i < len; i++) {
				if (str[i] != 'C')
					r = r * 10 + str[i] - '0';
				else {
					i++;
					for (; i < len; i++)
						c = c * 10 + str[i] - '0';
				}
			}
			break;
		case 1:
			for (i = 0; i < len; i++)
				if (str[i] < '0' || str[i] > '9')
					c = c * 26 + str[i] - 'A' + 1;
				else
					for (; i < len; i++)
						r = r * 10 + str[i] - '0';
			break;
		}
		switch (type) {
		case 0:
			ptr = 0;
			while (c > 0) {
				c--;
				num[ptr++] = c % 26 + 'A';
				c /= 26;
			}
			for (i = ptr - 1; i >= 0; i--)
				cout << num[i];
			cout << r << endl;
			break;
		case 1:
			cout << "R" << r << "C" << c << endl;
			break;
		}
	}
	return 0;
}