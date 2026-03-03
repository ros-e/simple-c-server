#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("no port dumbass");
        exit(1);
    }
    printf("HTTP Server Started on %s\n", argv[1]);
    int server_fd, new_socket;
    struct sockaddr_in address;
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

}
