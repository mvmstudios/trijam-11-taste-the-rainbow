#ifndef MVMATH_H_
#define MVMATH_H_

typedef struct Vec2i {
    int x;
    int y;
} vec2i_t;

int max_i(int x, int y) {
    return x > y ? x : y;
}

int min_i(int x, int y) {
    return x < y ? x : y;
}

#endif