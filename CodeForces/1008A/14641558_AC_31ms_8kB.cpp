/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-07-17 19:53:26
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

string str;

bool isVowel(int x) {
	char v[5] = {'a', 'e', 'i', 'o', 'u'};
	int i;
	for (i = 0; i < 5; i++)
		if (str[x] == v[i])
			break;
	if (i == 5)
		return false;
	else
		return true;
}

bool isVowelX(int x) {
	char v[6] = {'a', 'e', 'i', 'o', 'u', 'n'};
	int i;
	for (i = 0; i < 6; i++)
		if (str[x] == v[i])
			break;
	if (i == 6)
		return false;
	else
		return true;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (isVowelX(i) == false) {
			if (i + 1 < str.length())
				if (isVowel(i + 1) == false) {
					cout << "NO" << endl;
					return 0;
				}
		}
	}
	if(isVowelX(str.length()-1)==false){
		cout<<"NO"<<endl;
		return 0;
	}
	cout << "YES" << endl;
	return 0;
}