/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-15 19:40:51
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int cmp(const string, int p, int q);

int main(void) {
	string str;
	int t, i, minptr, len;
	cin >> t;
	while (t--) {
		cin >> str;
		//初始化变量
		minptr = 0;
		len = (int) str.length();
		//遍历循环寻找最小字典序
		for (i = 1; i < len; i++) {
			if (cmp(str, i, minptr))
				minptr = i;
		}
		//输出
		for (i = 0; i < len; i++)
		{
			cout << str[(i + minptr) % len];
		}
		cout << endl;
	}
	return 0;
}

int cmp(const string str, int p, int q) {
	int n = str.length();
	for (int i = 0; i < n; i++) {
		if (str[(p + i) % n] != str[(q + i) % n])
			return str[(p + i) % n] < str[(q + i) % n];
	}
	//两式相等
	return 0;
}