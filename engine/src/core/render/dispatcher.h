#pragma once

#include <stdint.h>


typedef struct Canvas_t Canvas_t;

typedef struct Manifest_t{

}Manifest_t;

typedef struct Dispatch_t{
    Manifest_t currentManifest;
}Dispatch_t;



uint8_t Dispatch_Init(Dispatch_t* dispatch);
uint8_t Dispatch_Destroy(Dispatch_t* dispatch);

// Dispatch will start calling sub systems to render the information on the manifest,
uint8_t Dispatch_Run(Dispatch_t* dispatch, const Manifest_t* manifest);

// When no updates were made to the manifest data. dispatch will call using internal copy
uint8_t Dispatch_Send(Dispatch_t* dispatch);

uint8_t Dispatch_NewMesh(Dispatch_t* dispatch, )