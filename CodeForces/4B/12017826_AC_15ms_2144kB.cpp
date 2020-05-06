/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-19 16:50:24
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

struct days
{
	int studyTime;
	int minTime;
	int maxTime;
} d[30];

int main(void) {
	int i, dy, sumTime;
	cin >> dy >> sumTime;
	for (i = 0; i < dy; i++) {
		cin >> d[i].minTime >> d[i].maxTime;
		d[i].studyTime = d[i].minTime;
		sumTime -= d[i].minTime;
		if (sumTime < 0) {
			cout << "NO" << endl;
			return 0;
		}
	}
	for (i = 0; i < dy; i++) {
		if (d[i].studyTime < d[i].maxTime) {
			d[i].studyTime += min(sumTime, (d[i].maxTime - d[i].minTime));
			sumTime -= min(sumTime, (d[i].maxTime - d[i].minTime));
		}
		if (sumTime == 0)
			break;
	}
	if (sumTime > 0) {
		cout << "NO" << endl;
		return 0;
	} else {
		cout << "YES" << endl;
		for (i = 0; i < dy; i++) {
			if (i != 0)
				putchar(' ');
			cout << d[i].studyTime;
		}
		cout << endl;
	}
	return 0;
}