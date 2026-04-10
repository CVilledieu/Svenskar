#pragma once
/* Hook in api for root to access core functions

*/

typedef struct {
    EngRenderer_t renderer;
}EngCore_t;



EngCore_t* Core_Init(void);