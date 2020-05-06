/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-17 18:40:02
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
	int xs, ys, xe, ye, dx, dy, tmpx, tmpy, ans;
	xs = getchar() - 'a' + 1;
	ys = getchar() - '0';
	getchar();
	xe = getchar() - 'a' + 1;
	ye = getchar() - '0';
	dx = xe - xs;
	dy = ye - ys;
	tmpx = dx;
	tmpy = dy;
	ans = 0;
	while (tmpy != 0 || tmpx != 0) {
		if (tmpx > 0) {
			tmpx--;
		}
		if (tmpx < 0) {
			tmpx++;
		}
		if (tmpy > 0) {
			tmpy--;
		}
		if (tmpy < 0) {
			tmpy++;
		}
		ans++;
	}
	cout << ans << endl;
	tmpx = dx;
	tmpy = dy;
	while (tmpy != 0 || tmpx != 0) {
		if (tmpx > 0) {
			cout << "R";
			tmpx--;
		}
		if (tmpx < 0) {
			cout << "L";
			tmpx++;
		}
		if (tmpy > 0) {
			cout << "U";
			tmpy--;
		}
		if (tmpy < 0) {
			cout << "D";
			tmpy++;
		}
		cout << endl;
	}
	return 0;
}