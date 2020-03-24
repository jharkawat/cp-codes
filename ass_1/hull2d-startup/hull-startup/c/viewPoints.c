/* view1.c 

Laura Toma

What it does:  

Draws a set of points in the default 2D projection.  

Includes a tentative function for printing and drawing a list of-
points (assumed to be a convex hull). These functions were not 
debugged so use them at your own risk.

This code is written in C.  You will need to update this code to work
with your own (presumably C++) data structures. Feel free to change
this code as much as you need to.

*/

#include "geom.h"
#include "rtimer.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


GLfloat red[3] = {1.0, 0.0, 0.0};
GLfloat green[3] = {0.0, 1.0, 0.0};
GLfloat blue[3] = {0.0, 0.0, 1.0};
GLfloat black[3] = {0.0, 0.0, 0.0};
GLfloat white[3] = {1.0, 1.0, 1.0};
GLfloat gray[3] = {0.5, 0.5, 0.5};
GLfloat yellow[3] = {1.0, 1.0, 0.0};
GLfloat magenta[3] = {1.0, 0.0, 1.0};
GLfloat cyan[3] = {0.0, 1.0, 1.0};

GLint fillmode = 0;



/* forward declarations of functions */
void display(void);
void keypress(unsigned char key, int x, int y);
void main_menu(int value);



/* global variables */
const int WINDOWSIZE = 500; 

//the array of n points; note: this variable needs to be global
//because it needs to be rendered
point2D*  points = NULL;
int n;  

//the convex hull, stored as a list. note: this variable needs to be
//global because it needs to be rendered
pointNode*  hull = NULL; 



void initialize_points_circle() {

  assert(points); 

  double  step = 2* M_PI/n; 
  int rad = 100; 

  int i; 
  for (i=0; i<n; i++) {
    points[i].x = WINDOWSIZE/2+ rad*cos(i*step); 
    points[i].y = WINDOWSIZE/2+ rad*sin(i*step); 
  }

}


void initialize_points_horizontal_line() {

  assert(points); 

  int i; 
  for (i=0; i<n; i++) {
    points[i].x = (int)(.3*WINDOWSIZE)/2 + random() % ((int)(.7*WINDOWSIZE)); 
    points[i].y =  WINDOWSIZE/2; 
  }

}


/* ****************************** */
/* initialize  the array of points stored in global variable points[] with random points */
void initialize_points_random() {
  //points must be allocated 
  assert(points); 
  
  int i; 
  for (i=0; i<n; i++) {
    points[i].x = (int)(.3*WINDOWSIZE)/2 + random() % ((int)(.7*WINDOWSIZE)); 
    points[i].y =  (int)(.3*WINDOWSIZE)/2 + random() % ((int)(.7*WINDOWSIZE));
  }
}


/* ****************************** */
/* initialize the array of points stored in global variable points[]
   with random points shaped like a star */
void initialize_points_star() {
  
  //points must be allocated 
  assert(points); 
  
  int i; 
  for (i=0; i<n; i++) {
    if (i%2 == 0) {
      
      points[i].x = (int)(.3*WINDOWSIZE)/2 + random() % ((int)(.7*WINDOWSIZE)); 
      points[i].y =  random() % ((int)(.7*WINDOWSIZE))  / 5;
      points[i].y += (int)((1-.7/5)*WINDOWSIZE/2);
    };
    if (i%2 == 1)  {
      
      points[i].x = random() % ((int)(.7*WINDOWSIZE)) / 5; 
      points[i].x +=  (int)((1-.7/5)*WINDOWSIZE/2);
      points[i].y =  (int)(.3*WINDOWSIZE)/2 + random() % ((int)(.7*WINDOWSIZE));
    }
   
  }//for i

}

/* ****************************** */
/* print the array of points stored in global variable points[]*/
void print_points() {
  assert(points); 
  int i; 
  printf("points: ");
  for (i=0; i<n; i++) {
    printf("[%3d,%3d] ", points[i].x, points[i].y);
  }
  printf("\n");
  fflush(stdout);  //flush stdout, weird sync happens when using gl thread
}

/* ****************************** */
//print the list of points in global variable  hull; 
void print_hull () {
  
  printf("convex hull: ");
  int i=0;
  pointNode* crt = hull; 
  while (crt) {
    i++; 
    printf("[%3d,%3d] ", crt->p.x, crt->p.y);
    crt = crt->next; 
  }
  printf(" total %d points\n", i);
}



/* ****************************** */
int main(int argc, char** argv) {

  //read number of points from user
  if (argc!=2) {
    printf("usage: viewPoints <nbPoints>\n");
    exit(1); 
  }
  n = atoi(argv[1]); 
  printf("you entered n=%d\n", n);
  assert(n >0); 

  //allocate global arrays of n points 
  points = (point2D*)malloc(n*sizeof(point2D));
  assert(points); 
  //initialize_points_random();
  initialize_points_star();

  //print_points();

  Rtimer rt1; 
  rt_start(rt1); 
  hull = graham_scan(points, n); 
  rt_stop(rt1); 
  //print the hull 
  print_hull(); 
  //print the timing 
  char buf [1024]; 
  rt_sprint(buf,rt1);
  printf("finding convex hull with graham scan:  %s\n\n", buf);
  fflush(stdout); 

 
  

  /* initialize GLUT  */
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(WINDOWSIZE, WINDOWSIZE);
  glutInitWindowPosition(100,100);
  glutCreateWindow(argv[0]);

  /* register callback functions */
  glutDisplayFunc(display); 
  glutKeyboardFunc(keypress);

  /* init GL */
  /* set background color black*/
  glClearColor(0, 0, 0, 0);   
  /* here we can enable depth testing and double buffering and so
     on */

  
  /* give control to event handler */
  glutMainLoop();
  return 0;
}


/* ****************************** */
/* draw the array of points stored in global variable points[] 
   each point is drawn as a small square 
  
*/
void draw_points(){

  const int R= 1;
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  //set color 
  glColor3fv(yellow);   
  
  assert(points);
  int i;
  for (i=0; i<n; i++) {
    //draw a small square centered at (points[i].x, points[i].y)
    glBegin(GL_POLYGON);
    glVertex2f(points[i].x -R,points[i].y-R);
    glVertex2f(points[i].x +R,points[i].y-R);
    glVertex2f(points[i].x +R,points[i].y+R);
    glVertex2f(points[i].x -R,points[i].y+R);
    glEnd();
  }

}





/* ****************************** */
/* draw the list of points stored in global variable hull; the points
   are expected to be in order (ccw or cw) and consecutive points are
   connected by a line
*/
void draw_hull(){

  //set color 
  glColor3fv(red);   
  
  if (hull) {
    pointNode* prev = hull; 
    pointNode* crt = prev->next; 

    while (crt) {
      //draw a line from prev to crt 
      glBegin(GL_LINES);
      glVertex2f(prev->p.x, prev->p.y); 
      glVertex2f(crt->p.x, crt->p.y); 
      glEnd();
      prev=crt; 
      crt=crt->next; 
    }
    
    //draw a line from the last point to the first point 
    glBegin(GL_LINES);
    glVertex2f(prev->p.x, prev->p.y); 
    glVertex2f(hull->p.x, hull->p.y); 
    glEnd();
    prev=crt; 
    crt=crt->next; 
  
  }//if (hull)
}


/* ****************************** */
void display(void) {

  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW); 
  glLoadIdentity(); //clear the matrix


  /* the default GL window is [-1,1]x[-1,1] with the origin in the
     center the points are in the range (0,0) to (WINSIZE,WINSIZE), so
     they need to be mapped to [-1,1]x [-1,1] */
  glScalef(2.0/WINDOWSIZE, 2.0/WINDOWSIZE, 1.0);  
  glTranslatef(-WINDOWSIZE/2, -WINDOWSIZE/2, 0); 
  draw_points();
  draw_hull(); 

  /* execute the drawing commands */
  glFlush();
}



/* ****************************** */
void keypress(unsigned char key, int x, int y) {
  switch(key) {
  case 'q':
    exit(0);
    break;

  case 'i': 
    initialize_points_circle(); 
    glutPostRedisplay();
    break; 
    

  } 
}


/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
     
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   gluOrtho2D(0.0, (GLdouble) width, 0.0, (GLdouble) height); 
}


