/*
** ETNA PROJECT, 26/10/2018 by hauteb_m
** my_putnbr
** File description:
**      put nbr
*/

#include <unistd.h>
#include <include/my_string.h>

void my_putnbr(int n)
{
    if (n == -2147483648) {
        write(1, "-2147483648", 11);
        return;
    }

    if (n < 0) {
        my_putchar(45);
        n *= -1;
    }

    if (n >= 10) {
        my_putnbr(n / 10);
        my_putnbr(n % 10);
    } else {
        my_putchar(n + '0');
    }

}
