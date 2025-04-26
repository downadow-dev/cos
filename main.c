#include <stdio.h>
#include <time.h>
#include "sin_cos.h"

#define H 24
#define W 62

int main(void) {
    char screen[H][W];
    float a = 0.1f;
    long time;
    
    for(int y = 0; y < H; y++)
        for(int x = 0; x < W; x++)
            screen[y][x] = ' ';
    
    time = clock();
    while(a < 23.0f) {
        int x = a * cosf(a) + W / 2;
        int y = a / 2 * sinf(a) + H / 2;
        
        if(x >= 0 && x < W && y >= 0 && y < H)
            screen[y][x] = '#';
        
        a += 0.05f;
    }
    time = clock() - time;
    
    for(int y = 0; y < H; y++) {
        for(int x = 0; x < W; x++)
            putchar(screen[y][x]);
        putchar('\n');
    }
    printf("%ld\n", time);
}

