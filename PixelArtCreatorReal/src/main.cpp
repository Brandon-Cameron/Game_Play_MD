#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

#define MAX_RECTS 10000

typedef struct Rect {
    Vector2 position;
    float width;
    float height;
    Color color;
} Rect;

const int cellWidth = 20;
const int cellHeight = 20;

const int canvasWidth = 600;
const int canvasHeight = 600;

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "Simple Drawing Package - Rectangle Mode");

    RenderTexture2D canvas = LoadRenderTexture(canvasWidth, canvasHeight);

    // Variables
    Rect rectangles[MAX_RECTS];
    int rectCount = 0;
    Color currentColor = BLACK;  // Default color for drawing rectangles
    Vector2 rectStart = { 0 };
    bool drawing = false;

    // Define a simple color palette
    Color palette[] = { BLACK, RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, MAROON };
    int paletteSize = sizeof(palette) / sizeof(palette[0]);
    int selectedColor = 0;
    int colorNo = 0;

    SetTargetFPS(60);

    BeginTextureMode(canvas);
    ClearBackground(WHITE);
    EndTextureMode();



    // Main game loop
    while (!WindowShouldClose()) {
        // Update
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            // Start a new rectangle
            rectStart = GetMousePosition();
            if (rectCount < MAX_RECTS) {
                Vector2 rectEnd = GetMousePosition();

                rectangles[rectCount].position.x = rectStart.x;
                rectangles[rectCount].position.y = rectStart.y;
                rectangles[rectCount].width = 20;
                rectangles[rectCount].height = 20;
                rectangles[rectCount].color = currentColor;
                rectCount++;
            }
        }


        // Change color based on palette selection
        for (int i = 0; i < paletteSize; i++) {
            Rectangle colorButton = { 10 + 40 * i, screenHeight - 40, 30, 30 };
            if (GuiButton(colorButton, "")) {
                currentColor = palette[i];
                selectedColor = i;
            }
        }

        // Draw
        BeginDrawing();
        ClearBackground(DARKGRAY);

        //DrawRectangle(100, 100, canvasWidth, canvasHeight, BLANK);
        DrawTextureRec(canvas.texture, Rectangle { 0, 0, (float)canvas.texture.width, (float)-canvas.texture.height }, Vector2{ 100, 100 }, WHITE);
        //DrawTexture(canvas.texture, 0, 0, WHITE);

        for (int i = 5; i < 35; i++)
        {
            for (int j = 5; j < 35; j++)
            {
                DrawRectangleLines(i * cellWidth, j * cellHeight, cellWidth, cellHeight, BLACK);
            }
        }

        // Draw the palette buttons
        for (int i = 0; i < paletteSize; i++) {
            Rectangle colorButton = { 10 + 40 * i, screenHeight - 40, 30, 30 };
            DrawRectangleRec(colorButton, palette[i]);
            if (i == selectedColor) {
                DrawRectangleLinesEx(colorButton, 2, BLACK);  // Highlight selected color
            }
        }

        // Draw all stored rectangles
        for (int i = 0; i < rectCount; i++) {
            DrawRectangleRec({ rectangles[i].position.x, rectangles[i].position.y, rectangles[i].width, rectangles[i].height }, rectangles[i].color);
        }

        // Draw the current rectangle if drawing


        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
/*#include "raylib.h"

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Draw Rectangles from Array");

    // Define an array of 5 rectangles with different positions, sizes, and colors
    Rectangle rectangles[5] = {
        {100, 100, 120, 60},
        {300, 150, 80, 120},
        {500, 200, 140, 50},
        {200, 400, 90, 90},
        {600, 300, 110, 70}
    };

    Color colors[5] = { RED, GREEN, BLUE, YELLOW, PURPLE };  // Colors for each rectangle

    SetTargetFPS(60);  // Set the frame rate

    // Main game loop
    while (!WindowShouldClose()) {
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Loop through the array and draw each rectangle with its respective color
        for (int i = 0; i < 5; i++) {
            DrawRectangleRec(rectangles[i], colors[i]);
        }

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
*/