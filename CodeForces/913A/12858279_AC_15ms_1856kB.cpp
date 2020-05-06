/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-29 00:10:54
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

long long int arr[28];

int main(void) {
	int n, m;
	arr[0] = 1;
	for (int i = 1; i < 28; i++)
		arr[i] = arr[i - 1] * 2;
	cin >> n >> m;
	if (n > 27)
		cout << m << endl;
	else
		cout << m % arr[n] << endl;
	return 0;
}