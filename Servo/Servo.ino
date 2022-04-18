
#include <Servo.h> 
#define kCoarsePin    A0    // Entrée analogique "Grossier"
#define kFinePin      A1    // Entrée analogique "Fin"
#define kServoPin     2     // Sortie Servo

#define kMinServoUs   1300  // Min Servo en µs    
#define kMaxServoUs   1700  // Max Servo en µs  

Servo Servo1;               // Objet Servo

void setup() {
 Servo1.attach(kServoPin);  // Init Servo
}

void loop() {

long Coarse = analogRead(kCoarsePin); // Lecture grossière 0->1023
long Fine = analogRead(kFinePin);     // Lecture Fine 0->1023

long Cmd=map(Coarse,0,1023,512,(1023*1023)-512)+Fine-512; // Valeur de commande 0-> 1023²

long ServoUs=map(Cmd, 0, 1023*1023, kMinServoUs, kMaxServoUs);// Valeur de Servo min à max
Servo1.writeMicroseconds(ServoUs);
}
