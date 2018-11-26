// Homework: Write two versions of mkRectangle, one that accepts
// two points, and one that accepts 4 real numbers.
//
// Homework: How big is each version of sizeof(struct gameValType)?
// How big is sizeof employee?

Rectangle mkRectanglePt() {

}

Rectangle mkRectangleN(double left, double right, double top, double bottom) {

}


#include <math.h>
struct point {
double x;
double y;
};
struct rectangle {
struct point ll;
struct point ur;
} rect1;
double f(struct point pt);
struct point mkPoint(double x, double y);
struct point midPoint(struct point pt1,
struct point pt2);
int main(int argv, *char argv[]) {
struct point pt1={40.,20.}, pt2;
pt2 = pt1;
rect1.ll = pt2;
pt1.x += 1.0;
pt1.y += 1.0;
rect1.ur = pt1;
rect1.ur.x += 2.;
return 0;
}

double dist (struct point pt) {
return sqrt(pt.x*pt.x+pt.y*pt.y);
}
struct point mkPoint(double x, double y) {
// return {x, y};   not C
struct point pt;
pt.x = x;
pt.y = y;
return pt;
}
struct point midpoint(struct point pt1,
struct point pt2){
// return (pt1 + pt2) / 2;  not C
struct point pt;
pt.x = (pt1.x+pt2.x) / 2;
pt.y = (pt1.y+pt2.y) / 2;
return pt;
}
void mvToOrigin(struct rectangle *r){
(*r).ur.x = (*r).ur.x - (*r).ll.x;
r->ur.y = r->ur.y - r->ll.y;
r->ll.y = 0;
r->ll.x = 0;
}
On the right we see some simple structure declarations for use in a geometry application. They should be familiar from your experience with Java classes in CS101 and CS102.
