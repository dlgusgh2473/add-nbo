#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]){
    FILE *fd1, *fd2;
    uint32_t buf1;
    uint32_t buf2;

    fd1 = fopen(argv[1], "r");
    fd2 = fopen(argv[2], "r");

    fread(&buf1, sizeof(uint32_t), 1, fd1);
    fread(&buf2, sizeof(uint32_t), 1, fd2);

    int htonl_sum = htonl(buf1) + htonl(buf2);

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", htonl(buf1), htonl(buf1), htonl(buf2), htonl(buf2), htonl_sum, htonl_sum);

    fclose(fd1);
    fclose(fd2);
}
