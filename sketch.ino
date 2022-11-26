#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define BUTTON_LEFT D5
#define BUTTON_RIGHT D4
#define BUZZER_PIN D6

#define DEBOUNCE_BUTTON 100000
#define ROUND_INTERVAL 90 // This is the time in seconds a round should take

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

typedef struct { 
  uint8_t index;
  char* menuItemName;
  char* options[5];
} MenuOption;

const MenuOption MenuOptions[] {
    {0, "Fun & Games", {"Fun & Games testing"}},
    {1, "On The Air", {"On The Air testing"}},
    {2, "Snack Time", {"Snack Time testing"}}, 
    {3, "The Great Outdoors", {"The Great Outdoors testing"}}, 
    {4, "Toss Up", {"Toss Up testing"}}
};

enum GameState {
  PAUSED,
  MAIN_MENU,
  START_ROUND,
  IN_A_ROUND,
  FINISH_ROUND,
};

GameState gameState = MAIN_MENU;

// State
long lastMenuOption=0;
long lastGameOption=0;
long timeSinceLastTick=0;
long lastPress=0;
long timeSinceGameStarted=0;

void tickingSound() {
  tone(BUZZER_PIN, 1000, 5);
}

void setup() {
  Serial.begin(115200);

  Wire.begin(D1, D2);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);

  pinMode(BUTTON_LEFT,INPUT_PULLUP);
  pinMode(BUTTON_RIGHT,INPUT_PULLUP);
  pinMode(BUZZER_PIN,OUTPUT);

  printCenteredText("Welcome!");  

  display.display();
}

uint8_t getButton(){
  uint8_t ret=0;
  for(;;){
    if(digitalRead(BUTTON_LEFT)==LOW){
      ret=BUTTON_LEFT;
    }else if(digitalRead(BUTTON_RIGHT)==LOW){
      ret=BUTTON_RIGHT;
    }
    if(ret!=0){
      if(micros()-lastPress>DEBOUNCE_BUTTON){
        lastPress=micros();
        return ret;
      }else{
        lastPress=micros();
        ret=0;
      }
    }
    delay(10);
  }
}

void printCenteredText(String text) {
  int16_t x1;
  int16_t y1;
  uint16_t width;
  uint16_t height;

  display.getTextBounds(text, 0, 0, &x1, &y1, &width, &height);

  // display on horizontal and vertical center
  display.clearDisplay(); // clear display
  display.setCursor((SCREEN_WIDTH - width) / 2, (SCREEN_HEIGHT - height) / 2);
  display.println(text); // text to display
  display.display();
}

void round() {
  Serial.print("current game state");
  Serial.println(gameState);
  while(gameState == IN_A_ROUND) {
    int currentTime = millis();
    // we break up the total ROUND_INTERVAL time into 3 segments with distinct delay times.
    int timeSinceGameStartedSeconds = (currentTime - timeSinceGameStarted) / 1000;
    int timeToTick = 0;

    Serial.print("time since started ");
    Serial.println(timeSinceGameStartedSeconds);
    Serial.println(currentTime);
    Serial.println(timeSinceGameStarted);

    if(timeSinceGameStartedSeconds < (ROUND_INTERVAL / 3)) {
      timeToTick = 1000;
    } else if(timeSinceGameStartedSeconds > (ROUND_INTERVAL / 3) && timeSinceGameStartedSeconds < (ROUND_INTERVAL / 2)) {
      timeToTick = 500;
    } else {
      timeToTick = 250;
    }

    // We want to make sure that we are not exceeding the round interval limit in seconds
    if(timeSinceGameStartedSeconds >= ROUND_INTERVAL) {
      Serial.println("finishing the round");
      gameState = FINISH_ROUND;
    }

    MenuOption selectedMenuOption = MenuOptions[lastMenuOption];

    int totalGameOptions = sizeof(selectedMenuOption.options) / sizeof(selectedMenuOption.options[0]);
    Serial.print("Total Game Options: ");
    Serial.println(totalGameOptions);
    Serial.println(lastGameOption);

    printCenteredText(selectedMenuOption.options[lastGameOption]);

    // TODO: dirty checks for button presses, this should be abstracted to a non-blocking getButton
    uint8_t ret=0;
    for(int i = 0; i <= 5; i++){
      if(digitalRead(BUTTON_RIGHT)==LOW){
        ret=BUTTON_RIGHT;      
      }
      if(ret!=0){
        if(micros()-lastPress>DEBOUNCE_BUTTON){
          if((lastGameOption + 1) > totalGameOptions) {
            lastGameOption = 0;
          } else {
            lastGameOption += + 1;
          }

          lastPress=micros();
        }else{
          lastPress=micros();
          ret=0;
        }
      }
      delay(10);
    }

    if(currentTime - timeSinceLastTick >= timeToTick) {
      tickingSound();
      timeSinceLastTick = currentTime;
    }
  }
}

// We want to check what state we are in
void game() {
  switch(gameState) {
    case MAIN_MENU: {
      Serial.println("MAIN_MENU");

      int totalMenuOptions = sizeof(MenuOptions) / sizeof(MenuOptions[0]);

      MenuOption selectedMenuOption = MenuOptions[lastMenuOption];

      printCenteredText(selectedMenuOption.menuItemName);

      switch(getButton()) {
        case BUTTON_RIGHT:
          // We are starting the game
          gameState = START_ROUND;
        break;
        case BUTTON_LEFT:
          // We are cycling through menu options
          if(lastMenuOption + 1 > totalMenuOptions) {
            lastMenuOption = 0;
          } else {
            lastMenuOption += 1;
          }
          MenuOption selectedMenuOptionNested = MenuOptions[lastMenuOption];

          printCenteredText(selectedMenuOptionNested.menuItemName);
        break;
      }
    }break;
    case START_ROUND:
      Serial.println("START_ROUND");

      printCenteredText("Starting");

      // Resetting the game constants
      timeSinceGameStarted = millis();
      lastGameOption = 0;

      gameState = IN_A_ROUND;

      round();
      break;
    case FINISH_ROUND:
      Serial.println("FINISH_ROUND");

      printCenteredText("If you are holding the device your team loses!");

      delay(2000);

      gameState = MAIN_MENU;
      break;
  }

  display.display();
}

void loop() {
  switch(gameState) {
    case IN_A_ROUND:
      Serial.println("I am dealing with the game in a different loop");
      break;
    case PAUSED:
      Serial.println("PAUSED");
      break;
    default:
      Serial.println("calling game()");
      game();
      break;
  }
}