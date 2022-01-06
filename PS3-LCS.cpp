#include <iostream> //c++에 있는 입출력을 위한 헤더파일
#include <string.h>
#include <algorithm> // 이 헤더는 max와 min 함수가 내장되어있는 헤더파일이다.
using namespace std;

char str1[1010]; //넉넉히 1010으로 설정
char str2[1010];
int len1;
int len2;

int dp[1010][1010]; //trivial case를 위한 공간 1추가
int main()
{
	scanf("%s", &str1[1]); //1번째 index부터 받아야 '편하다'
	/*
	scanf("%s", str1) 과 뭐가 다른가?
	str1은 이 자체로 주소값, 즉 0번째 인덱스의 주소값을 담는다.
	그러면 1번째 index의 주소부터 문자열을 입력하고자 한다면
	str1[1]에 &을 붙인 str1[1]의 주소값을 입력하면 된다. 혼동하지 말자.
	*/
	scanf("%s", &str2[1]);
	len1 = strlen(&str1[1]); //마찬가지로 strlen에 주소값만 신경써서 넣으면 됨.
	len2 = strlen(&str2[1]);
	//---------------------solution-----------------//
	
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			//dp[i][j]를 채우기 위한 점화식
			//(i,j)
			if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //max함수는 algorithm 헤더파일 추가해야함

		}
	}
	printf("%d", dp[len1][len2]);
}