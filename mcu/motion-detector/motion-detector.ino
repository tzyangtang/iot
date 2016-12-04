const int led = 13; //LED 連接至數位腳13。
const int PIRout = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT); //設定數位腳13 為輸出模式。
  pinMode(PIRout, INPUT);
  Serial.begin(9600);
  Serial1.begin(57600); // Important! communicate with MT7688
  Serial.println("reading from A0..");
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(PIRout); //讀取PIR狀態(PIR 短路夾連接至H)。
  if (val == HIGH) //PIR 輸出狀態為HIGH(有物體移動)?
  {
    Serial.println(1);
    Serial1.print(1);
    while (digitalRead(PIRout) == HIGH) {
      digitalWrite(led, HIGH); //閃爍LED。
      delay(50); //點亮LED 50ms。
      digitalWrite(led, LOW);
      delay(50); //關閉LED 50ms。
    }
  }
  else //PIR 輸出狀態為LOW。
    digitalWrite(led, LOW);
}
