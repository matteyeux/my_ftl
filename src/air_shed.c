/*
** ETNA PROJECT, 12/11/2018 by hauteb_m
** My_FTL
** File description:
**      air_shed
*/

#include <stdlib.h>
#include <include/my_string.h>
#include <include/ftl.h>

ship_t *create_ship(void)
{
    ship_t *ship_to_create = NULL;

    my_putstr_color("yellow", "building of the ship in progress...\n");
    ship_to_create = malloc(sizeof(ship_t));

    if (ship_to_create == NULL) {
        my_putstr_color("red", "the ship could not be built due to lack of materials\n");
        return NULL;
    }

    ship_to_create->weapon = NULL;
    ship_to_create->ftl_drive = NULL;
    ship_to_create->navigation_tools = NULL;
    ship_to_create->container = NULL;
    ship_to_create->hull = 50;
    my_putstr_color("green", "ship improvement is finished!\n");
    return ship_to_create;
}

int add_weapon_to_ship(ship_t *my_ship)
{
    weapon_t *weapon = NULL;

    my_putstr_color("yellow", "adding weapons in progress...\n");

    weapon = malloc(sizeof(weapon_t));
    if (weapon == NULL) {
        my_putstr_color("red", "your ship exploded when you tried to add the weapons\n");
        return 0;
    }

    weapon->damage = 10;
    weapon->system_state = my_strdup("online");
    my_ship->weapon = weapon;
    my_putstr_color("green", "weapons were successfully added!\n");
    return 1;
}

int add_ftl_drive_to_ship(ship_t *my_ship)
{
    ftl_drive_t *ftl_drive = NULL;

    my_putstr_color("yellow", "adding the reactor in progress...\n");
    ftl_drive = malloc(sizeof(ftl_drive_t));
    if (ftl_drive == NULL) {
        my_putstr_color("red", "your ship exploded when you put the reactor in\n");
        return 0;
    }
    ftl_drive->energy = 10;
    ftl_drive->system_state = my_strdup("online");
    my_ship->ftl_drive = ftl_drive;
    my_putstr_color("green", "the reactor was successfully added!\n");
    return 1;
}

int add_navigation_tools_to_ship(ship_t *my_ship)
{
    navigation_tools_t *navigation_tools = NULL;

    my_putstr_color("yellow", "adding navigation tools...\n");
    navigation_tools = malloc(sizeof(navigation_tools_t));

    if (navigation_tools == NULL) {
        my_putstr_color("red", "your ship exploded when you put in the navigation tools\n");
        return 0;
    }

    navigation_tools->sector = 0;
    navigation_tools->evade = 25;
    navigation_tools->system_state = my_strdup("online");
    my_ship->navigation_tools = navigation_tools;
    my_putstr_color("green", "navigation tools were successfully added\n");
    return 1;
}
