#include <Servo.h> 

//All the servo objects
Servo myservo1; //Thumb Bend
Servo myservo2; //Pointer finger bend
Servo myservo3; //Middle finger bend
Servo myservo4; //Ring finger bend
Servo myservo5; //Pinky bend
Servo myservo6; //Thumb inward

const int flexpin1 = 0; //Thumb Bend
const int flexpin2 = 1; //Pointer finger bend
const int flexpin3 = 2; //Middle finger bend
const int flexpin4 = 3; //Ring finger bend
const int flexpin5 = 4; //Pinky bend
const int flexpin6 = 5; //Thumb inward

int open1 = 220;
int open2 = 310;
int open3 = 300;
int open4 = 261;
int open5 = 197;
int open6 = 152;

int closed1 = 181;
int closed2 = 244;
int closed3 = 285;
int closed4 = 199;
int closed5 = 149;
int closed6 = 175;

boolean reset = false;

void setup() 
{ 

  //Debugging purposes
  Serial.begin(9600);

  //Attaching all the servos to pins on the board
  myservo1.attach(8); //Thumb Bend
  myservo2.attach(9); //Pointer finger bend
  myservo3.attach(10); //Middle finger bend
  myservo4.attach(11); //Ring finger bend
  myservo5.attach(12); //Pinky bend
  myservo6.attach(13); //Thumb inward

  //Initial servo positions for open hand
  myservo1.write(150);
  myservo2.write(170);
  myservo3.write(140);
  myservo4.write(15);
  myservo5.write(0);
  myservo6.write(130);
} 


void loop() 
{

  //Flex readings
  int flexposition1; //Thumb bend
  int flexposition2; //Pointer
  int flexposition3; //Middle
  int flexposition4; //Ring
  int flexposition5; //Pinky
  int flexposition6; //Thumb inward

  //Position for servos
  int servoposition1; //Thumb bend
  int servoposition2; //Pointer
  int servoposition3; //Middle
  int servoposition4; //Ring
  int servoposition5; //Pinky
  int servoposition6; //Thumb inward

  // Read the position of the flex sensors (0 to 1023):
  flexposition1 = analogRead(flexpin1);
  flexposition2 = analogRead(flexpin2);
  flexposition3 = analogRead(flexpin3);
  flexposition4 = analogRead(flexpin4);
  flexposition5 = analogRead(flexpin5);
  flexposition6 = analogRead(flexpin6);


  char readIn = Serial.read();
  
  if(readIn == 'o'){
      open1 = flexposition1;
      open2 = flexposition2;
      open3 = flexposition3;
      open4 = flexposition4;
      open5 = flexposition5;
      Serial.println("Updating open");
  }

  if(readIn == 'c'){
      closed1 = flexposition1;
      closed2 = flexposition2;
      closed3 = flexposition3;
      closed4 = flexposition4;
      closed5 = flexposition5;
      Serial.println("Updating closed");
  }
  
  //Constraint all sensors and motors
  servoposition1 = map(flexposition1, open1, closed1, 150, 0);
  servoposition1 = constrain(servoposition1, 0, 150);

  servoposition2 = map(flexposition2, open2, closed2, 170, 0);
  servoposition2 = constrain(servoposition2, 0, 170);

  servoposition3 = map(flexposition3, open3, closed3, 160, 0);
  servoposition3 = constrain(servoposition3, 0, 160);

  servoposition4 = map(flexposition4, open4, closed4, 15, 180);
  servoposition4 = constrain(servoposition4, 15, 180);

  servoposition5 = map(flexposition5, open5, closed5, 0, 180);
  servoposition5 = constrain(servoposition5, 0, 180);

  servoposition6 = map(flexposition6, open6, closed6, 180, 130);
  servoposition6 = constrain(servoposition6, 130, 180);

  // Moves servos
  myservo1.write(servoposition1);
  myservo2.write(servoposition2);
  myservo3.write(servoposition3);
  myservo4.write(servoposition4);
  myservo5.write(servoposition5);
  myservo6.write(servoposition6);

  /*
  //debugging
  Serial.print("sensor1: ");
  Serial.println(flexposition1);
  //debugging
  Serial.print("sensor2: ");
  Serial.println(flexposition2);
  //debugging
  Serial.print("sensor3: ");
  Serial.println(flexposition3);
  //debugging
  Serial.print("sensor4: ");
  Serial.println(flexposition4);
  //debugging
  Serial.print("sensor5: ");
  Serial.println(flexposition5);
  //debugging
  Serial.print("sensor6: ");
  Serial.println(flexposition6);
  */
  
  // Note that all of the above lines are "print" except for the
  // last line which is "println". This puts everything on the
  // same line, then sends a final carriage return to move to
  // the next line.

  // After you upload the sketch, turn on the serial monitor
  // (the magnifying-glass icon to the right of the icon bar).
  // You'll be able to see the sensor values. Bend the flex sensor
  // and note its minimum and maximum values. If you replace the
  // 600 and 900 in the map() function above, you'll exactly match
  // the flex sensor's range with the servo's range.

  delay(20);  // wait 20ms between servo updates
} 
