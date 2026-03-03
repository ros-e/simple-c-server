#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
int main(int argc, char* argv[]) {
    char buffer[1024] = { 0 };
    if (argc < 2) {
        printf("no port dumbass");
        exit(1);
    }
    // add some validation bullshit here sometime
    printf("HTTP Server Started on %s\n", argv[1]);
    int server_fd, new_socket;
    struct sockaddr_in address;
    if((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }
    int opt = 1;
    // some bullshit to allow the port to be reused
    if(setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        exit(1);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(atoi(argv[1]));
    if(bind(server_fd, (struct sockaddr *)&address, sizeof(address))) {
        perror("bind failed");
        exit(1);
    }
    if(listen(server_fd, 3)) {
        perror("listen failed");
        exit(1);
    }
    if((new_socket = accept(server_fd, (struct sockaddr*)NULL, NULL)) < 0) {
        perror("accept failed");
        exit(1);
    }
    size_t bytes_read = read(new_socket, buffer, 1024);
    printf("Received: %s\n", buffer);
    // this will either handle a json or HTML response.

    // close socket
    close(new_socket);
    close(server_fd);
    return 0;
}
