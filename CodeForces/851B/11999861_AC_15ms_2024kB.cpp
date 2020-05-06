/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-17 17:51:03
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
	long long int ax, ay, bx, by, cx, cy;
	long long int da, db, ka, kb;
	cin >> ax >> ay >> bx >> by >> cx >> cy;
	da = (ax - bx) * (ax - bx) + (ay - by) * (ay - by);
	db = (cx - bx) * (cx - bx) + (cy - by) * (cy - by);
	ka = (by - ay) * (bx - cx);
	kb = (by - cy) * (bx - ax);
	if (da == db && ka != kb)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}