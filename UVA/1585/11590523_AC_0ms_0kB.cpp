/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-16 19:23:54
 *
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int t, score, i, add;
	string str;
	cin >> t;
	while (t--) {
		cin >> str;
		score = 0;
		add = 0;
		for (i = 0; i < (int)str.length(); i++)
		{
			if (str[i] == 'X')
				add = 0;
			else {
				score += ++add;
			}
		}
		cout << score << endl;
	}
	return 0;
}