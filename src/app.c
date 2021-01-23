#include <raylib.h>

#include "Env/env.c"
#include "Env/Logger/logger.c"
#include "Scene/Manager/scenemanager.c"

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
// Initialize game
static void InitGame(Camera2D * camera, SceneManager * sceneManager);
// Update game (one frame)
static void UpdateGame(Camera2D * camera, SceneManager * sceneManager, float delta);
// Draw game (one frame)
static void DrawGame(Camera2D * camera, SceneManager * sceneManager);
// Unload game
static void UnloadGame(Camera2D * camera, SceneManager * sceneManager); 
// Update and Draw (one frame)
static void UpdateDrawFrame(Camera2D * camera, SceneManager * sceneManager);
// Update camera position
static void UpdateCameraCenter(Camera2D * camera);

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    Camera2D camera = {0};
    SceneManager sceneManager;

    // Initialization (Note windowTitle is unused on Android)
    //---------------------------------------------------------
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_NAME);
    
    SetTraceLogCallback(logger);
    InitGame(&camera, &sceneManager);

    SetTargetFPS(GAME_FPS);
    //--------------------------------------------------------------------------------------
    
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update and Draw
        //----------------------------------------------------------------------------------
        UpdateDrawFrame(&camera, &sceneManager);
        //----------------------------------------------------------------------------------
    }
    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadGame(&camera, &sceneManager);     // Unload loaded data (textures, sounds, models...)
    
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

// Initialize game variables
void InitGame(Camera2D * camera, SceneManager * sceneManager) {
    InitAudioDevice();

    SceneManager_init(sceneManager);

    // INIT CAMERA
    UpdateCameraCenter(camera);
    camera->rotation = 0.0f;
    camera->zoom = 0.5f;
}

// Update game (one frame)
void UpdateGame(Camera2D * camera, SceneManager * sceneManager, float delta) {
    SceneManager_update(sceneManager, delta);
}

// Draw game (one frame)
void DrawGame(Camera2D * camera, SceneManager * sceneManager) {
    BeginDrawing();
        ClearBackground(BLACK);
        SceneManager_draw(sceneManager);
    EndDrawing();
}

// Unload game
void UnloadGame(Camera2D * camera, SceneManager * sceneManager) {
    CloseAudioDevice();
}

// Update and Draw (one frame)
void UpdateDrawFrame(Camera2D * camera, SceneManager * sceneManager)
{
    UpdateGame(camera, sceneManager, GetFrameTime());
    DrawGame(camera, sceneManager);
}

void UpdateCameraCenter(Camera2D * camera)
{
    camera->target = (Vector2){ GetScreenWidth()/2, GetScreenHeight()/2 }; // Use Player Position
    camera->offset = (Vector2){ GetScreenWidth()/2, GetScreenHeight()/2 };
}
