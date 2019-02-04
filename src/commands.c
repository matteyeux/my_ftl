/*
** ETNA PROJECT, 14/11/2018 by hauteb_m
** project_name
** File description:
**      project_description
*/

#include <stdlib.h>
#include <include/my_putnbr.h>
#include <include/ftl.h>
#include <include/fight.h>
#include <include/enemy.h>
#include <include/commands.h>
#include <include/container.h>
#include <include/system_repair.h>
#include <include/system_control.h>
#include <include/system_break.h>
#include <include/my_string.h>

static const my_commands_t my_commands[] = {
    {"attack", attack},
    {"detect", detect},
    {"jump", jump_my_ship},
    {"getbonus", get_bonus},
    {"repair_system", system_repair},
    {"control_system", system_control},
    {"stat", stat},
    {"help", help},
    {NULL, NULL}
};

void jump_my_ship(ship_t *my_ship)
{
    if (!strcmp(my_ship->ftl_drive->system_state, "offline"))
    {
        my_putstr_color("red", "[e] ftl drive is down, you can't jump\n");
    }
    my_ship->navigation_tools->sector += 1;
    my_ship->ftl_drive->energy -= 1;
}

void attack(ship_t *my_ship)
{
    int evade_val;
    int break_stuff_down = 20;

    evade_val = randomize();

    my_putstr_color("green", "[i] my_ship is attacking\n");

    if (!strcmp(my_ship->weapon->system_state, "offline")) {
        my_putstr_color("red", "[e] weapon is down, you can't attack your enemy\n");
    }

    my_ship->enemy->life -= my_ship->weapon->damage;
    info_enemy(my_ship);

    if (randomize() <= evade_val) {
        my_putstr_color("yellow", "my ship got damages\n");

        my_ship->hull -= my_ship->enemy->damage;

        if (randomize() <= break_stuff_down)
        {
            randomly_break_something(my_ship);
        } else {
            my_putstr_color("yellow", "no critical component down\n");
        }
    }

    if (my_ship->enemy->life <= 0) {
        my_ship->enemy->is_up = 0;
        destroy_enemy(my_ship);
    }
}

void stat(ship_t *my_ship)
{
    my_putstr("hull: ");
    my_putnbr(my_ship->hull);
    my_putchar('\n');
    my_putstr("weapon system: ");
    my_putstr(my_ship->weapon->system_state);
    my_putchar('\n');
    my_putstr("ftl drive system: ");
    my_putstr(my_ship->ftl_drive->system_state);
    my_putchar('\n');
    my_putstr("energy: ");
    my_putnbr(my_ship->ftl_drive->energy);
    my_putchar('\n');
    my_putstr("navigation tools system: ");
    my_putstr(my_ship->navigation_tools->system_state);
    my_putchar('\n');
    my_putstr("sector: ");
    my_putnbr(my_ship->navigation_tools->sector);
    my_putchar('\n');
}

void help(ship_t *my_ship)
{
    (void)my_ship;
    my_putstr_color("cyan", "attack : If an enemy is present in the area, damage is inflicted on it\n");
    my_putstr_color("cyan", "detect : Allows the use of navigation tools to detect space containers\n");
    my_putstr_color("cyan", "jump : Jumps to the next stellar sector and reduces energy by 1\n");
    my_putstr_color("cyan", "getbonus : Allows you to clear the container list and retrieve all bonuses found there\n");
    my_putstr_color("cyan", "repair_system : Provides access to functions to repair various parts of your ship\n");
    my_putstr_color("cyan", "control_system : Allows you to see the status of the different parts of the ship\n");
    my_putstr_color("cyan", "stat : Allows you to see the stat of the ship\n");
}

void detect(ship_t *my_ship)
{
    (void)my_ship;
    my_putstr("you don't deserve it yet\n");
}

void handle_commands(ship_t *my_ship, char *command, int can_jump)
{
    int i = 0;
    int yes = 0;

    while (my_commands[i].my_cmd != NULL) {
        if (!strcmp(my_commands[i].my_cmd, command) && !yes) {
            yes = 1;
            if (!strcmp(command, "jump") && can_jump == 0) {
                my_putstr_color("red", "you can't jump while enemy is in your sector\n");
            } else if (!strcmp(command, "attack") && can_jump == 1) {
                my_putstr_color("yellow", "no enemy here, don't waste your time\n");
            }
            else {
                my_commands[i].pf(my_ship);
            }
        }
        i++;
    }
}
