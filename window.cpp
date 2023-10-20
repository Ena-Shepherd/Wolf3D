#include <stdio.h>
#include <stdlib.h>

#include <SFML/OpenGL.hpp>
// Include GLEW
// #include <GL/glew.h>

// Include GLFW
// #include <GLFW/glfw3.h>

// GLFWwindow* window;

// Include GLM
// #include <glm/glm.hpp>
// using namespace glm;

int draw_window(void)
{
	// Initialise GLFW
	if( !gl_Init() )
	{
		fprintf( stderr, "Failed to initialize GLFW\n" );
		getchar();
		return -1;
	}

	// gl_WindowHint(GLFW_SAMPLES, 4);
	// gl_WindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// gl_WindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// gl_WindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	// gl_WindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Open a window and create its OpenGL context
	// window = gl_CreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);
	// if( window == NULL ){
	// 	fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
	// 	getchar();
	// 	gl_Terminate();
	// 	return -1;
	// }
	// gl_MakeContextCurrent(window);

	// Initialize GLEW
	// if (glewInit() != GLEW_OK) {
	// 	fprintf(stderr, "Failed to initialize GLEW\n");
	// 	getchar();
	// 	gl_Terminate();
	// 	return -1;
	// }

	// Ensure we can capture the escape key being pressed below
	//gl_SetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Dark blue background
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);

	do{
		// Clear the screen. It's not mentioned before Tutorial 02, but it can cause flickering, so it's there nonetheless.
		glClear( GL_COLOR_BUFFER_BIT );

		// Draw nothing, see you in tutorial 2 !

		
		// Swap buffers
		gl_SwapBuffers(window);
		gl_PollEvents();

	} // Check if the ESC key was pressed or the window was closed
	while( gl_GetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   gl_WindowShouldClose(window) == 0 );

	// Close OpenGL window and terminate GLFW
	//gl_Terminate();

	return 0;
}