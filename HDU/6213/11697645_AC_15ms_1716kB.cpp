/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-24 18:04:20
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

int cal(string str);

int main(void) {
	int t, ay, by, ans;
	string a, b;
	cin >> t;
	while (t--) {
		ans = 0;
		cin >> a >> b;
		ay = cal(a);
		by = cal(b);
		if (ay == by)
			cout << "12" << endl;
		else if (ay < by)
			cout << by - ay << endl;
		else
			cout << by + 12 - ay << endl;

	}
	return 0;
}

int cal(string str) {
	if (str == "rat")
		return 1;
	if (str == "ox")
		return 2;
	if (str == "tiger")
		return 3;
	if (str == "rabbit")
		return 4;
	if (str == "dragon")
		return 5;
	if (str == "snake")
		return 6;
	if (str == "horse")
		return 7;
	if (str == "sheep")
		return 8;
	if (str == "monkey")
		return 9;
	if (str == "rooster")
		return 10;
	if (str == "dog")
		return 11;
	if (str == "pig")
		return 12;
}