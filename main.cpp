#include<windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>
#include <math.h>

GLfloat	tx	=  0.0;
GLfloat	ty	=  0.0;


static float	car_run	=  0.0;
static float	car_run2 =  0.0;
static float	boat_move =  0.0;
static float	cloud_right =  0.0;
static float	cloud_left =  0.0;
static float	plane_move =  0.0;
static float	plane_move1 =  0.0;
float t=0;


void init(void)
{
  glClearColor(0.0,0.0,0.0,0.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50,50,-50,25,-25,5);

}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)//radius_x,radius_y,certre_position_x,centre_position_y
{

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);

    for(int i=0;i<=100;i++)

    {
        float angle = 2.0f * 3.1416f * i/100;

        float x = rx * cosf(angle);
        float y = ry * sinf(angle);

        glVertex2f((x+cx),(y+cy));
    }
    glEnd();



}


//Car1

    void car()
    {glPushMatrix();
    glColor3ub(220.5, 230.0, 130.0);


    glBegin(GL_QUADS);
        glVertex2f(-42.0,-48.0);
        glVertex2d(-19.0, -48.0);
        glVertex2d(-19.0, -43.0);
        glVertex2d(-42.0,-43.0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2d(-37.0,-39.0);
        glVertex2d(-39.0,-43.0);
        glVertex2d(-22.0, -43.0);
        glVertex2d(-24.0, -39.0);
    glEnd();
     glColor3f(0.0f,0.0f,1.0f);
     glBegin(GL_QUADS);
        glVertex2d(-36.0,-40.0);
        glVertex2d(-38.0,-44.0);
        glVertex2d(-23.0, -44.0);
        glVertex2d(-25.0, -40.0);
    glEnd();
    glColor3ub(230.5f,220.0f,130.0f);
     glBegin(GL_QUADS);
        glVertex2d(-31.0,-44.0);
        glVertex2d(-29.0,-44.0);
        glVertex2d(-29.0, -40.0);
        glVertex2d(-31.0, -40.0);
    glEnd();
     glColor3f(0.0f,0.0f,0.0f);
    circle(2.5,2.5,-36,-47);
    circle(2.5,2.5,-26,-47);

    glColor3ub(247, 244, 245);
    circle(1,1,-36,-47);
    circle(1,1,-26,-47);
    //circle(4,4);
    glPopMatrix();
    }

//Car2

void car2()
    {glPushMatrix();
    glColor3ub(150.0, 150.0, 0.0);

    glTranslatef(tx,ty,0);
    glBegin(GL_QUADS);
        glVertex2d(-22.0,-40.0);
        glVertex2d(1.0, -40.0);
        glVertex2d(1.0, -35.0);
        glVertex2d(-22.0,-35.0);
    glEnd();
    glBegin(GL_QUADS);
        glVertex2d(-17.0,-31.0);
        glVertex2d(-19.0,-35.0);
        glVertex2d(-2.0, -35.0);
        glVertex2d(-4.0, -31.0);
    glEnd();
     glColor3ub(120.f,233.0f,123.0f);
     glBegin(GL_QUADS);
        glVertex2d(-16.0,-32.0);
        glVertex2d(-18.0,-36.0);
        glVertex2d(-3.0, -36.0);
        glVertex2d(-5.0, -32.0);
    glEnd();
    glColor3ub(150.0f,150.0f,0.0f);
     glBegin(GL_QUADS);
        glVertex2d(-11.5,-36.0);
        glVertex2d(-9.5,-36.0);
        glVertex2d(-9.5, -32.0);
        glVertex2d(-11.5, -32.0);
    glEnd();
     glColor3f(0.0f,0.0f,0.0f);
    circle(2.5,2.5,-14.7,-39);
    circle(2.5,2.5,-4.7,-39);

    glColor3ub(247, 244, 245);
    circle(1,1,-14.7,-39);
    circle(1,1,-4.7,-39);
    //circle(4,4);
    glPopMatrix();
    }


void boat(){
    //Boat1
    glColor3ub( 152.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-5 ,-30);
   glVertex2f(10 ,-30);
   glVertex2f(15 ,-25);
   glVertex2f(-5 ,-25);
   glEnd();

   glColor3ub( 147.0 ,0.0, 219.0);
   glBegin(GL_POLYGON);
   glVertex2f(-3 ,-25);
   glVertex2f(11 ,-25);
   glVertex2f(9 ,-22);
   glVertex2f(-3 ,-22);
   glEnd();

   glColor3ub( 148.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-1.5 ,-24.5);
   glVertex2f(0.5 ,-24.5);
   glVertex2f(0.5 ,-22.5);
   glVertex2f(-1.5 ,-22.5);
   glEnd();

   glColor3ub( 148.0 ,1.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(2.5 ,-24.5);
   glVertex2f(4.5 ,-24.5);
   glVertex2f(4.5 ,-22.5);
   glVertex2f(2.5 ,-22.5);
   glEnd();

   glColor3ub( 148 ,1.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(6.5 ,-24.5);
   glVertex2f(8.5 ,-24.5);
   glVertex2f(8.5 ,-22.5);
   glVertex2f(6.5 ,-22.5);
   glEnd();



}

void boat_Move(){
    boat_move=boat_move+0.02;
    if (boat_move>70)
        boat_move=-70;
    glutPostRedisplay();


}

void cloud1(){
    //Cloud1

    glPushMatrix();
	glTranslatef(-60.0f, 5.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,14,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,16.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,19.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,15.5,13.2);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,18.3,13.2);
   glPopMatrix();

}

void cloud2(){
    //Cloud2

    glPushMatrix();
	glTranslatef(-40.0f, 0.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,14,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,16.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,19.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,15.5,13.2);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,18.3,13.2);
glPopMatrix();

}

void cloud3(){
    //Cloud3

    glPushMatrix();
	glTranslatef(-30.0f, 8.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

  glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,19,10);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,20.5,10);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,22,10);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,19.5,11.2);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,21.0,11.2);

glPopMatrix();

}


void cloud4(){
    //Cloud4

    glPushMatrix();
	glTranslatef(-10.0f, 7.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,14,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,16.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,19.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,15.5,13.2);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,18.3,13.2);
glPopMatrix();

}

void cloud5(){
       //Cloud5

    glPushMatrix();
	glTranslatef(-10.0f, 7.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,14,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,16.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,19.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,15.5,13.2);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,18.3,13.2);
glPopMatrix();

}

void cloud6(){
    //Cloud6

    glPushMatrix();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

  glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,19,10);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,20.5,10);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,22,10);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,19.5,11.2);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(1,1,21.0,11.2);

glPopMatrix();

}

void cloud7(){
    //Cloud7

    glPushMatrix();
	glTranslatef(28.0f, 0.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,14,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,16.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,19.5,11);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,15.5,13.2);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(2,2,18.3,13.2);
glPopMatrix();

}

void plane()
{
    glColor3ub(100,20,13.2);
    glBegin(GL_POLYGON);
    glVertex2f(21,20);
    glVertex2f(18,19);
    glVertex2f(21,19);
    glVertex2f(24,19);
    glVertex2f(24,20);
    glVertex2f(25,21);
    glEnd();

    glColor3ub(255,255,255);
    circle(.2,.2,20,19.6);
    glColor3ub(0,0,1);
    circle(.2,.2,23.8,20);
    glColor3ub(1,0,0);
    circle(.2,.2,23.8,19.5);

}


void plane1()
{
    glColor3ub(100,60,10.2);
    glBegin(GL_POLYGON);
    glVertex2f(21,20);
    glVertex2f(18,19);
    glVertex2f(21,19);
    glVertex2f(24,19);
    glVertex2f(24,20);
    glVertex2f(25,21);
    glEnd();

    glColor3f(1,1,1);
    circle(.2,.2,20,19.6);
    glColor3f(0,0,1);
    circle(.2,.2,23.8,20);
    glColor3f(1,0,0);
    circle(.2,.2,23.8,19.5);

}


void cloud1_move()
{
    cloud_right=cloud_right+0.0005;
    if (cloud_right>100)
        cloud_right=-50;
    glutPostRedisplay();
}

void cloud6_move()
{
    cloud_right=cloud_right+0.0005;
    if (cloud_right>100)
        cloud_right=-70;
    glutPostRedisplay();
}

void cloud7_move()
{
    cloud_left=cloud_left-0.0005;
    if (cloud_left<-60)
        cloud_left=70;
    glutPostRedisplay();
}



void cloud3_move()
{
    cloud_left=cloud_left-0.0005;
    if (cloud_left<-60)
        cloud_left=70;
    glutPostRedisplay();
}









void car_Run()
{
    car_run=car_run+0.05;
    if (car_run>100)
        car_run=-50;
    glutPostRedisplay();
}

void car_Run2()
{
    car_run2=car_run2-0.05;
    if (car_run2<-100)
        car_run2=70;
    glutPostRedisplay();
}

void plane_Move()
{
    plane_move=plane_move-0.05;
    if (plane_move<-100)
        plane_move=70;
    glutPostRedisplay();
}

void plane_Move1()
{
    plane_move1=plane_move1-0.05;
    if (plane_move1<-100)
        plane_move1=70;
    glutPostRedisplay();
}
void sky(){
//sky
    glColor3f(0.4,0.7,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-50,-50);
	glVertex2f(50,-50);
	glVertex2f(50,35);
	glVertex2f(-50,35);
	glEnd();

}

void ground(){
//Ground

    glPushMatrix();
	glTranslatef(0.0f, 30.0f, 0.0f);

	glColor3f(0.0,0.6,0.0);
    glBegin(GL_POLYGON);
	glVertex2f(-50,-50);
	glVertex2f(50,-50);
	glVertex2f(50,-40);
	glVertex2f(-50,-40);
	glEnd();

	glPopMatrix();

}

void river(){
//river
	glPushMatrix();
	glTranslatef(0.0f, 10.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

	 glColor3f(0.0,0.5,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(-50,-50);
	glVertex2f(50,-50);
	glVertex2f(50,-30);
	glVertex2f(-50,-30);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 8.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

	 glColor3f(0.0,0.5,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(-50,-50);
	glVertex2f(50,-50);
	glVertex2f(50,-30);
	glVertex2f(-50,-30);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 6.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

	 glColor3f(0.0,0.4,0.7);
	glBegin(GL_POLYGON);
	glVertex2f(-50,-50);
	glVertex2f(50,-50);
	glVertex2f(50,-30);
	glVertex2f(-50,-30);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 4.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

	 glColor3f(0.0,0.3,0.6);
	glBegin(GL_POLYGON);
	glVertex2f(-50,-50);
	glVertex2f(50,-50);
	glVertex2f(50,-30);
	glVertex2f(-50,-30);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0f, 2.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

	 glColor3f(0.0,0.2,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(-50,-50);
	glVertex2f(50,-50);
	glVertex2f(50,-30);
	glVertex2f(-50,-30);
	glEnd();

	glPopMatrix();

}


void Tree1(){
//Tree1
    glColor3f( 1.0 ,0.5, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-8.9 ,-2.5);
   glVertex2f(-6.8 ,-2.5);
   glVertex2f(-6.8 ,-12);
   glVertex2f(-8.9 ,-12);
   glEnd();


   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-10.5,-1.5);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-8.5,-1.5);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-7,-1.5);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-5,-1.5);


   glColor3f(0.1f, 0.5f, 0.0f);
   circle(1.5,1.5,-9.5,0.6);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-8.1,0.6);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-6.3,0.6);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(2,2,-8,1.7);
}

void Tree2(){
//Tree2


   glColor3ub( 125.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(10 ,-3);
   glVertex2f(11.2 ,-3);
   glVertex2f(11.2 ,-12);
   glVertex2f(10 ,-12);
   glEnd();

   glColor3f( 0.0 ,1.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(7 ,-5);
   glVertex2f(14 ,-5);
   glVertex2f(10.8 ,4);
   glEnd();

   glColor3f( 0.2 ,0.6, 0.5);
   glBegin(GL_POLYGON);
   glVertex2f(7 ,-2);
   glVertex2f(14 ,-2);
   glVertex2f(10.8 ,3);
   glEnd();

   glColor3f( 0.0 ,1.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(8.2 ,1);
   glVertex2f(13 ,1);
   glVertex2f(10.8 ,5);
   glEnd();
}

void Tree3(){

glPushMatrix();
	glTranslatef(-35.0f, 0.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

  //Tree1
    glColor3f( 1.0 ,0.5, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-8.9 ,-2.5);
   glVertex2f(-6.8 ,-2.5);
   glVertex2f(-6.8 ,-12);
   glVertex2f(-8.9 ,-12);
   glEnd();


   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-10.5,-1.5);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-8.5,-1.5);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-7,-1.5);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-5,-1.5);


   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-9.5,0.6);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-8.1,0.6);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(1.5,1.5,-6.3,0.6);

   glColor3f(0.0f, 0.5f, 0.0f);
   circle(2,2,-8,1.7);



   //Tree4


   glColor3ub( 125.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(9.3 ,-3);
   glVertex2f(10.5 ,-3);
   glVertex2f(10.5 ,-12);
   glVertex2f(9.3 ,-12);
   glEnd();

   glColor3f( 0.0 ,1.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(7 ,-5);
   glVertex2f(12.7 ,-5);
   glVertex2f(9.85 ,4);
   glEnd();

   glColor3f( 0.2 ,0.6, 0.5);
   glBegin(GL_POLYGON);
   glVertex2f(7 ,-2);
   glVertex2f(12.7 ,-2);
   glVertex2f(9.85 ,3);
   glEnd();

   glColor3f( .0 ,1.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(7.5 ,1);
   glVertex2f(12.2 ,1);
   glVertex2f(9.85 ,5);
   glEnd();
}

void House1(){

//House1

   glColor3ub( 50.7 ,95.0, 120.0);
   glBegin(GL_POLYGON);
   glVertex2f(-3.2 ,-15);
   glVertex2f(6.8 ,-15);
   glVertex2f(6.8 ,5);
   glVertex2f(-3.2 ,5);
   glEnd();

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-2.7 ,-6);
   glVertex2f(0.8 ,-6);
   glVertex2f(0.8 ,4.3);
   glVertex2f(-2.7 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-1 ,-6);
   glVertex2f(-0.90 ,-6);
   glVertex2f(-0.90 ,4.3);
   glVertex2f(-1 ,4.3);
   glEnd();



   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-2.7 ,-3.35);
   glVertex2f(0.8 ,-3.35);
   glVertex2f(0.8 ,-3.45);
   glVertex2f(-2.7 ,-3.45);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-2.7 ,1.70);
   glVertex2f(0.8 ,1.70);
   glVertex2f(0.8 ,1.85);
   glVertex2f(-2.7 ,1.85);
   glEnd();



   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(3 ,-6);
   glVertex2f(6.3 ,-6);
   glVertex2f(6.3 ,4.3);
   glVertex2f(3 ,4.3);
   glEnd();

 glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(4.65 ,-6);
   glVertex2f(4.72 ,-6);
   glVertex2f(4.72 ,4.3);
   glVertex2f(4.65 ,4.3);
   glEnd();


   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(3 ,1.70);
   glVertex2f(6.3 ,1.70);
   glVertex2f(6.3 ,1.85);
   glVertex2f(3 ,1.85);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(3 ,-3.35);
   glVertex2f(6.3 ,-3.35);
   glVertex2f(6.3 ,-3.45);
   glVertex2f(3 ,-3.45);
   glEnd();

   //Door


   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(0.3 ,-15);
   glVertex2f(3.7 ,-15);
   glVertex2f(3.7 ,-7);
   glVertex2f(0.3 ,-7);
   glEnd();
}

void House2(){

//House2

   glColor3ub( 123.2 ,0.0, 123.2);
   glBegin(GL_POLYGON);
   glVertex2f(-22.2 ,-15);
   glVertex2f(-12.2 ,-15);
   glVertex2f(-12.2 ,5);
   glVertex2f(-22.2 ,5);
   glEnd();

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-21.7 ,-6);
   glVertex2f(-18.2 ,-6);
   glVertex2f(-18.2 ,4.3);
   glVertex2f(-21.7 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-20 ,-6);
   glVertex2f(-19.90 ,-6);
   glVertex2f(-19.90 ,4.3);
   glVertex2f(-20 ,4.3);
   glEnd();

   glColor3f( 0.2 ,0.0, 0.2);
   glBegin(GL_POLYGON);
   glVertex2f(-21.7 ,-0.7);
   glVertex2f(-18.2 ,-0.7);
   glVertex2f(-18.2 ,0);
   glVertex2f(-21.7 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-21.7 ,-3.35);
   glVertex2f(-18.2 ,-3.35);
   glVertex2f(-18.2 ,-3.45);
   glVertex2f(-21.7 ,-3.45);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-21.7 ,1.75);
   glVertex2f(-18.2 ,1.75);
   glVertex2f(-18.2 ,1.95);
   glVertex2f(-21.7 ,1.95);
   glEnd();



   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-16 ,-6);
   glVertex2f(-12.7 ,-6);
   glVertex2f(-12.7 ,4.3);
   glVertex2f(-16 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-14.35 ,-6);
   glVertex2f(-14.28 ,-6);
   glVertex2f(-14.28 ,4.3);
   glVertex2f(-14.35 ,4.3);
   glEnd();

   glColor3f( 0.2 ,0.0, 0.2);
   glBegin(GL_POLYGON);
   glVertex2f(-16 ,-0.7);
   glVertex2f(-12.7 ,-0.7);
   glVertex2f(-12.7 ,0);
   glVertex2f(-16 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-16 ,1.75);
   glVertex2f(-12.7 ,1.75);
   glVertex2f(-12.7 ,1.95);
   glVertex2f(-16 ,1.95);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-16 ,-3.35);
   glVertex2f(-12.7 ,-3.35);
   glVertex2f(-12.7 ,-3.45);
   glVertex2f(-16 ,-3.45);
   glEnd();

   //Door

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-18.7 ,-15);
   glVertex2f(-15.3 ,-15);
   glVertex2f(-15.3 ,-7);
   glVertex2f(-18.7 ,-7);
   glEnd();
}

void House3(){

//House3

   glColor3ub( 120.2 ,240.0, 80.2);
   glBegin(GL_POLYGON);
   glVertex2f(14.3 ,-15);
   glVertex2f(24.3 ,-15);
   glVertex2f(24.3 ,5);
   glVertex2f(14.3 ,5);
   glEnd();

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,-6);
   glVertex2f(18.3 ,-6);
   glVertex2f(18.3 ,4.3);
   glVertex2f(14.8 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(16.5 ,-6);
   glVertex2f(16.6 ,-6);
   glVertex2f(16.6 ,4.3);
   glVertex2f(16.5 ,4.3);
   glEnd();

   glColor3f( 1.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,-0.7);
   glVertex2f(18.3 ,-0.7);
   glVertex2f(18.3 ,0);
   glVertex2f(14.8 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,1.75);
   glVertex2f(18.3 ,1.75);
   glVertex2f(18.3 ,1.95);
   glVertex2f(14.8 ,1.95);
   glEnd();



   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,-6);
   glVertex2f(23.8 ,-6);
   glVertex2f(23.8 ,4.3);
   glVertex2f(20.5 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(22.15 ,-6);
   glVertex2f(22.22 ,-6);
   glVertex2f(22.22 ,4.3);
   glVertex2f(22.15 ,4.3);
   glEnd();

   glColor3f( 1.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,-0.7);
   glVertex2f(23.8 ,-0.7);
   glVertex2f(23.8 ,0);
   glVertex2f(20.5 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,1.75);
   glVertex2f(23.8 ,1.75);
   glVertex2f(23.8 ,1.95);
   glVertex2f(20.5 ,1.95);
   glEnd();


   //Door

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(17.8 ,-15);
   glVertex2f(21.2 ,-15);
   glVertex2f(21.2 ,-7);
   glVertex2f(17.8 ,-7);
   glEnd();
}

void House4(){

//House4


    glPushMatrix();
	glTranslatef(15.0f, 0.0f, 0.0f);
	//glRotatef(0, 0.0f, 0.0f, -1.0f);

	glColor3ub( 030.7 ,160.0, 130.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.3 ,-15);
   glVertex2f(24.3 ,-15);
   glVertex2f(24.3 ,5);
   glVertex2f(14.3 ,5);
   glEnd();

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,-6);
   glVertex2f(18.3 ,-6);
   glVertex2f(18.3 ,4.3);
   glVertex2f(14.8 ,4.3);
   glEnd();



   glColor3f( 1.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,-0.7);
   glVertex2f(18.3 ,-0.7);
   glVertex2f(18.3 ,0);
   glVertex2f(14.8 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,-3.35);
   glVertex2f(18.3 ,-3.35);
   glVertex2f(18.3 ,-3.45);
   glVertex2f(14.8 ,-3.45);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,1.75);
   glVertex2f(18.3 ,1.75);
   glVertex2f(18.3 ,1.95);
   glVertex2f(14.8 ,1.95);
   glEnd();



   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,-6);
   glVertex2f(23.8 ,-6);
   glVertex2f(23.8 ,4.3);
   glVertex2f(20.5 ,4.3);
   glEnd();



   glColor3f( 1.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,-0.7);
   glVertex2f(23.8 ,-0.7);
   glVertex2f(23.8 ,0);
   glVertex2f(20.5 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,1.75);
   glVertex2f(23.8 ,1.75);
   glVertex2f(23.8 ,1.95);
   glVertex2f(20.5 ,1.95);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,-3.35);
   glVertex2f(23.8 ,-3.35);
   glVertex2f(23.8 ,-3.45);
   glVertex2f(20.5 ,-3.45);
   glEnd();

   //Door

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(17.8 ,-15);
   glVertex2f(21.2 ,-15);
   glVertex2f(21.2 ,-7);
   glVertex2f(17.8 ,-7);
   glEnd();

	glPopMatrix();
}

void House5(){

//House5


    glPushMatrix();
	glTranslatef(30.0f, 0.0f, 0.0f);
	glRotatef(0, 0.0f, 0.0f, -1.0f);

	glColor3ub( 150.2 ,24.2, 145.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.3 ,-15);
   glVertex2f(24.3 ,-15);
   glVertex2f(24.3 ,5);
   glVertex2f(14.3 ,5);
   glEnd();

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,-6);
   glVertex2f(18.3 ,-6);
   glVertex2f(18.3 ,4.3);
   glVertex2f(14.8 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(16.5 ,-6);
   glVertex2f(16.6 ,-6);
   glVertex2f(16.6 ,4.3);
   glVertex2f(16.5 ,4.3);
   glEnd();

   glColor3f( 1.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,-0.7);
   glVertex2f(18.3 ,-0.7);
   glVertex2f(18.3 ,0);
   glVertex2f(14.8 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,-3.35);
   glVertex2f(18.3 ,-3.35);
   glVertex2f(18.3 ,-3.45);
   glVertex2f(14.8 ,-3.45);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(14.8 ,1.75);
   glVertex2f(18.3 ,1.75);
   glVertex2f(18.3 ,1.95);
   glVertex2f(14.8 ,1.95);
   glEnd();



   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,-6);
   glVertex2f(23.8 ,-6);
   glVertex2f(23.8 ,4.3);
   glVertex2f(20.5 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(22.15 ,-6);
   glVertex2f(22.22 ,-6);
   glVertex2f(22.22 ,4.3);
   glVertex2f(22.15 ,4.3);
   glEnd();

   glColor3f( 1.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,-0.7);
   glVertex2f(23.8 ,-0.7);
   glVertex2f(23.8 ,0);
   glVertex2f(20.5 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,1.75);
   glVertex2f(23.8 ,1.75);
   glVertex2f(23.8 ,1.85);
   glVertex2f(20.5 ,1.85);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(20.5 ,-3.35);
   glVertex2f(23.8 ,-3.35);
   glVertex2f(23.8 ,-3.45);
   glVertex2f(20.5 ,-3.45);
   glEnd();

   //Door

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(17.8 ,-15);
   glVertex2f(21.2 ,-15);
   glVertex2f(21.2 ,-7);
   glVertex2f(17.8 ,-7);
   glEnd();

	glPopMatrix();
}

void House6(){

//House6

   glColor3ub( 230.2 ,60.2, 134.0);
   glBegin(GL_POLYGON);
   glVertex2f(-3.2 ,-15);
   glVertex2f(6.8 ,-15);
   glVertex2f(6.8 ,5);
   glVertex2f(-3.2 ,5);
   glEnd();

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-2.7 ,-6);
   glVertex2f(0.8 ,-6);
   glVertex2f(0.8 ,4.3);
   glVertex2f(-2.7 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-1 ,-6);
   glVertex2f(-0.9 ,-6);
   glVertex2f(-0.9 ,4.3);
   glVertex2f(-1 ,4.3);
   glEnd();

   glColor3f( 1.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-2.7 ,-0.7);
   glVertex2f(0.8 ,-0.7);
   glVertex2f(0.8 ,0);
   glVertex2f(-2.7 ,0);
   glEnd();






   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(3 ,-6);
   glVertex2f(6.3 ,-6);
   glVertex2f(6.3 ,4.3);
   glVertex2f(3 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(4.65 ,-6);
   glVertex2f(4.72 ,-6);
   glVertex2f(4.72 ,4.3);
   glVertex2f(4.65 ,4.3);
   glEnd();

   glColor3f( 1.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(3 ,-0.7);
   glVertex2f(6.3 ,-0.7);
   glVertex2f(6.3 ,0);
   glVertex2f(3 ,0);
   glEnd();




   //Door

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(0.3 ,-15);
   glVertex2f(3.7 ,-15);
   glVertex2f(3.7 ,-7);
   glVertex2f(0.3 ,-7);
   glEnd();

}

void House7(){

//House7

   glColor3f( 0.2 ,0.0, 0.2);
   glBegin(GL_POLYGON);
   glVertex2f(-22.2 ,-15);
   glVertex2f(-12.2 ,-15);
   glVertex2f(-12.2 ,5);
   glVertex2f(-22.2 ,5);
   glEnd();

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-21.7 ,-6);
   glVertex2f(-18.2 ,-6);
   glVertex2f(-18.2 ,4.3);
   glVertex2f(-21.7 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-20 ,-6);
   glVertex2f(-19.95 ,-6);
   glVertex2f(-19.95 ,4.3);
   glVertex2f(-20 ,4.3);
   glEnd();

   glColor3f( 0.2 ,0.0, 0.2);
   glBegin(GL_POLYGON);
   glVertex2f(-21.7 ,-0.7);
   glVertex2f(-18.2 ,-0.7);
   glVertex2f(-18.2 ,0);
   glVertex2f(-21.7 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-21.7 ,-3.35);
   glVertex2f(-18.2 ,-3.35);
   glVertex2f(-18.2 ,-3.45);
   glVertex2f(-21.7 ,-3.45);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-21.7 ,1.75);
   glVertex2f(-18.2 ,1.75);
   glVertex2f(-18.2 ,1.85);
   glVertex2f(-21.7 ,1.85);
   glEnd();



   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-16 ,-6);
   glVertex2f(-12.7 ,-6);
   glVertex2f(-12.7 ,4.3);
   glVertex2f(-16 ,4.3);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-14.35 ,-6);
   glVertex2f(-14.28 ,-6);
   glVertex2f(-14.28 ,4.3);
   glVertex2f(-14.35 ,4.3);
   glEnd();

   glColor3f( 0.2 ,0.0, 0.2);
   glBegin(GL_POLYGON);
   glVertex2f(-16 ,-0.7);
   glVertex2f(-12.7 ,-0.7);
   glVertex2f(-12.7 ,0);
   glVertex2f(-16 ,0);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-16 ,1.75);
   glVertex2f(-12.7 ,1.75);
   glVertex2f(-12.7 ,1.95);
   glVertex2f(-16 ,1.95);
   glEnd();

   glColor3f( 0.0 ,0.0, 0.0);
   glBegin(GL_POLYGON);
   glVertex2f(-16 ,-3.35);
   glVertex2f(-12.7 ,-3.35);
   glVertex2f(-12.7 ,-3.45);
   glVertex2f(-16 ,-3.45);
   glEnd();

   //Door

   glColor3f( 1.0 ,1.0, 1.0);
   glBegin(GL_POLYGON);
   glVertex2f(-18.7 ,-15);
   glVertex2f(-15.3 ,-15);
   glVertex2f(-15.3 ,-7);
   glVertex2f(-18.7 ,-7);
   glEnd();

    glPopMatrix();
}

void Road1(){

//Road1

   glColor3ub(22, 21, 21);
   glBegin(GL_POLYGON);
   glVertex2f(-50 ,-20);
   glVertex2f(50 ,-20);
   glVertex2f(50 ,-15);
   glVertex2f(-50 ,-15);
   glEnd();

    glColor3ub(252, 255, 249);
    glBegin(GL_LINES);

    glVertex2d(-50.0,-17.5);
    glVertex2d(50.0,-17.5);
    glEnd();
}

void Moon()
{
     glColor3f(1.0f, 1.0f, 1.0f);
   circle(3,3,25.5,16.5);

   glColor3f(0.0f, 0.0f, 0.0f);
   circle(3,3,24.5,17.5);

}
void stars()
{
    glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.2,10.5,16.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.2,-5.5,10.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.2,-8.5,12.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.2,-20,18.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,-15,7.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,-25,11.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,-32,14.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,-40,10.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,-46,16.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,32,19.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,37,14.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,46,17.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,0,18);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,-8,20.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,8,13.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,15,11.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,19,18.5);

   glColor3f(1.0f, 1.0f, 1.0f);
   circle(0.2,0.3,14,20.5);
}
void Road2(){

//Road2

   glColor3ub(22, 21, 21);
     glBegin(GL_QUADS);
      glVertex2d(-50,-50);
      glVertex2d(50,-50);
      glVertex2d(50,-35);
      glVertex2d(-50,-35);
    glEnd();

    glColor3ub(252, 249, 249);
    glBegin(GL_LINES);
    glVertex2d(-50.0,-42.5);
    glVertex2d(50.0,-42.5);
    glEnd();
}

void Sun(){
//Sun
    glPushMatrix();
	glTranslatef(35.0f, 5.0f, 0.0f);

   glColor3f(1.0f, 1.0f, 0.0f);
   circle(3,3,4.5,11.5);
glPopMatrix();

}


void Day()
{  glClear(GL_COLOR_BUFFER_BIT);


    //sky
	sky();

	//Ground
	ground();

	//river
    river();

	//Back Wall



    //Tree1
    Tree1();


    //Tree2
    Tree2();


    //House1
    House1();

    //House2
    House2();

    //House3
    House3();

    //Road1
    Road1();

    //Sun
    Sun();

    //House4
    House4();


    //House5
    House5();

    //Tree3
	Tree3();


    //House6
    House6();

    //House7
    House7();



    //Road2
    Road2();


    plane_Move1();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(plane_move1+i,0,0);
       plane1();
       glPopMatrix();
   }



    cloud1_move();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(cloud_right+i,0,0);
       cloud1();
       glPopMatrix();
   }

   cloud1_move();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(cloud_right+i,0,0);
       cloud2();
       glPopMatrix();
   }

   cloud3_move();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(cloud_left+i,0,0);
       cloud3();
       glPopMatrix();
   }

   cloud3_move();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(cloud_left+i,0,0);
       cloud4();
       glPopMatrix();
   }

   cloud1_move();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(cloud_right+i,0,0);
       cloud5();
       glPopMatrix();
   }

   cloud6_move();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(cloud_right+i,0,0);
       cloud6();
       glPopMatrix();
   }

   cloud7_move();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(cloud_left+i,0,0);
       cloud7();
       glPopMatrix();
   }


    car_Run2();
   for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(car_run2+i,0,0);
       car2();
       glPopMatrix();
   }


    car_Run();
   for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(car_run+i,0,0);
       car();
       glPopMatrix();
   }

   boat_Move();
   for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(boat_move+i,0,0);
       boat();
       glPopMatrix();
   }


glutSwapBuffers();


}

void Night(){
glClear(GL_COLOR_BUFFER_BIT);


    //sky
    glColor3f(0.0,0.0,.0);
	glBegin(GL_POLYGON);
	glVertex2f(-50,-50);
	glVertex2f(50,-50);
	glVertex2f(50,35);
	glVertex2f(-50,35);
	glEnd();


	//Ground
	ground();

    //river
    river();

    //Back Wall
   boat();
     stars();
    //Tree1
    Tree1();

    //Tree2
    Tree2();

    //House1
    House1();

    //House2
    House2();

    //House3
    House3();

    //Road1
    Road1();

   Moon();


   //Stars




    //House4
    House4();


    //House5
	House5();

    //Tree3
	Tree3();

    //House6
    House6();

    //House7
    House7();

    //Front Wall


    //Road2
    Road2();



    plane_Move();
    for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(plane_move+i,0,0);
       plane();
       glPopMatrix();
   }




    car_Run();
   for(int i=0; i<1; i++)
   {
       glPushMatrix();
       glTranslatef(car_run+i,0,0);
       car();
       glPopMatrix();
   }



glutSwapBuffers();


}


void sound()
{
    PlaySound("one.wav",NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}

void sound2()
{
    PlaySound("two.wav", NULL, SND_ASYNC|SND_FILENAME|SND_LOOP);
}




void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
	    case  'd':
	        glutDisplayFunc(Day);
	        glutKeyboardFunc(handleKeypress);
	        sound();
	        glutPostRedisplay();
            break;

         case 'n':
            glutDisplayFunc(Night);
	        glutKeyboardFunc(handleKeypress);
	        sound2();
	        glutPostRedisplay();
            break;




    }
}





int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode ( GLUT_RGB | GLUT_DOUBLE );
    glutInitWindowPosition(30,0);
    glutInitWindowSize(1000,650);
    glutCreateWindow("Cool City");
    init();
    glutDisplayFunc(Day);
    glutKeyboardFunc(handleKeypress);
    glutMainLoop();
    return 0;
}
