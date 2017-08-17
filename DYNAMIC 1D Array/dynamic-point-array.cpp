/*
 * dynamic-point-array.cpp
 *
 *  Created on: Apr 11, 2015
 *      Author: user
 */
#include <iostream> /* File: dynamic-point-array.cpp */
#include "point.h"
using namespace std;

int main(void)
{
    void print_distance(const Point*, const Point*);
    int num_points;
    cout << "Enter the number of points : "; cin >> num_points;

    Point* point = new Point [num_points]; // Allocate a dynamic array of points
    cout<<point[0].x<<endl;
    for (int j = 0; j < num_points; ++j) // Input the points
    {
        cout << "Enter the x & y coordinates of point #" << j << " : ";
        cin >> point[j].x >> point[j].y;
    }

    for (int i = 0; i < num_points; ++i) // Compute distance between 2 points
        for (int j = 0; j < num_points; ++j)
            if (i < j)
                print_distance(point+i, point+j);

    delete [ ] point; // Deallocate the dynamic array of points
    return 0;
} /* g++ dynamic-point-array.cpp point-distance.cpp */




