#include <stdio.h>

int PL[101][101];
typedef struct {
	int row, col, cnt;
}queue;
queue que[10012];//행과 열, 그리고 cnt(움직이는 횟수)가 포함된 구조체 배열 선언 전역변수로 설정되면 구조체배열 안에있는 멤버 모두 0으로 설정 그냥 싹다 0으로 설정된다고 생각하면 된다. 100*100보다 크게설정

int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2,2,1,-1,-2,2,1 };
 
int main()
{
	int N, M;
	int R, C, S, K;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &R, &C, &S, &K);
	int tempR, tempC;
	int cur = 0;
	int next = 0;
	que[cur].row = R, que[cur].col = C; //
	while (1)//큐에 맨 앞에있는 애의 기준으로 8방향으로 움직인 결과에서 다시 8방향 가는것을 while 반복문으로 시행.
	{
		for (int i = 0; i <= 7; i++) //8방향 이동한 값을 que에 저장해야함
		{
			if (R + dx[i] > 0 && R + dx[i] <= N && C + dy[i] > 0 && C + dy[i] <= M)
			{
				que[++cur].row = R + dx[i], que[cur].col = C + dy[i];
				que[cur].cnt = que[next].cnt + 1; //next의 변수가 필요한 이유를 잘생각해보자. 8번방향을 보내기 전의 index가 따로 필요하면 변수설정 한번 더하면됨.
				if (R + dx[i] == S && C + dy[i] == K)
				{
					printf("%d", que[cur].cnt);
					return 0;
				}
				else
				{
					tempR = R + dx[i], tempC = C + dy[i];
					if (PL[tempR][tempC] > que[cur].cnt) //이미 왔던 행과 열의 위치를 다시한번 탐색할수도 있음. 최소의 거리가 되어야 하므로 비교하는 코드가 반드시 필요
						PL[tempR][tempC] = que[cur].cnt; //그중 최소값
					else
						continue;
				}

			}
			else
				continue;
		}
		R = que[++next].row, C = que[next].col;
	}
}


