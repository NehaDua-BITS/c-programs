#include <stdio.h>
#include <string.h>

#define MAX 50

void reverseWordsUsingRecursion(char *word, char *targetStr)
{
    if (word)
    {
	reverseWordsUsingRecursion(strtok(NULL, " "),targetStr);
	
	//removing trailing newline character in word
	int wordLength = strlen(word);
	if ( word[wordLength-1] == '\n')
	    word[wordLength-1] = '\0';
	    
	strcat(targetStr, " ");
	strcat(targetStr, word);
    }	
}

int main()
{
    char sentence[MAX];
    char reversedPara[MAX] = {0};
    
    printf("Enter a sentence : ");
    fgets(sentence, MAX, stdin);
    printf("Entered sentence is : %s", sentence);
    
    reverseWordsUsingRecursion(strtok(sentence, " "), reversedPara);
    printf("Reversed para is : %s", reversedPara);
    
    return 0;
}
