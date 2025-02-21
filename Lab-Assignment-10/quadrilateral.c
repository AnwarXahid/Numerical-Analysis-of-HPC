/*
* quadrilateral.c
 * Written by Anwar Hossain Zahid
 * Department of Computer Science, Iowa State University
 */

#include <stdio.h>
#include <math.h>
#include "quadrilateral.h"

/**
 * Compute the area of a triangle using the Shoelace formula
 */
double triangle_area(Point a, Point b, Point c) {
    return fabs((a.x * (b.y - c.y) +
                 b.x * (c.y - a.y) +
                 c.x * (a.y - b.y)) / 2.0);
}

/**
 * Compute the area of the quadrilateral by splitting it into two triangles
 */
void compute_area(Quadrilateral* quad) {
    // Triangulation: split the quadrilateral into two triangles
    double area1 = triangle_area(quad->vertices[0], quad->vertices[1], quad->vertices[2]);
    double area2 = triangle_area(quad->vertices[0], quad->vertices[2], quad->vertices[3]);

    quad->area = area1 + area2;
}

/**
 * Calculate the Euclidean distance between two points
 */
double distance(Point a, Point b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
