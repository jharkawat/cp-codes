
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>  
#include <utility>    
#define RT -1  // CW
#define LT 1  // CCW
#define COLLI 0  // Collinear
using namespace std;
/* Class to handle the 2D points! */
class point
{
public:
  int x;
  int y;
  point (int newx=0,int newy=0){
    x=newx;
    y=newy;
  }
  /*
    Overloaded == operator to check for equality between 2 objects of class point
  */
  friend bool operator== (const point& p1,const point& p2){
    return (p1.x==p2.x && p1.y==p2.y);
  }
  /*
    Overloaded != operator to check for non-equality between 2 objects of class point
  */
  friend bool operator!= (const point& p1,const point& p2){
    return (!(p1.x==p2.x && p1.y==p2.y));
  }
  /*
    Overloaded ostream << operator to check for print object of class point to STDOUT
  */
  friend ostream& operator<<(ostream& output,const point& p){
    output<<"("<<p.x<<","<<p.y<<")";
    return output;
  }
}p0; // Global point class object 

int dist(point p1, point p2)
{
  return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
/*
  Returns orientation of the line joining points p and q and line joining points q and r
  Returns -1 : CW orientation
      +1 : CCW orientation
      0 : Colli
*/
int orientation(point p, point q, point r)
{
  int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  if (val == 0) return 0;  // Colli
  return (val > 0)? -1: 1; // CW: -1 or CCW: 1
}
/*
  Predicate function used while sorting the points using qsort() inbuilt function in C++
*/
int compare(const void *vp1, const void *vp2)
{
  point *p1 = (point *)vp1;
  point *p2 = (point *)vp2;
  int orient = orientation(p0, *p1, *p2);
  if (orient == 0)
    return (dist(p0, *p2) >= dist(p0, *p1))? -1 : 1;
  return (orient == 1)? -1: 1;
}

int tangent(vector<point> v,point p){
  int l=0;
  int r= v.size();
  int l_before = orientation(p, v[0], v[v.size()-1]);
  int l_after = orientation(p, v[0], v[(l + 1) % v.size()]);
  while (l < r){
    int c = ((l + r)>>1);
    int c_before = orientation(p, v[c], v[(c - 1) % v.size()]);
    int c_after = orientation(p, v[c], v[(c + 1) % v.size()]);
    int c_side = orientation(p, v[l], v[c]);
    if (c_before != RT and c_after != RT)
      return c;
    else if ((c_side == LT) and (l_after == RT or l_before == l_after) or (c_side == RT and c_before == RT))
      r = c;
    else
      l = c + 1 ;
    l_before = -c_after; 
    l_after = orientation(p, v[l], v[(l + 1) % v.size()]);
  }
  return l;
}

pair<int,int> extreme_hullpt_pair(vector<vector<point> >& hulls){
  int h= 0,p= 0;
  for (int i=0; i<hulls.size(); ++i){
    int min_index=0, min_y = hulls[i][0].y;
    for(int j=1; j< hulls[i].size(); ++j){
      if(hulls[i][j].y < min_y){
        min_y=hulls[i][j].y;
        min_index=j;
      }
    }
    if(hulls[i][min_index].y < hulls[h][p].y){
      h=i;
      p=min_index;
    }   
  }
  return make_pair(h,p);
}

pair<int,int> next_hullpt_pair(vector<vector<point> >& hulls, pair<int,int> lpoint){
  point p = hulls[lpoint.first][lpoint.second];
  pair<int,int> next = make_pair(lpoint.first, (lpoint.second + 1) % hulls[lpoint.first].size());
  for (int h=0; h< hulls.size(); h++){
    if(h != lpoint.first){
      int s= tangent(hulls[h],p);
      point q= hulls[next.first][next.second];
      point r= hulls[h][s];
      int t= orientation(p,q,r);
      if( t== RT || (t==COLLI) && dist(p,r)>dist(p,q))
        next = make_pair(h,s);
    }
  }
  return next;
}    

vector<point> keep_left (vector<point>& v,point p){
  while(v.size()>1 && orientation(v[v.size()-2],v[v.size()-1],p) != LT)
    v.pop_back();
  if(!v.size() || v[v.size()-1] != p)
    v.push_back(p);
  return v;
}

vector<point> GrahamScan(vector<point>& points){
  if(points.size()<=1)
    return points;
  qsort(&points[0], points.size(), sizeof(point), compare);
  vector<point> lower_hull;
  for(int i=0; i<points.size(); ++i)
    lower_hull = keep_left(lower_hull,points[i]);
  reverse(points.begin(),points.end());
  vector<point> upper_hull;
  for(int i=0; i<points.size(); ++i)
    upper_hull = keep_left(upper_hull,points[i]);
  for(int i=1;i<upper_hull.size();++i)
    lower_hull.push_back(upper_hull[i]);
  return lower_hull;   
}
/*
  Implementation of Chan's Algorithm to compute Convex Hull in Order(nlogh) complexity 
*/
vector<point> chansalgorithm(vector<point> v){
  for(int t=0; t< v.size(); ++t){
    for(int m=1; m< (1<<(1<<t)); ++m){
      vector<vector<point> > hulls;
      for(int i=0;i<v.size();i=i+m){
        vector<point> chunk;
        if(v.begin()+i+m <= v.end())
          chunk.assign(v.begin()+i,v.begin()+i+m);
        else
          chunk.assign(v.begin()+i,v.end());          
        hulls.push_back(GrahamScan(chunk));
      }
      cout<<"\nM (Chunk Size): "<<m<<"\n";
      for(int i=0;i<hulls.size();++i){
        cout<<"Convex Hull for Hull #"<<i<<" (Obtained using Graham Scan!!)\n";
        for(int j=0; j<hulls[i].size();++j)
          cout<<hulls[i][j]<<" ";
        cout<<"\n";
      }
      vector<pair<int,int> > hull;
      hull.push_back(extreme_hullpt_pair(hulls));
      for(int i=0; i<m; ++i){
        pair<int,int> p= next_hullpt_pair(hulls,hull[hull.size()-1]);
        vector<point> output;
        if(p==hull[0]){
          for(int j=0; j<hull.size();++j){
            output.push_back(hulls[hull[j].first][hull[j].second]);
          }
          return output;
        }
        hull.push_back(p);
      }
    }
  }
}
int main()
{
  int T=0,x=0,y=0;
  cin>>T;
  if(T<=0)
    return -1;
  point points[T];
  for(int i=0;i<T;++i){
    cin>>x>>y;
    points[i].x=x;
    points[i].y=y;
  }
  vector<point> v(points,points+T);
  vector<point> output = chansalgorithm(v);
  cout<<"\n==>>Using Chan's Algorithm::\n";
  cout<<"\n----CONVX HULL:::: \n";
  for(int i=0; i< output.size(); ++i)
    cout<<output[i]<<" ";
  cout<<"\n";
  return 0;
}
