/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-05-16 09:56:43
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

int n;
struct Node
{
	int a;
	int b;
} N[105];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &N[i].a, &N[i].b);
	scanf("%d", &t);
	for (int i = 0; i < n; i++)
		if (t <= N[i].b)
			ans++;
	printf("%d\n", ans );
	return 0;
}