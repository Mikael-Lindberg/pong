#include <raylib.h>

struct Player {
    bool is_left_player;
    int width;
    int height;
    int space_from_back;
    int y_pos;
};

void DrawPlayer(Player* player) {
    DrawRectangle(player -> space_from_back, player -> y_pos, player -> width, player -> height, WHITE);
}

void DrawGrid(int i) {
    DrawRectangle(GetScreenWidth() / 2 - 8, i, 8, 8, RAYWHITE);
}

int main() {
    const int screen_width = 800;
    const int screen_height = 480;

    InitWindow(screen_width, screen_height, "Pong!");
    SetTargetFPS(60);

    // Unsure about correct size, have to check on the window.
    int screen_center_y = GetScreenHeight() / 2;

    // Scores
    int score_left =  0;
    int score_right = 0;
    int max_score = 9;

    int delay = 1;
    int speed = 4;

    int ball_size = 12;

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

    Player player_left = { true, 12, 72, 32, screen_center_y - 36 };
    Player player_right = { false, 12, 72, GetScreenWidth() - 32 - 12, screen_center_y - 36 };

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);

            for (i = 0; i < 60; i++) {
                DrawGrid(arr[i]);
            }

            if (IsKeyDown(KEY_W) && player_left.y_pos >= 0) { player_left.y_pos -= speed; }
            if (IsKeyDown(KEY_S) && player_left.y_pos <= GetScreenHeight() - player_left.height) { 
                player_left.y_pos += speed; 
            }

            if (IsKeyDown(KEY_UP) && player_right.y_pos >= 0) { player_right.y_pos -= speed; }
            if (IsKeyDown(KEY_DOWN) && player_right.y_pos <= GetScreenHeight() - player_right.height) { 
                player_right.y_pos += speed; 
            }

            DrawPlayer(&player_left);
            DrawPlayer(&player_right);

            //DrawRectangle(200, 200, ball_size, ball_size, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
