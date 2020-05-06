/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-13 17:51:13
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	int i, num;
	num = 0;
	while (getline(cin, str)) {
		for (i = 0; i != str.length(); i++)
		{
			if (str[i] == '"') {
				if (num == 0) {

					cout << "``";
					num = 1;
				} else {
					cout << "''";
					num = 0;
				}
			} else {
				cout << str[i];
			}
		}
		cout << endl;
	}
	return 0;
}