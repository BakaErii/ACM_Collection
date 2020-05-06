/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-24 14:59:35
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

bool vis[101];
struct node
{
	int a;
	int b;
} no[100];

bool cmp(node na, node nb) {
	return na.b < nb.b;
}

int main(void) {
	int i, j, n, m;
	vis[0] = true;
	for (i = 1; i <= 100; i++)
		vis[i] = false;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> no[i].a >> no[i].b;
	sort(no, no + n, cmp);
	for (i = 0; i < n; i++)
		if (vis[no[i].a] == true)
			for (j = no[i].a; j <= no[i].b; j++)
				vis[j] = true;
	if (vis[m] == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}