#include "jobSearch.h"

void stable(Job* job, People* person, int jobSize, int peopleSize) { 
	//initalize everything
	int i =0;
	int numJobs = jobSize;
	printf("jobSize is: %d\n", numJobs);
	printf("peopleSize is: %d\n", peopleSize);
	//sets employees names to null
	for(i=0;i<numJobs;i++){
		strcpy(job[i].employeeFirst, "");
		strcpy(job[i].employeeLast, "");
	//	printf("setting to null\n");
	}
	
	for(i=0;i<peopleSize;i++){
		strcpy(person[i].job_title, "");
		printf("setting to null\n");
	}
	
	//begin matching
	numJobs = calcNumJobs(job, numJobs);
	i = 0;
	while(numJobs != 0)
	{
		numJobs=apply(job[i], person[i]);
		printf("number of jobs left after applying: %d \n", numJobs);
		printf("Applying %d\n",i);
		i++;
		//numJobs = calcNumJobs(job, jobSize);//must be at the end of the loop
		printf("number of jobs left: %d \n", numJobs);
	}
}

//function to get the total number of jobs left.  used to decide if the algorithm needs to keep going or not
int calcNumJobs(Job* jobs, int jobSize){
	int numJobs = 0;
	int i = 0;
	printf("calculating number of jobs left\n");
	for(i=0;i<jobSize;i++){
		numJobs += jobs[i].openings;
	//	printf("counting\n");fd
	//	printf("%d jobs\n",numJobs);
	}

	return numJobs;
}

//function to hire the person
int hire(Job job, People person){

	if(job.openings > 0)
		job.openings--;
	else
		printf("Job not available!\n");
	/*
		job.employees=(*char) malloc(30*sizeof(char));
		
	*/
	strcpy(job.employeeFirst, person.first);
	strcpy(job.employeeLast, person.last);
	strcpy(person.job_title, job.jobName);
	return job.openings;
	
}

//function to have a person apply to a job and they are either accepted or rejected
int apply(Job job, People person){

	if(job.openings != 0)//if there is a position available accept applicant
	{
		job.openings=hire(job, person);
	}
	else if (rank(job, person) < rank(job, person))
	{
		strcpy(job.employeeFirst, "");
		strcpy(job.employeeLast, "");	
		strcpy(person.job_title, "");		
		job.openings++;
		
		job.openings=hire(job, person);
	}
		return job.openings;
}

//function to return the employer's rank of a given person
int rank(Job job, People person){
	printf("you called rank!\n");
	int i;
	char* fullName=(char*) malloc(sizeof(char)*40);
	strcpy(fullName,person.first);
	strcat(fullName," ");
	strcat(fullName,person.last);
	printf("preferred person is %s\n",person.pref[0]);
	for(i=0; i<=job.openings && (strcmp(person.pref[i],fullName));i++); 
	return i;
}

/*int wantOtherJobEmployee(Job job, People person){

	would handle the case where one job felt another job's employee was better for them

}*/

/*void otherEmployee(){
	would match coveting job with said employee if they coveted one another.
}*/

/*void unstable() {

	would check for odd employee/employer match.

}*/