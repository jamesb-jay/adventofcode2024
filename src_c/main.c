/*
 * Advent of code in C
 * by jamesb-jay
 * A little late
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOFATAL(message) do {printf("Fatal: %s\n", message); return 1;} while (0)

static int cmpInt(const void *a, const void *b)
{
	return (*(int*)a - *(int*)b);
}

static void day1(FILE *fp)
{
	printf("\tReading file...\n");

	rewind(fp);

	size_t list_length = 0;
	size_t list_capacity = 0xF00;
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
			list_capacity += 0xF00;
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


int main(int argc, const char **argv)
{
	/* Arg guarding */
	if (argc < 2) DOFATAL("No puzzle input!");
	if (argc < 3) DOFATAL("No day!");

	if (strlen(argv[1]) > 255)
		DOFATAL("Path input too long!");
	if (strlen(argv[2]) == 4)
		DOFATAL("Day input too long");


	int day;
	int s = sscanf(argv[2], "%d", &day);
	if (s != 1)
		DOFATAL("Day number could not be parsed!");



	FILE *fp = fopen(argv[1], "r");

	if (!fp) DOFATAL("Could not read puzzle input!");

	/* Run day */
	printf("==== Starting AOC day %d\n", day);

	switch (day)
	{
	case 1:
		day1(fp);
		break;
	default:
		DOFATAL("No such day!");
		break;
	}


	printf("==== Finished day %d\n", day);
	return 0;
}
