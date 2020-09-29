#include <stdio.h>
int main() {
char *s;
char foo[] = "Hello World";
s = foo;
printf("s is %s\n",s);
printf("s[0] is %c\n",s[0]);
return(0);
} 

/* the problem was that the memory segment contaning the string "Hello World" is read-only, so when we tried to change its content by *s = foo; we got segmentation fault */
/* and in the printf("s[0] is %s\n",s[0]); we expect a string pointer, but we got a character itself  */
