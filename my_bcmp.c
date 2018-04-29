#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 512
#define GOOD 0
#define BAD 1

int my_bcmp(const void *b1, const void *b2, size_t len);

int main()
{
	int length;
	int p1;
	int p2;
	char array[MAX];
	char temp;

	printf("Please enter the length to check in the array: ");
	if (scanf("%d" , &length) != 1)
	{
		printf("The input is not an integer.\n");
		return BAD;
	}
	if (length > MAX)
	{
		printf("The length is bigger than the valid max size of the array.\n");
		return BAD;
	}

	while ((temp = getchar()) != EOF && temp != '\n');

	printf("Please enter the first pointer to compare: ");
	if (scanf("%d" , &p1) != 1)
	{
                printf("The input is not an integer.\n");
                return BAD;
        }

	while ((temp = getchar()) != EOF && temp != '\n');

	printf("Please enter the second pointer to compare: ");
	if (scanf("%d" , &p2) != 1)
	{
                printf("The input is not an integer.\n");
                return BAD;
        }

	while ((temp = getchar()) != EOF && temp != '\n');

	printf("Please enter the array to start the comparison: ");
	fgets(array , MAX , stdin);

	if (p1+length > strlen(array) || p2+length > strlen(array))
	{
		printf("Error out of array boundaries.\n");
		return BAD;
	}

	printf("\nThe result is: %d\n\n" , my_bcmp(&array[p1] , &array[p2] , length));

	return GOOD;
}

int my_bcmp(const void *b1, const void *b2, size_t len)
{
	const char *check1 = b1;
	const char *check2 = b2;

	for (;len>0;len--)
	{
	        printf("\n%c , %c\n", *check1, *check2);

		if (*check1 != *check2)
			return BAD;

		check1++;
		check2++;
	}

	return GOOD;
}
