/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-18 23:59:27
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int i, t, ptr;
	char str[1000];
	cin >> t;
	getchar();
	while (t) {
		ptr = 0;
		while (str[ptr] = getchar()) {
			if (str[ptr] == ' ') {
				str[ptr] = '\0';
				for (i = --ptr; i >= 0; i--) {
					cout << str[i];
				}
				cout << " ";
				break;
			} else if (str[ptr] == '\n') {
				t--;
				str[ptr] = '\0';
				for (i = --ptr; i >= 0; i--) {
					cout << str[i];
				}
				cout << endl;
				break;
			}
			ptr++;
		}
	}
	return 0;
}