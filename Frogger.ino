#include <Arduboy2.h>
#include "Images.h"

Arduboy2 arduboy;

int frogX = 62;
int frogY = 58;
int carX =  130;
int carY = 33;

void setup() {
  
    arduboy.begin();
    arduboy.setFrameRate(30);
    arduboy.initRandomSeed();
    
}

void loop() {

    if ( !arduboy.nextFrame() ) return;
    arduboy.clear();


    // Controlling ..

    if (arduboy.pressed(UP_BUTTON)) {
        frogY = frogY -1;
    }
    if (arduboy.pressed(DOWN_BUTTON) && frogY<58) {
        frogY = frogY +1;
    }
    if (arduboy.pressed(RIGHT_BUTTON)) {
        frogX = frogX +1;
    }
    if (arduboy.pressed(LEFT_BUTTON)) {
        frogX = frogX -1;
    }



    carX = 

    // Drawing ..
    arduboy.drawLine(0,57,127,57);
    arduboy.drawLine(0,31,127,31);
    arduboy.drawLine(0,27,127,27);

    for (int x = 8; x < 128; x = x + 12) {

        arduboy.drawLine(x,40, x + 4, 40);
        arduboy.drawLine(x,49, x + 4, 49);

    }


    Sprites::drawSelfMasked(frogX, frogY, Frog, 0);
       Sprites::drawSelfMasked(carX, carY, Car1, 0);
    arduboy.display();
    
}
