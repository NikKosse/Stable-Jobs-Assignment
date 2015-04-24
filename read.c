#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Job {
   char jobName[100];
    char pref[10][10];
    int openings;
    int full;
    int employees[10][10];
};

struct People {
    
    char first[100];
    char last[100];
   char pref[10][10];
    int hasJob;
    char job_title[100];
};


int main(int argc, char**argv)
{
	
	if (argc > 2)
        {
                printf("USAGE: %s <Number of Iterations> (s1) (s2).....\n\n", argv[0]);
                return 0;
        }

        FILE *in;
        in = fopen(argv[1], "r");

	
        if (in == NULL)
        {
                printf("Error reading file... Terminating...");
                return 0;
        }
	

	char temp1[100];
    char temp2[100];
    char prefTemp[100];
    
    int i;
    int jobSize =0;
    int peopleSize =0;
    int l;
    int m;
    int temp;
    int n =0;
    
    int prefIndex;
    
  
    
    struct Job* jobTest =  malloc(sizeof(struct Job));
    struct People* peopleTest =  malloc(sizeof(struct People));
    
    

    while (1){
        fscanf(in, "%s", temp1);
        if (feof(in)) break;
      
        if (strcmp(temp1, "Departments") == 0)
            break;
        }
        
    while (1)
         {
                fscanf(in, "%s", temp1);
                
                if(strcmp(temp1, "Job") == 0)
                    break;
                 
                jobTest[jobSize].openings = atoi(temp1);
                
                fscanf(in, "%s", temp1);
                strcpy(jobTest[jobSize].jobName, temp1);

                jobSize++;
        }
        fscanf(in, "%s", temp1);
    

    
    while (1){
        fscanf(in, "%s", temp1);
      
        
        if(strcmp(temp1, "Preferences") == 0)
            break;
       
       
        strcpy(peopleTest[peopleSize].first, temp1);
      
    
        fscanf(in, "%s", temp1);
         strcpy(peopleTest[peopleSize].last, temp1);
       
        peopleSize++;
    }
 

    
    for (m=0; m<jobSize; m++){
            
        fscanf(in, "%s", temp1);
        
        
                    
        
        for (l=0; l<jobSize; l++)
        {
                        
            if(strcmp(temp1, jobTest[l].jobName) == 0){
                prefIndex = l;               
                break;
            }          
        }
                     
        n=0;
        

  
        while(1)
        {
                      
                fscanf(in, "%s", temp1);
            
             
            
                if(strcmp(temp1, "Preferences") == 0)
                    break;
            
            
            
            
              
            
       
            
              strcpy(jobTest[prefIndex].pref[n], temp1);
            
                fscanf(in, "%s", temp1);

              n++;
            
        }  
    }
     
    prefIndex =0;
    
    

    

    
    
    
    
    
    for (m=0; m<peopleSize; m++){
        fscanf(in, "%s", temp1);
        
      
        for (l=0; l<peopleSize; l++)
        {
            
            if(strcmp(temp1, peopleTest[l].first) == 0)
            {
                prefIndex = l;
                break;
            }
        }
        n=0;
        
        fscanf(in, "%s", temp1);
        
        while(1)
        {
                fscanf(in, "%s", temp1);
                if(strcmp(temp1, "Preferences") == 0)
                    break;
                if(strcmp(temp1, "END") == 0)
                    break;
            

             //peopleTest[prefIndex].pref[n] = (char*) malloc(100 * sizeof(char));
              strcpy(peopleTest[prefIndex].pref[n], temp1);
            
            
            
            
            n++;
               
            
        }  
        
    }
     
   
    int p, q;
  
    for (p=0; p<jobSize; p++)
    {
        printf("\n\nName: %s\n", jobTest[p].jobName);
        printf("Vaccacies: %d\n", jobTest[p].openings);
        printf("Pref Order:\n");
        
       
        for (q=0; q<peopleSize; q++)
        {
            printf("%d. %s\n", q+1, jobTest[p].pref[q]);   
        }
    }
   
    
    for (p=0; p<peopleSize; p++)
    {
        printf("\n\nName: %s %s\n", peopleTest[p].first, peopleTest[p].last);
        printf("Pref Order:\n");
        for (q=0; q<jobSize; q++)
        {
            printf("%d. %s\n", q+1, peopleTest[p].pref[q]);   
        }
    }
    
   
    

}