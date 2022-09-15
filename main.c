#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello world\n");
    ft_printf("");

    // Printf testing to see how its working
    printf("#%X\n", 23);

    printf("%g\n%#g\n%G\n%#G\n%#g\n", (double)0, (double)0, (double)0, (double)0, (double)0);

    ft_printf("%.5d\n", 32544);
    ft_printf("%05d\n", 32455);
    ft_printf("%052d\n", 32455);
    ft_printf("%523d\n", 32455);
    ft_printf("%-0#52.3lld\n", 32455);
    ft_printf("%-0#52.3hhd\n", 32455);
    ft_printf("%s", "ANDREI");
//


//    int res1 = ft_printf("%c\n %c\n", 'c', 'd');
//    int res2 = ft_printf("%d\n", 2);
//
//    int res1p = printf("%c\n %c\n", 'c', 'd');
//    int res2p = printf("%d\n", 2);
//
//    printf("%d %d\n%d %d\n", res1, res1p, res2, res2p);
//
//    ft_printf("%% %d\n", 2);
//    int number = 4;
//    printf("%10d \n", number);
//    printf("%-10d \n", number);
//    printf("%0#10d \n", number);
//    printf("%-#10x \n", number);
//    printf("%#10x \n", number);

    return (0);
}
