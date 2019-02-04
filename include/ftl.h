/*
** ETNA PROJECT, 12/11/2018 by hauteb_m
** My_FTL
** File description:
**      main header
*/

#ifndef FTL_H_
#define FTL_H_
#define strcmp my_strcmp

typedef struct ship_s ship_t;
typedef struct weapon_s weapon_t;
typedef struct ftl_drive_s ftl_drive_t;
typedef struct navigation_tools_s navigation_tools_t;
typedef struct freight_s freight_t;
typedef struct container_s container_t;
typedef struct repair_command_s repair_command_t;
typedef struct enemy_s enemy_t;

struct ship_s {
    int hull;
    weapon_t *weapon;
    ftl_drive_t *ftl_drive;
    navigation_tools_t *navigation_tools;
    container_t *container;
    enemy_t *enemy;
};

struct weapon_s {
    char *system_state;
    int damage;
};

struct ftl_drive_s {
    int energy;
    char *system_state;
};

struct navigation_tools_s {
    char *system_state;
    int sector;
    int evade;
};

struct freight_s {
    char *item;
    freight_t *next;
    freight_t *prev;
};

struct container_s {
    freight_t *first;
    freight_t *last;
    int nb_elem;
};

struct repair_command_s {
    char *ptr;
    void (*pf)(ship_t *);
};

struct enemy_s {
    int damage;
    int life;
    int is_up;
};

#endif // !FTL_H_
