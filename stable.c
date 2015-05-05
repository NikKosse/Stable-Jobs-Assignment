#include "jobSearch.h"

void stable(Job* job, People* person, int jobSize, int peopleSize) { 
	//initalize everything
	int i =0;
	int numJobs = 0;
	for(i=0;i<jobSize;i++){
		strcpy(job[i]employeeFirst, "");
		strcpy(job[i]employeeLast, "");
	}

	for(i=0;i<peopleSize;i++){
		strcpy(person[i].job_title, "");
	}
	
	//begin matching
	numJobs = calcNumJobs(job, jobSize);
	i = 0;
	while(numJobs != 0)
		
		//do stuff here
		numJobs = calcNumJobs(job, jobSize);//must be at the end of the loop
}

//function to get the total number of jobs left.  used to decide if the algorithm needs to keep going or not
int calcNumJobs(Job* jobs, int jobSize){
	int numJobs = 0;
	int i = 0;

	for(i=0;i<jobSize;i++){
		numJobs += jobs[i].openings;
	}

	return numJobs;
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

	if(job.openings != 0)//if there is a position available accept applicant
	{
		hire(job, person);
	}
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


