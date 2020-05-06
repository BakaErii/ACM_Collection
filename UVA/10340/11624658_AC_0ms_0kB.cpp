/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-18 22:36:04
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str, cmpstr;
	int len, cmplen, i, ptr, cmpptr;
	bool isEnd, isDone;
	while (cin >> str >> cmpstr) {
		//初始化变量
		len = (int)str.length();
		cmplen = (int)cmpstr.length();
		isEnd = false;
		isDone = false;
		ptr = 0;
		cmpptr = 0;
		//比较
		while (!isEnd) {
			for (i = cmpptr; i < cmplen; i++)
			{
				if (str[ptr] == cmpstr[i]) {
					ptr++;
					cmpptr = ++i;
					break;
				}
			}
			if (i == cmplen) {
				//没找到
				isEnd = true;
			}
			if (ptr == len) {
				//全找完了
				isEnd = true;
				isDone = true;
			}
		}
		if (isDone)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}