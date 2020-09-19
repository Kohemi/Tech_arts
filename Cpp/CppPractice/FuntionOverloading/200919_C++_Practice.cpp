#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

//char *MakeStrAdr(int len)
//{
//	char * str = (char*)malloc(sizeof(char)*len);
//	return str;
//}
//
//int main(void)
//{
//	char * str = MakeStrAdr(20);
//	strcpy(str, "I am so happy~");
//	cout << str << endl;
//	free(str);
//	return 0;
//}

int main()
{
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2, str1);
	strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}