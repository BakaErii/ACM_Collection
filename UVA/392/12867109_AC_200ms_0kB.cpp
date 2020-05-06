/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-30 00:30:57
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

int arr[9];

int main(void) {
	int i;
	bool isfirstoutput;
	while (cin >> arr[8]) {
		isfirstoutput = true;
		for (i = 7; i >= 0; i--)
			cin >> arr[i];
		for (i = 8; i >= 0; i--) {
			if (arr[i] != 0) {
				//第一次输出判定
				if (isfirstoutput == true) {
					if (arr[i] < 0)
						cout << "-";
					isfirstoutput = false;
				} else {
					if (arr[i] < 0)
						cout << " - ";
					else
						cout << " + ";
				}
				//项数为正负1的判定
				if (arr[i] == 1 || arr[i] == -1) {
					//是否是常数项
					if (i == 0) {
						cout << abs(arr[i]);
						continue;
					}
					cout << "x";
					//判断是否为一次项
					if (i != 1)
						cout << "^" << i;
					continue;
				}
				//项数正常输出
				if (i != 0 && i != 1) {
					cout << abs(arr[i]) << "x^" << i;
				} else if (i == 0)
					cout << abs(arr[0]);
				else
					cout << abs(arr[1]) << "x";
			}
		}
		//无输出判定
		if (isfirstoutput == true)
			cout << "0";
		//换行
		cout << endl;
	}
	return 0;
}