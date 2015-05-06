#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
	char jobName[100];
	char* pref[30];
	int openings;//to check if there are any openings check this value
	char employeeFirst[10];
	char employeeLast[10];
} Job;

typedef struct {
	char first[100];
	char last[100];
	char pref[10][10];
	char job_title[100];//to check if they are employed check this value
} People;

void stable(Job*, People*, int, int);
int *read(int, char**, Job*, People*);

