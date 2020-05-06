/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-01 18:32:10
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

string str;

int tenpw(int a) {
	int i, tmp;
	tmp = 1;
	for (i = 0; i < a; i++)
		tmp *= 10;
	return tmp;
}

int main(void) {
	int a, b, count, tmp, isFB;
	count = 0;
	tmp = 0;
	while (cin >> str) {
		//判断数字输入
		if (str == "one")
			tmp = tmp * tenpw(count++) + 1;
		else if (str == "two")
			tmp = tmp * tenpw(count++) + 2;
		else if (str == "three")
			tmp = tmp * tenpw(count++) + 3;
		else if (str == "four")
			tmp = tmp * tenpw(count++) + 4;
		else if (str == "five")
			tmp = tmp * tenpw(count++) + 5;
		else if (str == "six")
			tmp = tmp * tenpw(count++) + 6;
		else if (str == "seven")
			tmp = tmp * tenpw(count++) + 7;
		else if (str == "eight")
			tmp = tmp * tenpw(count++) + 8;
		else if (str == "nine")
			tmp = tmp * tenpw(count++) + 9;
		else if (str == "zero")
			tmp = tmp * tenpw(count++) + 0;
		//判断相加
		if (str == "+") {
			//赋值并清零变量
			a = tmp;
			tmp = 0;
			count = 0;
		}
		//求和 初始化变量
		if (str == "=") {
			b = tmp;
			tmp = 0;
			count = 0;
			if (a == 0 && b == 0)
				return 0;
			cout << a + b << endl;
		}
	}
	return 0;
}