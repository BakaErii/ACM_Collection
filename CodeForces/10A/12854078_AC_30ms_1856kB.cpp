/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-15 17:10:41
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
	int power, n, p1, p2, p3, t1, t2, t, ts, te;
	cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;
	cin >> ts >> te;
	t = te;
	power = (te - ts) * p1;
	for (int i = 1; i < n; i++) {
		cin >> ts >> te;
		if (ts >= t + t1 + t2) {
			power += t1 * p1;
			power += t2 * p2;
			power += (ts - t - t1 - t2) * p3;
		} else if (ts > t + t1) {
			power += t1 * p1;
			power += (ts - t - t1) * p2;
		} else {
			power += (ts - t) * p1;
		}
		power += (te - ts) * p1;
		t = te;
	}
	cout << power << endl;
	return 0;
}