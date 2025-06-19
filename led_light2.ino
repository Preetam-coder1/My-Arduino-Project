int led =13;
int led1 =2;
void setup()
{
  pinMode( led , OUTPUT );
  pinMode( led1 ,OUTPUT );
}
void loop()
{
  digitalWrite(led, HIGH);
  digitalWrite(led1, HIGH);
}