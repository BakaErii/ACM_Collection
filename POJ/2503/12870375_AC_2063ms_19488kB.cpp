/**
 * @author	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2018-02-07 13:45:24
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

map<string, string> dict;

int main(void) {
	string a, b;
	int i, ptr;
	char str[30];
	a.resize(30);
	b.resize(30);
	while (gets(str) && strlen(str) != 0) {
		i = 0;
		ptr = 0;
		while (str[i] != ' ')
			a[ptr++] = str[i++];
		a[ptr] = '\0';
		ptr = 0;
		i++;
		while (str[i] != '\0')
			b[ptr++] = str[i++];
		dict[b] = a;
	}
	while (~scanf("%s", &a[0])) {
		if (dict.count(a) == 0)
			printf("eh\n");
		else
			printf("%s\n", dict[a].c_str());
	}
	return 0;
}