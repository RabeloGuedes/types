#include <typelib/str.h>
#include <stdio.h>

typedef struct p_string p_string;

void	print(string *s);
string	*copy(string *s);
size_t	stringlen(char *s);
char	*stringdup(char *s);
bool	contains(string *s, char *sub);
void	pstring(char *s);
size_t	stringlcopy(char *dst, char *src, size_t dst_size);
void	memcopy(void *dst, void *src, size_t n);
char	*stringfind(char *s, char *sub);
char	*stringlconcat(char *dst, char *src, size_t dst_size);
size_t	len(string *s);

struct	p_string {
	// Public
	size_t	(*len)(string *);
    void	(*print)(string *);
    string	*(*copy)(string *);
    bool	(*contains)(string *, char *);
    void	(*join)(string *);
	
	// Private
    size_t	length;
    size_t	size;
    char	*string;
};

string *String(char *s)
{
    p_string *ptr = (p_string *)calloc(1, sizeof(p_string));

    if (!ptr)
        return (NULL);
    ptr->length = stringlen(s);
	ptr->len = &len;
    ptr->size = ptr->len;
    ptr->print = &print;
    ptr->copy = &copy;
	ptr->string = stringdup(s);
	ptr->contains = &contains;
	if (!ptr->string)
	{
		free(ptr);
		return (NULL);
	}
    return (string *)ptr;
}

size_t	len(string * s)
{
	if (!s)
		return (0);
	return (stringlen(((p_string *)(s))->length));
}

void print(string *s)
{
	p_string	*ptr = (p_string *)s;

	if (ptr)
		pstring(ptr->string);
	else
		pstring("NULL");
}

void pstring(char *s)
{
    while (s && *s)
        write(1, s++, 1);
	write(1, "\n", 1);
}

size_t stringlen(char *s)
{
    size_t len = 0;
    while (s && s[len])
        len++;
    return len;
}

size_t stringlcopy(char *dst, char *src, size_t dst_size)
{
    size_t src_len = stringlen(src);
    size_t dst_len = 0;

    if (!dst || !src || !dst_size)
        return 0;
    while (dst_len < dst_size - 1 && src[dst_len])
    {
        dst[dst_len] = src[dst_len];
        dst_len++;
    }
    dst[dst_len] = '\0';
    return src_len + dst_size;
}

void memcopy(void *dst, void *src, size_t n)
{
    if (!dst || !src || !n)
        return ;
    if (dst < src)
    {
        while (dst < src && n--)
            *(unsigned char *)dst++ = *(unsigned char *)src++;
    }
    else
        stringlcopy(dst, src, n);
}

string *copy(string *s)
{
	p_string *ptr = (p_string *)s;

	if (!ptr || !ptr->string)
		return (NULL);
	string *new = String(ptr->string);
	if (!new)
		return NULL;
	return (new);
}

char *stringdup(char *s)
{
    char *string;
    size_t s_len = stringlen(s);

    if (!s_len)
        return NULL;
    string = (char *)calloc(1, sizeof(char) * (s_len + 1));
    if (!string)
        return NULL;
    stringlcopy(string, s, s_len + 1);
    return string;
}

char *stringfind(char *s, char *sub)
{
    int j;

    while (s && sub)
    {
        j = 0;
        while (s[j] && sub[j] && s[j] == sub[j])
        {
            j++;
            if (!sub[j])
                return s;
        }
        s++;
    }
    return NULL;
}

bool contains(string *s, char *sub)
{
	p_string *ptr = (p_string *)s;

	if (!ptr || !ptr->string)
		return false;
	return (stringfind(ptr->string, sub));
}

char *stringlconcat(char *dst, char *src, size_t dst_size)
{
    size_t dst_len = stringlen(dst);
    size_t src_len = stringlen(src);
    char *s;

    dst_size = dst_len + src_len >= dst_size ? (dst_len + src_len + 1) : dst_size;
    s = (char *)calloc(1, sizeof(char) * dst_size);
    if (!s)
        return NULL;
    stringlcopy(s, dst, dst_size);
    while (dst && src && *src && dst_len - 1 < dst_size)
        s[dst_len++] = *src++;
    s[dst_len] = '\0';
    return s;
}

