/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-20 19:38:30
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	bool l1 = true, l2 = true, l3 = true, l4 = true, isSafe = true;
	int i, l, s, r, p[4];
	//判断各个路口情况
	for (i = 0; i < 4; i++)
	{
		cin >> l >> s >> r >> p[i];
		switch (i) {
		case 0:
			if (l == 1) {
				l1 = false;
				l4 = false;
			}
			if (s == 1) {
				l1 = false;
				l3 = false;
			}
			if (r == 1) {
				l1 = false;
				l2 = false;
			}
			break;
		case 1:
			if (l == 1) {
				l1 = false;
				l2 = false;
			}
			if (s == 1) {
				l2 = false;
				l4 = false;
			}
			if (r == 1) {
				l3 = false;
				l2 = false;
			}
			break;
		case 2:
			if (l == 1) {
				l3 = false;
				l2 = false;
			}
			if (s == 1) {
				l1 = false;
				l3 = false;
			}
			if (r == 1) {
				l3 = false;
				l4 = false;
			}
			break;
		case 3:
			if (l == 1) {
				l3 = false;
				l4 = false;
			}
			if (s == 1) {
				l2 = false;
				l4 = false;
			}
			if (r == 1) {
				l4 = false;
				l1 = false;
			}
			break;
		}
	}
	//判断人行道情况
	for (i = 0; i < 4; i++)
		switch (i) {
		case 0:
			if (p[i] == 1)
				if (!l1)
					isSafe = false;
			break;
		case 1:
			if (p[i] == 1)
				if (!l2)
					isSafe = false;
			break;
		case 2:
			if (p[i] == 1)
				if (!l3)
					isSafe = false;
			break;
		case 3:
			if (p[i] == 1)
				if (!l4)
					isSafe = false;
			break;
		}
	//输出
	if (isSafe)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
	return 0;
}