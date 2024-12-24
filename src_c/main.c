/*
 * Advent of code in C
 * by jamesb-jay
 * A little late
 */

#include <stdio.h>
#include <string.h>

#define DOFATAL(message) do {printf("Fatal: %s\n", message); return 1;} while (0)


static void day1(FILE *fp)
{
	(void) fp;
}


int main(int argc, const char **argv)
{
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
