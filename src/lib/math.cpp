#include "math.h"


struct Point {
    float x;
    float y;
};

struct Edge {
    struct Point start;
    struct Point end;
};

int polygone(struct Edge* edges, int edgeCount, struct Point p) {
    int count = 0;
    for (int i = 0; i < edgeCount; i++) {
        struct Edge e = edges[i];
        if ((p.y < e.start.y) != (p.y < e.end.y)) {
            if (p.x < e.start.x + (p.y - e.start.y)/(e.end.y - e.start.y)*(e.end.x - e.start.x)) {
                count++;
            }
        }
    }

    return count % 2;
}
