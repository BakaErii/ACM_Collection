/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-07 15:42:05
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

map<string, int> smap;
map<string, int>::iterator it;

int main(void) {
	int n = 0;
	string str;
	while (getline(cin, str)) {
		smap[str]++;
		n++;
	}
	cout.setf(ios::fixed);
	cout.precision(4);
	for (it = smap.begin(); it != smap.end(); it++) {
		cout << it->first << " " << 100.0 * (it->second) / n << endl;
	}
	return 0;
}