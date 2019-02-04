/*
** ETNA PROJECT, 12/11/2018 by hauteb_m
** My_FTL
** File description:
**      another file
*/

#include <stdlib.h>
#include <include/ftl.h>
#include <include/my_string.h>

int add_container_to_ship(ship_t *my_ship)
{
    container_t *container = NULL;
    my_putstr_color("yellow", "adding the current container...\n");
    container = malloc(sizeof(container_t));

    if (container == NULL) {
        my_putstr_color("red", "your ship exploded when you put the container down\n");
        return 0;
    }

    container->first = NULL;
    container->last = NULL;
    container->nb_elem = 0;

    my_ship->container = container;
    my_putstr_color("green", "the container was successfully added\n");
    return 1;
}

void add_freight_to_container(ship_t *my_ship, freight_t *my_freight)
{

    if (my_ship->container->first == NULL) {
        my_ship->container->first = my_freight;
        my_ship->container->last = my_freight;
        my_freight->next = NULL;
        my_freight->prev = NULL;
    } else {
        my_ship->container->last = my_freight;
        //my_ship->container->next = my_freight;
    }

    my_ship->container->nb_elem += 1;
}

void del_freight_from_container(ship_t *my_ship, freight_t *my_freight)
{

    if (my_freight == NULL || my_ship == NULL) {
        return;
    }

    my_freight->prev->next = my_freight->next;
    my_freight->next->prev = my_freight->prev;

    my_ship->container->nb_elem = my_ship->container->nb_elem - 1;
    free(my_freight);
}

void get_bonus(ship_t *my_ship)
{
    freight_t *my_freight;
    //char *item;
    my_freight = my_ship->container->first;
    //item = my_freight->item;

    for (; my_freight != NULL; my_freight = my_freight->next) {
        if (!strcmp(my_freight->item, "attackbonus")) {
            my_ship->weapon->damage += 5;
        } else if (!strcmp(my_freight->item, "evadebonus")) {
            my_ship->navigation_tools->evade += 3;
        } else if (!strcmp(my_freight->item, "energy")) {
            my_ship->ftl_drive->energy += 1;
        } else if (!strcmp(my_freight->item, "scrap")) {
            my_putstr("don't do anything\n");
        } else {
            my_putstr("don't do anything\n");
        }
    }

    my_freight = my_ship->container->last;

    for (; my_freight != NULL; my_freight = my_freight->prev) {
        del_freight_from_container(my_ship, my_freight);
    }
}

