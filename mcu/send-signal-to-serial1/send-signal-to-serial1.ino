/*
 * This program send signal 1 to serial port with baudrate: 57600
 * whenever it detects D13 signal is low
 */

const int debounce=20;
const int sw=13;

void setup() {
  Serial.begin(9600);
  Serial1.begin(57600); // Important! communicate with MT7688
  Serial.println("reading from A0..");
  pinMode(sw, INPUT_PULLUP);
}
void loop() {

  if(digitalRead(sw) == 0){
    delay(debounce);
    while(digitalRead(sw)==0)
      ;
    Serial.println(1);
    Serial1.print(1);    
  }

  delay(50);
}

