#define MAX_NAMES 30 /*The maximal number of names in the list received from the user */
#define MAX_CHARS 20 /*The maximal letters in each name in the list*/
#define RAND_NAMES 10 /*The number of names which will be randomly chosen out of the list*/

char* get_name();/*This function does not receive any parameters and returns a random number between 0 and the maximal index in the list*/
 
int isEqual(char str1[],char str2[]);/*This function receives two strings and returns 1 if they're equal or 0 if they're not*/
