/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-05-11 10:08:29
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

int n, m;
struct Plant {
	int a;
	int b;
} P[1005];

double tmp, ans, nowM;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &P[i].a, &P[i].b);
		if(P[i].a == 1 || P[i].b == 1) {
			printf("-1\n");
			return 0;
		}
	}
	nowM = m;
	tmp = (double)nowM / (P[0].b - 1);
	nowM += tmp;
	ans += tmp;
	for(int i = n - 1; i >= 1; i--) {
		tmp = (double)nowM / (P[i].a - 1);
		nowM += tmp;
		ans += tmp;
		tmp = (double)nowM / (P[i].b - 1);
		nowM += tmp;
		ans += tmp;
	}
	tmp = (double)nowM / (P[0].a - 1);
	nowM += tmp;
	ans += tmp;
	printf("%.8f\n", ans);
	return 0;
}