int sensor4 = A4;
int sensor3 = A3;
int sensor2 = A2;
int sensor1 = A1;
int sensor0 = A0;
int mata0; 
int mata1; 
int mata2; 
int mata3; 
int mata4;
int r , d ;
void setup()
{
  Serial.begin(9600);
}

void loop()
{

  mata0 = analogRead(sensor0);
  mata1 = analogRead(sensor1); 
  mata2 = analogRead(sensor2); 
  mata3 = analogRead(sensor3); 
  mata4 = analogRead(sensor4); 
  Serial.print(mata0);
  Serial.print("   ");
  Serial.print(mata1);
  Serial.print("   ");
  Serial.print(mata2);
  Serial.print("   ");
  Serial.print(mata3);
  Serial.print("   ");
  Serial.print(mata4);
  Serial.println(" ");
 
}