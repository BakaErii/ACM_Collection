/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-19 18:11:52
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

map<string, size_t> mail;

int main(void) {
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (mail[str] == 0) {
			cout << "OK" << endl;
			mail[str]++;
		} else {
			cout << str << mail[str] << endl;
			mail[str]++;
		}
	}
	return 0;
}