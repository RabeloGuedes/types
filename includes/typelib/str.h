#ifndef TYPELIBSTR_H
# define TYPELIBSTR_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct string string;

struct string {
    size_t	(*len)(string *);
    void	(*print)(string *);
    string	*(*copy)(string *);
    bool	(*contains)(string *, char *);
    void	(*join)(string *);
};

string	*String(char *s);
void	print(string *s);
string	*copy(string *s);
size_t	stringlen(char *s);
char	*stringdup(char *s);
bool	contains(string *s, char *sub);
#endif