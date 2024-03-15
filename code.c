#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char *str_arg;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            switch (*format)
            {
                case 'c':
                    {
                        char char_arg = va_arg(args, int);
                        write(1, &char_arg, 1);
                        count++;
                        break;
                    }
                case 's':
                    {
                        str_arg = va_arg(args, char *);
                        while (*str_arg)
                        {
                            write(1, str_arg, 1);
                            str_arg++;
                            count++;
                        }
                        break;
                    }
                case '%':
                    write(1, "%", 1);
                    count++;
                    break;
                default:
                    write(1, "%", 1);
                    write(1, format, 1);
                    count += 2;
                    break;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);

    return count;
}
