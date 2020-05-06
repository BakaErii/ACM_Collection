/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-24 19:03:48
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

int arr[600];

int main(void) {
	int i, n, l, t, num;
	unsigned long long int sum;
	while (cin >> l >> t) {
		//初始化变量
		sum = 0;
		for (i = 0; i < t; i++)
			cin >> arr[i];
		//计算长度
		for (i = 0; i < t; i++) {
			sum += arr[i];
			if (sum >= l)
				break;
		}
		if (i == t) {
			cout << "impossible" << endl;
			continue;
		}
		//排序
		sort(arr, arr + t);
		//从大到小判断
		sum = 0;
		num = 0;
		for (i = t - 1; i >= 0; i--)
		{
			sum += arr[i];
			num++;
			if (sum >= l) {
				cout << num << endl;
				break;
			}
		}
	}
	return 0;
}