/*
** ETNA PROJECT, 13/11/2018 by hauteb_m
** My_FTL
** File description:
**      another file
*/

#include <include/ftl.h>
#include <include/my_string.h>

void ftl_drive_system_check(ship_t *my_ship)
{
    char *reactor;
    reactor = my_ship->ftl_drive->system_state;
    my_putstr_color("yellow", "checking the reactor in progress...\n");
    if (!strcmp(reactor, "online")) {
        my_putstr_color("green", "reactor OK!\n");
    } else {
        my_putstr_color("red", "reactor out of order!\n");
    }
}

void navigation_tools_system_check(ship_t *my_ship)
{
    char *nav_tools;
    nav_tools = my_ship->navigation_tools->system_state;

    my_putstr_color("yellow", "checking the navigation tools in progress...\n");

    if (!strcmp(nav_tools, "online")) {
        my_putstr_color("green", "navigation tools OK!\n");
    } else {
        my_putstr_color("red", "navigation tools out of order!\n");
    }
}

void weapon_system_check(ship_t *my_ship)
{
    char *weapon;
    weapon = my_ship->weapon->system_state;

    my_putstr_color("yellow", "checking weapon system in progress...\n");

    if (!strcmp(weapon, "online")) {
        my_putstr_color("green", "weapon system OK!\n");
    } else {
        my_putstr_color("red", "weapon system out of order!\n");
    }
}

void system_control(ship_t *my_ship)
{
    ftl_drive_system_check(my_ship);
    navigation_tools_system_check(my_ship);
    weapon_system_check(my_ship);
}

