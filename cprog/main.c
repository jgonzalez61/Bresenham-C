
/*
Jose Gonzalez
Cs3600
 
Use  OpenGl and GLUT frameworks, import to Xcode or favorite IDE.
This code was run and tested in  Xcode version 9.3
Algorithm from LeArn_MorE
 
This program implements the Bresenham's algorighm to draw a line.
When this program is executed, the user will be asked for imput.
The input shuld be in the format <x> <y>, whre x and y are integer values
representing the canvas dimenstions. I suggest usig values bigger that 400
and smaller than 1000 for x and y. In short the program does the following
 
 1. ask for kanvas dimensions, format <x> <y>
 2. ask for srtart coordinates,format <x> <y>
 3. ask for finish coordinates,format <x> <y>
    (end coordinates > start coordinates)
 4. execute Bresenhams algorithm
 5. Ouput interpreted line
 
 User must see a window named canvas with the line.
 Don't draw outside canvas
*/

#include <OpenGL/OpenGL.h>
#include <GLUT/GLUT.h>

//declared functions
void display(void);
void init (void);

//Global variables type int to store coordinates and other atributes.
int x1, Y1, x2, y2, p, i,step,x, y, Dx, Dy, xcanvas, ycanvas;

//main funcion
int main(int argc, char** argv)
{
    printf("Enter canvas size, format x y >> ");
    scanf("%d %d", &xcanvas, &ycanvas);//get canvas size stores in int variables
    printf("Enter the start coordinates, format x y >> ");
    scanf("%d %d", &x1, &Y1);//get and store  int variables
    printf("Enter the End coordinates, format x y >> ");
    scanf("%d %d", &x2, &y2);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (xcanvas, ycanvas);// sets canvas size desired by the user
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Canvas");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    
    
    return 0;
}

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
        glColor3f(0,0,255);//set line color RGB
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


