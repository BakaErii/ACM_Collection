/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-09 18:57:16
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

const int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	int i, y, m, d, sum;
	//判断
	while (cin >> y >> m >> d) {
		//初始化变量
		sum = 0;
		//判断月日是否为0
		if (m == 0 || d == 0) {
			cout << "illegal" << endl;
			continue;
		}
		//判断日期是否有效
		if (m == 2) {
			//判断闰月的特殊情况
			if (d > 29) {
				cout << "illegal" << endl;
				continue;
			} else if (d == 29)
				if (!(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))) {
					cout << "illegal" << endl;
					continue;
				}
		} else if (d > days[m]) {
			cout << "illegal" << endl;
			continue;
		}
		//计算日期
		for (i = 1; i < y; i++)
			if (i % 400 == 0 || (i % 100 != 0 && i % 4 == 0))
				sum += 366;
			else
				sum += 365;
		//计算月
		for (i = 1; i < m; i++)
			sum += days[i];
		//算闰年
		if (m > 2 && (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)))
			sum += 1;
		sum += d;
		switch (sum % 7) {
		case 0:  cout << "Sunday" << endl; break;
		case 1:  cout << "Monday" << endl; break;
		case 2:  cout << "Tuesday" << endl; break;
		case 3:  cout << "Wednesday" << endl; break;
		case 4:  cout << "Thursday" << endl; break;
		case 5:  cout << "Friday" << endl; break;
		case 6:  cout << "Saturday" << endl; break;
		}
	}
	return 0;
}