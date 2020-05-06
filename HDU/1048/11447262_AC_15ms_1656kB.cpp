/**
 * @authors	Moe_Sakiya    	sakiya@tun.moe
 * @date    	2017-11-06 23:43:51
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(void) {
	char tmp[1001];
	int i;
	while (gets(tmp)) {
		//判断开始与结束
		if (strcmp(tmp, "ENDOFINPUT") == 0)
			return 0;
		if (strcmp(tmp, "START") == 0 || strcmp(tmp, "END") == 0)
		{
			//不做处理
		} else {
			for (i = 0; i < strlen(tmp); i++)
			{
				if (tmp[i] >= 'A' && tmp[i] <= 'Z')
					if (tmp[i] <= 'E') {
						tmp[i] = 'Z' - ('E' - tmp[i]);
					} else {
						tmp[i] = tmp[i] - 5;
					}
			}
			puts(tmp);
		}
	}
	return 0;
}