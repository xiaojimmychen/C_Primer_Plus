#include <stdio.h>

/************************************************************************/
/* practice 1                                                                     */
/************************************************************************/
void p6_1(void)
{
	char letter[26];
	for (int i = 0; i < 26; i++)
	{
		letter[i] = 'a' + i;
	}

	for (int i = 0; i < 26; i++)
	{
		printf("%c ", letter[i]);
	}

	printf("\n");

	return;
}


/************************************************************************/
/* practice 2                                                                     */
/************************************************************************/
void p6_2(void)
{
	const char let = '$';
	for (int i = 1; i < 6; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf("%c", let);
		}
		printf("\n");
	}

	return;
}


int main(int argc, char **argv)
{
	p6_2();

	getchar();

	return;
}