String frame;

unsigned int dst = 7;
unsigned int src = 7;

char data[2] = {12, 13};

void setup() {
  Serial.begin(9600);
}

void loop() {
  frame += dst;
  frame += src;
  
  for(byte i =0; i <sizeof(data); i++){
    data[i] = rot47(data[i]);
    frame += data[i];
  }
  
  Serial.println(frame);
  exit(0);
}

char rot47(char var) {
  var = (126 -var <=47) ? var -47 : var +47;
  return(var);
}
