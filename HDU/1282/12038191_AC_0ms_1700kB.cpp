/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-21 18:17:47
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

int arr[100000];

int main(void) {
	int i, n, tn, tmp, ans;
	while (~scanf("%d", &n)) {
		tmp = n;
		tn = 0;
		ans = 0;
		arr[ans] = n;
		while (tmp > 0) {
			tn = tn * 10 + tmp % 10;
			tmp /= 10;
		}
		while (tn != n) {
			n += tn;
			ans++;
			arr[ans] = n;
			tmp = n;
			tn = 0;
			while (tmp > 0) {
				tn = tn * 10 + tmp % 10;
				tmp /= 10;
			}
		}
		cout << ans << endl;
		for (i = 0; i < ans+1; i++) {
			if(i!=0)
				cout<<"--->";
			cout<<arr[i];
		}
		putchar('\n');
	}
	return 0;
}