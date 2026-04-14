#pragma once

#include "graphics/render.h"
#include "modules/game_app/hook.h"

typedef struct EngineCore_t{
    AppHook_t appHook;
    GraphicsEngine_t renderer;
}EngineCore_t;

