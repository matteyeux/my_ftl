/*
** ETNA PROJECT, 13/11/2018 by hauteb_m
** My_FTL
** File description:
**      not_my_string lol
*/

/*
** This file contains the basic functions for managing strings.
**
** my_putchar allows you to display a character on the standard output.
**
** my_strlen returns the size of a string.
**
** my_putstr allows you to display a string on the standard output.
**
** my_strcmp allows you to compare two strings if these strings are equal then the function returns 0.
**
** my_strdup allows you to dynamically allocate a string and copy the content of the string passed as parameter and return it.
**
** my_putstr_color allows you to display a string on the standard output in the desired color.
**   The colors available for this function are:
**     "red", "green", "yellow", "blue", "purple" and "cyan"
**   This function also allows you to "clear" everything that is currently displayed on the screen.
*/

#include <stdlib.h>
#include <unistd.h>

typedef struct color_s
{
  char         *color;
  char         *unicode;
}              color_t;

static const char *reset_color = "\033[0m";

static const color_t color_g[] =
{
  {"clear",   "\033[H\033[2J"},
  {"red",     "\033[31m"},
  {"green",   "\033[32m"},
  {"yellow",  "\033[33m"},
  {"blue",    "\033[34m"},
  {"purple",  "\033[35m"},
  {"cyan",    "\033[36m"},
  {NULL, NULL}
};

void my_putchar(const char c)
{
  write(1, &c, 1);
}

int my_strlen(const char *str)
{
  int i = 0;

  while (str[i])
    ++i;
  return (i);
}

void my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
}

int my_strcmp(const char *s1, const char *s2)
{
  int i = 0;

    if (s1 == NULL && s2 == NULL)
      return (0);
    while (s1[i] != '\0' || s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}

char *my_strdup(const char *str)
{
  int i = 0;
  char *copy = NULL;

  copy = malloc((my_strlen(str) + 1) * sizeof(char));
  if (copy == NULL)
    return NULL;
  while (str[i]) {
    copy[i] = str[i];
    i++;
  }
  copy[i] = '\0';
  return copy;
}

void my_putstr_color(const char *color, const char *str)
{
  int i = 0;

  while (color_g[i].color && my_strcmp(color_g[i].color, color))
    ++i;
  if (color_g[i].color) {
    my_putstr(color_g[i].unicode);
    my_putstr(str);
    my_putstr(reset_color);
  } else {
    my_putstr(str);
  }
}
