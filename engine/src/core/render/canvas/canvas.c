#include "canvas.h"


static void ResizeCallBackCanvas(GLFWwindow* window, int width, int height){
    (void)window;
    glViewport(0, 0, width, height);
}



uint8_t DisplayCanvas(Canvas_t* canvas){
    if(!canvas){
        return 0;
    }
    //Reminder to add Context binding if multiple canvas support is added.
    //glfwMakeContextCurrent(canvas);
    
    glfwShowWindow(canvas);

    return 1;
}



uint8_t NewCanvas(Canvas_t* canvas, int width, int height, const char* title){
    if(!canvas || !glfwInit()){
        return 0;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

    canvas = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(canvas);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        return 0;
    }

    glfwSetFramebufferSizeCallback(canvas, ResizeCallBackCanvas);

    return 1;
}
