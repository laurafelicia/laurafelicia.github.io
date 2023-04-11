#include <TFT_eSPI.h>
#include <SPI.h>

// Set up the TFT display
TFT_eSPI tft = TFT_eSPI();

// Create a sprite to represent the rectangle
TFT_eSprite rect_sprite = TFT_eSprite(&tft);

int x = 0;
int y = 0;
int xSpeed = 2;
int ySpeed = 2;
int color = TFT_RED;

void setup() {
  // Initialize the TFT display
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  // Create a sprite for the rectangle
  rect_sprite.createSprite(80, 48);
  rect_sprite.fillSprite(TFT_BLACK);
}

void loop() {
  // Clear the screen before redrawing the rectangle

  // Draw the outline rectangle
  tft.drawRect(x - 1, y - 1, rect_sprite.width() + 2, rect_sprite.height() + 2, TFT_BLACK);

  // Draw the rectangle
  rect_sprite.fillSprite(color);
  rect_sprite.setTextSize(1);
  rect_sprite.setTextColor(TFT_BLACK);
  int text_width = rect_sprite.textWidth("you look ");
  int x_cursor = (rect_sprite.width() - text_width) / 2;
  rect_sprite.setCursor(x_cursor, 10);
  rect_sprite.println("you look");

  text_width = rect_sprite.textWidth("like");
  x_cursor = (rect_sprite.width() - text_width) / 2;
  rect_sprite.setCursor(x_cursor, 20);
  rect_sprite.println("like");

  text_width = rect_sprite.textWidth("a movie");
  x_cursor = (rect_sprite.width() - text_width) / 2;
  rect_sprite.setCursor(x_cursor, 30);
  rect_sprite.println("a movie");

  // Draw the rectangle sprite on the screen
  rect_sprite.pushSprite(x, y);

  // Update the position of the rectangle
  x = x + xSpeed;
  y = y + ySpeed;

  // Check if the rectangle has hit any of the edges of the screen
  if (x > (tft.width() - rect_sprite.width()) || x < 0) {
    xSpeed = -xSpeed;
    color = random(0xFFFF);
  }
  if (y > (tft.height() - rect_sprite.height()) || y < 0) {
    ySpeed = -ySpeed;
    color = random(0xFFFF);
  }

  // Wait a little before redrawing the rectangle
  delay(30);
}