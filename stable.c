#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define size 5
#define sName 50

typedef struct {
	char name[sName];
	char prefrences[sName][sName];
	int hasJob;
	char job_title[sName];
} Applicant;

typedef struct {
	char name[sName];
	char prefrences[sName][sName];
	int openings;
	int full;
	char employees[sName][sName];
} Job;


int main() {
	printf("fycker");
	system("clear");
	Applicant *applicants;
	applicants = malloc(size * sizeof(Applicant));
	
	Job *jobs;
	jobs = malloc(size * sizeof(Job));
}
