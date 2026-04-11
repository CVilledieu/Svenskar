#pragma once
/* Hook in api for root to access core functions

*/

typedef struct {
    SBO_t* sbo;
}EngCore_t;



EngCore_t* Core_Init(void);