/*
 * PrintDistance.cpp
 *
 *  Created on: May 22, 2015
 *      Author: user
 */
#include "Point.h"
#include <iostream>
#include<cmath>
using namespace std;
double euclidean_distance(const Point*p1, const Point *p2){
	double x_diff=p1->x-p2->x;
	double y_diff=p2->x-p2->y;
	return(x_diff*x_diff+y_diff*y_diff);
}

void print_point(const Point*p){
	cout<<p->x<<","<<p->y;
}

void print_distance(const Point*p1,const Point*p2){
cout<<"Distance betweeen ";print_point(p1);
cout<<" and ";print_point(p2);
cout<<" is "<<euclidean_distance(p1,p2)<<endl;
}



