/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-22 12:18:04
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

int n, s;
int arr[105];
int maxcost;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		arr[i] *= s;
	}
	for (int i = 0; i < n; i++)
		maxcost = max(maxcost, arr[i]);
	if (maxcost % 1000 == 0)
		maxcost = maxcost / 1000;
	else {
		maxcost = (maxcost / 1000) + 1;
	}
	printf("%d\n",maxcost );
	return 0;
}