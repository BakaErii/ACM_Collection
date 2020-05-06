/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-13 20:35:26
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
	unsigned long long  n, m, a, w, d;
	cin >> n >> m >> a;
	w = n / a;
	d = m / a;
	if (n % a != 0)
		w++;
	if (m % a != 0)
		d++;
	cout << w*d << endl;
	return 0;
}