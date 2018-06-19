typedef struct {
  unsigned int fir_thr : 3;
  unsigned int sec_thr : 3;
  unsigned int thi_two : 2;
} byte332;

void setup() {
  Serial.begin(9600);
}

void loop() {
  byte332 sensors;
  sensors.thi_two = 1;
  Serial.println(sensors.thi_two);
  exit(0);
}

