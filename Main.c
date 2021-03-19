/*This program receives a list of 30 different names (not case sensitive), chooces a random name out of the list and prints it out. If the list contains two or more identical names, the program terminates immediately*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include "get_name.h"


char names[MAX_NAMES][MAX_CHARS]; /*This global array will contain the list of name given by the user*/

int main()
{
	int i,j;
	srand(time(NULL));/*initializing the seed of our random method which will be used on the list*/


	printf("\n Please enter a list of names \n");

	for (i = 0; i <MAX_NAMES; i++){
    	scanf("%s\n",names[i]);
		printf("\n %s", names[i]);
		
 	}

	
 	printf("\n");
	/*we'll check each name in the list with every other name in the list to make sure there are no duplicate names*/
	for (i = 0; i<MAX_NAMES; i++)
	{
    	for(j = i+1; j <=MAX_NAMES; j++)
		{
       		if(isEqual(names[i],names[j])==1)/*if isEqual returns 1 it means it found duplicate names*/
			{
				printf("\n The list contains two or more identical (not case sensitive) names. \n The program will terminate shortly. Please correct the list and try again. \n");
				exit(0);
			}
	
   		}
   		
	} 
	/*we'll call get_name method a number of times to print out a random name from the list*/
	printf("\nThe names that were drawn are:\n"); 
	for(i=1;i<=RAND_NAMES;i++)
	{
		
		printf("\n %s", get_name());
	}
	printf("\n");
	return 0;
}
	
/*this function chocces a random numbers in the range of the list (between 1 and the
 maximal index in the list) and then return a pointer to the list using that number*/
char* get_name()
{
	int lower=1, upper=MAX_NAMES;
	
	int num = (rand() % (upper - lower + 1)) + lower;
	
    return *(names+num); 
}
	
/*this function compares two string to see if they are equal. The function does not consider
capital or small letters. It returns 0 if the strings are different and 1 if they are equal */
int isEqual (char *str1,char *str2)
{
    int i;
    for(i=0; str1[i]!='\0'; i++)/*looping through the string*/
    {
        if( toupper(str1[i])!=toupper(str2[i]) )/*using 'toupper' to compare strings without consideration for capital or small letters */
            return 0;           
    }
	if(strlen(str1)-strlen(str2)!=0)/*if one string is longer or shorter than the other, they are surely not equal. This is to prevent the 
									function from returning 1 if the strings are equal except extra letters at the end */
		return 0;
	/*If none of the above apply, the strings are equal */
    return 1;
}
