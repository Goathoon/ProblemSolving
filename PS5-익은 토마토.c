#include <stdio.h>
#define X -100;

int grid[1010][1010];
typedef struct {
	int r, c, cnt;
}queue;
queue que[1010 * 1010];

int main()
{
	int M, N;
	scanf("%d %d", &M, &N);
	
	for (int i = N + 1; i <= 1009; i++) //여기서 헛짓거리함. 이중 for문쓰면 초기화 안되는 구간 발생함.
		for (int j = 0; j <= 1009; j++)
			grid[i][j] = X;
	for (int j = M + 1; j <= 1009; j++)
		for (int i = 0; i <= 1009; i++)
			grid[i][j] = X;
	for (int k = 0; k <= 1009; k++)
	{
		grid[0][k] = X;
		grid[k][0] = X;
	}

	int cur = 0; //que 삽입 위한 변수 선언

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &grid[i+1][j+1]);
			if (grid[i+1][j+1] == 1)
				que[cur].r = i+1, que[cur++].c = j+1;
			else
				continue;
		}
	}
	//처음 입력받은 것에 대한 que삽입

	int pt = 0;
	while (1)
	{
		if (que[pt].c == 0)//아무것도 존재하지 x(que에 원소가 없는 경우임. 전역변수로 다 0으로 초기화했으니까)
		{
			for(int i = 1; i<= N; i++)
				for (int j = 1; j <= M; j++)
				{
					if (grid[i][j] == 0)
					{
						printf("-1");
						return 0;
					}
				}
			printf("%d", que[pt - 1].cnt);
			break;
		}

		if (grid[que[pt].r + 1][que[pt].c] == 0)//익지 않았다면
		{
			grid[que[pt].r + 1][que[pt].c] = 1;
			que[cur].r = que[pt].r + 1;
			que[cur].c = que[pt].c;
			que[cur++].cnt = que[pt].cnt + 1;
		}
		if (grid[que[pt].r][que[pt].c + 1] == 0)
		{
			grid[que[pt].r][que[pt].c + 1] = 1;
			que[cur].r = que[pt].r;
			que[cur].c = que[pt].c + 1;
			que[cur++].cnt = que[pt].cnt + 1;
		}
		if (grid[que[pt].r - 1][que[pt].c] == 0)
		{
			grid[que[pt].r - 1][que[pt].c] = 1;
			que[cur].r = que[pt].r - 1;
			que[cur].c = que[pt].c;
			que[cur++].cnt = que[pt].cnt + 1;
		}
		if (grid[que[pt].r][que[pt].c - 1] == 0)
		{
			grid[que[pt].r][que[pt].c - 1] = 1;
			que[cur].r = que[pt].r;
			que[cur].c = que[pt].c - 1;
			que[cur++].cnt = que[pt].cnt + 1;
		}
		pt++;
		
	}
}