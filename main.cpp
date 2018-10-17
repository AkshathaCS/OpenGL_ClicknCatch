#include<GL/freeglut.h>
#include<stdio.h>
#include<stdlib.h>
#define sizex 150
#define sizey 100

GLsizei ww=500,wh=500;
int x,y,flg=0;
int count=0;

struct object
{
    int val[2][2];
}obj;

void myInit()
{
    glViewport(0,0,ww,wh);
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
    glMatrixMode(GL_MODELVIEW);
}

void draw(int i)
{
    /*if(i==0)
    {
     x=y=10;
    }*/
    if(i==1)
    {
        printf("object caught\n");
        count++;
    x=(rand())%400;
    y=(rand())%400;
    }
    obj.val[0][0]=x;
    obj.val[0][1]=x+sizex;
    obj.val[1][0]=y;
    obj.val[1][1]=y+sizey;
    glBegin(GL_POLYGON);
    glColor3f(1,0,0);
    glVertex2f(x,y);
    glColor3f(0,1,0);
    glVertex2f(x+sizex,y);
    glColor3f(0,0,1);
    glVertex2f(x+sizex,y+sizey);
    glColor3f(1,0,1);
    glVertex2f(x,y+sizey);
    glEnd();
    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
}

void myMouse(int button,int state,int a,int b)
{
    //printf("a=%d b=%d\n",a,b);
    b=wh-b;
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
      printf("no of objects caught=%d\n",count);
      exit(0);
    }

    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
     glFlush();
    if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
    {
     if(obj.val[0][0]<=a && a<=obj.val[0][1] && obj.val[1][0]<=b && b<=obj.val[1][1])
     {
      flg=1;
     }
     else
     {
      flg=2;
     }
     draw(flg);
    }
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_SINGLE);
    glutInitWindowSize(ww,wh);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Click N Catch");
    myInit();
    glutDisplayFunc(display);
    glutMouseFunc(myMouse);
    glutMainLoop();
}
