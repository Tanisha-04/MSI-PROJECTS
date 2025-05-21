#include <Pixy.h>
Pixy pixy;


void setup() {
Serial.begin(9600);
pixy.init();
}

void loop() {
int blocks = pixy.getBlocks();
if (blocks) {
// Loop through detected blocks
for (int i = 0; i < blocks; i++) {
Serial.println("Block ");
Serial.println(i);
Serial.println(": ");
Serial.println("Signature: ");
Serial.print(pixy.blocks[i].signature);
Serial.println(" X: ");
Serial.println(pixy.blocks[i].x);
Serial.println(" Y: ");
Serial.println(pixy.blocks[i].y);
// Add logic to identify and react based on the color signature
if (pixy.blocks[i].signature == 1) {
Serial.println("Red detected");
} else if (pixy.blocks[i].signature == 2) {
Serial.println("Blue detected");
} else if (pixy.blocks[i].signature == 3) {
Serial.println("Green detected");
}
}
}
}