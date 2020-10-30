#include <stdio.h>
#include <stdlib.h>
/*
 c operator precedence
 *p++ will be parsed to *(p++)
*/
char *mystrcpy(char *dest, char *src)
{
	char * head = dest;
	while((*dest++ = *src++) != '\0');
	return head;
}

char *mystrncpy(char *dest, char *src, size_t count)
{
	char *head = dest;
	while(count-- && (*dest++ = *src++) != '\0');
	return head;
}

char * mystrcat(char * dest, const char * src)
{
	char *head = dest;
	while (*dest)
		dest++;
	while ((*dest++ = *src++) != '\0');
	return head;
}

int main()
{
	char *str1 = "what a fuck";
	char *str2 = (char *)malloc(sizeof(char)*20);
	char *str3 = (char *)malloc(sizeof(char)*20);

	char *str4 = mystrcpy(str2, str1);
	printf("str1: %s, str2: %s\n", str1, str2);
	printf("str4: %s\n", str4);

    	char *str5 = mystrncpy(str3, str1, 4);
	printf("str1: %s, str3: %s\n", str1, str3);
	printf("str5: %s\n", str5);

	char *str6 = mystrcat(str5, str2);
	printf("str6: %s\n", str6);

	free(str2);
	free(str3);

	char dest[] = "Hello,i am!";
	char source[] = "abc\0def";
	strncpy(dest, source, 5);
	printf("dest: %s\n", dest);

	return 0;
}
