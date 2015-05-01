#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char jobName[100];
    char pref[10][10];
    int openings;
    int full;
    char employees[10][10];
} Job;

typedef struct {
    char first[100];
    char last[100];
    char pref[10][10];
    int hasJob;
    char job_title[100];
} People;

void stable(Job*, People*);
int read(int, char**, Job*, People*);

