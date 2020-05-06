/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-22 20:21:10
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
	int i, len, kase;
	cin >> kase;
	getchar();
	for (i = 0; i < kase; i++) {
		getline(cin,str);
		len = (int)str.length();
		sort(str.begin(), str.end());
		do {
			cout<<str<<endl;
		} while (next_permutation(str.begin(), str.end()));
		putchar('\n');
	}
	return 0;
}
