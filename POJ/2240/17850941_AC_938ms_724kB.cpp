/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-01-21 01:01:00
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

const int maxN = 32;

int n, k, kase;

struct Edge
{
	int u, v;
	double val;
} E[maxN * maxN];

map<string, int> mp;

bool BF(int startPos) {
	double arrDis[maxN];
	memset(arrDis, 0, sizeof(arrDis));
	arrDis[startPos] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			if (arrDis[E[j].v] < arrDis[E[j].u]*E[j].val)
				arrDis[E[j].v] = arrDis[E[j].u] * E[j].val;
	if (arrDis[startPos] > 1)
		return true;
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string tmpStrA, tmpStrB;
	double curr;
	bool isHas;
	while (cin >> n && n != 0) {
		// Init
		isHas = false;
		mp.clear();
		// Input
		for (int i = 0; i < n; i++) {
			cin >> tmpStrA;
			mp[tmpStrA] = i;
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> tmpStrA >> curr >> tmpStrB;
			E[i].u = mp[tmpStrA];
			E[i].v = mp[tmpStrB];
			E[i].val = curr;
		}
		// BF
		for (int i = 0; i < n; i++)
			if (BF(i)) {
				isHas = true;
				break;
			}
		printf("Case %d: %s\n", ++kase, isHas ? "Yes" : "No");
	}
	return 0;
}