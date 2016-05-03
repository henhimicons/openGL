// LaborTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <GL/glut.h>
#define _TCHAR char
static int shoulderz = 0, elbow = 0,shouldery=0;
void init(){
	glClearColor(0.0,0.0,0.0,0.0);
	glShadeModel(GL_FLAT);
}
void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0, (GLfloat)w / (GLfloat)h,1.0,20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);
}
void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();

	glTranslatef(-1.0, 0.0, 0.0);
	glRotatef((GLfloat)shoulderz,0.0,0.0,1.0);
    glRotatef((GLfloat)shouldery, 0.0, 1.0, 0.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();

	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glTranslatef(1.0, 0.0, 0.0);
	glRotatef((GLfloat)elbow,0.0,0.0,1.0);
	glTranslatef(1.0, 0.0, 0.0);
	glPushMatrix();

	glScalef(2.0, 0.4, 1.0);
	glutWireCube(1.0);
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key){
	    case 's':
			shoulderz = (shoulderz + 5) % 360;
			if (shoulderz >= 90) shoulderz = 90;
			glutPostRedisplay();
			break;
		case 'S':
			shoulderz = (shoulderz - 5) % 360;
			if (shoulderz <= - 90) shoulderz = -90;
			glutPostRedisplay();
			break;
		case 'e':
			elbow = (elbow + 5) % 360;
			if (elbow >= 180) elbow = 180;
			glutPostRedisplay();
			break;
		case 'E':
			elbow = (elbow - 5) % 360;
			if (elbow <= -180) elbow = -180;
			glutPostRedisplay();
			break;
		case 'y':
			shouldery = (shouldery + 5) % 360;
			if (shouldery >= 90) shouldery = 90;
			glutPostRedisplay();
			break;
		case 'Y':
            shouldery = (shouldery - 5) % 360;
			if (shouldery <= -90) shouldery = -90;
			glutPostRedisplay();
			break;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
