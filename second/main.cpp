#include "../HEADER_H.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
using namespace glm;
int main(int argc, char *argv[])
{
   if( !glfwInit() ) {
    fprintf( stderr, "Error al inicializar GLFW\n" );
    return -1;
   }

   glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Queremos OpenGL 3.3
glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Para hacer feliz a MacOS ; Aunque no debería ser necesaria
glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //No queremos el viejo OpenGL 

//Crear una ventana y su contexto OpenGL
GLFWwindow* window; // (En el código que viene aqui, está variable es global)
window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
if( window == NULL ){
    fprintf( stderr, "Falla al abrir una ventana GLFW. Si usted tiene una GPU Intel, está no es compatible con 3.3. Intente con la versión 2.1 de los tutoriales.\n" );
    glfwTerminate();
    return -1;
}
glfwMakeContextCurrent(window); // Inicializar GLEW
glewExperimental=true; // Se necesita en el perfil de base.
if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Falló al inicializar GLEW\n");
    return -1;
}

while(1);
    return 0;
}
