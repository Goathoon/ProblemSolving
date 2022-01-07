#include <iostream>
#include <queue> //bfs에서의 que사용위함
using namespace std;

int N, M;
int sx, sy, fx, fy;
int grid[110][110]; //장기판

//큐에는 두 정수쌍으로 나타내는 애들이 필요 따라서 구조체

struct coor
{
	int x, y;
};

//제네릭 클래스 (Generic Class)
//queue q; 이렇게하면 일반적인 q의 생성 하지만 우리가 필요한건,queue에 뭐가 들어가는지도 나타내야함. queue<int> q; 처럼
queue <struct coor> q;


int main()
{
	scanf("%d %d", &N, &M);
	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &fx, &fy);

	q.push({ sx,sy }); //구조체 sx,sy 삽입
	while (q.size() > 0) //큐에 차있으면 계속 반복
	{
		auto c = q.front(); //auto는 자동으로 type 반환. q.front는 peek함수
		q.pop(); //진정한 의미의 pop이 이뤄짐

		if (c.x == fx && c.y == fy)
		{
			//지금 pop한 노드가 목적지 좌표일때
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