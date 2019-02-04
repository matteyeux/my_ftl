/*
** ETNA PROJECT, 13/11/2018 by hauteb_m
** My_FTL
** File description:
**      break system
*/

#include <stdlib.h>
#include <include/ftl.h>
#include <include/fight.h>
#include <include/system_repair.h>
#include <include/system_break.h>
#include <include/commands.h>
#include <include/my_string.h>
#include <include/my_readline.h>

static const my_stuff_t my_array[] = {
    {0, "ftl_drive", ftl_drive_system_break},
    {1, "navigation_tools", navigation_tools_system_break},
    {2, "weapon", weapon_system_break},
    {0, NULL, NULL}
};

int randomize_but_with_3(void)
{
    return random() % (2 + 1 - 0) + 0;
}

void ftl_drive_system_break(ship_t *my_ship)
{
    free(my_ship->ftl_drive->system_state);

    my_ship->ftl_drive->system_state = my_strdup("offline");

    if (my_ship->ftl_drive->system_state == NULL) {
        my_putstr("break failed\n");
        return;
    }

}

void navigation_tools_system_break(ship_t *my_ship)
{
    free(my_ship->navigation_tools->system_state);
    my_ship->navigation_tools->system_state = my_strdup("offline");

    if (my_ship->navigation_tools->system_state == NULL) {
        my_putstr("break failed\n");
        return;
    }

}

void weapon_system_break(ship_t *my_ship)
{
    free(my_ship->weapon->system_state);

    my_ship->weapon->system_state = my_strdup("offline");

    if (my_ship->weapon->system_state == NULL) {
        my_putstr("break failed\n");
        return;
    }

}

void randomly_break_something(ship_t *my_ship)
{
    int i = 0;
    int random_with_3;

    random_with_3 = randomize_but_with_3();

    while (my_array[i].id != random_with_3)
        i++;
    my_array[i].pf(my_ship);
    my_putstr_color("red", my_array[i].name);
    my_putstr_color("red", " is now broken\n");
}
