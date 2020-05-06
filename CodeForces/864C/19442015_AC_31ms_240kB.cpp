/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-04-24 18:56:52
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

int a, b, f, k;
int nowDis, nowFuel, ans;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d %d %d", &a, &b, &f, &k);
	nowDis = 0;
	nowFuel = b;
	for(int i = 0; i < k; i++) {
		switch(nowDis) {
		case 0:
			// to gas station
			if(f > nowFuel) {
				printf("-1\n");
				return 0;
			}
			nowFuel -= f;
			// check fuel is enough?
			if(i == k - 1) {
				if(nowFuel < (a - f)) {
					nowFuel = b;
					ans++;
				}
			} else {
				if(nowFuel < (a - f) * 2) {
					nowFuel = b;
					ans++;
				}
			}
			// to a point
			if(nowFuel < a - f) {
				printf("-1\n");
				return 0;
			}
			nowFuel -= a - f;
			nowDis = 1;
			break;
		case 1:
			// to gas station
			if(a - f > nowFuel) {
				printf("-1\n");
				return 0;
			}
			nowFuel -= a - f;
			// check fuel enough?
			if(i == k - 1) {
				if(nowFuel < f) {
					nowFuel = b;
					ans++;
				}
			} else {
				if(nowFuel < f * 2) {
					nowFuel = b;
					ans++;
				}
			}
			// to 0 poinr
			if(nowFuel < f) {
				printf("-1\n");
				return 0;
			}
			nowFuel -= f;
			nowDis = 0;
			break;
		}
	}
	printf("%d\n", ans );
	return 0;
}