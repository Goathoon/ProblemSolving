#include <stdio.h>
#include <string.h>

int dp[1001][1001]; //전역 변수로 배열 설정하면 모두 0으로 초기화. 지역변수와 다른점 지역 변수는 쓰레기값을 저장

int main()
{
	char str1[1001];
	char str2[1001];
	scanf("%s", str1);
	scanf("%s", str2);

	//-----------dp 배열(trivial) 초기화 -----------//
	//큰 문제를 작은문제로 나누어 생각 but how? trivial에서 nontrivial한 방향으로(한번에 묶어서 생각하지말고, 문자하나하나부터 차례대로 생각해보자)//
	for (int k = 0; k <= strlen(str1); k++)
	{
		for (int m = 0; m <= strlen(str2); m++)
		{
			if (str1[k] == str2[m])
				dp[k + 1][m + 1] = dp[k][m] + 1; //점화식 도출 각 str마다 참조하는 index의 문자가 같으면 당연히 LCS의 값은 하나 더 늘어나게 됨.
			else //다를 경우에는 어떻게 될까. 최대한 trivial한 케이스에서 발전시키자. 만약 각 문자마다 3, 3번째 index값을 비교한다면 2,3 번째 그리고 3,2번째 dp배열값이 무엇인지 확인후 큰값이 채워져야할것이다.
				dp[k + 1][m + 1] = dp[k][m + 1] >= dp[k + 1][m] ? dp[k][m + 1] : dp[k + 1][m];
		}
	}
	printf("%d", dp[strlen(str1)][strlen(str2)]);

}