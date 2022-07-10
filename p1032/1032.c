#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	int		test_case;
	char	file_name[50][51];
	int		len;

	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)//테스트 케이스 갯수를 입력받고 입력갯수만큼 파일을 적음
	{
		scanf("%s", file_name[i]);
	}
	len = strlen(file_name[0]);
	for (int i = 0; i < len; i++)//문장에서 1개씩늘리기
	{
		for (int m = 0; m < test_case; m++)//testcase끼리의 문장 비교
		{
			if (file_name[0][i] != file_name[m][i])//만약 다르면
			{
				file_name[0][i] = '?';//그부분을 물음표
			}
		}
	}
	printf("%s\n", file_name[0]);
}