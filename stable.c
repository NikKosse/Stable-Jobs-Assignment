//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
#include "jobSearch.h"

void stable(Job* job, People* person) { 
	
}

void hire(Job job, People person){

	strcpy(job.employeeFirst, person.first);
	strcpy(job.employeeLast, person.last);
	strcpy(person.job_title, job.jobName);

	if(job.openings > 0)
		job.openings--;
	else
		printf("Job not available!\n");
}

void fire(Job job, People person){
	
	strcpy(job.employeeFirst, "");
	strcpy(job.employeeLast, "");	
	strcpy(person.job_title, "");
}



