#include <cstdio>

const char string[] = "This is a null-terminated string.";

void printStrlen(const char* const string) 
{
	int count = 0;

	for (auto ptr = string; *ptr; ++ptr) {
		++count;
	}

	printf("The number of character is: %d\n", count);
}

//int main() 
//{
//	printStrlen(string);
//}