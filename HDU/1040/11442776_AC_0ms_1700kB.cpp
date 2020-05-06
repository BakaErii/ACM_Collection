/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-06 23:34:34
 *
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k, i, j, r[1000];
	while (cin >> n) {
		for (j = 0; j < n; j++)
		{
			cin >> k;
			for (i = 0; i < k; i++)
			{
				cin >> r[i];
			}
			sort(r, r + k);
			for (i = 0; i < k; i++)
			{
				cout << r[i];
				if (i != k - 1)
					cout << " ";
			}
			cout << endl;
		}
	}
	return 0;
}