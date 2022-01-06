#include <iostream> //c++�� �ִ� ������� ���� �������
#include <string.h>
#include <algorithm> // �� ����� max�� min �Լ��� ����Ǿ��ִ� ��������̴�.
using namespace std;

char str1[1010]; //�˳��� 1010���� ����
char str2[1010];
int len1;
int len2;

int dp[1010][1010]; //trivial case�� ���� ���� 1�߰�
int main()
{
	scanf("%s", &str1[1]); //1��° index���� �޾ƾ� '���ϴ�'
	/*
	scanf("%s", str1) �� ���� �ٸ���?
	str1�� �� ��ü�� �ּҰ�, �� 0��° �ε����� �ּҰ��� ��´�.
	�׷��� 1��° index�� �ּҺ��� ���ڿ��� �Է��ϰ��� �Ѵٸ�
	str1[1]�� &�� ���� str1[1]�� �ּҰ��� �Է��ϸ� �ȴ�. ȥ������ ����.
	*/
	scanf("%s", &str2[1]);
	len1 = strlen(&str1[1]); //���������� strlen�� �ּҰ��� �Ű�Ἥ ������ ��.
	len2 = strlen(&str2[1]);
	//---------------------solution-----------------//
	
	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			//dp[i][j]�� ä��� ���� ��ȭ��
			//(i,j)
			if (str1[i] == str2[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); //max�Լ��� algorithm ������� �߰��ؾ���

		}
	}
	printf("%d", dp[len1][len2]);
}