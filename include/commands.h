/*
** ETNA PROJECT, 14/11/2018 by hauteb_m
** project_name
** File description:
**      project_description
*/

#include <include/ftl.h>
typedef struct my_commands_s my_commands_t;
typedef struct my_stuff_s my_stuff_t;

struct my_commands_s {
    char *my_cmd;
    void (*pf)(ship_t *);
};

struct my_stuff_s {
    int id;
    char *name;
    void (*pf)(ship_t *);
};

void jump_my_ship(ship_t *my_ship);
void attack(ship_t *my_ship);
void stat(ship_t *my_ship);
void detect(ship_t *my_ship);
void help(ship_t *my_ship);
void handle_commands(ship_t *my_ship, char *command, int can_jump);