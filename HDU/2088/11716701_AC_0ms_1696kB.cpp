/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-25 20:08:31
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

int main(void) {
	int n, i, avg, sum, ans, isFirst;
	isFirst = 1;
	while (cin >> n && n != 0) {
		if (isFirst == 1)
			isFirst = 0;
		else
			cout << endl;
		//初始化变量
		sum = 0;
		ans = 0;
		for (i = 0; i < n; i++) {
			cin >> arr[i];
			sum += arr[i];
		}
		avg = sum / n;
		//排序
		sort(arr, arr + n);
		//计算
		for (i = 0; i < n; i++)
			if (arr[i] <= avg)
				ans += avg - arr[i];
			else
				break;
		//输出
		cout << ans << endl;
	}
	return 0;
}