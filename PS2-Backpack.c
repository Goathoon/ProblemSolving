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
        if (p == 0)//ù��° �� 0���� �ʱ�ȭ
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
                    arr[p][i] = b; //���Կ� �´� �ַ� ����
                if (i - a >= 0 && arr[p][i] <= arr[p - 1][i - a] + b) //���⼭ i-a>=0 �� ������ ���� ������, arr[p-1][i-a]���� i-a�������ǵǾ����� ���� �޸��ּҸ� �����ϹǷ� �߸��� ����� ���´�.
                    arr[p][i] = arr[p - 1][i - a] + b;
            }
            p++;
        }

    }
    printf("%d", arr[n][k]);
}
