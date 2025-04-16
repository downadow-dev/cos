#ifndef __cos_h
#define __cos_h   1

/* from <https://github.com/AZHenley/cosine> (modified by me) */
float cosf(float x) {
    x -= (int)(x / 6.2831853f) * 6.2831853f;
    char sign = 1;
    if(x > 3.1415926f) {
        x -= 3.1415926f;
        sign = -1;
    }
    float xx = x * x;

    return sign * (1 - ((xx) / (2)) + ((xx * xx) / (24)) - ((xx * xx * xx) / (720)) + ((xx * xx * xx * xx) / (40320)) - ((xx * xx * xx * xx * xx) / (3628800)));
}

float sinf(float x) {
    return x != 0.0f ? cosf(x - 1.5707963f) : 0.0f;
}

#endif

