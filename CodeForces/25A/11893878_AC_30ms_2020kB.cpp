/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-08 20:52:17
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

int arr[100];
int cal[100];

int main(void) {
	int i, n, jnum = 0, onum = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		cal[i] = arr[i] % 2;
		if (cal[i] == 0)
			onum++;
		else
			jnum++;
	}
	if (jnum == 1) {
		for (i = 0; i < n; i++)
			if (cal[i] == 1) {
				cout << i + 1 << endl;
				break;
			}
	} else {
		for (i = 0; i < n; i++)
			if (cal[i] == 0) {
				cout << i + 1 << endl;
				break;
			}
	}
	return 0;
}