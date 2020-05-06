/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-29 23:36:36
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

string name[1000];
map<string, int> smap;

int main(void) {
	string command, ip;
	int i, n, m;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> command >> ip;
		name[i] = command;
		smap[ip] = i;
	}
	for (i = 0; i < m; i++) {
		cin >> command >> ip;
		ip.pop_back();
		cout << command << " " << ip << "; #" << name[smap[ip]] << endl;
	}
	return 0;
}