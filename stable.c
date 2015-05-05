#include "jobSearch.h"

void stable(Job* job, People* person) { 
	//logic will go here
}

//function to hire the person
void hire(Job job, People person){

	if(job.openings > 0)
		job.openings--;
	else
		printf("Job not available!\n");

	strcpy(job.employeeFirst, person.first);
	strcpy(job.employeeLast, person.last);
	strcpy(person.job_title, job.jobName);

}

//function to have a person apply to a job and they are either accepted or rejected
void apply(Job job, People person, Job currJob, People currPerson){

/*	Job* currJob = malloc(sizeof(Job));
	currJob = job[current];//will this work?

	Person* currPerson = malloc(sizeof(Person));
	currPerson = person[current];//will this work?*/

	if(job.openings != 0)//if there is a position available accept applicant
	{
		hire(job, person);
	}
	//this is where I"m stuck, handling the fireing of the current employee and hiring the new one.  keeping track of which is which is throwing me off, I'm sure the solution is simple I'm just not seeing it. good luck!
	else if (rank(currJob, currPerson) < rank(job, person))
	{
		strcpy(currJob.employeeFirst, "");
		strcpy(currJob.employeeLast, "");	
		strcpy(currPerson.job_title, "");		
		currJob.openings++;
		
		hire(job, person);
	}
		
}

//function to return the employer's rank of a given person
int rank(Job job, People person){
	printf("you called rank!\n");
	int i;
	char* fullName=(char*) malloc(sizeof(char)*40);
	strcpy(fullName,person.first);
	strcat(fullName," ");
	strcat(fullName,person.last);
	for(i=0; i<=job.openings && (strcmp(job.pref[i],fullName));i++); 
	return i;
}

void tempHire() {


}
