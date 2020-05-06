/**
 * @authors Moe_Sakiya sakiya@tun.moe
 * @date    2017-10-11 20:49:37
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void) {
	int n, k, addnum, i, tmp;
	double score;
	while (scanf("%d %d", &n, &k) != EOF) {
		//初始化变量
		score = 0;
		addnum = 0;
		for (i = 0; i < n; i++) {
			scanf("%d", &tmp);
			score += tmp;
		}
		//判断
		while (score / (addnum + n) < (double)k - 0.5 ) {
			score += k;
			addnum++;
		}
		printf("%d\n",addnum );
	}
	return 0;
}