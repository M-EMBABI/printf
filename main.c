#include <stdio.h>

extern int _printf(const char *format, ...); // Declare _printf function

int main()
{
    _printf("Hello, %s!\n", "world"); // Call _printf function
    return 0;
}
