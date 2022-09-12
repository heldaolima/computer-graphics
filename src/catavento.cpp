#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>


/*
A lógica do programa do programa é fazer o efeito de catavento
trocando as cores das pétalas sempre que o usuário pressiona 
a tecla espaço
*/


float south[3] = {1.0, 1.0, 1.0}; //começa branco 
float east[3] = {0.0, 0.0, 1.0}; //começa azul
float north[3] = {0.0, 1.0, 0.0}; //começa verde
float west[3] = {1.0, 0.0, 0.0}; //começa vermelho

void init (void){
  /* selecionar cor de fundo (preto) */
  glClearColor (0.0, 0.0, 0.0, 0.0);

  glMatrixMode (GL_PROJECTION); //Projecao 2D

  glOrtho(0.0, 500.0, 0.0, 400.0, -1.0, 1.0); //Definindo os limites da Porta de Visao (ViewPort)

}


void displayFcn(void){
   /* Limpar todos os pixels  */
   glClear (GL_COLOR_BUFFER_BIT);

   glColor3f (1.0, 1.0, .0);
   glBegin(GL_POLYGON);
   	   glVertex3f (249.0f, 250.0f, -1.0f);
       glVertex3f (251.0f, 250.0f, -1.0f);
       glVertex3f (249.0f, 100.0f, -1.0f);
       glVertex3f (251.0f, 100.0f, -1.0f);
   glEnd();

   /* Desenhar um polígono branco  */
   glColor3f (south[0], south[1], south[2]);
     glBegin(GL_TRIANGLES);
      glVertex2f (250.0f, 250.0f);
      glVertex2f (230.0f, 200.0f);
      glVertex2f (270.0f, 200.0f);
   glEnd();

   /* Desenhar um polígono vermelho */
   glColor3f (west[0], west[1], west[2]);
   glBegin(GL_TRIANGLES);
      glVertex2f (250.0f, 250.0f);
      glVertex2f (300.0f, 230.0f);
      glVertex2f (300.0f, 270.0f);
   glEnd();

   /* Desenhar um polígono verde */
   glColor3f (north[0], north[1], north[2]);
   glBegin(GL_TRIANGLES);
      glVertex2f (250.0f, 250.0f);
      glVertex2f (230.0f, 300.0f);
      glVertex2f (270.0f, 300.0f);
   glEnd();

   /* Desenhar um polígono vermelho */
   glColor3f (east[0], east[1], east[2]);
   glBegin(GL_TRIANGLES);
      glVertex2f (250.0f, 250.0f);
      glVertex2f (200.0f, 270.0f);
      glVertex2f (200.0f, 230.0f);
   glEnd();


   /* Não esperar! */
   glFlush ();
}


void handleSpace(unsigned char key, int x, int y) {
    switch (key){
    case 32: //space
        float southAux[3], eastAux[3], northAux[3], westAux[3]; 
        
        // inicializa arrays auxiliares
        for (int i = 0; i < 3; i++) {
            southAux[i] = south[i];
            eastAux[i] = east[i];
            northAux[i] = north[i];
            westAux[i] = west[i];
        }
        
        // troca os valores dos arrays em sentido horário
        for (int i = 0; i < 3; i++) {
            south[i] = westAux[i];
            east[i] = southAux[i];
            north[i] = eastAux[i];
            west[i] = northAux[i];  
        }
        break;
    
    default: break;
    }
}



int main(int argc, char** argv) {
    std::cout << "Press space!\n";
	glutInit(&argc, argv);

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (500, 400);
	glutInitWindowPosition (200, 200);
	glutCreateWindow ("Catavento");

	init();

	glutIdleFunc(displayFcn);
    glutKeyboardFunc(handleSpace);

	glutMainLoop();
	return 0;

}
