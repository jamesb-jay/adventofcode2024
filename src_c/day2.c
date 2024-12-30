#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEVELS 8

typedef struct Report {
    char levels[MAX_LEVELS];
    size_t count;
} Report;

#if 0
static void print_report(Report *r)
{
    for (size_t i = 0; i < r->count; i++)
    {
        printf("%d ", r->levels[i]);
    }

    printf("\n");
}
#endif


static int is_report_safe(Report *r)
{
    char diff[MAX_LEVELS - 1];

    for (size_t i = 0; i < r->count-1; i++)
    {
        diff[i] = r->levels[i] - r->levels[i+1];
        if (diff[i] == 0) return 0;
        if (abs(diff[i]) > 3) return 0;
    }

    for (size_t i = 0; i < r->count-2; i++)
    {
        if (diff[i] > 0 && diff[i+1] < 0) return 0;
        if (diff[i] < 0 && diff[i+1] > 0) return 0;
    }

    return 1;
}

#if 0
static int is_report_safe_tolerate(Report *r)
{
    char diff[MAX_LEVELS - 1];

    for (size_t i = 0; i < r->count-1; i++)
    {
        diff[i] = r->levels[i] - r->levels[i+1];
        if (diff[i] == 0) return 0;
        if (abs(diff[i]) > 3) return 0;
    }

    for (size_t i = 0; i < r->count-2; i++)
    {
        if (diff[i] > 0 && diff[i+1] < 0) return 0;
        if (diff[i] < 0 && diff[i+1] > 0) return 0;
    }

    return 1;
}
#endif 

void day2(FILE *fp)
{
    rewind(fp);

    size_t report_capacity = 0x100;
    size_t reports_count = 0;
    Report *reports = calloc(report_capacity, sizeof(Report));
    char line_buffer[256];

    if (reports == NULL)
    {
        printf("Failed to alloc memory");
        return;
    }
    
    while (fgets(line_buffer, sizeof line_buffer, fp) != NULL)
    {
        int i = 0;

        char *tok = strtok(line_buffer, " ");
        while (tok != NULL)
        {
            int n = atoi(tok);
            reports[reports_count].levels[i++] = (char) n;
            tok = strtok(NULL, " ");
        }
        reports[reports_count].count = i;
        reports_count++;

        if (reports_count >= report_capacity)
        {
            report_capacity += 0x100;
            reports = realloc(reports, report_capacity * sizeof(Report));
        }
    }


    unsigned int total_safe = 0;
    for (size_t i = 0; i < reports_count; i++)
    {
        int safe = is_report_safe(&reports[i]);
        if (safe) total_safe++;
        #if 0
        printf("[%s] ", safe ? "SAFE" : "    ");
        print_report(&reports[i]);
        #endif
    }

    printf("\tTotal safe reports = %u\n", total_safe);

    free(reports);
}