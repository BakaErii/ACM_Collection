/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-13 18:32:55
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	string conststr = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	int i, j;
	while (getline(cin, str)) {
		for (i = 0; i != str.length(); i++) {
			//寻找在字符串中的元素
			for (j = 0; j != conststr.length(); j++)
				if (conststr[j] == str[i]) {
					cout << conststr[j - 1];
					break;
				}
			if (j == conststr.length())
				cout << " ";
		}
		cout << endl;
	}
	return 0;
}