// defining the pins
const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;

// defining variables
long duration;
int distance;

void setup() {
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(buzzerPin, OUTPUT); //pin for buzzer
    Serial.begin(9600); // Starts the serial communication
}
void loop() {
  digitalWrite(trigPin, LOW); // Clearing the trigPin
  delayMicroseconds(2); // Sets the trigPin on LOW state for 2 micro seconds
  digitalWrite(trigPin, HIGH); // Trigering the trigPin
  delayMicroseconds(10); // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, LOW); // Clearing the trigPin
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2; // Calculating the distance
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
 if(distance<30){  //distance between stik and obect is less than 3o cm
     digitalWrite(buzzerPin,HIGH); //buzzer on for 550 ms
     delay(550); //delay for 550ms
     digitalWrite(buzzerPin,LOW); //buzzer off
    }
 else if(diistance<15){ ////distance between stik and obect is less than 20 cm
     digitalWrite(buzzerPin,HIGH); // buzzer on for 70 ms
     delay(70); //delay for 70 ms
     digitalWrite(buzzerPin,LOW); // buzzer off
    }
 else{
      digitalWrite(buzzerPin,LOW);
    }
 delay(10); //10 ms wait for starting the loop again
}