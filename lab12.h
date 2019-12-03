#ifndef lab12_h
#define lab12_h
typedef struct Digits
{
    int first;
    int second;
} t_digits;

typedef struct Number
{
    int number;
    t_digits *dig_arr;
} t_number;
#endif