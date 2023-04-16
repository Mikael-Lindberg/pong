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

void DrawGridLine(int size, int spacing, int gap) {
    for (int i = spacing/2; i <= GetScreenHeight(); i += size + spacing) {
        if (i <= GetScreenHeight() / 2 - gap || i >= GetScreenHeight() / 2 + gap) {
            DrawRectangle(GetScreenWidth() / 2 - size / 2, i, size, size, RAYWHITE);
        }
    }
}

int main() {
    // Screen related stuff
    const int screen_width = 800;
    const int screen_height = 480;
    const int screen_center_y = screen_height / 2;
    const int screen_center_x = screen_width / 2;

    // Initialization related calls
    InitWindow(screen_width, screen_height, "Pong!");
    SetTargetFPS(60);

    // Scores
    int score_left =  0;
    int score_right = 0;
    int max_score = 9;

    // Gameplay
    int delay = 1;
    int speed = 4;

    // Grid in middle
    int grid_size = 8;
    int grid_spacing = 22;
    int grid_gap_middle = 44;

    Player player_left = { true, 12, 72, 32, screen_center_y - 36 };
    Player player_right = { false, 12, 72, GetScreenWidth() - 32 - 12, screen_center_y - 36 };

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);

            DrawGridLine(grid_size, grid_spacing, grid_gap_middle);

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
