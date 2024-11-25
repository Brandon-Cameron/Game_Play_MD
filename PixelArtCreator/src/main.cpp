#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include <iostream>
#include <algorithm>

#define MAX_RECTS 10000

typedef struct Rect {
    Vector2 position;
    float width;
    float height;
    Color color;
} Rect;

const int cellSize = 20;

const int canvasWidth = 600;
const int canvasHeight = 600;

const int canvasOffset = 100;

void saveImage(Texture2D t_texture)
{
    Image image = LoadImageFromTexture(t_texture);
    ImageFlipVertical(&image);
    ExportImage(image, "test.png");
    UnloadImage(image);
    std::cout << "save" << "\n";
}

Texture2D loadTexture()
{
    Texture2D t_texture;
    Image image = LoadImage("test.png");
    ImageFlipVertical(&image);
    t_texture = LoadTextureFromImage(image);
    std::cout << "load" << "\n";
    return t_texture;
}

void drawPixel(int& t_rectCount, Rect t_rectangles[], Color t_currentColor = WHITE)
{
    Vector2 t_rectStart = GetMousePosition();
    if (t_rectCount < MAX_RECTS) {
        int pixelX = t_rectStart.x / cellSize;
        int pixelY = t_rectStart.y / cellSize;

        Vector2 rectEnd = GetMousePosition();

        t_rectangles[t_rectCount].position.x = (cellSize * pixelX) - 100;
        t_rectangles[t_rectCount].position.y = (cellSize * pixelY) - 100;
        t_rectangles[t_rectCount].width = cellSize;
        t_rectangles[t_rectCount].height = cellSize;
        t_rectangles[t_rectCount].color = t_currentColor;

        t_rectCount++;
    }
}

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
   // Color palette[] = { BLACK, RED, GREEN, BLUE, YELLOW, ORANGE, PURPLE, MAROON };
    Color palette[] = { BLACK, DARKGRAY, LIGHTGRAY, GRAY, YELLOW, GOLD, ORANGE, PINK, RED, MAROON, GREEN, LIME, DARKGREEN, SKYBLUE, BLUE, DARKBLUE, PURPLE, VIOLET, DARKPURPLE, BEIGE, BROWN, DARKBROWN };
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
            if ((GetMousePosition().x >= canvasOffset && GetMousePosition().x < (canvasWidth + canvasOffset)) && (GetMousePosition().y >= canvasOffset && GetMousePosition().y < (canvasWidth + canvasOffset)))
            {
                drawPixel(rectCount, rectangles, currentColor);
            }
        }

        if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT))
        {
            if ((GetMousePosition().x >= canvasOffset && GetMousePosition().x < (canvasWidth + canvasOffset)) && (GetMousePosition().y >= canvasOffset && GetMousePosition().y < (canvasWidth + canvasOffset)))
            {
                drawPixel(rectCount, rectangles);
            }
        }

        // Change color based on palette selection
        int paletteNo = 0;

        for (int i = 0; i < 2; i++) {
           /* Rectangle colorButton = { 10 + 40 * i, screenHeight - 40, 30, 30 };
            if (GuiButton(colorButton, "")) {
                currentColor = palette[i];
                selectedColor = i;
            }*/
            for (int j = 0; j < 11; j++)
            {
                Rectangle colorButton = { 185 + 40 * j, screenHeight - 80 + (40 * i), 30, 30};
                if (GuiButton(colorButton, "")) {
                    currentColor = palette[paletteNo];
                    selectedColor = paletteNo;
                }
                paletteNo++;
            }
        }

        Rectangle saveButton = { 20, 20, 80, 60 };
        if (GuiButton(saveButton, GuiIconText(ICON_FILE_SAVE_CLASSIC, "SAVE")))
        {
            saveImage(canvas.texture);
        }

        Rectangle loadButton = { 700, 20, 80, 60 };
        if (GuiButton(loadButton, GuiIconText(ICON_FILE_OPEN, "LOAD")))
        {
            BeginTextureMode(canvas);
            ClearBackground(WHITE);
            EndTextureMode();
            //canvas.texture = loadTexture();
        }

        Rectangle recButton = { 20, 720, 80, 30 };
        if (GuiButton(recButton, GuiIconText(ICON_BOX, "Rectangle")))
        {

        }

        Rectangle selButton = { 20, 760, 80, 30 };
        if (GuiButton(selButton, GuiIconText(ICON_BOX_DOTS_BIG, "Select")))
        {

        }

        // Draw
        BeginDrawing();
        ClearBackground(Color{100, 100, 100, 255});

        BeginTextureMode(canvas);
        // Draw all stored rectangles
        for (int i = 0; i < rectCount; i++) {
            DrawRectangleRec({ rectangles[i].position.x, rectangles[i].position.y, rectangles[i].width, rectangles[i].height }, rectangles[i].color);
        }
        EndTextureMode();

        //DrawRectangle(100, 100, canvasWidth, canvasHeight, BLANK);
        DrawTextureRec(canvas.texture, Rectangle { 0, 0, (float)canvas.texture.width, (float)-canvas.texture.height }, Vector2{ canvasOffset, canvasOffset }, WHITE);
        //DrawTexture(canvas.texture, 0, 0, WHITE);

        for (int i = 5; i < 35; i++)
        {
            for (int j = 5; j < 35; j++)
            {
                DrawRectangleLines(i * cellSize, j * cellSize, cellSize, cellSize, BLACK);
            }
        }

        paletteNo = 0;
        // Draw the palette buttons
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 11; j++)
            {
                Rectangle colorButton = { 185 + 40 * j, (screenHeight - 80) + (40 * i), 30, 30 };
                DrawRectangleRec(colorButton, palette[paletteNo]);
                if (paletteNo == selectedColor) {
                    DrawRectangleLinesEx(colorButton, 2, BLACK);  // Highlight selected color
                }
                paletteNo++;
            }
            //Rectangle colorButton = { 10 + 40 * i, screenHeight - 40, 30, 30 };
            //DrawRectangleRec(colorButton, palette[i]);
            //if (i == selectedColor) {
            //    DrawRectangleLinesEx(colorButton, 2, BLACK);  // Highlight selected color
            //}
        }

        DrawRectangleRec(saveButton, BLANK);

        //BeginTextureMode(canvas);
        //// Draw all stored rectangles
        //for (int i = 0; i < rectCount; i++) {
        //    DrawRectangleRec({ rectangles[i].position.x, rectangles[i].position.y, rectangles[i].width, rectangles[i].height }, rectangles[i].color);
        //}
        //EndTextureMode();

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
