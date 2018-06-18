#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int getComplexity(char *s);

int main()
{
	char *sentence = (char *)malloc(sizeof(char) * 100);
	printf("enter the sentence : \n");
	fgets(sentence, 100, stdin);
	int length = strlen(sentence);
	printf("sentence is : %s length = %d", sentence, length);	
	printf("\nComplexity of sentence is : %d\n", getComplexity(sentence));
	
	return 0;
}

int isVowel(char ch)
{
	int isVowel = -1;
	
	switch(tolower(ch))
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			isVowel = 1;
			break;
		default:
			isVowel = 0;
	}
	
	return isVowel;
}

int isWordHard(char *word)
{
	int i;
	int numOfConsonants = 0;
	int numOfVowels = 0;
	int consecutiveConsonants = 0;
	
	for (i = 0; i < strlen(word); i++)
	{		
		if (word[i] == '\n')
			continue;
			
		if (isVowel(word[i]))
		{
			numOfVowels++;
			if (consecutiveConsonants >= 4)
			{
				return 1;
			}
			consecutiveConsonants = 0;	
		}
		else
		{
			numOfConsonants++;
			consecutiveConsonants++;
		}
	} 
	
	return consecutiveConsonants >=4 || (numOfConsonants > numOfVowels) ? 1 : 0;
}

int getComplexity(char *sentence)
{
	int numOfHardWords = 0;
	int numOfEasyWords = 0;
	
	char *word = strtok(sentence, " ");
	while (word)
	{
		if (isWordHard(word))
			numOfHardWords++;
		else
			numOfEasyWords++;
		
		word = strtok(NULL, " ");		
	}
	
	printf("\nHard = %d Easy = %d", numOfHardWords, numOfEasyWords);
	return 5*numOfHardWords + 3*numOfEasyWords;
}
