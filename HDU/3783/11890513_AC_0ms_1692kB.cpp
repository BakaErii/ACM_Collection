/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-08 18:15:29
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
	int i, znum, onum, jnum;
	while (cin >> str && str[0] != 'E') {
		znum = 0;
		onum = 0;
		jnum = 0;
		for (i = 0; i < (int)str.length(); i++)
			switch (str[i]) {
			case 'Z': znum++; break;
			case 'O': onum++; break;
			case 'J': jnum++; break;
			}
		while (znum != 0 || onum != 0 || jnum != 0) {
			if (znum != 0) {
				putchar('Z');
				znum--;
			}
			if (onum != 0) {
				putchar('O');
				onum--;
			}
			if (jnum != 0) {
				putchar('J');
				jnum--;
			}
		}
		putchar('\n');
	}
	return 0;
}