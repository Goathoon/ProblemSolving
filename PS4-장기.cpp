#include <iostream>
#include <queue> //bfs������ que�������
using namespace std;

int N, M;
int sx, sy, fx, fy;
int grid[110][110]; //�����

//ť���� �� ���������� ��Ÿ���� �ֵ��� �ʿ� ���� ����ü

struct coor
{
	int x, y;
};

//���׸� Ŭ���� (Generic Class)
//queue q; �̷����ϸ� �Ϲ����� q�� ���� ������ �츮�� �ʿ��Ѱ�,queue�� ���� �������� ��Ÿ������. queue<int> q; ó��
queue <struct coor> q;


int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &fx, &fy);

	q.push({ sx,sy }); //����ü sx,sy ����
	while (q.size() > 0) //ť�� �������� ��� �ݺ�
	{
		auto c = q.front(); //auto�� �ڵ����� type ��ȯ. q.front�� peek�Լ�
		q.pop(); //������ �ǹ��� pop�� �̷���

		if (c.x == fx && c.y == fy)
		{
			//���� pop�� ��尡 ������ ��ǥ�϶�
			printf("%d\n", grid[c.x][c.y]);
			break;
		}
		int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
		int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };

		{
			for (int i = 0; i <= 7; i++)
			{
				int nx = c.x + dx[i];
				int ny = c.y + dy[i];
				if (!(1 <= nx && nx <= N && 1 <= ny && ny <= M))
					continue;
				if (grid[nx][ny] != 0)
					continue;
				grid[nx][ny] = grid[c.x][c.y] + 1;
				q.push({ nx,ny });
			}
		}

	}
}