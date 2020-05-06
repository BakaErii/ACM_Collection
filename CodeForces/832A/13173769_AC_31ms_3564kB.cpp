/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-03-24 18:50:01
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
	unsigned long long int n, k;
	scanf("%llu %llu", &n, &k);
	if ((n / k) % 2 != 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}