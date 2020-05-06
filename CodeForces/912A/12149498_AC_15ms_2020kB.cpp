/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-05 22:39:17
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
	long long int a, b, la, lb;
	long long int y, g, bl;
	cin >> a >> b;
	cin >> y >> g >> bl;
	la = y * 2 + g;
	la -= a;
	if (la < 0)
		la = 0;
	lb = bl * 3 + g;
	lb -= b;
	if (lb < 0)
		lb = 0;
	cout << la + lb << endl;
	return 0;
}