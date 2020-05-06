/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-24 18:54:02
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
	int a, b, tmp, d;
	while (~scanf("%d %d", &a, &b)) {
		if (b > a)
			swap(a, b);
		d = a - b;
		tmp = d * (1 + sqrt(5)) / 2;
		if (b == tmp)
			cout << "0" << endl;
		else
			cout << "1" << endl;
	}
	return 0;
}