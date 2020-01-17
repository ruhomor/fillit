#include "fillit.h"

int main(int argc, char **argv) {
    if (argc < 0) {
        return (0);
    }
    printf("%d\n", ft_fromBiStringToInteger(argv[1]));
}