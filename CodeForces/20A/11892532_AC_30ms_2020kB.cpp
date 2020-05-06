/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-12-08 18:41:52
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
	string str;
	char newstr[101];
	char tmp = '\0';
	int i, ptr;
	cin >> str;
	ptr = 0;
	for (i = 0; i < (int)str.length(); i++) {
		if (str[i] == '/') {
			if (tmp != '/')
				newstr[ptr++] = str[i];
		}
		else
			newstr[ptr++] = str[i];
		tmp = str[i];
	}
	//过滤尾部斜线
	if (newstr[ptr - 1] == '/' && ptr != 1)
		newstr[ptr - 1] = '\0';
	else
		newstr[ptr] = '\0';
	puts(newstr);
	return 0;
}