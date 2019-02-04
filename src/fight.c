/*
** ETNA PROJECT, 14/11/2018 by hauteb_m
** My_FTL
** File description:
**      fight file
*/

#include <stdlib.h>
#include <include/my_string.h>
#include <include/ftl.h>
#include <include/enemy.h>

int randomize(void)
{
    return random() % (100 + 1 - 0) + 0;
}

void randomly_lose_energy(ship_t *my_ship)
{
    int will_i_lose;
    will_i_lose = randomize();

    if (will_i_lose >= 50) {
        my_putstr("lost energy\n");
        my_ship->ftl_drive->energy -= 1;
    }
}
