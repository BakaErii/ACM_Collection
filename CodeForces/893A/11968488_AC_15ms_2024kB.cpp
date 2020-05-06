/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-14 18:08:33
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
	int win, lose, sec, n, tmp;
	cin >> n;
	cin >> win;
	if (win == 1)
		lose = 2;
	else if (win == 2)
		lose = 1;
	else {
		cout << "NO" << endl;
		return 0;
	}
	sec = 3;
	n--;
	while (n--) {
		cin >> tmp;
		if (tmp == lose) {
			cout << "NO" << endl;
			return 0;
		}
		if (tmp == win)
			swap(lose, sec);
		else {
			swap(win, sec);
			swap(lose, sec);
		}
	}
	cout << "YES" << endl;
	return 0;
}