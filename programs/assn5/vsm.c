/*
vsm.c - Simulates a virtual machine and interprets programs written in vsml
author: Sam Johnson
date: 10-21-13
*/

#include <stdio.h>
#include <stdlib.h>

void load_program(int* memory, int* u_input);
int get_opcode(int instruction);
int get_operand(int instruction);
void read(int destination, int* memory, int* u_input, int count);
void write(int location, int* memory);
void load(int location, int* memory, int* accum);
void store(int location, int* memory, int* accum);
void add(int location, int* memory, int* accum);
void subtract(int location, int* memory, int* accum);
void divide(int location, int* memory, int* accum);
void multiply(int location, int* memory, int* accum);
int branch(int location, int instr_counter);
int branchneg(int location, int instr_counter, int* accum);
int branchzero(int location, int instr_counter, int* accum);


int main(){
	int* accumulator; // Accumulator register
	int instruction_counter; // Contains the current location in memory
	int instruction_register; // Contains the next instruction to be executed
	int operation_code;
	int operand;
	int read_counter = 0;
	int* vsm_memory = (int*)malloc(100*sizeof(int)); // Initializes the system memory
	int* user_input = (int*)malloc(100*sizeof(int)); // Holds onto the user_input
	printf("*** Welcome to VSM! ***\n*** Please enter your program one instruction ***\n*** (or data word) at a time. I will type the ***\n*** location number and a question mark (?).***\n*** You then type the word forthat location. ***\n*** Type the sentinel -9999to stop entering ***\n*** your program. ***\n");
	load_program(vsm_memory, user_input);
	printf("*** Program loading completed ***\n*** Program execution begins ***\n");
	instruction_counter = 0;
	while(instruction_counter<100){
		instruction_register = vsm_memory[instruction_counter];
		int operation_code = get_opcode(instruction_register);
		int operand = get_operand(instruction_register);
		// Below evaluates the operation_code and calls the appropriate function		
		switch(operation_code){
			case 10: read(operand, vsm_memory, user_input, read_counter);
					 read_counter++; 
					 break;
			case 11: write(operand, vsm_memory);
					 break;
			case 20: load(operand, vsm_memory, accumulator); 
					 break;
			case 21: store(operand, vsm_memory, accumulator);
					 break;
			case 30: add(operand, vsm_memory, accumulator); 
					 break;					 
			case 31: subtract(operand, vsm_memory, accumulator); 
					 break;
			case 32: divide(operand, vsm_memory, accumulator); 
					 break;
			case 33: multiply(operand, vsm_memory, accumulator);
					 break;
			case 40: instruction_counter = branch(operand, instruction_counter);
					 break;
			case 41: instruction_counter = branchneg(operand, instruction_counter, accumulator);
					 break;
			case 42: instruction_counter = branchzero(operand, instruction_counter, accumulator);
					 break;
			case 43: goto double_break;
			default: break;
		}
		instruction_counter++;
	}
	double_break:;
	printf("*** VSM execution terminated ***\n\n");
	
	// Computer Dump
	printf("REGISTERS:\n");
	printf("%-25s%+05d\n", "accumulator", *accumulator);
	printf("%-25s%02d\n", "instructionCounter", instruction_counter);
	printf("%-25s%+05d\n", "instructionRegister", instruction_register);
	printf("%-25s%02d\n", "operationCode", operation_code);
	printf("%-25s%02d\n", "operand", operand);
	printf("\nMEMORY:\n");
	printf("%8s%6s%6s%6s%6s%6s%6s%6s%6s%6s", "0","1","2","3","4","5","6","7","8","9");
	int k;
	for(k=0;k<100;k++){
		if(k%10 == 0){
			int s = k/10;
			printf("\n%d%s%s", s,"0"," ");
		}
		printf("%+05d ", vsm_memory[k]);
	}
	printf("\n");

}

/* load_program - Loads the program into the VSM's memory */
void load_program(int* memory, int* u_input){
 	int i = 0;
 	int j = 0;
 	int instruction = 0;
 	int program_code = 1; // Flag showing end of program code
 	while((scanf("%d", &instruction) != EOF)){
 		if(instruction<-9999 || instruction>9999){
 			printf("*** Invalid Instruction (Range is -9999 <= x <= 9999) ***\n");
 			printf("*** VSM execution abnormally terminated ***\n");
 			exit(0);
 		}
 		if(instruction == -9999){
 			program_code = 0;
 			goto here;
 		}
 		if(program_code){
 			memory[i] = instruction;
 			i++;
 		}
 		else{
 			u_input[j] = instruction;
 			j++;
 		}
 		here:;
 	}
}

/* get_opcode - Gets the opcode for the position in memory. */
int get_opcode(int instruction){
	int* opcode_p = (int*)malloc(2*sizeof(int));
	int opcode;
	
	// Divides up the instruction
	instruction /= 100;
	opcode_p[1] = instruction%10;
	instruction /= 10;
	opcode_p[0] = instruction%10;
	
	// Converts the int array into an int
	opcode = 10*opcode_p[0]+opcode_p[1];
	return opcode;
}

/* get_operand - Gets the operand for the position in memory. */
int get_operand(int instruction){
	int* operand_p = (int*)malloc(2*sizeof(int));
	int operand;
	
	// Divides up the instruction
	operand_p[1] = instruction%10;
	instruction /= 10;
	operand_p[0] = instruction%10;
	
	// Converts the int array into an int
	operand = 10*operand_p[0]+operand_p[1];
	return operand;
}

/* read - Reads in a value from the user and stores it at a specified location. */
void read(int destination, int* memory, int* u_input, int count){
	/* Below mimics scanning from the terminal. Fetches the next linear input 
	 * from the user_input array.
	 */
	int input_value = u_input[count]; 
	memory[destination] = input_value;
}

/* write - Writes a value from the VSM memory to the console. */
void write(int location, int* memory){
	printf("%d\n", memory[location]);
}

/* load - Loads a value from memory into the accumulator. */
void load(int location, int* memory, int* accum){
	*accum = memory[location];
}

/* store - Stores a value from the accumulator into the memory. */
void store(int location, int* memory, int* accum){
	memory[location] = *accum;
}

/* add - Adds a word from a memory location to the value in the accumulator. */
void add(int location, int* memory, int* accum){
	*accum = *accum + memory[location];
	if(*accum < -9999 || *accum > 9999){
		printf("*** Integer Overflow ***\n");
 		printf("*** VSM execution abnormally terminated ***\n");
 		exit(0);
	}
}

/* subtract - Subtracts a word from a memory location to the value in the accumulator. */
void subtract(int location, int* memory, int* accum){
	*accum = *accum - memory[location];
	if(*accum < -9999 || *accum > 9999){
		printf("*** Integer Overflow ***\n");
 		printf("*** VSM execution abnormally terminated ***\n");
 		exit(0);
	}
}

/* divide - Divides a word from a memory location to the value in the accumulator. */
void divide(int location, int* memory, int* accum){
	if(memory[location] == 0){
		printf("*** Attempt to divide by zero ***\n");
 		printf("*** VSM execution abnormally terminated ***\n");
 		exit(0);
	}
	*accum = *accum / memory[location];
}

/* multiply - Multiplies a word from a memory location to the value in the accumulator. */
void multiply(int location, int* memory, int* accum){
	*accum = *accum * memory[location];
	if(*accum < -9999 || *accum > 9999){
		printf("*** Integer Overflow ***\n");
 		printf("*** VSM execution abnormally terminated ***\n");
 		exit(0);
	}
}

/* branch - Branches to a specific location in memory. */
int branch(int location, int instr_counter){
	instr_counter = location;
	return instr_counter;
}

/* branchneg - Branches to a specific location in memory if accumulator < 0. */
int branchneg(int location, int instr_counter, int* accum){
	if(*accum < 0){
		instr_counter = location-1;
	}
	return instr_counter;
}

/* branchzero - Branches to a specific location in memory if accumulator == 0. */
int branchzero(int location, int instr_counter, int* accum){
	if(*accum == 0){
		instr_counter = location-1;
	}
	return instr_counter;
}
