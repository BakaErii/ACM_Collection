#include <stdio.h>

int main(void)
{
	int num, i;
	float score, avg, min, max, tmp;
	// 获取评委数量
	while (scanf("%d", &num) != EOF)
	{
		avg = 0;
		tmp = 0;
			// 获取基准值
			scanf("%f", &min);
		scanf("%f", &max);
		if (max < min)
		{
			tmp = max;
			min = max;
			min = tmp;
		}
		// 读取剩下得分
		for (i = 2; i < num; i++)
		{
			scanf("%f", &score);
			// 直接相加
			if (score >= min && score <= max)
			{
				avg = avg + score;
			}
			// 判断得分是否是最值
			if (score < min)
			{
				avg = avg + min;
				min = score;
			}
			if (score > max)
			{
				avg = avg + max;
				max = score;
			}
		}
		avg = avg / (num - 2);
		printf("%.2f\n", avg);
	}
	return 0;
}