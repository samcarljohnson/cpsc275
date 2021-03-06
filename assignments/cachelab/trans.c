/*
 * Name: Sam Johnson
 * Login ID: sjohnso7
 * Date: 11-28-13
 * 
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */ 
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);

/* 
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded. 
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
	//The labels on these variables help understand iteration over array A
	int blockcol, blockrow, col, row, size_of_block, true_M, true_N, size_flag, temp_index, diag_flag;
	//Switch statement below sets the block size for a specific matrix
	switch(M){
		case 32: 
			size_flag = 32;
			size_of_block = 8;
			break;
		case 64:
			size_flag = 64;
			size_of_block = 8;
			break;
		case 61:
			size_flag = 61;
			size_of_block = 23;
			true_N = N;
			true_M = M;
			N += size_of_block;
			M += size_of_block;
			break;
		default:
			size_of_block = 2;
			break;
	}
	
	/* Traverses A in row major fashion and before making the copy from A to B, the code checks to see  */
	/* if the index in question is along the diagonal. If it is, the copy is held off until exiting the */
	/* most interior for loop, and makes the copy then to prevent unecessary overwriting of the cache   */
	if(size_flag == 61){
	//Traverses Rows and Cols of entire matrix by size_of_block jumps
	for(blockcol = 0; blockcol < N; blockcol += size_of_block){
		for(blockrow = 0; blockrow < M; blockrow += size_of_block){
			//Traverses Rows and Cols of each block. If on the diagonal, hold off on the copy to B
			for(row = blockrow; row < blockrow + size_of_block && row < true_N; row++){
				for(col = blockcol; col < blockcol + size_of_block && col < true_M; col++){
					if(blockrow == blockcol && row == col){
						temp_index = row;
						diag_flag = 1;
					}
					else{
						B[col][row] = A[row][col];
					}	
				}
                                if(diag_flag==1){
                                	B[temp_index][temp_index] = A[temp_index][temp_index];
                                        diag_flag = 0;
                                }
			}	
		}
	}
	}
	
	/* Traverses A in row major fashion, and splits the blocks even more once inside before copy to B.  */
	/* Once within a block, the code below will start with the top left 4x4 submatrix and work its way  */
	/* to the bottom left, to the bottom right, and finally to the top right. This will milk the most   */
	/* out of what has been stored in the cache instead of just writing over data.                      */
	/* implements the same policy for diagonal indicies as the code for 61x67                           */
	else if(size_flag == 64){
        //Takes care of all the submatricies that are not along the diagonal
        for(blockrow = 0; blockrow < N; blockrow += size_of_block){
                for(blockcol = 0; blockcol < M; blockcol += size_of_block){
                        //Traverses Rows and Cols of each block. If on the diagonal, hold off on the copy to B
				//Top Left submatrix
                        	for(row = blockrow; row < (blockrow + (size_of_block/2)); row++){
					for(col = blockcol; col < (blockcol +(size_of_block/2)); col++){
                                 
					if(blockrow == blockcol && row == col){
                                                        	temp_index = row;
                                                        	diag_flag = 1;
                                               	}
                                               	else{
                                                        	B[col][row] = A[row][col];
                                                	}
                                        	}
                                        	if(diag_flag==1){
                                                	B[temp_index][temp_index] = A[temp_index][temp_index];
                                                	diag_flag = 0;
                                        	}				

				}
				//Bottom Left submatrix
				for(row = (blockrow + (size_of_block/2)); row < (blockrow + size_of_block); row++){
                                        for(col = blockcol; col < (blockcol + (size_of_block/2)); col++){
						if(blockrow == blockcol && row == col){
                                                        	temp_index = row;
                                                        	diag_flag = 1;
                                               	}
                                               	else{
                                                        	B[col][row] = A[row][col];
                                                	}
                                        	}
                                        	if(diag_flag==1){
                                                	B[temp_index][temp_index] = A[temp_index][temp_index];
                                                	diag_flag = 0;
                                        	}

				}
				//Bottom Right submatrix
				for(row = (blockrow + (size_of_block/2)); row < (blockrow + size_of_block); row++){
                                        for(col = (blockcol + (size_of_block/2)); col < (blockcol + size_of_block); col++){
                                		if(blockrow == blockcol && row == col){
                                                        temp_index = row;
                                                        diag_flag = 1;
                                                }
                                                else{
                                                        B[col][row] = A[row][col];
                                                }
                                        }
                                        if(diag_flag==1){
                                                B[temp_index][temp_index] = A[temp_index][temp_index];
                                                diag_flag = 0;
                                        }
				}
				//Top Right submatrix
				for(row = blockrow; row < (blockrow+(size_of_block/2)); row++){
                                        for(col = (blockcol + (size_of_block/2)); col < (blockcol + size_of_block); col++){
                                		if(blockrow == blockcol && row == col){
                                                        temp_index = row;
                                                        diag_flag = 1;
                                                }
                                                else{
                                                        B[col][row] = A[row][col];
                                                }
                                        }
                                        if(diag_flag==1){
                                                B[temp_index][temp_index] = A[temp_index][temp_index];
                                                diag_flag = 0;
                                        }

				}        
                }
        }
	}

        /* Traverses A in row major fashion and before making the copy from A to B, the code checks to see  */
        /* if the index in question is along the diagonal. If it is, the copy is held off until exiting the */
        /* most interior for loop, and makes the copy then to prevent unecessary overwriting of the cache   */
	else{
	int temp_index, diag_flag;
        //Traverses Rows and Cols of entire matrix by size_of_block jumps
        for(blockrow = 0; blockrow < N; blockrow += size_of_block){
                for(blockcol = 0; blockcol < M; blockcol += size_of_block){
                        //Traverses Rows and Cols of each block
                        for(row = blockrow; row < blockrow + size_of_block; row++){
                                for(col = blockcol; col < blockcol + size_of_block; col++){
                                        if(blockrow == blockcol && row == col){
                                                temp_index = row;
                                                diag_flag = 1;
                                        }
                                        else{
                                                B[col][row] = A[row][col];
                                        }
                                }
                                if(diag_flag==1){
                                        B[temp_index][temp_index] = A[temp_index][temp_index];
                                        diag_flag = 0;
                                }
                        }
                }
        }

	}

}

/* 
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started. 
 */ 

/* 
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    

}

/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc); 

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc); 

}

/* 
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

