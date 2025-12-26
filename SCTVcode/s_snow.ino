// Some calming snow for the winter...

const int time_step_ms = 50;
const int _size = 100;
const int gravity = -10;
const int ground = -500;
const int bg_segs = 12;
const int bg[bg_segs][4] = {
  {-1000, -500, 1000, -500},  // Ground
  {-500, 500, -500, -500},    // Tree
  {-500, 500, -750, 250},
  {-500, 500, -250, 250},
  {-500, 250, -750, 0},
  {-500, 250, -250, 0},
  {-500, 0, -750, -250},
  {-500, 0, -250, -250},
  {250, -500, 250, 0},        // House
  {750, 0, 750, -500},
  {150, -100, 500, 250},
  {500, 250, 850, -100},
};

typedef struct {
  int x;
  float y;
  int size;
  float rate;
  bool falling;
} snowflake_t;

snowflake_t snowflakes[100];

// Any constant "background" stuff (lines, text, etc) goes here.
struct item snowList[] = {
  {listend,0,0,BlankLn,0,0}
};

void resetSnow(void) 
{
  for(int i = 0; i < 100; i++) {
    snowflakes[i].x = random(2000) - 1000;
    snowflakes[i].y = 1000 + random(2000);
    snowflakes[i].rate = (float)(random(300) + 200) / 100.0;
    snowflakes[i].falling = true;
    snowflakes[i].size = 5 + random(20);  
  }
}

void doSnow(void)
{
  static int time_ms = 0;

  // Draw background
  for(int i = 0; i < bg_segs; i++) {
    drawALine(bg[i][0], bg[i][1], bg[i][2], bg[i][3]);
  }
  
  // Draw snow
  for(int i = 0; i < 100; i++) {
    if(snowflakes[i].falling) {
      snowflakes[i].y -= snowflakes[i].rate;
      if(snowflakes[i].y < ground) {
        snowflakes[i].y = 1000 + random(2000);
      }
    }
    if(snowflakes[i].y < 1500) {
      drawACircle(snowflakes[i].x, snowflakes[i].y, snowflakes[i].size);
    }
  }

  time_ms += time_step_ms;
}