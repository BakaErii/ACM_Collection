/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-01-31 17:19:48
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

int arr[1000], ans[1000], st[1000];

int main(void) {
	int i, ptr, sptr, n;
	bool isOutput = false;
	while (cin >> n && n != 0) {
		if (isOutput == false) {
			isOutput = true;
		} else {
			cout << endl;
		}
		while (cin >> arr[0] && arr[0] != 0) {
			//init
			ptr = 0;
			sptr = 0;
			for (i = 1; i < n; i++)
				cin >> arr[i];
			//solve
			for (i = 0; i < n; i++) {
				//push
				st[sptr++] = i + 1;
				//pop
				while (sptr > 0 && st[sptr - 1] == arr[ptr])
					ans[ptr++] = st[--sptr];
			}
			//popall
			while (sptr > 0)
				ans[ptr++] = st[--sptr];
			//check
			for (i = 0; i < n; i++)
				if (arr[i] != ans[i]) {
					cout << "No" << endl;
					break;
				}
			if (i == n)
				cout << "Yes" << endl;
		}
	}
	return 0;
}