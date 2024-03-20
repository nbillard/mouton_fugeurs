#include<stdio.h>
#include "lib/link.h"
#include "lib/math.h"

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage:\n");
        printf("   ./lien <lattitude> <longitude>\n");
    } else {
        char dest[100] = "";
        link(argv[1], argv[2], dest);
        printf("%s\n", dest);
    }
}
