/*
price.c - Computes the best  price for tissue paper from input values and tells 
		  the user where it's sold the cheapest
Author: Sam Johnson / Jacobo Carbo
Date: 5-26-13
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
	/* Declaration of variables to read in for each line */
	int brand_code;
	int product_code;
	double length;
	double width;
	int sheets_per;
	int store_code;
	double price;
	double best_buy_price;
	int best_buy[3];
	
	/* Init of coded arrays for products/stores/brands */
	const char* brands_array[4];
	brands_array[0] = "Kleenex";
	brands_array[1] = "Charmin";
	brands_array[2] = "Delsey";
	brands_array[3] = "Generic";
	
	const char* product_array[2];
	product_array[0] = "Tissue";
	product_array[1] = "TP";
	
	const char* store_array[4];
	store_array[0] = "Shaw's";
	store_array[1] = "Walmart";
	store_array[2] = "BJ's";
	store_array[3] = "Mom's";
	
	/* Declaration and init of counter variables */
	int number_of_lines;
	int i,k;
	best_buy_price = 0.0;
	scanf("%d", &number_of_lines);
	
	/* Iterates over the input file until the amount of number_of_lines */
	/* has been read in and checked for a best price                    */
	for(i=0;i<number_of_lines;i++){
		scanf("%d %d %lf %lf %d %d %lf", &brand_code, &product_code, &length, &width, &sheets_per, &store_code, &price);
		
		/* Below is the algorithm which computes the best price per square inch of the product currently in memory */
		double calculated_price = price/((length*width)*sheets_per);
		
		/* If the best price hasn't been set or the calculated price is     */ 
		/* less than the current best price a new best price is set and the */
		/* product is stored away in an array to be referenced later        */
		if(i==0||calculated_price<best_buy_price){
			*(best_buy) = brand_code;
			*(best_buy+1) = product_code;
			*(best_buy+2) = store_code; 
			best_buy_price = calculated_price;
		}
	}
	/* The array that stored the information of the product with the best price per amount of product is   */
	/* used here to print relevant information for the user. What brand/product to get and where to get it */
	printf("Get %s %s at %s.\n", brands_array[best_buy[0]-1], product_array[best_buy[1]-1], store_array[best_buy[2]-1]);
	return 0;	
}