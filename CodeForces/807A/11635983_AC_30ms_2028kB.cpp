/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-19 19:23:02
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int n, i;
	int scr[1001][2];
	bool isRated, isMaybe;
	//初始化变量
	isRated = false;
	isMaybe = true;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> scr[i][0] >> scr[i][1];
		if (scr[i][0] != scr[i][1])
			isRated = true;
	}
	if (isRated)
		cout << "rated" << endl;
	else {
		//从大到小排列
		for (i = 0; i < n - 1; i++)
			if (scr[i][0] < scr[i + 1][0]) {
				cout << "unrated" << endl;
				isMaybe = false;
				break;
			}
		if (isMaybe)
			cout << "maybe" << endl;
	}
	return 0;
}