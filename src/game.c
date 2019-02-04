/*
** ETNA PROJECT, 14/11/2018 by hauteb_m
** My_FTL
** File description:
**      this part of the project contains the main loop
*/

#include <time.h>
#include <stdlib.h>
#include <include/ftl.h>
#include <include/my_string.h>
#include <include/my_readline.h>
#include <include/commands.h>
#include <include/enemy.h>
#include <include/fight.h>

#define CAN_EXIT_LOOP (my_ship->navigation_tools->sector != 10 || my_ship->hull <= 0)

void do_enemy(ship_t *my_ship, int enemy_nb)
{
    create_enemy(my_ship);
    if (enemy_nb != 0)
        update_enemy(my_ship, enemy_nb);
    my_putstr_color("cyan", "[i] an enemy is in your sector, fight him\n");
    info_enemy(my_ship);
    enemy_nb++;
}

int main_loop(ship_t *my_ship)
{
    char *command;
    int is_enemy;
    int can_u_jump;
    int enemy_nb;
    int current_sector = 0;
    int new_sector = 1;

    enemy_nb = 0;
    can_u_jump = 1;

    while (CAN_EXIT_LOOP) {
        new_sector = my_ship->navigation_tools->sector;

        if (my_ship->ftl_drive->energy <= 0) {
            my_putstr_color("red", "no more energy\nyou lost :(\n");
            return 0;
        }

        is_enemy = randomize();

        if (is_enemy <= 30 && can_u_jump == 1 && current_sector != new_sector) {
            can_u_jump = 0;
            do_enemy(my_ship, enemy_nb);
            enemy_nb++;
        }

        if (can_u_jump == 0 && my_ship->enemy->is_up == 0) {
            can_u_jump = 1;
            randomly_lose_energy(my_ship);
        }

        my_putstr_color("purple", "-> ");
        command = my_readline();

        if (command != NULL) {
            handle_commands(my_ship, command, can_u_jump);
        }

        current_sector = new_sector;
        free(command);
    }

    my_putstr_color("green", "YOU WON !\n");
    return 0;
}
