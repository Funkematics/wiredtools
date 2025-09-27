#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
  int sock;
  struct sockaddr_in target;

  //Create socket
  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0){
    perror("Socket creation failed");
    return 1;
  }

  // target setup, google DNS on port 53
  target.sin_family = AF_INET;
  target.sin_port = htons(53);
  inet_pton(AF_INET, "8.8.8.8", &target.sin_addr);

  // Try to connect
  if (connect(sock, (struct sockaddr*)&target, sizeof(target)) == 0) {
    printf("Connection to 8.8.8.8:53 successful!\n");
  } else {
    printf("Connection failed\n");
  }

  close(sock);
  return 0;
}
