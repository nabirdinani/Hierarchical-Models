//NABIR DINANI

#include <GLUT/GLUT.h>
#include <math.h>

#define PI 3.1415926535897

static int shoulder = 0, elbow = 0;

static int head_Roll = 0;
static int head_Pitch = 0;

static GLdouble x_Pos = 0.0;
static GLdouble y_Pos = 0.0;
static GLdouble z_Pos = 15.0;

static GLdouble rho = 15.0;
static GLdouble theta = 0;
static GLdouble phi = 0;

//distance panned from not panned position
static GLdouble x_Pan = 0;
static GLdouble y_Pan = 0;
static GLdouble z_Pan = 0;

static GLdouble x_Mouse = 0;
static GLdouble y_Mouse = 0;

static int width;
static int height;

static GLdouble zoom = 70;  //Lower the value, the larger the zoom

static int upper_arm1 = 15;
static int upper_arm2 = 15;
static int upper_arm3 = 15;
static int upper_arm4 = 15;
static int upper_arm5 = 15;
static int upper_arm6 = 15;

static int fore_arm1 = -100;
static int fore_arm2 = -100;
static int fore_arm3 = -100;
static int fore_arm4 = -100;
static int fore_arm5 = -100;
static int fore_arm6 = -100;

void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_FLAT);
}

void display(void)
{

    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    
    //body
    glTranslatef(0.0, 0.0, 2.0);
    glPushMatrix();
    glScalef(4.0, 2.5, 4.5);
    glColor3f(1.0, 0.0, 0.0);
    glutSolidSphere(.6, 25, 25);
    glPopMatrix();
    
    //head
    glTranslatef(0.0, 0.0, 4.0);
    glPushMatrix();
    glScalef(2.2, 2.0, 2.5);
    glColor3f(1.0, 1.0, 0.0);
    glutSolidSphere(.6, 25, 25);
    glPopMatrix();
    
    //eye right
    glTranslatef(0.5, 0.2, 1.0);
    glPushMatrix();
    glScalef(0.8, 0.8, 0.8);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(.2, 25, 25);
    glPopMatrix();
    
    //eye left
    glTranslatef(-1.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.8, 0.8, 0.8);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidSphere(.2, 25, 25);
    glPopMatrix();
    
    //right up first
    glTranslatef(3.0, 0.0, -3.2);
    glPushMatrix();
    glScalef(5.0, 0.3, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //right up second
    glTranslatef(0.0, 0.0, -1.8);
    glPushMatrix();
    glScalef(5.0, 0.3, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //right up third
    glTranslatef(0.0, 0.0, -1.5);
    glPushMatrix();
    glScalef(5.0, 0.3, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //left up first
    glTranslatef(-5.0, 0.0, 0.0);
    glPushMatrix();
    glScalef(5.0, 0.3, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //left up second
    glTranslatef(0.0, 0.0, 1.8);
    glPushMatrix();
    glScalef(5.0, 0.3, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();

    //left up third
    glTranslatef(0.0, 0.0, 1.5);
    glPushMatrix();
    glScalef(5.0, 0.3, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //cover right 1
    glTranslatef(6.2, 0.0, 0.0);
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    glColor3f(1.3, 1.0, 1.0);
    glutSolidSphere(.8, 25, 25);
    glPopMatrix();
    
    //cover right 2
    glTranslatef(0.0, 0.0, -1.8);
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    glColor3f(1.3, 1.0, 1.0);
    glutSolidSphere(.9, 25, 25);
    glPopMatrix();
    
    //cover right 3
    glTranslatef(0.0, 0.0, -1.5);
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    glColor3f(1.3, 1.0, 1.0);
    glutSolidSphere(.9, 25, 25);
    glPopMatrix();
    
    
    //cover left 1
    glTranslatef(-7.5, 0.0, 3.3);
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    glColor3f(1.3, 1.0, 1.0);
    glutSolidSphere(.9, 25, 25);
    glPopMatrix();
    
    //cover left 2
    glTranslatef(0.0, 0.0, -1.5);
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    glColor3f(1.3, 1.0, 1.0);
    glutSolidSphere(.9, 25, 25);
    glPopMatrix();
    
    //cover left 3
    glTranslatef(0.0, 0.0, -1.8);
    glPushMatrix();
    glScalef(0.3, 0.3, 0.3);
    glColor3f(1.3, 1.0, 1.0);
    glutSolidSphere(.9, 25, 25);
    glPopMatrix();
    
    //right down first
    glTranslatef(7.5, -1.7, 3.3);
    glPushMatrix();
    glScalef(0.3, 7.0, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //right down second
    glTranslatef(0.0, 0.0, -1.8);
    glPushMatrix();
    glScalef(0.3, 7.0, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //right down third
    glTranslatef(0.0, 0.0, -1.5);
    glPushMatrix();
    glScalef(0.3, 7.0, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //left down first
    glTranslatef(-7.5, 0.0, 3.3);
    glPushMatrix();
    glScalef(0.3, 7.0, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //left down second
    glTranslatef(0.0, 0.0, -1.5);
    glPushMatrix();
    glScalef(0.3, 7.0, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    //left down third
    glTranslatef(0.0, 0.0, -1.8);
    glPushMatrix();
    glScalef(0.3, 7.0, 0.5);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidCube(0.5);
    glPopMatrix();
    
    
    glPopMatrix();
    glutSwapBuffers();
}

void reshape (int w, int h)
{
    width = w;
    height = h;
    
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(zoom, (GLfloat)w / (GLfloat)h, 0.5, 20.0);   // Can be changed to alter viewpoint maybe
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    GLfloat val1 = x_Pos;
    GLfloat val2 = y_Pos;
    GLfloat val3 = z_Pos;
    GLfloat val4 = x_Pan;
    GLfloat val5 = y_Pan;
    GLfloat val6 = z_Pan;
    
    gluLookAt(val1, val2, val3, val4, val5, val6, 0, 1, 0);
}

void newViewpoint()
{
    GLfloat val_phi = (phi * PI) / 180;
    GLfloat val_theta = (theta * PI) / 180;
    
    x_Pos = rho * cos(val_phi) * sin(val_theta) + x_Pan;
    y_Pos = rho * sin(val_phi) + y_Pan;
    z_Pos = rho * cos(val_phi) * cos(val_theta) + z_Pan;
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    GLfloat val1 = x_Pos;
    GLfloat val2 = y_Pos;
    GLfloat val3 = z_Pos;
    GLfloat val4 = x_Pan;
    GLfloat val5 = y_Pan;
    GLfloat val6 = z_Pan;
    
    gluLookAt(val1, val2, val3, val4, val5, val6, 0, 1, 0);
    
    glutPostRedisplay();
}

void keyboard (unsigned char key, int x, int y)
{
    switch (key) {
        case 's':   /*  s key rotates at shoulder  */
            shoulder = (shoulder + 5) % 360;
            glutPostRedisplay();
            break;
        case '1':
            if (upper_arm1 < 50){
                
                upper_arm1 = (upper_arm1 + 5) % 360;
                glutPostRedisplay();
            }
            break;
        case 'S':
            shoulder = (shoulder - 5) % 360;
            glutPostRedisplay();
            break;
        case 'e':  /*  e key rotates at elbow  */
            elbow = (elbow + 5) % 360;
            glutPostRedisplay();
            break;
        case 'E':
            elbow = (elbow - 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':
            
            theta = theta + 10;
            
            newViewpoint();
            
            break;
        case 'a':
            
            theta = theta - 10;
            
            newViewpoint();
            
            break;
        case 'w':
            if (phi + 10 < 90){
                
                phi = phi + 10;
                
                newViewpoint();
            }
            break;
        case 'z':
            if (phi - 10 > -90){
                
                phi = phi - 10;
                
                newViewpoint();
            }
            break;
        default:
            break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (1000, 1000);
    glutInitWindowPosition (100, 100);
    glutCreateWindow (argv[0]);
    init ();
    glEnable(GL_DEPTH_TEST); //Z-buffer.
    glEnable(GL_CULL_FACE); //backface culling.
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}