/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-17 14:45:16
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

int arr[24];
int normalarr[24] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int spcarr[24] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(void) {
	bool isSpc = false;
	int i, j, n;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] == 29)
			isSpc = true;
	}
	if (!isSpc) {
		for (i = 0; i < 24; i++)
			if (arr[0] == normalarr[i]) {
				for (j = 0; j < n; j++)
					if (arr[j] != normalarr[(j + i)%24])
						break;
				if (j == n) {
					cout << "YES" << endl;
					return 0;
				}
			}
	} else {
		for (i = 0; i < 24; i++)
			if (arr[0] == spcarr[i]) {
				for (j = 0; j < n; j++)
					if (arr[j] != spcarr[(j + i)%24])
						break;
				if (j == n) {
					cout << "YES" << endl;
					return 0;
				}
			}
	}
	cout << "NO" << endl;
	return 0;
}