#include <stdio.h>

int PL[101][101];
typedef struct {
	int row, col, cnt;
}queue;
queue que[10012];//��� ��, �׸��� cnt(�����̴� Ƚ��)�� ���Ե� ����ü �迭 ���� ���������� �����Ǹ� ����ü�迭 �ȿ��ִ� ��� ��� 0���� ���� �׳� �ϴ� 0���� �����ȴٰ� �����ϸ� �ȴ�. 100*100���� ũ�Լ���

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
	while (1)//ť�� �� �տ��ִ� ���� �������� 8�������� ������ ������� �ٽ� 8���� ���°��� while �ݺ������� ����.
	{
		for (int i = 0; i <= 7; i++) //8���� �̵��� ���� que�� �����ؾ���
		{
			if (R + dx[i] > 0 && R + dx[i] <= N && C + dy[i] > 0 && C + dy[i] <= M)
			{
				que[++cur].row = R + dx[i], que[cur].col = C + dy[i];
				que[cur].cnt = que[next].cnt + 1; //next�� ������ �ʿ��� ������ �߻����غ���. 8�������� ������ ���� index�� ���� �ʿ��ϸ� �������� �ѹ� ���ϸ��.
				if (R + dx[i] == S && C + dy[i] == K)
				{
					printf("%d", que[cur].cnt);
					return 0;
				}
				else
				{
					tempR = R + dx[i], tempC = C + dy[i];
					if (PL[tempR][tempC] > que[cur].cnt) //�̹� �Դ� ��� ���� ��ġ�� �ٽ��ѹ� Ž���Ҽ��� ����. �ּ��� �Ÿ��� �Ǿ�� �ϹǷ� ���ϴ� �ڵ尡 �ݵ�� �ʿ�
						PL[tempR][tempC] = que[cur].cnt; //���� �ּҰ�
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


