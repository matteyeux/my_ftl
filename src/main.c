/*
** ETNA PROJECT, 12/11/2018 by hauteb_m
** My_FTL
** File description:
**      main function and usage
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <include/ftl.h>
#include <include/game.h>
#include <include/air_shed.h>
#include <include/container.h>
#include <include/my_string.h>
#include <include/my_readline.h>

int main(void) {

    ship_t *my_ship = NULL;
    srandom(time(0));
    my_ship = create_ship();

    my_putstr_color("clear", "");

    if (add_weapon_to_ship(my_ship) == 0) {
        return -1;
    }

    if (add_ftl_drive_to_ship(my_ship) == 0) {
        return -2;
    }

    if (add_navigation_tools_to_ship(my_ship) == 0) {
        return -3;
    }

    if (add_container_to_ship(my_ship) == 0) {
        return -4;
    }

    main_loop(my_ship);
    free(my_ship);
    return 0;
}
