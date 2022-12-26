#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

void displayFcn()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0f, 0.0f, 0.0f);
    glRectf(-0.50f, 0.25f, 0.25f, -0.25f);
    
    glColor3f(0.0f, 1.0f, 0.0f);
    glRectf(0.0f, 0.25f, 0.75f, 0.5f);
    
    glColor3f(0.0f, 0.0f, 1.0f);
    glRectf(0.0f, 0.25f, 0.75f, 0.5f);

    glFlush();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow ("Catavento");

	glutIdleFunc(displayFcn);
	init();
	glutMainLoop();

	return 0;
}
