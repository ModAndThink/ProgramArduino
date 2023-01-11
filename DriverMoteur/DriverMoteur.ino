/* L298N DC motor example */

const int IN1=8;
const int IN2=9;
const int ENA=3;

bool isWorking = false;
bool rotation = false;

void setup()
{
 Serial.begin(9600);
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);  
 pinMode(ENA,OUTPUT);  
 analogWrite(ENA, 200);
 Serial.println("Programme lance :");
 Serial.println("a : lance le moteur");
 Serial.println("z : arrete le moteur");
 Serial.println("r : sens horaire");
 Serial.println("l : sense anti-horaire");
}
void loop()
{  
 if (Serial.available()){
  int message = Serial.read();
  if (message==97) {
    Serial.println("moteur mis en route");
    isWorking = true;
  }
  else if (message==122) {
    Serial.println("moteur arrete");
    isWorking = false;
  }
  else if (message==114) {
    Serial.println("sens horaire");
    rotation = true;
  }
  else if (message==108) {
    Serial.println("sens anti-horaire");
    rotation = false;
  }
 }
 if (isWorking==true) {
  if (rotation==true) {
    digitalWrite(IN1,LOW);// rotate forward
    digitalWrite(IN2,HIGH);
  }
  else {
    digitalWrite(IN1,HIGH);// rotate reverse
    digitalWrite(IN2,LOW);
  }
 }
 else {
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,LOW);
 }
 delay(1000);
}
