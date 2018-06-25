/*void rot47() {
  for(byte i =0; i <sizeof(var); i++)
   var[i] = (126 -var[i] <=47) ? var[i] -47 : var[i] +47; 
} */

void setup() {
  Serial.begin(9600);
}

void loop() {
  char lol[2] = {'A', 'B'};
  Serial.println("---------------");
  Serial.println(rot47(lol[1]));
}


char rot47(char var) {
  var = (126 -var <=47) ? var -47 : var +47;
  return(var);
}
