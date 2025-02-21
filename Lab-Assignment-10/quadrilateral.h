/*
* quadrilateral.h
 * Written by Anwar Hossain Zahid
 * Department of Computer Science, Iowa State University
 */

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point vertices[4];  // Four vertices of the quadrilateral
    double area;
} Quadrilateral;

// Function prototypes
void compute_area(Quadrilateral* quad);
double distance(Point a, Point b);
double triangle_area(Point a, Point b, Point c);

#endif
