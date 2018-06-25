char msg[4] = {'A','B','C',0};
unsigned short poly = 0xEA;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println((short)msg[0], BIN);
  Serial.println(poly, BIN);
}
