/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-22 16:02:45
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

int arr[100001];

int main(void) {
	ios::sync_with_stdio(false);
	int i, n, tmp;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp]++;
	}
	for (i = 1; i < 100001; i++)
		if (arr[i] % 2 == 1)
			break;
	if (i == 100001)
		cout << "Agasa" << endl;
	else
		cout << "Conan" << endl;
	return 0;
}