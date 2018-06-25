  char var = 32;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(var);
  //if( 31 < var < 127)
    var = (126 -var <= 47) ? var -47 : var +47;
}


