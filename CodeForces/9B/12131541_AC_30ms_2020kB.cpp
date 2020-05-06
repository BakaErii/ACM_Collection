/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-03 17:21:22
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

long long int arr[100];
double d[100];

int main(void) {
	int i, n, vb, vs, x, y;
	cin >> n >> vb >> vs;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	cin >> x >> y;
	//分割成两部分 行车部分和到学校部分
	for (i = 1; i < n; i++) {
		d[i] = sqrt((x - arr[i]) * (x - arr[i]) + y * y);
	}
	//寻找时间最少的那一个
	double min = 100000000;
	int min_i = 1;
	for (i = 1; i < n; i++)
		if (min >= arr[i] / (double)vb + d[i] / vs) {
			min = arr[i] / (double)vb + d[i] / vs;
			min_i = i;
		}
	cout << min_i + 1 << endl;
	return 0;
}