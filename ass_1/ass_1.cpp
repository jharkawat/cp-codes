#include <iostream>
#include "ch_chan.h"
#include "SDL.h"

#if USE_SDL
static SDL* sdl;
#endif

Point_2* ch_chan::FindHull(Point_2* start, Point_2* end, Point_2* result){
#if USE_SDL
    sdl = new SDL(1280, 720, Point_2(-100,-100), Point_2(100,100));
#endif

    int size = end-start;
    int t = 0;
    int m = pow(2,pow(2 , t++));
    int k;
    int hIndex;
    int pIndex;
    vector< Point_2 > out;
    vector<vector< Point_2 > > hulls;
    while(m <= size){
        hulls = GetSubHulls(start, end, m);
#if USE_SDL
        if(sdl) {
            sdl->clear_buffer();
            sdl->draw_points_to_buffer(end - start, start);
            for (int i = 0; i < hulls.size(); i++) {
                sdl->draw_hull_to_buffer(hulls[i]);
            }
            sdl->display_buffer();
        }
        sdl->wait_for_msecs(1000);
#endif
        FindLeftmostHull(hulls, hIndex, pIndex);
        Point_2 firstPoint =hulls[hIndex][pIndex];
        Point_2 nextPoint;
        k = 0;
        result[k++] = firstPoint;
        for(int i =1;i<m;i++){
            NextPair(hulls,hIndex,pIndex);
            nextPoint = hulls[hIndex][pIndex];
#if USE_SDL
            if(sdl) {
                sdl->draw_line_between(result[k-1], nextPoint, 0, 255, 0);
                sdl->display_buffer();
                sdl->wait_for_msecs(500);
            }
#endif
            if(nextPoint==firstPoint) break;
            result[k++] = nextPoint;
        }
        if(nextPoint==firstPoint || m == size) break;
        m = min((int)pow(2,pow(2 , t++)),size);
#if USE_SDL
        if(sdl) sdl->wait_for_msecs(1000);
#endif
    }

    return result+k;
}

vector<vector< Point_2 >> ch_chan::GetSubHulls(Point_2 *start,Point_2 *end, int m) {
    Point_2 *s,*e,*r;
    int size = end-start;
    int nHulls = ceil((double)size / m);
    r = new Point_2[size];
    vector<vector< Point_2 >> hulls;
    for(int j = 0; j < nHulls; j++){
        s = start+j*m;
        e = start + min((j+1)*m, size);
        Point_2* ptr = CGAL::ch_graham_andrew(s, e, r+j*m);
        vector< Point_2 >  V (r+j*m,ptr);
        V.push_back(V[0]);
        hulls.push_back(V);
    }
    delete[](r);

    return hulls;
}

//Returns first point of the convexHull with the leftmost point
    // TODO(erick): Use DOUBLE_MAX
void ch_chan::FindLeftmostHull(const vector<vector<Point_2> > &hulls, int &hIndex, int &pIndex) {
    double minX = 9999;
    for(int i =0;i<hulls.size();i++){
        vector<Point_2> hullI = hulls[i];
        for(int j = 0;j<hullI.size();j++){
            if(hullI[j].x()<minX){
                hIndex = i;
                pIndex = j;
                minX = hullI[j].x();
            }
        }
    }
}

// Rtangent_PointPolyC(): binary search for convex polygon right tangent
//    Input:  P = a 2D point (exterior to the polygon)
//            n = number of polygon vertices
//            V = array of vertices for a 2D convex polygon with V[n] = V[0]
//    Return: index "i" of rightmost tangent point V[i]
int ch_chan::Rtangent_PointPolyC(const Point_2 &P,const vector<Point_2> &V )
{
    // use binary search for large convex polygons
    int     a, b, c;            // indices for edge chain endpoints
    int     upA, dnC;           // test for up direction of edges a and c
    int n = V.size()-1;

    // rightmost tangent = maximum for the isLeft() ordering
    // test if V[0] is a local maximum
    if (below(P, V[1], V[0]) && !above(P, V[n-1], V[0]) || n==1)
        return 0;               // V[0] is the maximum tangent point

    for (a=0, b=n;;) {          // start chain = [0,n] with V[n]=V[0]
        c = (a + b) / 2;        // midpoint of [a,b], and 0<c<n
        dnC = below(P, V[c+1], V[c]);
        if (dnC && !above(P, V[c-1], V[c]))
            return c;          // V[c] is the maximum tangent point

        // no max yet, so continue with the binary search
        // pick one of the two subchains [a,c] or [c,b]
        upA = above(P, V[a+1], V[a]);
        if (upA) {                       // edge a points up
            if (dnC)                         // edge c points down
                b = c;                           // select [a,c]
            else {                           // edge c points up
                if (above(P, V[a], V[c]))     // V[a] above V[c]
                    b = c;                       // select [a,c]
                else                          // V[a] below V[c]
                    a = c;                       // select [c,b]
            }
        }
        else {                           // edge a points down
            if (!dnC)                        // edge c points up
                a = c;                           // select [c,b]
            else {                           // edge c points down
                if (below(P, V[a], V[c]))     // V[a] below V[c]
                    b = c;                       // select [a,c]
                else                          // V[a] above V[c]
                    a = c;                       // select [c,b]
            }
        }
    }
}

void ch_chan::NextPair(const vector<vector<Point_2>> &hulls, int &hIndex, int &pIndex){
    int myHullIndex = hIndex;
    Point_2 p = hulls[hIndex][pIndex];
    hIndex = hIndex;
    pIndex = (pIndex + 1) % (hulls[hIndex].size()-1);
    Point_2 bestGuess = hulls[hIndex][pIndex];
    for(int i = 0; i<hulls.size();i++){
        if(i==myHullIndex) continue;
        int index = Rtangent_PointPolyC(p,hulls[i]);
        Point_2 guess = hulls[i][index];
        //TODO tratar pontos colineares
        if(Utils::isLeft(p,bestGuess,guess)<0){
            hIndex = i;
            pIndex = index;
            bestGuess = hulls[hIndex][pIndex];
        }
    }
}