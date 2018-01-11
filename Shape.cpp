#include "Shape.hpp"
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void Shape::scale(double ratio){
    for(int i=0; i<points.size(); i++){
		points[i].x *= ratio;
		points[i].y *= ratio;
	}
	return;
}

void Shape::move(double x_offset, double y_offset){
    for(int i=0; i<points.size(); i++){
		points[i].x += x_offset;
		points[i].y += y_offset;
	}
	return;
}

void Shape::flipHorizontally(){ //NIE DZIAŁA
    double maxX =.0, minX =.0;
    for(int i=0; i<points.size(); i++){
		if( points[i].x > maxX ) maxX = points[i].x;
		if( points[i].x < minX ) minX = points[i].x;
	}
	double offset = maxX - minX;
	
	for(int i=0; i<points.size(); i++){
		points[i].x *= -1;
		points[i].x += offset;
	}
	return;		
}

void Shape::flipVertically(){ //NIE DZIAŁA
    double maxY =.0, minY =.0;
    for(int i=0; i<points.size(); i++){
		if( points[i].y > maxY ) maxY = points[i].y;
		if( points[i].y < minY ) minY = points[i].y;
	}
	double offset = (maxY + minY)/2.0;
	
	for(int i=0; i<points.size(); i++){
		points[i].y *= -1;
		points[i].y += 2*offset;
	}
	return;	
}
