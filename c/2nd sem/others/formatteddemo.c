#include<ctype.h>
void main()
{
	char keys;
	printf("Enter any key:\n");
	keys=getchar();
	if(isalpha(keys))
	{
		printf("Entered input is alphabet");
	}
	else if(isdigit(keys))
	{
		printf("Entered input is digit");
	}
	else
	{
		printf("Entered input neither an alphabet nor digit");
	}
}
