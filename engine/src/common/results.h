#pragma once

#include <stdint.h>




typedef enum SEErrorCode_t {
    SE_OK = 0,
    SE_ERR_NULL_PTR,
    SE_ERR_ALLOC_FAILED,
    SE_ERR_GL_BUFFER,
    SE_ERR_GL_SHADER,
    SE_ERR_FILE_NOT_FOUND,
    SE_ERR_BUFFER_OVERFLOW,
    // ...
} SEErrorCode_t;

typedef struct SEResult_t {
    uint8_t       ok;
    SEErrorCode_t code;
} SEResult_t;


// _Thread_local struct { SEErrorCode_t code; const char* func; const char* msg; } g_seLastError;

// #define SE_FAIL(err_code, err_msg) \
//     (g_seLastError = (typeof(g_seLastError)){(err_code), __func__, (err_msg)}, \
//      (SEResult_t){0, (err_code)})

// #define SE_SUCCESS ((SEResult_t){1, SE_OK})