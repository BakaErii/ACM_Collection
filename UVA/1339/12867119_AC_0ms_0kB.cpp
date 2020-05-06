/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-23 13:45:52
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
int a[26], b[26];

int main(void) {
	int i;
	while (getline(cin, str)) {
		//init
		for (i = 0; i < 26; i++) {
			a[i] = 0;
			b[i] = 0;
		}
		for (i = 0; i < (int)str.length(); i++)
			a[(int)(str[i] - 'A')]++;
		getline(cin, str);
		for (i = 0; i < (int)str.length(); i++)
			b[(int)(str[i] - 'A')]++;
		sort(a, a + 26);
		sort(b, b + 26);
		for (i = 0; i < 26; i++)
			if (a[i] != b[i])
				break;
		if (i == 26)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}