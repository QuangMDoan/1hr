#define TRIGGER 11 
#define ECHO 10 
#define TRIGGER2 6 
#define ECHO2 5 

class DistanceSensor{
  public: 
  DistanceSensor(int triggerPin, int echoPin) : triggerPin(triggerPin), echoPin(echoPin) {
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
  }

  double getDistance(){
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    return pulseIn(echoPin, HIGH) * .0343/2; 
  }

  private: 
  const int triggerPin; 
  const int echoPin;
};

DistanceSensor sensor1(TRIGGER, ECHO);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  double distance = sensor1.getDistance();
  Serial.print("Distance 1: ");
  Serial.println(distance);
}
