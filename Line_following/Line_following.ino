int sensePin1 = 0;  //left
int sensePin2 = 1;  //middle
int sensePin3 = 2;  //right

int threshold = 200;

int ballSensePin = 3;
int frameMtrPin = 12;
boolean grabbingDone = false;

int ObstacleSensePin = 4;

int ballthreshold  = 150;
int obsthreshold  = 130;

const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;
const int Motor2Pin1 = 10;
const int Motor2Pin2 = 11;

int motorController_left = 5;  //left
int motorController_right = 3;  //right

void setup(){
  
  pinMode(sensePin1,INPUT);
  pinMode(sensePin2,INPUT);
  pinMode(sensePin3,INPUT);

  pinMode(ballSensePin,INPUT);

  pinMode(ObstacleSensePin,INPUT);

  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
  
  pinMode(frameMtrPin, OUTPUT);

  grabbingDone = false;
  
  pinMode(motorController_left, OUTPUT);   
  pinMode(motorController_right, OUTPUT);  

  analogWrite(motorController_left,900);  
  analogWrite(motorController_right,900);
}

void loop(){
  
  int val1;
  int val2;
  int val3;

  int ballSenseVal = analogRead(ballSensePin);
  int obstacleSenseVal = analogRead(ObstacleSensePin);

  if(ballSenseVal > ballthreshold && !grabbingDone){

    Stop();
    
    digitalWrite(frameMtrPin,HIGH);
    delay(5000);
    digitalWrite(frameMtrPin,LOW);
    
    grabbingDone = true;
    
    analogWrite(motorController_left,950);  
    analogWrite(motorController_right,950);
    
    GoRight();
    delay(1200);
    
    analogWrite(motorController_left,900);  
    analogWrite(motorController_right,900);
    
  }
  else{
    
    digitalWrite(frameMtrPin,LOW);

    val1 = analogRead(sensePin1);  //left
    val2 = analogRead(sensePin2);  //middle
    val3 = analogRead(sensePin3);  //right

    if(val1 > threshold && val2 > threshold && val3 > threshold){ //Go forward
      digitalWrite(frameMtrPin,LOW);
      GoForward();
      delay(30);
    }
    else if(val1 <= threshold && val2 > threshold && val3 > threshold){ //Turn right
      digitalWrite(frameMtrPin,LOW);
      GoRight();    
      delay(15);
    }
    else if(val1 <= threshold && val2 <= threshold && val3 > threshold){ //Turn right
      digitalWrite(frameMtrPin,LOW);
      GoRight();    
      delay(30);
    }
    else if(val1 > threshold && val2 > threshold && val3 <= threshold){ //Turn left
      digitalWrite(frameMtrPin,LOW);
      GoLeft();
      delay(15);
    }
    else if(val1 > threshold && val2 <= threshold && val3 <= threshold){ //Turn right
      digitalWrite(frameMtrPin,LOW);
      GoLeft();
      delay(30);
    }
    else{
      Stop();
    }
    
  }

  /*if(obstacleSenseVal > obsthreshold){
    Stop();
    delay(1000);
    GoBackward();
    delay(1000);
    GoLeft();
    delay(900);
    Stop();
    delay(100);
    GoForward();
    delay(3000);
    Stop();
    delay(100);
    GoRight();
    delay(2000);
    Stop();
    delay(100);
    int Obsval1 ;
    int Obsval2;
    int Obsval3;
    do{
      GoForward();
      delay(100);
      Stop();
      delay(100);
      Obsval1 = analogRead(sensePin1);  //left
      Obsval2 = analogRead(sensePin2);  //middle
      Obsval3 = analogRead(sensePin3);  //right
    }
    while(Obsval3<threshold && Obsval2 < threshold && Obsval1< threshold);
  }*/

}

void GoRight(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void GoLeft(){
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
}

void GoBackward(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
}

void GoForward(){
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void Stop(){
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}











