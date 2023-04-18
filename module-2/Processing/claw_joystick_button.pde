import processing.serial.*;

Serial myPort;
String val;

int button = 0;
int x = 0;
int y = 0;

PImage img;
PImage bg;
PImage prize; // declare prize variable
int clawX = 20;
int clawY = -400;
int ballX;
int ballY;
int circleSize = 120;
int padding = 120;
int speed = 3;
boolean isDropping = false;
boolean isLifting = false;
boolean gameOver = false;
boolean isPickedUp = false;

void setup() {
  size(600, 600);
  String portName = Serial.list()[2];
  //System.out.println(portName);
  myPort = new Serial(this, portName, 115200);
  
  img = loadImage("claw-actual.png");
  bg = loadImage("claw-bg-actual.png");
  prize = loadImage("claw-prize.png"); // load your image
  println("Image width: " + img.width + ", height: " + img.height);
  println("Bg width: " + img.width + ", height: " + img.height);
  
  ballY = height - circleSize - padding;
  
  ballX = (int) random(circleSize + padding*3, width - circleSize - padding*3);
}

void draw() {
  if ( myPort.available() > 0) {  // If data is available,
    val = myPort.readStringUntil('\n');  // read all values and store it in val
  }
    //val = trim(val);
    //val = getType(val);
    //System.out.println(val);
    if (val!= null) {
      val = val.trim();
      int[] vals = int(split(val, ","));
      
      // Assign to variables
      x = vals[0];
      y = vals[1];
      button = vals[2];
      
    //System.out.println("x: " + x + " y:" + y + " button: " + button);  
    // Data stored in variables - button, x, y
  image(bg, 0, 0, width, height);
  if (isDropping) {
    clawY += speed;
    if (clawY > height - 770) {
      isDropping = false;
      isLifting = true;
    }
  } else if (isLifting) {
    clawY -= speed;
    if (clawY < -400) {
      isLifting = false;
      if (isPickedUp) {
        gameOver = true;
      }
    }
  }
  
  image(img, clawX, clawY, 110, 110 * img.height/img.width);
  
  if (isLifting && abs(ballX - (clawX + 45)) < 20) {
    ballY -= speed;
    isPickedUp = true;
  }
  
  image(prize, ballX - circleSize/2, ballY - circleSize/2, circleSize, circleSize); // draw the image
  
  if (gameOver) {
    fill(0, 99);
    rect(0, 0, width, height);
    fill(255);
    textAlign(CENTER);
    textSize(32);
    text("GAME OVER", width/2, height/2);
    textSize(16);
    text("Press button to play again", width/2, height/2 + 30);
  }
}

void keyPressed() {
  if (button == 0) {
    if (gameOver) {
      clawX = 20;
      clawY = -400;
      ballY = height - circleSize - padding;
      ballX = (int) random(circleSize + padding, width - circleSize - padding);
      isDropping = false;
      isLifting = false;
      gameOver = false;
      isPickedUp = false;
    } else {
      isDropping = !isDropping;
    }
  } else if (x < 450) { // joystick moved left
    clawX -= 5;
  } else if (x > 550) { // joystick moved right
    clawX += 5;
  }
}
