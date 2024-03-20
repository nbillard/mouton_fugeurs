#include "link.h"
#include<stdio.h>

void link(char* longitude, char* lattitude, char* dest) {
    sprintf(dest, "https://www.openstreetmap.org/?mlat=%s&mlon=%s#map=15/%s/%s", lattitude, longitude,lattitude, longitude);
}
