#include<Windows.h>
#include<GL/glut.h>

int is_depth;

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil2(void) {
	//depan2
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-55.0, -10.0, 5.0);
	glVertex3f(-55.0, 10.0, 5.0);
	glVertex3f(-10, 10.0, 5.0);
	glVertex3f(-10.0, -10.0, 5.0);
	glEnd();

	//BAWAH2
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(-55, -10.0, 5.0);
	glVertex3f(-10, -10.0, 5.0);
	glVertex3f(-10, -10.0, -15.0);
	glVertex3f(-55, -10.0, -15.0);
	glEnd();
	glPushMatrix();
	glPopMatrix();
}

void tampil(void) {
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	//DEPAN
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-10.0, -10.0, 10.0);
	glVertex3f(-10, 10.0, 10.0);
	glVertex3f(35.0, 10.0, 10.0);
	glVertex3f(35.0, -10.0, 10.0);
	glEnd();

	//BELAKANG	
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-10.0, -10.0, -10.0);
	glVertex3f(-10.0, 10.0, -10.0);
	glVertex3f(35.0, 10.0, -10.0);
	glVertex3f(35.0, -10.0, -10.0);
	glEnd();

	//KANAN
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(10.0, 10.0, 10.0);
	glVertex3f(10.0, -10.0, 10.0);
	glVertex3f(10.0, -10.0, -10.0);
	glVertex3f(10.0, 10.0, -10.0);
	glEnd();

	//KIRI	
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-10, 10.0, 10.0);
	glVertex3f(-10, -10.0, 10.0);
	glVertex3f(-10, -10.0, -10.0);
	glVertex3f(-10, 10.0, -10.0);
	glEnd();

	//ATAS
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-10, 10.0, 10.0);
	glVertex3f(35, 10.0, 10.0);
	glVertex3f(35, 10.0, -10.0);
	glVertex3f(-10, 10.0, -10.0);
	glEnd();

	//BAWAH
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(-10, -10.0, 10.0);
	glVertex3f(35, -10.0, 10.0);
	glVertex3f(35, -10.0, -10.0);
	glVertex3f(-10, -10.0, -10.0);
	glEnd();

	tampil2();
	glPushMatrix();
	glPopMatrix();
	glutSwapBuffers();

}

void keyboard(unsigned char key, int x, int y) {
	switch (key) {

	case 's':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;

	case 'w':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;

	case 'd':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;

	case 'a':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;

	case 'q':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;

	case 'e':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;

	case 'x':
		if (is_depth) {
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else {
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	tampil();
}

void key(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_PAGE_UP:
		glTranslatef(0.0, 0.0, 3.0);
		break;

	case GLUT_KEY_PAGE_DOWN:
		glTranslatef(0.0, 0.0, -3.0);
		break;

	case GLUT_KEY_RIGHT:
		glTranslatef(3.0, 0.0, 0.0);
		break;

	case GLUT_KEY_LEFT:
		glTranslatef(-3.0, 0.0, 0.0);
		break;

	case GLUT_KEY_UP:
		glTranslatef(0.0, 3.0, 0.0);
		break;

	case GLUT_KEY_DOWN:
		glTranslatef(0.0, -3.0, 0.0);
		break;
	}
	tampil();

}

void ukuran(int lebar, int tinggi) {
	if (tinggi == 0) tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(100.0, lebar / tinggi, 5.0, 500.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("3D");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(key);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}