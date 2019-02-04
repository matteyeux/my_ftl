/*
** ETNA PROJECT, 14/11/2018 by hauteb_m
** My_FTL
** File description:
**      enemy file
*/

#include <stdlib.h>
#include <time.h>
#include <include/enemy.h>
#include <include/my_string.h>
#include <include/ftl.h>
#include <include/my_putnbr.h>

int create_enemy(ship_t *my_ship)
{
    enemy_t *my_enemy = NULL;
    my_enemy = malloc(sizeof(enemy_t));

    if (my_enemy == NULL) {
        my_putstr_color("red", "failed to build enemy\n");
        return 0;
    }

    my_enemy->damage = 10;
    my_enemy->life = 20;
    my_enemy->is_up = 1;
    my_ship->enemy = my_enemy;

    return 1;
}

void update_enemy(ship_t *my_ship, int enemy_nb)
{
    int i = 0;

    for (; i < enemy_nb; ++i)
    {
        my_ship->enemy->damage += my_ship->enemy->damage * 0.5;
        my_ship->enemy->life += my_ship->enemy->life * 0.5;
    }
}

void info_enemy(ship_t *my_ship)
{
    my_putstr("[i] enemy's life : ");
    my_putnbr(my_ship->enemy->life);
    my_putchar('\n');
}

void destroy_enemy(ship_t *my_ship)
{
    free(my_ship->enemy);
}
