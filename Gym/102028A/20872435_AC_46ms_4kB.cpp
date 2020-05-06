/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2019-07-29 12:42:48
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

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int tmp;
	int n, a;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		a = 0;
		for (int j = 0; j < 4; j++) {
			scanf("%d", &tmp);
			if (tmp != 0)
				a++;
		}
		switch (a) {
		case 0: cout << "Typically Otaku" << endl; break;
		case 1: cout << "Eye-opener" << endl;break;
		case 2: cout << "Young Traveller" << endl;break;
		case 3: cout << "Excellent Traveller" << endl;break;
		case 4: cout << "Contemporary Xu Xiake" << endl;break;
		}
	}
	return 0;
}