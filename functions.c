#include <stdio.h>
#include <string.h>

char *reverse_string(char *string); // Function prototype, interface for the function.

char *reverse_string(char *string) // Function that reverse's a string
{

	int length, left, right;
	char tmp;

	length = (int)strlen(string);
	left = 0;
	right = length - 1;

	while(left <= right) {
		tmp = string[left];
		string[left] = string[right];
		string[right] = tmp;
		++left;
		--right;
	}

	return string;
}
