#include "jobSearch.h"

void stable(Job* job, People* person) { 
	//logic will go here
}

void hire(Job job, People person){

	if(job.openings > 0)
		job.openings--;
	else
		printf("Job not available!\n");

	strcpy(job.employeeFirst, person.first);
	strcpy(job.employeeLast, person.last);
	strcpy(person.job_title, job.jobName);

}

void apply(Job job, People person){

//	Person* currEmployee = *person;

	if(job.openings != 0)//if there is a position available accept applicant
	{
		hire(job, person);
	}
	//this is where I"m stuck, handling the fireing of the current employee and hiring the new one.  keeping track of which is which is throwing me off, I'm sure the solution is simple I'm just not seeing it. good luck!
	else if (rank(job, person) < rank(job, person))//if there are no positions compare people and choose the one that's higher ranked. NOTE: rank not written yet
	{
		strcpy(job.employeeFirst, "");
		strcpy(job.employeeLast, "");	
		strcpy(person.job_title, "");		
		job.openings++;
		
		
	}
		
}

int rank(Job job, People person){
	printf("you called rank!\n");

	return 0;
}
