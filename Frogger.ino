#include <Arduboy2.h>
#include "Images.h"

Arduboy2 arduboy;

struct Car {
    int x;
    int y;
    int type;
};

int frameCount = 0;

int frogX = 62;
int frogY = 58;

Car car1;
Car car2;
Car car3;
Car car4;
Car car5;
Car car6;
void setup() {
  
    arduboy.begin();
    arduboy.setFrameRate(60);
    arduboy.initRandomSeed();
    
    car1.x = 130;
    car1.y = 33;
    car1.type =1;
    
    car2.x = 180;
    car2.y = 33;
    car2.type =2;

    car3.x = 64;
    car3.y = 42;
    car3.type =2;
    
    car4.x = 110;
    car4.y = 42;
    car4.type =3;

    car5.x = 45;
    car5.y =51;
    car5.type = 1;

    car6.x = 70;
    car6.y = 51;
    car6.type = 3;
}   


void loop() {

    if ( !arduboy.nextFrame() ) return;
    arduboy.clear();
    frameCount = frameCount + 1;


    // Controlling ..

    if (arduboy.pressed(UP_BUTTON)) {
        frogY = frogY - 1;
    }
    if (arduboy.pressed(DOWN_BUTTON) && frogY<58) {
        frogY = frogY + 1;
    }
    if (arduboy.pressed(RIGHT_BUTTON) && frogX<123) {
        frogX = frogX + 1;
    }
    if (arduboy.pressed(LEFT_BUTTON)&& frogX>0) {
        frogX = frogX - 1;
    }
    

    // Updating the car ..

    if (frameCount % 2 == 0) {

        car1.x = car1.x - 1;
        car2.x = car2.x - 1;

    }
    else {

        car1.x = car1.x - 2;
        car2.x = car2.x - 2;

    }

    if(car1.x< - 20) { launchCar(car1, car2); }
    if(car2.x< - 20) { launchCar(car2, car1); }

    car3.x = car3.x - 1;
    if(car3.x< - 20) { launchCar(car3, car4);;}

    car4.x = car4.x - 1;
    if(car4.x< - 20) { launchCar(car4, car3);;}

    if (frameCount % 2 == 0) {
        
        car5.x = car5.x - 1;
        if(car5.x< - 20) { launchCar(car5, car6); }

        car6.x = car6.x - 1;
        if(car6.x< - 20) { launchCar(car6, car5); }
    }

    // Look for collision ..

    if (carCrash(car1)) {

        arduboy.print("DEAD ! 1");
    }

    if (carCrash(car2)) {

        arduboy.print("DEAD ! 2");
    }
    if (carCrash(car3)) {

        arduboy.print("DEAD ! 3");
    }

    if (carCrash(car4)) {

        arduboy.print("DEAD ! 4");
    }
     if (carCrash(car5)) {

        arduboy.print("DEAD ! 5");
    }

    if (carCrash(car6)) {

        arduboy.print("DEAD ! 6");
    }

    // Drawing ..
    arduboy.drawLine(0,58,127,58);
    arduboy.drawLine(0,31,127,31);
    arduboy.drawLine(0,27,127,27);

    for (int x = 8; x < 128; x = x + 12) {

        arduboy.drawLine(x,40, x + 4, 40);
        arduboy.drawLine(x,49, x + 4, 49);

    }


    Sprites::drawErase(frogX - 1, frogY - 1, FrogMask, 0);
    Sprites::drawSelfMasked(frogX, frogY, Frogimage, 0);
    
    drawCar(car1);
    drawCar(car2);
    drawCar(car3);
    drawCar(car4);
    drawCar(car5);
    drawCar(car6);

    arduboy.display();
    
}

void drawCar(Car car) {

    if (car.type == 1) {

        Sprites::drawSelfMasked(car.x, car.y, Carimage1, 0);

    }

    if (car.type == 2) {

        Sprites::drawSelfMasked(car.x, car.y, Carimage2, 0);

    }

    if (car.type == 3) {

        Sprites::drawSelfMasked(car.x, car.y, Carimage3, 0);

    }


}

bool carCrash(Car car) {

    Rect frogRect = { frogX, frogY, 4, 5};
    Rect carRect = { car.x, car.y, 17, 6};

    if (car.type = 1) {
        carRect.width = 10;
    }

    if (arduboy.collide(frogRect, carRect)) {

        return true;

    }
    else {
    
        return false;
    
    }

}

void launchCar(Car &car, Car otherCar) {

    if (otherCar.x > 110) {

        car.x = random(otherCar.x + 20, otherCar.x + 60);

    }
    else {

        car.x = random(130, 170);

    }

}