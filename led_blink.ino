int ledb = 13;
int ledb1 = 11;
void setup() {
  pinMode( ledb , OUTPUT );
  pinMode( ledb1 , OUTPUT);
}
void loop() {
  digitalWrite( ledb , HIGH);
  delay(500);
  digitalWrite( ledb1 , HIGH);
  delay(500);
  digitalWrite( ledb , LOW );
  delay(500);
  digitalWrite( ledb1 , LOW);
  delay(500);
}