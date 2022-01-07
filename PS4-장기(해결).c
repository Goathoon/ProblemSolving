#include <stdio.h>

int PL[101][101];
int CN[101][101];
typedef struct {
	int row, col, cnt;
}queue;
queue que[110*110*8];//��� ��, �׸��� cnt(�����̴� Ƚ��)�� ���Ե� ����ü �迭 ���� ���������� �����Ǹ� ����ü�迭 �ȿ��ִ� ��� ��� 0���� ���� �׳� �ϴ� 0���� �����ȴٰ� �����ϸ� �ȴ�. 100*100���� ũ�Լ���

int dx[8] = { -2,-1,1,2,2,1,-1,-2 };
int dy[8] = { -1,-2,2,1,-1,-2,2,1 };
 
int main()
{
	int N, M;
	int R, C, S, K;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &R, &C, &S, &K);
	int tempR, tempC;
	int cur = 0;//ä������ que�� index
	int next = 0;//���õǾ��� que�� index(�湮�ϴ� index)
	que[cur].row = R, que[cur].col = C; //
	while (1)//ť�� �� �տ��ִ� ���� �������� 8�������� ������ ������� �ٽ� 8���� ���°��� while �ݺ������� ����.
	{
		for (int i = 0; i <= 7; i++) //8���� �̵��� ���� que�� �����ؾ���
		{
			if (R + dx[i] > 0 && R + dx[i] <= N && C + dy[i] > 0 && C + dy[i] <= M)
			{
				if (CN[R + dx[i]][C + dy[i]] != 0) //CN(�� ī���� �ϴ� ������ �迭(�����)) �� ���� 0�� ���� �ʴ´ٴ� �Ҹ��� �̹� �� ��ġ�� �ּ� �Ÿ��� ã�Ҵٴ� ��. ���� �׳� ���θ� ��.
					continue;
				else
				{
					que[++cur].row = R + dx[i], que[cur].col = C + dy[i];
					que[cur].cnt = que[next].cnt + 1; //next�� ������ �ʿ��� ������ �߻����غ���. 8�������� ������ ���� index�� ���� �ʿ��ϸ� �������� �ѹ� ���ϸ��.
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


