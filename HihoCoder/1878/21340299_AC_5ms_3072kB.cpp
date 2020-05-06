/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-08-16 14:51:21
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

string str, tmpStr;
int t;


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--) {
		cin >> str;
		if (str.length() == 1) {
			cout << str[0] - '1' << endl;
			continue;
		}
		bool flag = false;
		if (str[0] - '1' == 0 && str[1] >= '1')
			flag = true;
		str[0] = str[0] - 1;
		int ptr;
		if (str[0] == '0') {
			ptr = 1;
			if (str[ptr] == '0')
				str[ptr] = '9';
		}
		else
			ptr = 0;
		tmpStr = "";
		for (int i = ptr; i < (int)str.length(); i++)
			tmpStr.push_back(str[i]);
		cout << tmpStr;
		if (flag == false)
			tmpStr.pop_back();
		reverse(tmpStr.begin(), tmpStr.end());
		cout << tmpStr << endl;
	}
	return 0;
}