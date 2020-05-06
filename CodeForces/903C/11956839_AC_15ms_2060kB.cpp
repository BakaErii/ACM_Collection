/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-13 16:51:22
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

int arr[5001];
//flag对应三种状态 0:可用 1:装入其他箱中 2:自身装了其他箱
int flag[5001];

int main(void) {
	int i, j, n, ans = 0;
	bool nothingtodo = false;
	cin >> n;
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		flag[i] = 0;
	}
	sort(arr, arr + n);
	while (nothingtodo != true) {
		nothingtodo = true;
		for (i = 0; i < n - 1; i++) {
			if (flag[i] == 1)
				continue;
			for (j = i + 1; j < n; j++) {
				if (arr[i] < arr[j] && flag[j] == 0) {
					nothingtodo = false;
					flag[i] = 1;
					flag[j] = 2;
					break;
				}
			}
		}
	}
	for (i = 0; i < n; i++)
		if (flag[i] != 1)
			ans++;
	cout << ans << endl;
	return 0;
}