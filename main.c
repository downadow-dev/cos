#include <stdio.h>
#include "sin_cos.h"

#define H 16
#define W 32

int main(void) {
    char screen[H][W];
    int c;
    float a = 6.2831853f;
    for(;;) {
        /* filling */
        for(int y = 0; y < H; y++)
            for(int x = 0; x < W; x++)
                screen[y][x] = ' ';
        
        screen[H / 2][W / 2] = 'X';
        
        int x = 12 * cosf(a) + W / 2;
        int y = 6 * sinf(a) + H / 2;
        
        if(x >= 0 && x <= W && y >= 0 && y <= H)
            screen[y][x] = 'o';
        
        /* output */
#ifdef __XCC_C__
        clear_output();
#else
        printf("\033[H\033[2J\033[3J");
#endif
        for(int y = 0; y < H; y++) {
            for(int x = 0; x < W; x++)
                putchar(screen[y][x]);
            putchar('\n');
        }
        printf("%f\n", a);
        
        if((c = getchar()) == EOF) break;
        
        /* input handling */
        if(c == 'a') a += 0.16f; else if(c == 'd') a -= 0.16f;
        if(a >= 6.2831853) a -= 6.2831853f;
        if(a <= 0.0f) a = 6.2831853f;
    }
}

