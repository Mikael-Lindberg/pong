#include <raylib.h>

struct Player {
    bool is_left_player;
};

void DrawGrid(int i) {
    DrawRectangle(GetScreenWidth() / 2 - 8, i, 8, 8, RAYWHITE);
}

int main() {
    const int screen_width = 800;
    const int screen_height = 480;

    InitWindow(screen_width, screen_height, "Pong!");
    SetTargetFPS(60);

    // Unsure about correct size, have to check on the window.
    int player_width = 12;
    int player_height = 72;
    int space_from_back = 32;
    int start_y_pos = GetScreenHeight() / 2 - player_height / 2;

    int left_y = start_y_pos;
    int right_y = start_y_pos;

    // Scores
    int score_left =  0;
    int score_right = 0;

    int speed = 4;

    //480
    int arr[60];
    int i, value;

    value = 8;
    for (i = 0; i < 60; i++) {
        arr[i] = value;
        value += 24;
    }

    // These two need to be calculated.
    int left_position = 0;
    int right_position = 0;

    // Grid separation thingy
    int box_radius = 2;

    Player player_left = { true };
    Player player_right = { false };

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);

            for (i = 0; i < 60; i++) {
                DrawGrid(arr[i]);
            }

            if (IsKeyDown(KEY_W) && left_y >= 0) {
                left_y -= speed;
            }
            if (IsKeyDown(KEY_S) && left_y <= GetScreenHeight() - player_height) {
                left_y += speed;
            }


            if (IsKeyDown(KEY_UP) && right_y >= 0) {
                right_y -= speed;
            }
            if (IsKeyDown(KEY_DOWN) && right_y <= GetScreenHeight() - player_height) {
                right_y += speed;
            }

            DrawRectangle(space_from_back, left_y, player_width, player_height, WHITE);
            DrawRectangle(GetScreenWidth() - (space_from_back + player_width), right_y, player_width, player_height, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
