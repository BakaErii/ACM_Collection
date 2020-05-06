/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-19 19:00:06
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
int score[1000];
map<string, int> m1, m2;

int main(void) {
	int i, n, maxs = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> name[i] >> score[i];
		m1[name[i]] += score[i];
	}
	for (i = 0; i < n; i++)
		maxs = max(m1[name[i]], maxs);
	for (i = 0; i < n; i++) {
		m2[name[i]] += score[i];
		if (m2[name[i]] >= maxs && m1[name[i]] >= maxs) {
			cout << name[i] << endl;
			break;
		}
	}
	return 0;
}