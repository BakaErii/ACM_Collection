/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-24 17:55:01
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
	//最后没有方格
	int n, m, grid, turn;
	while (cin >> n >> m) {
		//turn=0 Akshat turn=1 Malvika
		turn = 0;
		grid = m * n;
		//最适宜:先拿对角线
		while (grid != 0) {
			m--;
			n--;
			grid = m * n;
			if (turn == 0)
				turn = 1;
			else
				turn = 0;
		}
		if (turn == 1)
			cout << "Akshat" << endl;
		else
			cout << "Malvika" << endl;
	}
	return 0;
}