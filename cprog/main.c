
/*
Jose Gonzalez
Cs3600
Use  OpenGl and GLUT frameworks, import in Xcode
Algorithm from LeArn_MorE
*/

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

int x1, Y1, x2, y2, p, i,step,x, y, Dx, Dy, nlines;
void display(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    
    Dy = y2-Y1;
    Dx = x2-x1;
    x = x1;
    y = Y1;
    step=Dx;
    p = 2*Dy - Dx;
    for(i = 0; i<step; i++){
        glColor3f(3,3,3);
        glBegin(GL_POINTS);
        if(p<0){
            x++;
            glVertex2d(x, y);
            p = p + 2*Dy;
        }
        else{
            x++;
            y++;
            glVertex2d(x, y);
            p = p+ 2*Dy - 2*Dx;
        }
        glEnd();
    }
    glFlush();
}
void init (void)
{
    /* select clearing (background) color */
    glClearColor (0, 0, 0, 0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 600);
}

int main(int argc, char** argv)
{
  
    printf("Enter the start point ");
    scanf("%d %d", &x1, &Y1);
    printf("Enter the End point ");
    scanf("%d %d", &x2, &y2);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Canvas");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    
    
    return 0; /* ISO C requires main to return int. */
}
