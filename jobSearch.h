#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stable();
int read(int, char**);

struct Job {
    char jobName[100];
    char pref[10][10];
    int openings;
    int full;
    int employees[10][10];
};

struct People {
    char first[100];
    char last[100];
    char pref[10][10];
    int hasJob;
    char job_title[100];
};


