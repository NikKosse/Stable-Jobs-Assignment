#include "jobSearch.h"

int main(int argc, char**argv){
	
	if (argc != 2)
	{
		printf("Usage: (executable) (text file)\n");
		return 0;
	}
        Job* job =  malloc(30 * sizeof(Job));
        People* people =  malloc(30 * sizeof(People));
	int* sizes;

	sizes = read(argc, argv, job, people);
	int jobSize = sizes[0];
	int peopleSize = sizes[1];

	stable(job, people, jobSize, peopleSize);
	return 0;
}
