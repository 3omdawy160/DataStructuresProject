#include "header.h"

// This function aims to take a string with new lines,tabs and spaces and convert it into a single line string.

string Minifying(string s)
{
	for(int i=0;i<s.length();i++)   // Looping on the whole string char by char
	{
		if(s[i]=='\n' || s[i]==' ') // In case we found a new line or a space in the string
		{
			s.erase(i,1); // Erasing this space or new line
			i--;          // Decreminting the iterator i to as we erased a place therefore i must be Decreminted to be at the same place it were 
		}
	}

	return s;
}
