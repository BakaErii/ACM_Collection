#include <stdio.h>
#include <math.h>

int main(void)
{
	int num[99], n, tmp, i, j, k;
	while (scanf("%d", &n) != EOF)
	{
		if (n == 0)
		{
			return 0;
		}
		for (i = 0; i < n; i++)
		{
			// 获取变量
			scanf("%d", &num[i]);
			// 冒泡排序
			for (j = 0; j < i; j++)
			{
				for (k = 0; k < i ; k++)
				{
					if (abs(num[k]) < abs(num[k + 1] ))
					{
						tmp = num[k + 1];
						num[k + 1] = num[k];
						num[k] = tmp;
					}
				}
			}
		}
		//输出结果
		for(i=0;i<n;i++){
		    printf("%d",num[i]);
		    if(i!=n-1){
		        printf(" ");
		    }
		}
		printf("\n");
	}
	return 0;
}