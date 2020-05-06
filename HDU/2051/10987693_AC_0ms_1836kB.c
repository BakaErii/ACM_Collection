/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-08 20:46:22
 * 这破题...肯定有坑
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	int n;
	char r[233];
	while (scanf("%d", &n) != EOF) {
		itoa(n, r, 2);
		printf("%s\n",r);
	}
	return 0;
}