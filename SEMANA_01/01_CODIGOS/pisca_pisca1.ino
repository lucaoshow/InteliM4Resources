void setup()
{
  pinMode(9, OUTPUT);
}

void loop()
{
  digitalWrite(9, HIGH);
  delay(5000); // Wait for 5000 millisecond(s)
  digitalWrite(9, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}