/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-10-30 21:51:00
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, i, tmp;
	while (cin >> n) {
		tmp = 0;
		for (i = 0; i < n; i++)
		{
			tmp += i + 1;
		}
		cout << tmp << endl<<endl;
	}
	return 0;
}