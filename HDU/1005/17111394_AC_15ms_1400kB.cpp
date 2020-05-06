/**
 * @author  Moe_Sakiya	sakiya@tun.moe
 * @date    2018-11-21 13:17:11
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

int arr[55];

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	//INIT
	arr[1] = arr[2] = 1;
	while (~scanf("%d %d %d", &a, &b, &n))
	{
		if (a == 0 && b == 0 && n == 0)
			break;
		for (int i = 3; i <= 49; i++)
		{
			arr[i] = (a * arr[i - 1] + b * arr[i - 2]) % 7;
		}
		printf("%d\n", arr[n % 49]);
	}
	return 0;
}