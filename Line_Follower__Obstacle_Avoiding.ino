/* The source Code from : https://github.com/riyadhasan24
 * By Md. Riyad Hasan
 */

int IN_1 = 11;
int IN_2 = 10;

int IN_3 = 6;
int IN_4 = 5;

int TrigPin = 2;
int EchoPin = 3;

float Duration;
float Distance;

int Speed = 55;

int Left_Sensor = A1; 
int Right_Sensor = A0; 

int SetDistance = 20;

void setup()
  {
    Serial.begin(9600);
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
 
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);
 
    pinMode(Left_Sensor, INPUT);
    pinMode(Right_Sensor, INPUT);
    
    pinMode(TrigPin, OUTPUT);
    pinMode(EchoPin, INPUT); 
 }

void loop()
{
  digitalWrite(TrigPin, LOW);
  delayMicroseconds(5);

  digitalWrite(TrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin, LOW);
  Duration = pulseIn(EchoPin, HIGH);
  Distance = Duration*0.034/2;    
    
    if(Distance > SetDistance)
      {
           if ((digitalRead(Left_Sensor) == LOW)&&(digitalRead(Right_Sensor) == LOW))
            {
              Rover_ForWard();
            }
          if ((digitalRead(Left_Sensor) == LOW)&&(digitalRead(Right_Sensor) == HIGH))
            {
              Rover_RightWard();
            }
          if ((digitalRead(Left_Sensor) == HIGH)&&(digitalRead(Right_Sensor) == LOW))
            {
              Rover_LeftWard();
            }
          if ((digitalRead(Left_Sensor) == HIGH)&&(digitalRead(Right_Sensor) == HIGH))
            {
              Rover_Stop();
            }
      }
     else
        {
            Rover_Stop();
            delay(200);
            Rover_RightWard();
            delay(700);
            Rover_ForWard();
            delay(400);
            Rover_LeftWard();
            delay(700);
          }     
}


  void Rover_Stop()
    {
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, LOW);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, LOW);  
    }

  void Rover_ForWard()
    {
      analogWrite(IN_1, Speed);
      analogWrite(IN_2, LOW);
      analogWrite(IN_3, Speed);
      analogWrite(IN_4, LOW);  
    }
 


  void Rover_RightWard()
    {
      analogWrite(IN_1, LOW);
      analogWrite(IN_2, LOW);
      analogWrite(IN_3, Speed);
      analogWrite(IN_4, LOW);  
    }

  void Rover_LeftWard()
    {
      analogWrite(IN_1, Speed);
      analogWrite(IN_2, LOW);
      analogWrite(IN_3, LOW);
      analogWrite(IN_4, LOW);     
    }
