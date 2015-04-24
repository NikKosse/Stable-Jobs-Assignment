#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define numJob 2
#define numApp 4

typedef struct {
	char first[100];
	char last[100];
	char pref[10][10];
	int hasJob;
} Applicant;

typedef struct {
	char jobName[100];
	char pref[10][10];
	int openings;
	int full;
	char employees[10][10];
} Job;


int main() {
	system("clear");
	Applicant *applicants;
	applicants = malloc(numApp * sizeof(Applicant));
	
	Job *jobs;
	jobs = malloc(numJob * sizeof(Job));
	
	applicants[0].first = "John";
	applicants[0].last = "Doe";
	applicants[0].pref = "By", "Ax";
	applicants[0].hasJob = 0;
	applicants[0].job_title = NULL;

	applicants[1].first = "Jane";
	applicants[1].last = "Doe";
        applicants[1].pref = "Ax","By";
        applicants[1].hasJob = 0;
        applicants[1].job_title = NULL;

        applicants[2].first = "Max";
	applicants[2].last = "Doe";
        applicants[2].pref = "Ax","By";
        applicants[2].hasJob = 0;
        applicants[2].job_title = NULL;

        applicants[3].first = "Min";
	applicants[3].last = "Doe";
        applicants[3].pref = "By","Ax";
        applicants[3].hasJob = 0;
        applicants[3].job_title = NULL;
}
