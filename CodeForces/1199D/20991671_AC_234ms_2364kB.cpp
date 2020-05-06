/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-31 13:54:57
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

const int maxN = 200005;

int arr[maxN];
int vis[maxN];
int arrOp[maxN];

int n, q;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, c;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d", &a);
		switch (a) {
		case 1:
			scanf("%d %d", &b, &c);
			arr[b] = c;
			vis[b] = i;
			break;
		case 2:
			scanf("%d", &b);
			arrOp[i] = b;
			break;
		}
	}
	for (int i = q - 1; i >= 1; i--)
		arrOp[i] = max(arrOp[i], arrOp[i + 1]);
	for (int i = 1; i <= n; i++)
		printf("%d%c", max(arr[i], arrOp[vis[i] + 1]), " \n"[i == n]);
	return 0;
}