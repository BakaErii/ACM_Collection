/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-05 14:35:12
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

int main(void) {
	int i;
	bool isYes = true;
	cin >> str;
	while (str[(int)str.length() - 1] == '0')
		str.pop_back();
	for (i = 0; i < (int)str.length() / 2; i++) {
		if (str[i] != str[(int)str.length() - i - 1])
			isYes = false;
	}
	if (isYes)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}