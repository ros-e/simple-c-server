#include <stdio.h>
#include <stdlib.h>

#define PORT 3000

int main(int argc, char* argv[]) {
    if (argc < 2) {
        // change this to an error message
        exit(1);
    }
    printf("HTTP Server Started on %s\n", argv[1]);
}
