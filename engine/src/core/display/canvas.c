#include "display/canvas.h"

static void ResizeCallBackCanvas(GLFWwindow* window, int width, int height){
    (void)window;
    glViewport(0, 0, width, height);
}



void Canvas_Shutdown(Canvas_t* canvas){
    if(!canvas){
        return;
    }

    glfwDestroyWindow(canvas);

}



uint8_t Canvas_Hide(Canvas_t* canvas){
    if(!canvas){
        return 0;
    }



    return 1;
}



uint8_t Canvas_Show(Canvas_t* canvas){
    if(!canvas){
        return 0;
    }
    //Reminder to add Context binding if multiple canvas support is added.
    //glfwMakeContextCurrent(canvas);
    
    glfwShowWindow(canvas);

    return 1;
}





Canvas_t* Canvas_Init(int width, int height, const char* title){
    if(!glfwInit() || !width || !height){
        return NULL;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


    glfwWindowHint(GLFW_VISIBLE, GL_FALSE);

    Canvas_t* canvas = glfwCreateWindow(width, height, title, NULL, NULL);
    glfwMakeContextCurrent(canvas);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        return NULL;
    }

    glfwSetFramebufferSizeCallback(canvas, ResizeCallBackCanvas);

    return canvas;
}
