/**
 * @author	Moe_Sakiya	sakiya@tun.moe
 * @date	2019-10-04 16:30:25
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

int arr[10005];
int cnt;

void Init() {
	int raw = 1;
	for(int i = 1; i <= 10000; i++) {
		while(true) {
			int tmp = raw;
			int ret = 0;
			while(tmp > 0) {
				ret += tmp % 10;
				tmp /= 10;
			}
			if(ret == 10) {
				arr[i] = raw;
				raw++;
				break;
			}
			raw++;
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	Init();
	int k;
	scanf("%d", &k);
	printf("%d\n", arr[k]);
	return 0;
}