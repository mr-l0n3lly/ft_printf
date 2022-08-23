#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("Hello world\n");
    ft_printf("");

    // Printf testing to see how its working
    printf("#%X\n", 23);

    printf("%g\n%#g\n%G\n%#G\n%#g\n", (double)0, (double)0, (double)0, (double)0, (double)0);

    printf("%.2G", (double)32.3);
    return (0);
}
