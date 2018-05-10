#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define buffSize 2096

char buffer[buffSize] = { '\0' };

int automata();

int main() {	
	
	if(automata() == 1)
		printf("\nFailed\n");
		
	else
		printf("\nSuccess\n");

	
	return 0;
	
}

int automata(){
	
	int i = 0;
	//Scan the array from the start until it finds a new line
	scanf("%[^\n]s", buffer);
	
	//Detect the number of characters
	while(!buffer[i]== '\0')
		i++;
	
	//Copy the buffer to a new String
	int opStringSize = i;
	char opString[opStringSize];	
	memset(opString, 0, opStringSize);
	strcpy(opString, buffer);
	
	//Print the string
	for(i = 0 ; i < opStringSize ; i++)
		putchar(buffer[i]);
		
		
	i = 0;
	//First Phase
	//Check if it starts with a letter
	if(!isupper(opString[i]))
		return 1;
	
	i++;//Character already checked
	//Check if the rest is a letter
	while(isupper(opString[i]))
		i++;
	
	printf("\nI found a secuence of letters\n");
	
	//Second Phase
	//Check if there are spaces	
	if(!isblank(opString[i]))
		return 1;
	
	//Check if there are adtitional spaces
	while(isblank(opString[i]))
		i++;
	
	printf("I found blank spaces\n");
	
	//Third Phase
	//Check if there is a numeral or ampersand
	if(!(opString[i] == 36 || opString[i] == 35))
		return 1;
	
	printf("I found a dollar sign or numeral\n");
	
	i++;//Character already checked
	
	//Fourth Phase
	//Check the operand (ONLY NUMBERS)
	if(!isdigit(opString[i]))
		return 1;
	
	//Check if there is aditional numbers
	while(isdigit(opString[1]))
		i++;
		
	printf("I found a secuence of numbers");
	
	return 0;

} 
