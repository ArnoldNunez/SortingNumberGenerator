/**
 * \file main.c
 *
 * \author Arnold Nunez
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Upper bound of rand numbers to generate
static const int RNGSORT_MAX_NUMBER = 1000;

int main(int argc, char* argv[])
{
	int cnt;		///< The number of numbers to generate
	time_t tseed;	///< Time will be used as the seed for random number generator
	FILE* numFile;	///< File pointer for the file to read/write to.

	/// Error handling
	if (argc != 3)
	{
		printf("Invalid Number of arguments. 2 expeted, %d given\n", argc);
		printf("Expected format: rngsort [filename w/o extension] [# of numbers]\n");
		return 1;
	}

	if (atoi(argv[2]) == 0)
	{
		printf("Error: 2nd parameter must be a number greater than 0.\n");
		return 1;
	}

	printf("Now generating your file, please wait...\n");


	/// Seed the random number generator
	srand((unsigned)time(&tseed));

	/// Open file for writing
	numFile = fopen(argv[1], "w");

	for (cnt = atoi(argv[2]); cnt > 0; --cnt)
	{
		fprintf(numFile, "%d\n", rand() % RNGSORT_MAX_NUMBER);
	}

	/// Close file
	fclose(numFile);

	printf("File generation completed!\n");

	return 0;
}