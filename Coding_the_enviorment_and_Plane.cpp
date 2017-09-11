
/***
Author : H. M. Tarek Ullah
***/

#include <stdio.h>
#include <GL/glut.h>
#include<math.h>




GLfloat rotation = 90.0;
float posX = 0, posY = 0, posZ = 0;
float move_unit = 3;
float rate = 1.0f;
float angle = -0.0f;
float RotateX = 0.f, RotateY = 45.f;

int viewY1, viewX1, viewX2, viewX3, viewY2, viewY3 ;

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}


//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}


void Timer(int value)
{
	glutPostRedisplay();      // Post re-paint request to activate display()
	glutTimerFunc(16, Timer, 0); // next Timer call milliseconds later
}

void stand()
{
	// windmill stand
	glBegin(GL_QUADS);
	glColor3f(0.69, 0.43, 0.314);
	glVertex3i(106, 298,0);
	glVertex3i(199, 296,0);
	glVertex3i(160, 420,0);
	glVertex3i(140, 420,0);
	glEnd();
	glFlush();

}

void windmill()
{

	//left 1st wing
	glBegin(GL_QUADS);
	glColor3f(0.4, 0.176, 0.070);
	glVertex3i(200, 400, 0);
	glVertex3i(180, 450, 0);
	glVertex3i(20, 570, 0);
	glVertex3i(40, 520, 0);
	//glEnd();
	glFlush();
	//2nd wing
	glColor3f(0.4, 0.176, 0.070);
	glVertex3i(0, 400, 0);
	glVertex3i(190, 520, 0);
	glVertex3i(210, 570, 0);
	glVertex3i(20, 450, 0);
	glEnd();
	glFlush();


}

void plane1() {
	/*----------------------- Plane ------------- */
	//plane


	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glPointSize(3.0);

	glVertex3i(10 + viewX1, 245 + viewY1, 0);
	glVertex3i(15 + viewX1, 245 + viewY1, 0);
	glVertex3i(35 + viewX1, 235 + viewY1, 0);
	glVertex3i(15 + viewX1, 225 + viewY1, 0);
	glEnd();

	//plane wing back
	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3i(80 + viewX1, 225 + viewY1, 0);
	glVertex3i(90 + viewX1, 245 + viewY1, 0);
	glVertex3i(85 + viewX1, 245 + viewY1, 0);
	glVertex3i(50 + viewX1, 225 + viewY1, 0);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3i(80 + viewX1, 225 + viewY1, 0);
	glVertex3i(90 + viewX1, 245 + viewY1, 0);
	glVertex3i(88 + viewX1, 245 + viewY1, 0);
	glVertex3i(55 + viewX1, 225 + viewY1, 0);
	glEnd();

	glColor3ub(0, 0, 255);
	glBegin(GL_POLYGON);
	glVertex3i(90 + viewX1, 220 + viewY1, 0);
	glVertex3i(30 + viewX1, 220 + viewY1, 0);
	glVertex3i(15 + viewX1, 225 + viewY1, 0);
	glVertex3i(35 + viewX1, 235 + viewY1, 0);
	glVertex3i(80 + viewX1, 235 + viewY1, 0);
	glVertex3i(90 + viewX1, 230 + viewY1, 0);
	glEnd();

	glColor3ub(0, 0, 255);
	glBegin(GL_POLYGON);
	glVertex3i(90 + viewX1, 227 + viewY1, 0);
	glVertex3i(30 + viewX1, 227 + viewY1, 0);
	glVertex3i(30 + viewX1, 230 + viewY1, 0);
	glVertex3i(90 + viewX1, 230 + viewY1, 0);
	glEnd();

	glColor3ub(255, 0, 0);//head
	glBegin(GL_POLYGON);
	glVertex3i(90 + viewX1, 220 + viewY1, 0);
	glVertex3i(90 + viewX1, 230 + viewY1, 0);
	glVertex3i(100 + viewX1, 222 + viewY1, 0);
	glVertex3i(100 + viewX1, 220 + viewY1, 0);
	glEnd();

	glColor3ub(0, 220, 0);//glass
	glBegin(GL_POLYGON);
	glVertex3i(80 + viewX1, 225 + viewY1, 0);
	glVertex3i(90 + viewX1, 225 + viewY1, 0);
	glVertex3i(90 + viewX1, 228 + viewY1, 0);
	glVertex3i(78 + viewX1, 237 + viewY1, 0);
	glEnd();

	glColor3ub(255, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3i(80 + viewX1, 225 + viewY1, 0);
	glVertex3i(35 + viewX1, 212 + viewY1, 0);
	glVertex3i(25 + viewX1, 212 + viewY1, 0);
	glVertex3i(50 + viewX1, 225 + viewY1, 0);
	glEnd();


	glutPostRedisplay();

}

void drawCircle(int x1, int y1, int radius)

{
	float x2, y2;
	float angle;
	glBegin(GL_POLYGON);
	for (angle = .1f; angle<361.0f; angle += 1.0f)

	{
		x2 = x1 + sin(angle)*radius;
		y2 = y1 + cos(angle)*radius;
		glVertex2f(x2, y2);
	}

	glEnd();
}



void megh()

{
	glColor3f(0.94, 1.0, 0.94);
	drawCircle(45, 680, 20);
	drawCircle(75, 680, 40);
	drawCircle(90, 680, 45);
	drawCircle(120, 680, 35);
	drawCircle(140, 680, 20);

	drawCircle(200, 670, 25);
	drawCircle(220, 670, 35);
	drawCircle(260, 670, 50);
	drawCircle(290, 670, 35);
	drawCircle(320, 670, 20);

}

void tree()
{
	//right leaf
	glColor3f(0, 0.098, 0);
	drawCircle(1170, 288, 25);
	drawCircle(1190, 344, 45);
	drawCircle(1185, 320, 30);
	drawCircle(1245, 380, 55);
	drawCircle(1238, 310, 25);
	drawCircle(1259, 315, 30);
	drawCircle(1200, 295, 25);

	//left leaf

	glColor3f(0, 0.098, 0);
	drawCircle(956, 364, 20);
	drawCircle(990, 361, 25);
	drawCircle(1046, 361, 25);
	drawCircle(1070, 360, 20);

	glColor3f(0, 0.098, 0);
	drawCircle(980, 400, 25);
	drawCircle(1020, 387, 35);
	drawCircle(1065, 392, 25);

 	glColor3f(0, 0.098, 0);
	drawCircle(999, 440, 30);
	drawCircle(1030, 435, 35);



}

void background()
{
	//*******backgrounds*******
	//back sky ash background
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

	//glRotatef(120, 0.0, 1.0, 1.0); //Rotate the camera
	//glRotatef(30,0.0,1.0,1.0) ;
	//glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units
	//glPushMatrix() ;


	glBegin(GL_QUADS);
	glColor3f(0.70, 0.96, 0.96);
	glVertex2i(0, 420);
	glVertex2i(1277, 420);
	glVertex2i(1277, 780);
	glVertex2i(0, 780);
	glEnd();
	glFlush();

	///back grass left
	glBegin(GL_QUADS);
	glColor3f(0.30, 0.701, 0.235);
	glVertex3i(0, 420,0);
	glVertex3i(0, 80,0);
	glVertex3i(1236, 80,0);
	glVertex3i(625, 420,0);
	glEnd();
	glFlush();



	///back grass right
	glBegin(GL_TRIANGLES);
	glColor3f(0.30, 0.701, 0.235);
	glVertex3i(1277, 117,0);
	glVertex3i(1277, 420,0);
	glVertex3i(600, 420,0);
	glEnd();
	glFlush();

	///river side
  	glBegin(GL_QUADS);
	//glColor3f(0.34, 0.266, 0.19);
	//glColor3f(0.30, 0.701, 0.235);
	glColor3f(0.019, 0.35, 0.65);
	glVertex3i(0, 80,0);
	glVertex3i(0, 50,0);
	glVertex3i(1277, 50,0);
	glVertex3i(1277, 80,0);
	glEnd();
	glFlush();


	///river water
	glBegin(GL_QUADS);
	glColor3f(0.019, 0.35, 0.65);
	glVertex3i(0, 50,0);
	glVertex3i(0, 0,0);
	glVertex3i(1277, 0,0);
	glVertex3i(1277, 50,0);
	glEnd();


	glFlush();
	glPopMatrix() ;
}


void treeBase()
{
	//tree base

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex3i(1230, 304, 0);
	glVertex3i(1230, 169, 0);
	glVertex3i(1260, 169, 0);
	glVertex3i(1260, 304, 0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex3i(1230, 180, 0);
	glVertex3i(1225, 170, 0);
	glVertex3i(1265, 170, 0);
	glVertex3i(1260, 180, 0);
	glEnd();
	glFlush();


	//tree base 2

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex3i(1004, 360, 0);
	glVertex3i(1004, 267, 0);
	glVertex3i(1027, 267, 0);
	glVertex3i(1027, 360, 0);
	glEnd();
	glFlush();

	glBegin(GL_QUADS);
	glColor3f(0.313, 0.321, 0.258);
	glVertex3i(1004, 267, 0);
	glVertex3i(1000, 265, 0);
	glVertex3i(1029, 265, 0);
	glVertex3i(1027, 267, 0);
	glEnd();
	glFlush();

	tree();

}

void Display1(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.5);
	glPointSize(4.0);

	background();

	stand();
	/////////rotatoin
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glScalef(0.7, 0.7, 0.0) ;
	glTranslatef(213.0, 595.0f, 1);
	glRotatef(angle, 0.0f, 0.0f, 1.0f);
	angle = angle - rate;
	glTranslatef(-100.0f, -500.0f, -2.0f);


	windmill();
	glPopMatrix();
	glFlush();


	treeBase();

    glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective

    glTranslatef(0.0,370.0, 0.0) ;
   // glTranslatef(posX, posY, posZ) ;

    plane1() ;

    glPopMatrix( ) ;

	//megh box
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glTranslatef(posX, posY, posZ);
	megh();
	glPopMatrix();

	glutSwapBuffers();

}

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1280.0, 0.0, 768.0);
}

void update(int value)
{
	posX += move_unit;
	if (posX>1000)
	{
		posX -= 1000;
	}
	glutPostRedisplay();
	glutTimerFunc(50, update, 0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1300, 800);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics Project");
	glutDisplayFunc(Display1);
	myInit();
	glutTimerFunc(1000, update, 0);



	glutMainLoop();
}
