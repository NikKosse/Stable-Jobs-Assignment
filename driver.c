#include "jobSearch.h"

int main(int argc, char**argv){
	
	
        Job* job =  malloc(30 * sizeof(Job));
        People* people =  malloc(30 * sizeof(People));

	read(argc, argv, job, people);
	stable(job, people);
	return 0;
}
