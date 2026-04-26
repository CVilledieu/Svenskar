#include "world/camera_sys/camera.h"
#include <cglm.h>




uint8_t Camera_Init(CameraSys_t* cam){
    if(!cam){
        return 0;
    }

    cam = (CameraSys_t*)malloc(sizeof(CameraSys_t));
    SetIdentityMatrix(cam->projection, 16);
    SetIdentityMatrix(cam->view, 16);

    return 1;
}