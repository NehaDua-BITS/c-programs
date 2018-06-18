#include <stdio.h>
#include <stdlib.h>

typedef struct height {
	int feet;
	int inches;
}Height;

Height *createItem(int feet, int inches)
{
	Height *h = (Height *)malloc(sizeof(Height));
	h->feet = feet;
	h->inches = inches;
	return h;
}

void printMaxHeight(Height* hArray[5])
{
	int maxHeight = 0;
	int i,height;
	for(i = 0; i < 5; i++)
	{
		height = hArray[i]->feet * 12 + hArray[i]->inches; 
		if(height > maxHeight)
		{
			maxHeight = height;
		}
	}
	
	printf("Max height = %d feet %d inches", maxHeight/12, maxHeight%12);  
}

int main()
{
	printf("in main function");
	
	Height* heightArray[5];
	heightArray[0] = createItem(5, 10);
	heightArray[1] = createItem(5, 2);
	heightArray[2] = createItem(4, 8);
	heightArray[3] = createItem(15, 10);
	heightArray[4] = createItem(12, 6);
	
	printf("in main function");
	
	printMaxHeight(heightArray);
	return 0;
}
