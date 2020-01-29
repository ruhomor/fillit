#include "fillit.h"

int main(int argc, char **argv) {
    if (argc < 0) {
        return (0);
    }
    int fd;
    fd = open(argv[1], O_RDONLY);
    fillit(fd);
}