#include "lve_window.hpp"

namespace lve {

	LveWindow::LveWindow(int w, int h, std::string name) : width{ w }, height{ h }, windowName{ name } {
		initWindow();
	}

	//Coiso para destruir quando terminar
	LveWindow::~LveWindow() {
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void LveWindow::initWindow() {
		glfwInit();
		// Normalmente GLFW cria um contexto opengl quando cria uma janela, mas ja que não usamos
		//		o opengl então não precisa
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		// Isso desavita resize, vamos resolver isso depois
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr);
	}



}