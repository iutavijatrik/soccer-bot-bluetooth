/*
 * app link: https://play.google.com/store/apps/details?id=com.bluino.arduinobluetoothrobotcar&hl=en&gl=US
 * if u want to use other apps, modify the bluetooth commands on either side
*/
// connections for right motors
#define rpwmRight 6   //do not let both of the pwm pins of the driver be high
#define lpwmRight 5   //it will fry the driver

// connections for left motors
#define rpwmLeft 11    //do not let both of the pwm pins of the driver be high
#define lpwmLeft 10    //it will fry the driver

//turn constant that determines the turn characteristics while 
// forward-left, forward-right, back-left, back-right
#define turnConst 4

//the variable that determines the speed
int valSpeed = 255;


void setup(){
  Serial1.begin(9600);
  //Serial.begin(9600);// set up Serial library at 9600 bps
  
  

  // Set all the motor control pins to outputs
  pinMode(rpwmRight, OUTPUT);
  pinMode(lpwmRight, OUTPUT);
  pinMode(rpwmLeft, OUTPUT);
  pinMode(lpwmLeft, OUTPUT);

  // Set the speed to start, from 0 (off) to 255 (max speed)
  //SetSpeed(0,0);
  
  
}

void loop() {
  while (Serial11.available() > 0) {
//     digitalWrite(A0, HIGH);
//     digitalWrite(A1, HIGH);
     char command = Serial1.read();    // gets one byte from serial buffer
     //Serial.println(command);
    
    switch(command){
    case 'F':   // move forward
        SetSpeed(valSpeed, valSpeed);
        
        break;
    case 'B':   // move backward
        SetSpeed(-valSpeed, -valSpeed);
        
        break;
    case 'R':   // turn right
        SetSpeed(valSpeed, -valSpeed);
        
        break;
    case 'L':   // turn left
        SetSpeed(-valSpeed, valSpeed);
        
        break;
    case 'G':   // forward left
        SetSpeed(valSpeed / turnConst, valSpeed);
       
        break;
    case 'H':   // backward left
        SetSpeed(-valSpeed / turnConst, valSpeed);
        
        break;
    case 'I':   // forward right
        SetSpeed(valSpeed , valSpeed / turnConst);
        break;
    case 'J':   // backward right
        SetSpeed(valSpeed , -valSpeed / turnConst);
        break;
    case 'S':   // stop
        SetSpeed(0,0);
        break;
    
    
    case '0':   // set speed motor to 0 (min)
        valSpeed = 0;
        break;
    case '1':   // set speed motor to 30
        valSpeed = 90;
        break;
    case '2':   // set speed motor to 55
        valSpeed = 100;
        break;
    case '3':   // set speed motor to 80
        valSpeed = 110;
        break;
    case '4':   // set speed motor to 105
        valSpeed = 120;
        break;
    case '5':   // set speed motor to 130
        valSpeed = 130;
        break;
    case '6':   // set speed motor to 155
        valSpeed = 150;
        break;
    case '7':   // set speed motor to 180
        valSpeed = 180;
        break;
    case '8':   // set speed motor to 205
        valSpeed = 200;
        break;
    case '9':   // set speed motor to 230
        valSpeed = 220;
        break;
    case 'q':   // set speed motor to 255 (max)
        valSpeed = 255;
        break;
    } 
  }
}

// function for setting speed of motors
void SetSpeed(int valLeft, int valRight){
  if (valLeft < 0) {
    // left Motor backward
    analogWrite(rpwmLeft, 0);
    analogWrite(lpwmLeft, abs(valLeft));
  } else {
    // left Motor forward
    analogWrite(rpwmLeft, valLeft);
    analogWrite(lpwmLeft, 0);
  }

  if (valRight < 0) {
    // right Motor backward
    analogWrite(rpwmRight, 0);
    analogWrite(lpwmRight, abs(valRight));
  } else {
    // left Motor forward
    analogWrite(rpwmRight, valRight);
    analogWrite(lpwmRight, 0);
  }
}
