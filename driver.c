#include "jobSearch.h"

int main(int argc, char**argv){
	
	
        Job* job =  malloc(30 * sizeof(Job));
        People* people =  malloc(30 * sizeof(People));
	int* sizes;

	sizes = read(argc, argv, job, people);
	int jobSize = sizes[0];
	int peopleSize = sizes[1];

	stable(job, people, jobSize, peopleSize);
	return 0;
}
