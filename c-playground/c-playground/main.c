//
//  main.c
//  c-playground
//
//  Created by Gantrol Hwang on 2022/4/27.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int x = 1, y = 2;
    int *ip;
    ip = &x;
    y = *ip;
    return 0;
}
