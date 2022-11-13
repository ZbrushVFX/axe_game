
#include "raylib.h"


int main()
{

// Create game window
  int width{800};
  int height{450};
  InitWindow(width, height,"My Window");

// Circle coordinates
  int circle_x{200};
  int circle_y{200};
  int circle_radius{25};

// axe coordinates
  int axe_x{400};
  int axe_y{0};
  int axe_lenght{50};

// circle edges
  int l_circle_x{circle_x - circle_radius};
  int r_circle_x{circle_x + circle_radius};
  int u_circle_y{circle_y - circle_radius};
  int b_circle_y{circle_y + circle_radius};

//axe edges
  int l_axe_x{axe_x};
  int r_axe_x{axe_x + axe_lenght};
  int u_axe_y{axe_y};
  int b_axe_y{axe_y + axe_lenght};

// Axe collision
  bool collision_with_axe = 
                           (b_axe_y >= u_circle_y) && 
                           (u_axe_y <= b_circle_y) && 
                           (r_axe_x >= l_circle_x) && 
                           (l_axe_x <= r_circle_x);

// Axe paths
  int direction{10};

// Update fps
  SetTargetFPS(60);




  while (!WindowShouldClose())
  {

// Обновление холста, чтобы не было мигания при двойной буфере
  BeginDrawing();
  ClearBackground(WHITE);

// Game logic begins

  if (collision_with_axe)
  {
    DrawText("Game Over", 400, 200, 20, RED);
  }
  else
  {
// Update edges
    l_circle_x = circle_x - circle_radius;
    r_circle_x = circle_x + circle_radius;
    u_circle_y = circle_y - circle_radius;
    b_circle_y = circle_y + circle_radius;
    l_axe_x = axe_x;
    r_axe_x = axe_x + axe_lenght;
    u_axe_y = axe_y;
    u_axe_y = axe_y + axe_lenght;

// update collision_with_axe
  collision_with_axe =
                        (b_axe_y >= u_circle_y) &&
                        (u_axe_y <= b_circle_y) &&
                        (r_axe_x >= l_circle_x) &&
                        (l_axe_x <= r_circle_x);

  DrawCircle(circle_x, circle_y, circle_radius, BLUE);
  DrawRectangle(axe_x, axe_y, axe_lenght, axe_lenght, RED);

// move the axe
    axe_y += direction;
  if(axe_y > height || axe_y < 0) 
  {
  direction = -direction;
  }

// Key down and move circle
  if (IsKeyDown(KEY_D) && circle_x < width )
  {
  circle_x += 10;
  }

  if (IsKeyDown(KEY_A) && circle_x > 0 )
  { 
  circle_x -= 10;
  }

// Game logic ends

  }

  EndDrawing();
  }

}