/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-15 16:41:13
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

//如果存在了重复走过的格子即为BUG
//对走到的格子周围判断是否走过 因为所停留的格子为空 如果周围走过意味着绕了远路
typedef pair<int, int> P;
P pos, tpos;
set<P> ps;

int main(void) {
	pos.first = 0;
	pos.second = 0;
	//先将原点插入
	ps.insert(pos);
	string command;
	cin >> command;
	for (int i = 0; i < (int)command.length(); i++) {
		//对当前格子计数
		if (command[i] == 'L')
			pos.second--;
		if (command[i] == 'U')
			pos.first++;
		if (command[i] == 'R')
			pos.second++;
		if (command[i] == 'D')
			pos.first--;
		if (ps.count(pos) == 1) {
			cout << "BUG" << endl;
			return 0;
		}
		//开始对周围格子计数
			if (command[i] != 'L') {
				tpos = pos;
				tpos.second++;
				if (ps.count(tpos) == 1) {
					cout << "BUG" << endl;
					return 0;
				}
			}
			if (command[i] != 'U') {
				tpos = pos;
				tpos.first--;
				if (ps.count(tpos) == 1) {
					cout << "BUG" << endl;
					return 0;
				}
			}
			if (command[i] != 'R') {
				tpos = pos;
				tpos.second--;
				if (ps.count(tpos) == 1) {
					cout << "BUG" << endl;
					return 0;
				}
			}
			if (command[i] != 'D') {
				tpos = pos;
				tpos.first++;
				if (ps.count(tpos) == 1) {
					cout << "BUG" << endl;
					return 0;
				}
			}
		ps.insert(pos);
	}
	cout << "OK" << endl;
	return 0;
}