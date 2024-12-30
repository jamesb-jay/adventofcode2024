#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmpInt(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

void day1(FILE *fp)
{
	printf("\tReading file...\n");

	rewind(fp);

	size_t list_length = 0;
	size_t list_capacity = 0x100;
	int *left_list  = calloc(list_capacity, sizeof(int));
	int *right_list = calloc(list_capacity, sizeof(int));
	char line_buffer[256];

	if (left_list == NULL || right_list == NULL)
	{
		printf("Failed to allocate memory!");
		return;
	}

	while (fgets(line_buffer, sizeof line_buffer, fp) != NULL)
	{
		char *tok = strtok(line_buffer, " ");
		int l = atoi(tok);
		tok = strtok(NULL, " ");
		int r = atoi(tok);

		left_list [list_length] = l;
		right_list[list_length] = r;
		list_length++;

		if (list_length >= list_capacity)
		{
			list_capacity += 0x100;
			left_list  = realloc(left_list,  sizeof(int) * list_capacity);
			right_list = realloc(right_list, sizeof(int) * list_capacity);
		}
	}

	/* If fgets failed for a reason other than EOF */
	if (!feof(fp))
	{
		printf("Failed to read file!\n");
		return;
	}

	printf("\tSorting lists...\n");
	qsort(left_list, list_length, sizeof(int), cmpInt);
	qsort(right_list, list_length, sizeof(int), cmpInt);

	printf("\tSumming difference...\n");
	unsigned int total_diff = 0;
	for (size_t i = 0; i < list_length; i++)
	{
		total_diff += abs(left_list[i] - right_list[i]);
	}

	printf("\tTotal list difference = %u\n", total_diff);

	printf("\tFinding similarity score...\n");

	unsigned int similarity_score = 0;
	for (size_t i = 0; i < list_length; i++)
	{
		int appearances = 0;
		for (size_t j = 0; j < list_length; j++)
		{
			if (left_list[i] == right_list[j]) appearances++;
		}

		similarity_score += appearances * left_list[i];
	}

	printf("\tSimilarity score = %u\n", similarity_score);

	free(left_list);
	free(right_list);
}

