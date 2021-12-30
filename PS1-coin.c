#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	scanf("%d", &n);
	int* arr;
	arr = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 0; i <= n; i++)
		arr[i] = 0;
	arr[3] = 1, arr[5] = 1;
	for (int k = 6; k <= n; k++)
	{
		if (arr[k - 3] != 0 && arr[k - 5] != 0)
			arr[k] = arr[k - 3] >= arr[k - 5] ? arr[k - 5] + 1 : arr[k - 3] + 1;
		else if (arr[k - 3] != 0)
			arr[k] = arr[k - 3] + 1;
		else if (arr[k - 5] != 0)
			arr[k] = arr[k - 5] + 1;
		else
			arr[k] = 0;
	}
	if (arr[n] == 0)
		printf("-1");
	else
		printf("%d", arr[n]);
	return 0;

}