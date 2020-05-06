/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-22 15:44:32
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
	long long int i, n, k, ans_id, ans_num, ans_remain, tmp;
	cin >> n >> k;
	cin >> tmp;
	ans_id = 1;
	ans_num = n / tmp;
	ans_remain = n % tmp;
	for (i = 1; i < k; i++) {
		cin >> tmp;
		if (n % tmp < ans_remain ) {
			ans_id = i + 1;
			ans_num = n / tmp;
			ans_remain = n % tmp;
		}
	}
	cout << ans_id << " " << ans_num << endl;
	return 0;
}