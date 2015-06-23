/*
	automata.c -- this program reads in a pattern string and creates a new pattern with a given pattern rule
	Author: Sam Johnson
	Date: 10-7-13
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRAY_LENGTH 8

/* Function Prototypes */
int* create_rule_pattern(int rule_number);
int* new_generation(int* input_string, int* r_pattern, int len);
int* generation_repeater(int* input_string, int* r_pattern, int generations, int len);

int main()
{
	int i;
	int number_of_lines;
	scanf("%d", &number_of_lines);
	for(i=0;i<number_of_lines;i++)
	{
		char* initial_string = (char*)malloc(50*sizeof(char));
		int* initial_string_i = (int*)malloc(50*sizeof(int));
		int* rule_pattern = (int*)malloc(8*sizeof(int));
		int* final_pattern = (int*)malloc(50*sizeof(int));
		int rule_number;
		int generations;
		scanf("%s %d %d\n", initial_string, &rule_number, &generations);
		
		/* --IMPORTANT-- keeps track of the true length of the initial input string */
		/* 				 this value is passed to each function as "int len"		    */
		int len = strlen(initial_string);
		
		/* The for loop below converts the character string into an integer array */
		int j;
		for(j=0;j<len;j++)
		{
			*(initial_string_i+j) = (*(initial_string+j))-'0';
		}
		
		/* Below are the function calls required to produce the output for each line */
		rule_pattern = create_rule_pattern(rule_number);
		final_pattern = generation_repeater(initial_string_i, rule_pattern, generations, len);
		
		/* Prints the full pattern for a given row. This is the final output */
		int k;
		for(k=0;k<len;k++)
		{
			printf("%d", *(final_pattern+k));
		}
		printf("\n");
	}
	return 0;
}

/* create_rule_pattern -- This function creates a binary pattern for the rule number provided */
int* create_rule_pattern(int rule_number)
{
	int rule = rule_number;
	int temp_rule = rule;
	int i = 0;
	
	int* new_pattern = (int*)malloc(ARRAY_LENGTH*sizeof(int));
	int binary_divisors[] = {128,64,32,16,8,4,2,1};
	
	while(i<ARRAY_LENGTH)
	{
		if(temp_rule/binary_divisors[i] >= 1)
		{
			temp_rule = rule%binary_divisors[i];
			new_pattern[i] = 1;
		}
		else
		{
			new_pattern[i] = 0;
		}
		i++;
	}
	return new_pattern;
}

/* generation_repeater -- This function calls the "new_generation" function "generations"    */
/* 						  amount of times. This results in the final pattern that is output. */
int* generation_repeater(int* input, int* r_pattern, int generations, int len)
{
	int* rule_pattern = r_pattern;
	int* temp_pattern = input;
	int i;
	for(i=0;i<generations;i++)
	{
		temp_pattern = new_generation(temp_pattern, rule_pattern, len);
	}
	return temp_pattern;
}



/* new_generation -- This function generates the new generation of a provided pattern according */
/*  				 to the rules provided by the rules pattern. 								*/
int* new_generation(int* input_string, int* r_pattern, int len)
{
	int* rule_pattern = r_pattern; // rule 142 in binary
	int* input_pattern = input_string; // sample input pattern
	int* new_generation = (int*)malloc(50*sizeof(int));
	int binary_divisors[] = {128,64,32,16,8,4,2,1};
	
	int i;
	int row;
	int col;
	int temp_pattern[3];
	int count = 0;
	int matched_pattern;
	
	/* Below is the array of 3-int patterns to be compared against. */
	int list_of_patterns[ARRAY_LENGTH][3] =
	{
		{0,0,0},
		{0,0,1},
		{0,1,0},
		{0,1,1},
		{1,0,0},
		{1,0,1},
		{1,1,0},
		{1,1,1}
	};
	
	/* This first for loop runs through each element in the input pattern and performs more */
	/* specific operations on each element as the repetition structure gets deeper.         */
	for(i=0; i<len; i++)
	{
		/* The if/else structure below fetches the 3 number pattern for each index  */
		/* of the input pattern													    */
		if(i==0)
		{
			temp_pattern[0] = input_pattern[len-1];
			temp_pattern[1] = input_pattern[i];
			temp_pattern[2] = input_pattern[i+1];
		}
		else if(i==len-1)
		{
			temp_pattern[0] = input_pattern[i-1];
			temp_pattern[1] = input_pattern[i];
			temp_pattern[2] = input_pattern[0];
		}
		else
		{
			temp_pattern[0] = input_pattern[i-1];
			temp_pattern[1] = input_pattern[i];
			temp_pattern[2] = input_pattern[i+1];
		}
		
		/* The for loop below attempts to match the 3-int pattern fetched from the input       */
		/* pattern to one that was predefined earlier in the function. (See: list_of_patterns) */
		for(row=0; row<ARRAY_LENGTH; row++)
		{
			int match = 1;
			for(col=0; col<3; col++)
			{
				if(list_of_patterns[row][col] != temp_pattern[col])
				{
					match = 0;
					break;
				}
			}
			if(match == 1)
			{
				matched_pattern = row;
				break;
			}
		}
		new_generation[i] = rule_pattern[(sizeof(rule_pattern)-1)-matched_pattern];
	}
	return new_generation;
}