/*
* main.c
 * Written by Anwar Hossain Zahid
 * Department of Computer Science, Iowa State University
 */

#include <stdio.h>
#include "quadrilateral.h"

int main() {
    Quadrilateral quad;

    printf("Enter the coordinates of the quadrilateral (x y for each point):\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: ", i + 1);
        scanf("%lf %lf", &quad.vertices[i].x, &quad.vertices[i].y);
    }

    // Compute area
    compute_area(&quad);

    printf("\nQuadrilateral Vertices:\n");
    for (int i = 0; i < 4; i++) {
        printf("Point %d: (%.2lf, %.2lf)\n", i + 1, quad.vertices[i].x, quad.vertices[i].y);
    }

    printf("\nArea of the Quadrilateral: %.2lf\n", quad.area);

    return 0;
}
