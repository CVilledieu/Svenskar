#pragma once
/* Hook in api for root to access core functions

*/

typedef struct {
    RenderSystem_t* renderSys;
}EngCore_t;



EngCore_t* Core_Init(void);