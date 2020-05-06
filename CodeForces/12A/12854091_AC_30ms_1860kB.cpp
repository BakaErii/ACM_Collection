/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-20 14:10:22
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

int main(void) {
	bool flag = true;
	char arr[3][4];
	int i;
	for (i = 0; i < 3; i++)
		gets(arr[i]);
	for (i = 0; i < 3; i++)
		if (arr[0][i] != arr[2][2 - i])
			flag = false;
	if (arr[1][0] != arr[1][2])
		flag = false;
	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}