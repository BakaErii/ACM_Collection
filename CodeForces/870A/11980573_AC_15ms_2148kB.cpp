/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-15 19:05:18
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

int arra[10], arrb[10];

int main(void) {
	int a, b;
	int i, j, min = 2333;
	cin >> a >> b;
	for (i = 0; i < a; i++)
		cin >> arra[i];
	for (i = 0; i < b; i++)
		cin >> arrb[i];
	for (i = 0; i < a; i++)
		for (j = 0; j < b; j++) {
			if (arra[i] == arrb[j] && arra[i] < min)
				min = arra[i];
			if (arra[i] * 10 + arrb[j] < min)
				min = arra[i] * 10 + arrb[j];
			if (arra[i]  + arrb[j] * 10 < min)
				min = arra[i] + arrb[j] * 10;
		}
	cout << min << endl;
	return 0;
}