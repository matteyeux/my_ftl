/*
** ETNA PROJECT, 13/11/2018 by hauteb_m
** My_FTL
** File description:
**      repair system
*/

#include <stdlib.h>
#include <include/ftl.h>
#include <include/system_repair.h>
#include <include/my_string.h>
#include <include/my_readline.h>

static const repair_command_t my_array[] = {
    {"ftl_drive", ftl_drive_system_repair},
    {"navigation_tools", navigation_tools_system_repair},
    {"weapon", weapon_system_repair},
    {NULL, NULL}
};

void ftl_drive_system_repair(ship_t *my_ship)
{
    my_putstr_color("yellow", "repair of the reactor in progress...\n");
    free(my_ship->ftl_drive->system_state);

    my_ship->ftl_drive->system_state = my_strdup("online");

    if (my_ship->ftl_drive->system_state == NULL) {
        my_putstr_color("red", "the reactor repairs failed\n");
        return;
    }

    my_putstr_color("green", "repair complete! reactor system OK!\n");
}

void navigation_tools_system_repair(ship_t *my_ship)
{
    my_putstr_color("yellow", "repair of the navigation tools system in progress...\n");

    free(my_ship->navigation_tools->system_state);
    my_ship->navigation_tools->system_state = my_strdup("online");

    if (my_ship->navigation_tools->system_state == NULL) {
        my_putstr_color("red", "the reactor repairs failed\n");
        return;
    }

    my_putstr_color("green", "repair complete! navigation tools system OK!\n");
}

void weapon_system_repair(ship_t *my_ship)
{
    free(my_ship->weapon->system_state);

    my_ship->weapon->system_state = my_strdup("online");

    if (my_ship->weapon->system_state == NULL) {
        my_putstr_color("red", "the weapon system repairs failed\n");
        return;
    }

    my_putstr_color("green", "repair complete! weapon system OK!\n");
}

void system_repair(ship_t *my_ship)
{
    char *command;
    int i = 0;
    int yes = 0;

    my_putstr("repair_system~> ");
    command = my_readline();

    while (my_array[i].ptr != NULL) {
        if (!strcmp(my_array[i].ptr, command) && yes != 1) {
            yes = 1;
            my_array[i].pf(my_ship);
        }
        i++;
    }
}
