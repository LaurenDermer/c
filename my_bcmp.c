/*
** Per Judy, it is ok to assume the user inputed faulty inputs such as a float value instead of an integer value,
** and use only the integer part.
*/

#include <stdio.h>
#include <string.h>

#define MAX 512
#define GOOD 0
#define BAD 1

/* Prototype function */
int my_bcmp(const void *b1, const void *b2, size_t len);

/* The main - checks if there's a comparison between 2 pointers in an array with a given length */ 
int main()
{
	int length; /* The amount of bytes to check */ 
	int p1; /* First pointer to check in the array */
	int p2; /* Second pointer to check in the array */
	char array[MAX]; /* The inputed array which we need to check the comparison */
	char temp; /* A helper variable which will assist to clean the buffer */

	printf("Please enter the length to check in the array: ");
	if (scanf("%d" , &length) != 1) /* Check if input is valid */
	{
		printf("The input is not an integer.\n");
		return BAD;
	}
	if (length > MAX) /* Check if input is not more than MAX */
	{
		printf("The length is bigger than the valid max size of the array.\n");
		return BAD;
	}
	if (length < 0) /* Check if input is not a negative value */
	{
		printf("The length cannot be negative.\n");
		return BAD;
	}

	/* A loop to clean the buffer assuming that anything might be stuck by last input which was not a valid input */
	while ((temp = getchar()) != EOF && temp != '\n');

	printf("Please enter the first pointer to compare: ");
	if (scanf("%d" , &p1) != 1) /* Check if input is valid */
	{
                printf("The input is not an integer.\n");
                return BAD;
        }
	if (p1 < 0) /* Check if input is not a negative value */
	{
		printf("The pointer cannot be negative.\n");
		return BAD;
	}

	/* A loop to clean the buffer assuming that anything might be stuck by last input which was not a valid input */
	while ((temp = getchar()) != EOF && temp != '\n');

	printf("Please enter the second pointer to compare: ");
	if (scanf("%d" , &p2) != 1) /* Check if input is valid */
	{
		printf("The input is not an integer.\n");
                return BAD;
        }
	if (p2 < 0) /* Check if input is not a negative value */
        {
                printf("The pointer cannot be negative.\n");
                return BAD;
        }


	/* A loop to clean the buffer assuming that anything might be stuck by last input which was not a valid input */
	while ((temp = getchar()) != EOF && temp != '\n');

	printf("Please enter the array to start the comparison: ");
	fgets(array , MAX , stdin);

	if (p1+length > strlen(array) || p2+length > strlen(array)) /* Check if the indexs do not exceed boundaries */
	{
		printf("Error out of array boundaries.\n");
		return BAD;
	}

	printf("\nThe result is: %d\n\n" , my_bcmp(&array[p1] , &array[p2] , length));

	return GOOD;
}

int my_bcmp(const void *b1, const void *b2, size_t len)
{
	const char *check1 = b1; /* Apply the pointer to a char type */
	const char *check2 = b2; /* Apply the pointer to a char type */

	for (;len>0;len--) /* Run over the array by the given length and check comparison */
	{
		if (*check1 != *check2) /* Return 'not 0' at first non comparison value */
			return BAD;

		check1++; /* Increment index pointer */
		check2++; /* Increment index pointer */
	}

	return GOOD; /* If we got here - all is good and compared */
}
