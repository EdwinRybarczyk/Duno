#pragma once
#include <GLFW\glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

namespace Duno2{namespace Graphics{


	class Display {
	private:
		GLFWwindow* m_window;



	public:

		void createDisplay();
		void updateDisplay();
		void closeDisplay();

		/*
		/* Create a windowed mode window and its OpenGL context 
		window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return -1;
		}

		/* Make the window's context current 
		glfwMakeContextCurrent(window);

		/* Loop until the user closes the window 
		while (!glfwWindowShouldClose(window))
		{
			/* Render here 
			glClear(GL_COLOR_BUFFER_BIT);

			/* Swap front and back buffers 
			glfwSwapBuffers(window);

			/* Poll for and process events 
			glfwPollEvents();
		}

		glfwTerminate();
		return 0;
		*/

	};
} }
