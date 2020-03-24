#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
//#include <graphics.h>
#include <math.h>

using namespace std;

#define PI 3.14159265

int nodes;

double xmin=10000000, ymin=10000000, totes=0;

struct ppoint
{
    double x, y, angle;
    void anglemake()
    {
        angle=atan2(y-ymin, x-xmin)*180/PI;
        if(angle<0)
        {
            angle=360+angle;
        }
    }
} np;
vector<ppoint> ch, clist;

bool hp(ppoint i, ppoint j)
{
    return i.angle<j.angle;
}

double cp(ppoint a, ppoint b, ppoint c)
{
    return ((b.x-a.x)(c.y-a.y))-((b.y-a.y)(c.x-a.x));
}
double dist(ppoint i, ppoint j)
{double vd, hd;
    vd=(i.y-j.y)*(i.y-j.y);
    hd=(i.x-j.x)*(i.x-j.x);
    return sqrt(vd+hd);
}
int main()
{
    scanf("%d", &nodes);
    for(int i=0; i<nodes; i++)
    {
        scanf("%lf%lf", &np.x, &np.y);
        if(np.y<ymin || (np.y==ymin && np.x<xmin))
        {
           ymin=np.y;
            xmin=np.x;
        }
        ch.push_back(np);
    }
  for(int i=0; i<nodes; i++)
    {
        ch[i].anglemake();
    }
    sort(ch.begin(), ch.end(), hp);
    clist.push_back(ch[0]);
    clist.push_back(ch[1]);
    ch.push_back(ch[0]);
  for(int i=2; i<=nodes; i++)
    {
        while(cp(clist[clist.size()-2], clist[clist.size()-1], ch[i])<0)
        {
            clist.pop_back();
        }
        clist.push_back(ch[i]);
    }
  for(int i=0; i<nodes; i++)
    {
        totes+=dist(clist[i], clist[i+1]);
    }
 printf("%.2lf\n", totes);
    return 0;
}
