#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int** arr = (int**)malloc(sizeof(int*) * (n + 1));
    for (int i = 0; i <= n; i++)
        arr[i] = (int*)malloc(sizeof(int) * (k + 1));
    int a, b;
    int p = 0;
    while (p <= n)
    {
        if (p == 0)//첫번째 행 0으로 초기화
        {
            for (int i = 0; i <= k; i++)
                arr[p][i] = 0;
            p++;
        }

        else
        {
            scanf("%d %d", &a, &b);
            for (int i = 0; i <= k; i++)
            {
                arr[p][i] = arr[p - 1][i];
                if (i >= a && arr[p - 1][i] < b)
                    arr[p][i] = b; //무게에 맞는 애로 갱신
                if (i - a >= 0 && arr[p][i] <= arr[p - 1][i - a] + b) //여기서 i-a>=0 의 조건을 넣지 않으면, arr[p-1][i-a]에서 i-a에서정의되어있지 않은 메모리주소를 참조하므로 잘못된 결과가 나온다.
                    arr[p][i] = arr[p - 1][i - a] + b;
            }
            p++;
        }

    }
    printf("%d", arr[n][k]);
}
