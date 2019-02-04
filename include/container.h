/*
** ETNA PROJECT, 14/11/2018 by hauteb_m
** My_FTL
** File description:
**      ccontainer header
*/

int add_container_to_ship(ship_t *my_ship);
void add_freight_to_container(ship_t *my_ship, freight_t *my_freight);
void del_freight_from_container(ship_t *my_ship, freight_t *my_freight);
void get_bonus(ship_t *my_ship);