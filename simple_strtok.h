#ifndef SIMPLE_STRTOK
#define SIMPLE_STRTOK
#include <stddef.h>

size_t simple_strlen(const char *s) {
    size_t n =0;
    while (s[n])
        ++n;

    return n;
}

int simple_strcmp(const char *lhs, const char *rhs) {
    while (*lhs == *rhs) {
        if (*lhs == '\0' || *rhs == '\0')
            break;
        lhs++;
        rhs++;
    }

    return (*lhs > *rhs) - (*lhs < *rhs);
}
/* utils function */
unsigned int is_delimiter(char c,const char *delimiters) {
    for(;*delimiters != '\0';delimiters++)
        if(c == *delimiters)
            return 1;

    return 0;
}

/* strtok realization */
char* simple_strtok(char * str,const char * delimiters) {
    static char* backup = NULL;

    // if strin is NULL we continue from last token
    if(str == NULL)
        str = backup;

    if(str == NULL)
        return NULL; // handle errors

    if(*str == '\0') {
        backup = NULL;
        return NULL;
    }

    char* start = str;
    while (*str != '\0' && !is_delimiter(*str, delimiters))
        str++;

    if(*str != '\0') {
        *str = '\0';
        str++;
    }
    
    backup = str;

    return start;
}

#endif
