/*
 * Name: Sam Johnson 
 * Login ID: sjohnso7
 * Date: 11-25-13
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "cachelab.h"

// Defines the structure used for specific lines in the cache
struct line{
	int valid;
	unsigned long tag;
	int last_access;
};

//Definition of global variables
struct line* cache;
int timecounter;
int hitcount;
int misscount;
int evictioncount;
int numsets;
int numblocks;
unsigned int s,E,b,h,v;

//Function declarations
void createcache(unsigned int numsets, unsigned int E);
void load(unsigned int tagbits, unsigned int setbits);
void modify(unsigned int tagbits, unsigned int setbits);
void store(unsigned int tagbits, unsigned int setbits);

int main(int argc, char* argv[]){
    	char* tracefile;
    	/* Set to 0 used as flag from input */
	v = 0;
	int option = 0;
	
	/* Fetches the arguments passed to the program by the command line */
	while ((option = getopt(argc, argv,"hvs:E:b:t:")) != -1) {
        	switch (option) {
            		case 'h' : printf("Usage: ./csim [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n-h: Optional flag that prints usage info\n-v: Optional verbose mode that displays trace info\n-s <s>: Number of set index bits (S = 2^(s) is the number of sets\n-E <E>: Associativity (number of lines per set)\n-b <b>: Number of block bits (B= 2^(b) is the block size)\n-t <tracefile>: Name of the valgrind trace to replay\n");
                		break;
            		case 's' : s = atoi(optarg);
               		break;
            		case 'E' : E = atoi(optarg);
                		break;
            		case 'b' : b = atoi(optarg);
                		break;
            		case 't' : tracefile = optarg;
                		break;
            		case 'v' : v = 1;
                		break;
        	}
	}

	/* Opens the tracefile for reading */
	FILE *fp;
        fp = fopen(tracefile, "r");
        if(fp == NULL){
                printf("Can't open this file...\n");
                exit(1);
        }
	
	/* Creates the cache and stores values for numsets and numblocks */
   	numsets = 2<<s;
    	numblocks = 2<<b;
    	createcache(numsets,E);
        
	/* Reads in an instruction from the trace file  */
	char workinginstr[2];
	int unsigned long workinghex;
	int workingblock;
	
	while(fscanf(fp, " %1s %lx, %d", workinginstr, &workinghex, &workingblock) != EOF){
		/* Retrieves individual bit sequences from the hex value read in  */
        	unsigned int t;
        	unsigned int tagbits;
        	unsigned int setbits;
        	t = 64-(s+b);
        	tagbits = workinghex >> (s+b);
        	setbits = (workinghex << t) >> (64-s);
		/* Each time a new line is read from the trace file, the counter variable in incrememnted */
		timecounter++;		
		
		/* The sequence of if statements below decide which functions to call with each alphabetic instruction */
		if(workinginstr[0] == 'L'){
			if(v){
				printf("%s %lx, %d ", workinginstr, workinghex, workingblock);
			}
			load(tagbits, setbits);
		}
		if(workinginstr[0] == 'M'){
			if(v){
				printf("%s %lx, %d ", workinginstr, workinghex, workingblock);
			}
			load(tagbits, setbits);
			store(tagbits, setbits);
		}
		if(workinginstr[0] == 'S'){
			if(v){
				printf("%s %lx, %d ", workinginstr, workinghex, workingblock);
			}
			store(tagbits, setbits);
		}
	}
	
        printSummary(hitcount, misscount, evictioncount);
	free(cache);
	fclose(fp);
}

/* createcache - This function simply allocates space for the cache with the dimensions specified  */
void createcache(unsigned int numsets, unsigned int E){
    	cache = (struct line *)malloc(numsets*E*(sizeof(struct line)));
}

/* load - searches for a matching within the set specified and increases the hit/miss/eviction counters appropriately  */
void load(unsigned int tagbits, unsigned int setbits){
	int line;
	
	/* The first case is for tag matches where the valid bit is turned on  */
        for(line=0;line<E;line++){
                if(cache[line+setbits*E].tag == tagbits && cache[line+setbits*E].valid == 1){
                                cache[line+setbits*E].valid = 1;
                                cache[line+setbits*E].last_access = timecounter;
                                hitcount++;
				if(v){
					printf("hit\n");
				}                                
				return;
                        }
        }
	 /* The second case searches for a place in the cache where the valid bit is turned off to be used for storage  */
        for(line=0;line<E;line++){
                if(cache[line+setbits*E].valid == 0){
                         cache[line+setbits*E].valid = 1;
			 cache[line+setbits*E].tag = tagbits;
                         cache[line+setbits*E].last_access = timecounter;
                         misscount++;
			 if(v){
				 printf("miss\n");
			 }      
                         return;
                }
        }
	/* The third case is for when the cache is full for the given set and the last_access line needs to be computed for eviction  */
        for(line=0;line<E;line++){
                int l, min;
                min = 0;
                for(l=1;l<E;l++){
                        if(cache[l+setbits*E].last_access < cache[min+setbits*E].last_access){
                                min = l;
                        }
                }
                cache[min+setbits*E].last_access = timecounter;
		cache[min+setbits*E].tag = tagbits;
                misscount++;
                evictioncount++;
		if(v){
			printf("miss eviction\n");
		}      
                return;
        }
}

/* modify - modifies the data at a certain location in memory. Uses the cache to load and store this value  */
void modify(unsigned int tagbits, unsigned int setbits){
	load(tagbits, setbits);
	store(tagbits, setbits);
}

/* store - stores a value at a certain location in memory. Uses load to store this value  */
void store(unsigned int tagbits, unsigned int setbits){
	load(tagbits, setbits);

}
