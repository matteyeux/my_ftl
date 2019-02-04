/*
** ETNA PROJECT, 14/11/2018 by hauteb_m
** project_name
** File description:
**      project_description
*/

#include <include/ftl.h>

/*typedef struct enemy_s enemy_t;
typedef struct enemy_fight_s enemy_fight_t;
*/
int is_there_an_enemy(void);
int create_enemy(ship_t *my_ship);
void update_enemy(ship_t *my_ship, int enemy_nb);
void info_enemy(ship_t *my_ship);
void destroy_enemy(ship_t *my_ship);