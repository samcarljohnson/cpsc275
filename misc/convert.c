/*
convert.c - Asks the user for a two digit number then prints the english word for it.
Author: Sam Johnson
Date: 9-15-13
*/

#include <stdio.h>

int main(){
        int num;
	printf("Enter a two-digit number: ");
	scanf("%d", &num);
	printf("You entered the number ");
        int firstNum = (num/10)%10;
        int secondNum = num%10;

        if(firstNum < 2){
                switch(num){
                        case 1: printf("One\n");
                                break;
                        case 2: printf("Two\n");
                                break;
                        case 3: printf("Three\n");
                                break;
                        case 4: printf("Four\n");
                                break;
                        case 5: printf("Five\n");
                                break;
                        case 6: printf("Six\n");
                                break;
                        case 7: printf("Seven\n");
                                break;
                        case 8: printf("Eight\n");
                                break;
                        case 9: printf("Nine\n");
                                break;
                        case 10: printf("Ten\n");
                                 break;
                        case 11: printf("Eleven\n");
                                 break;
                        case 12: printf("Twelve\n");
                                 break;
                        case 13: printf("Thirteen\n");
                                 break;
                        case 14: printf("Fourteen\n");
                                 break;
                        case 15: printf("Fifteen\n");
                        		 break;
                        case 16: printf("Sixteen\n");
                                 break;
                        case 17: printf("Seventeen\n");
                                 break;
                        case 18: printf("Eighteen\n");
                                 break;
                        case 19: printf("Nineteen\n");
                                 break;
                        default: printf("Zero\n");
                }
        }
        else{
			switch(firstNum){
					case 2: printf("Twenty");
							break;
					case 3: printf("Thirty");
							break;
					case 4: printf("Forty");
							break;
					case 5: printf("Fifty");
							break;
					case 6: printf("Sixty");
							break;
					case 7: printf("Seventy");
							break;
					case 8: printf("Eighty");
							break;
					case 9: printf("Ninety");
							break;
            }
            switch(secondNum){
            				case 1: printf("-One\n");
            						break;
					case 2: printf("-Two\n");
							break;
					case 3: printf("-Three\n");
							break;
					case 4: printf("-Four\n");
							break;
					case 5: printf("-Five\n");
							break;
					case 6: printf("-Six\n");
							break;
					case 7: printf("-Seven\n");
							break;
					case 8: printf("-Eight\n");
							break;
					case 9: printf("-Nine\n");
							break;
					case 0: printf("\n");
							break;
            }
        }
	return 0;
}

