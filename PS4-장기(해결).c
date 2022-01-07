#include <stdio.h>

int PL[101][101];
int CN[101][101];
typedef struct {
	int row, col, cnt;
}queue;
queue que[110*110*8];//행과 열, 그리고 cnt(움직이는 횟수)가 포함된 구조체 배열 선언 전역변수로 설정되면 구조체배열 안에있는 멤버 모두 0으로 설정 그냥 싹다 0으로 설정된다고 생각하면 된다. 100*100보다 크게설정

int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2,2,1,-1,-2,2,1 };
 
int main()
{
	int N, M;
	int R, C, S, K;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &R, &C, &S, &K);
	int tempR, tempC;
	int cur = 0;//채워지는 que의 index
	int next = 0;//선택되어진 que의 index(방문하는 index)
	que[cur].row = R, que[cur].col = C; //
	while (1)//큐에 맨 앞에있는 애의 기준으로 8방향으로 움직인 결과에서 다시 8방향 가는것을 while 반복문으로 시행.
	{
		for (int i = 0; i <= 7; i++) //8방향 이동한 값을 que에 저장해야함
		{
			if (R + dx[i] > 0 && R + dx[i] <= N && C + dy[i] > 0 && C + dy[i] <= M)
			{
				if (CN[R + dx[i]][C + dy[i]] != 0) //CN(즉 카운터 하는 이차원 배열(장기판)) 의 수가 0이 되지 않는다는 소리는 이미 그 위치의 최소 거리를 찾았다는 것. 따라서 그냥 냅두면 됨.
					continue;
				else
				{
					que[++cur].row = R + dx[i], que[cur].col = C + dy[i];
					que[cur].cnt = que[next].cnt + 1; //next의 변수가 필요한 이유를 잘생각해보자. 8번방향을 보내기 전의 index가 따로 필요하면 변수설정 한번 더하면됨.
					CN[R + dx[i]][C + dy[i]] = que[cur].cnt;
				}
			}
			else
				continue;
		}
		R = que[++next].row, C = que[next].col;
		if (R == S && C == K)
		{
			printf("%d", CN[R][C]);
			break;
		}
	}
	return 0;
}


