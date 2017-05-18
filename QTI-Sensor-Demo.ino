int pins[] = {6, 7, 8, 9};   // pins for the sensors stored in an array
int values[4];               // 0 or 1 depending on whether the object read by the sensor is light or dark
int durations[4];            // stores the actual duration value

int threshold = 100;         // this value has to be higher than the value when the sensor is hovering over a black-colored object

void setup() {
  Serial.begin(9600);
}

void loop() {
  checkSensors();
  /* 
    for(int i = 0; i < sizeof(pins)/2; i++) {
      Serial.print("#"); 
      Serial.print(pins[i]); 
      Serial.print(" - ");
      Serial.print(values[i]);
      Serial.print(" (");
      Serial.print(durations[i]);
      Serial.println(")");
    }
    Serial.println("-------------");
    delay(2000);
  */
}

/* 
 * INPUT:  Reads the values from the QTI sensors stored in the array pins[]
 * OUTPUT: A 0 or 1 in array values[] depending on if the sensor reads a dark or light objects
 * In order to calibrate what is dark and what is light, use the threshold variable above
 */
void checkSensors() {
  for(int i = 0; i < sizeof(pins)/2; i++) { 
    long duration = 0;                      //
    pinMode(pins[i], OUTPUT);               // code that actually    
    digitalWrite(pins[i], HIGH);            // reads from the sensor 
    delay(1);                               // 
    pinMode(pins[i], INPUT);                // low values from the sensor
    digitalWrite(pins[i], LOW);             // are dark objects, high
    while(digitalRead(pins[i])){            // values are light objects
      duration++;                           //
    }                                       
    
    durations[i] = duration;                // store values in arrays
    values[i] = (duration > threshold);     // 
  }
}




