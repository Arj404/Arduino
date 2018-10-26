int sensor0 = A4;
int sensor1 = A3;
int sensor2 = A2;
int sensor3 = A1;
int sensor4 = A0;
int mata0; 
int mata1; 
int mata2; 
int mata3; 
int mata4;

int button = 8;
int xax=0;

int motorR1 = 5; 
int motorR2 = 7;
int onR = 6; 
int onL = 3; 
int motorL1 = 4;
int motorL2 = 2;

int data;
unsigned char s[5]; 

int pathlength; 
int readpath; 
char path[99]; 

int threshold1 = 750; 
int threshold2 = 900; 

int BLUEled = 13;
int GREENled = 12;
int YELLOWled = 11;

void rightforward()
{
  digitalWrite(motorR1, HIGH);
  digitalWrite(motorR2, LOW);
}

void leftforward()
{
  digitalWrite(motorL1, HIGH);
  digitalWrite(motorL2, LOW);
}

void rightbackward()
{
  digitalWrite(motorR1, LOW);
  digitalWrite(motorR2, HIGH);
}

void leftbackward()
{
  digitalWrite(motorL1, LOW);
  digitalWrite(motorL2, HIGH);
}

void strongright()
{
  analogWrite(onL, 100);
  leftforward();
  analogWrite(onR, 90);
  rightbackward();
}


void midright()
{
  analogWrite(onL, 250);
  leftforward();
  analogWrite(onR, 150);
  rightforward();
}

void moveforward()
{
  analogWrite(onL, 255);
  leftforward();
  analogWrite(onR, 255); 
  rightforward();
}
void movebackward()
{
  analogWrite(onL, 255);
  leftbackward();
  analogWrite(onR, 255); 
  rightbackward();
  delay(300);
}

void midleft()
{
  analogWrite(onL, 150);
  leftforward();
  analogWrite(onR,250);
  rightforward();
}

void strongleft()
{
  analogWrite(onL, 90);
  leftbackward();
  analogWrite(onR, 100);
  rightforward();
}

void turnright()
{
  analogWrite(onL, 150);
  leftforward();
  analogWrite(onR, 150);
  rightbackward();
}

void turnleft()
{
  analogWrite(onL, 150);
  leftbackward();
  analogWrite(onR, 150);
  rightforward();
}

void righttillstraight()
{
  turnright();
  delay(500); 
  readsensor();
  while (s[2]==0)
  {
    turnright();readsensor();
  }
}

void lefttillstraight()
{
  turnleft();
  delay(500); 
  readsensor();
  while (s[2]==0)
  {
    turnleft();readsensor();
  }
}

void turnaround()
{
  lefttillstraight();
}

void stop()
{  
  analogWrite(onL, 0);
  leftbackward();
  analogWrite(onR, 0);
  rightbackward();
}

void lilmoveforward()
{
  moveforward();
  delay(150); 
  readsensor();
}
void ONforBLUEled()
{
  digitalWrite (BLUEled, HIGH); delay(25);
  digitalWrite (BLUEled, LOW);
}

void ONforGREENled()
{
  digitalWrite (GREENled, HIGH); delay(25);
  digitalWrite (GREENled, LOW);
}

void ONforYELLOWled()
{
  digitalWrite (YELLOWled, HIGH); delay(25);
  digitalWrite (YELLOWled, LOW);
}

void readsensor()
{
  //if declared outside, the sensor readings become “11111”
  mata0 = analogRead(sensor0);
  mata1 = analogRead(sensor1); 
  mata2 = analogRead(sensor2); 
  mata3 = analogRead(sensor3); 
  mata4 = analogRead(sensor4); 

//converting to digital
if (mata0 > threshold2)
  {s[0] = 1;}
else
  {s[0] = 0;}

if (mata1 < threshold1)
  {s[1] = 1;}
else
  {s[1] = 0;}

if (mata2 < threshold1)
  {s[2] = 1;}
else
  {s[2] = 0;}

if (mata3 < threshold1)
  {s[3] = 1;}
else
  {s[3] = 0;}

if (mata4 > threshold2)
  {s[4] = 1;}
else
  {s[4] = 0;}

//change the sensor readings into a series of binary number
data=(s[0]*1000)+(s[1]*1000)+(s[2]*100)+(s[3]*10)+(s[4]*1);

//to display the sensor readings on serial monitor
Serial.print(s[0]);
Serial.print("   ");
Serial.print(s[1]);
Serial.print("   ");
Serial.print(s[2]);
Serial.print("   ");
Serial.print(s[3]);
Serial.print("   ");
Serial.print(s[4]);
Serial.println(" ");
}

//Crossroad condition -------------- 0b00abcde
void condition()
{
 if (data==100)
   {moveforward();}
 else if (data==1)
   {
    movebackward();
    strongright();
    readsensor();
    while (s[3]==0)
    {
      strongright();
      readsensor();
    }
   }  
 else if (data==11)
   {strongright();}  
 else if (data==10)
   {strongright();}
 else if (data==110)
   {midright();}
 else if (data==1100)
   {midleft();}
 else if (data==1000)
   {strongleft();}
 else if (data==11000)
   {strongleft();}
 else if (data==10000)
   {
    movebackward();
    strongleft();
    readsensor();
    while (s[1]==0)
    {
     strongleft();
     readsensor();
    }
   }
 else //there is a right angle turn or crossroads
   {
      if (data==0) //dead end
        {
          lilmoveforward();
          delay(400);
          if(data==0){
            turnaround();
            path[pathlength]='U';pathlength++;//save U
            ONforYELLOWled();
          }
          
        }
      else if (data==11111) //T, +, end of maze
        {
          lilmoveforward();
          if (data==0)// T crossroad
            {
              lilmoveforward(); //turning stabilizer
              righttillstraight();
              path[pathlength]='R';pathlength++;//save R
              ONforGREENled();
            }
          else if (data==11111)//end of maze
            {
              stop(); //stopping the robot
              path[pathlength]='F';pathlength++;//save F
              
              //sign for the end of maze
              ONforBLUEled();delay(300);
              ONforBLUEled();delay(300);
              ONforYELLOWled();delay(300);
              ONforYELLOWled();delay(300);
              ONforGREENled();delay(300);
              ONforGREENled();delay(300);
              ONforBLUEled();ONforYELLOWled();ONforGREENled();
              
              shortpath(); //calculate the shortest path
              ONforBLUEled();ONforYELLOWled();ONforGREENled();
              while(xax==1){
              //sign to prepare the robot (put it back) on the starting position
              ONforBLUEled();delay(300);
              ONforYELLOWled();delay(1000);
              ONforGREENled();delay(300);
              ONforGREENled();delay(300);
              ONforGREENled();delay(1000);
              
              shortestpath(); //move through the shortest path
            }}
          else //there is a straight line 00100 dll (+ crossroad)
            {
              lilmoveforward(); //turning stabilizer
              righttillstraight();
              path[pathlength]='R';pathlength++;//save R
              ONforGREENled();
            }
        }
  //straight or right junction
      else if ((data==111)||(data==1111))
        {
          lilmoveforward();lilmoveforward();
          if (data==0)//right only
            {
              lilmoveforward();
              righttillstraight();
            }
    else if (s[0]==0)
                  {
              lilmoveforward();
              righttillstraight();
              path[pathlength]='R';pathlength++;//save R
              ONforGREENled();
            }
        }
//left or straight junction
      else if ((data==11100)||(data==11110))
        {
          lilmoveforward();lilmoveforward();
          if (data==0) //left only
            {
              lilmoveforward();
              lefttillstraight();
            }
        else if (s[4]==0) //there is a straight path
            {
              moveforward();
              path[pathlength]='S';pathlength++;//save S
              ONforBLUEled();
            }
         }
    }
}

void shortpath() //calculate the shortest path
{
  //because (..F) is the last and there is no U recorderd before F 
  int x = (pathlength-2);

  while (x > 0)  
  {
    if (path[x]=='U')
      {
        if (path[x-1]=='L' && path[x+1]=='L')
          {path[x-1]='S';path[x]='O';path[x+1]='O';}
        else if (path[x-1]=='L' && path[x+1]=='S')
          {path[x-1]='R';path[x]='O';path[x+1]='O';}
        else if (path[x-1]=='R' && path[x+1]=='R')
          {path[x-1]='S';path[x]='O';path[x+1]='O';}
        else if (path[x-1]=='R' && path[x+1]=='S')
          {path[x-1]='L';path[x]='O';path[x+1]='O';}
        else if (path[x-1]=='S' && path[x+1]=='L')
          {path[x-1]='R';path[x]='O';path[x+1]='O';}
        else if (path[x-1]=='S' && path[x+1]=='R')
          {path[x-1]='L';path[x]='O';path[x+1]='O';}
        else if (path[x-1]=='L' && path[x+1]=='R')
          {path[x-1]='U';path[x]='O';path[x+1]='O';}
        else if (path[x-1]=='R' && path[x+1]=='L')
          {path[x-1]='U';path[x]='O';path[x+1]='O';}
        else if (path[x-1]=='S' && path[x+1]=='S')
          {path[x-1]='U';path[x]='O';path[x+1]='O';}
        //---------------------------------------
        x--;
      }
    else
      {x--;}
  }
}

void shortestpath()
{
 readsensor();
 if (data==100)
   {moveforward();}
 else if (data==1)
   {
    movebackward();
    strongright();
    readsensor();
    while (s[3]==0)
    {
      strongright();
      readsensor();
    }
   }
 else if (data==11)
   {strongright();}  
 else if (data==10)
   {strongright();}
 else if (data==110)
   {midright();}
 else if (data==1100)
   {midleft();}
 else if (data==1000)
   {strongleft();}
 else if (data==11000)
   {strongleft();}
 else if (data==10000)
   {
    movebackward();
    strongleft();
    readsensor();
    while (s[1]==0)
    {
     strongleft();
     readsensor();
    }
   }
 else
     //right or straight
     if ((data==111)||(data==1111))
      {
        lilmoveforward();
        if (data==0)//right only
          {
            lilmoveforward();
            righttillstraight();
          }
        else //there is a straight path
          {
            choosepath();
          }
      }
    //left or straight
    else if ((data==11100)||(data==11110))
      {
        lilmoveforward();
        if (data==0) //left only
          {
            lilmoveforward();
            lefttillstraight();
          }
        else //there is a straight path
          {
            choosepath();
          }
      }
    //T, +, or END OF MAZE
    else if  (data==11111)
      {
        choosepath();
      }
  shortestpath();
}  

void choosepath()//to get rid of the effect of “path[]==0” in the record
{
  if (path[readpath]=='F')
    { 
      stop();finish();
    }
  else if (path[readpath]=='R')
    {
      ONforGREENled();
      righttillstraight();
    }
  else if (path[readpath]=='S')
    {
      ONforGREENled();ONforBLUEled();
      moveforward();delay(200);
    }
  else if (path[readpath]=='L')
    {
      ONforGREENled();ONforYELLOWled();
      lefttillstraight();
    }
  else if (path[readpath]=='O')
    {
      readpath++;choosepath();
    } 
  readpath++;
  shortestpath();
}

void finish()
{
  ONforBLUEled();delay(100);
  ONforYELLOWled();delay(100);
  ONforGREENled();delay(100);
  finish();
}

void setup()
{
  Serial.begin(9600);
  pinMode(motorR1, OUTPUT);
  pinMode(motorL1, OUTPUT);
  pinMode(motorR2, OUTPUT);
  pinMode(motorL2, OUTPUT);
  pinMode(onR, OUTPUT);
  pinMode(onL, OUTPUT);
  pinMode(BLUEled, OUTPUT);
  pinMode(YELLOWled, OUTPUT);
  pinMode(GREENled, OUTPUT);
  analogReference(INTERNAL);
  pinMode(button, OUTPUT);
}

void loop()
{

   readsensor();
   condition();
     if(digitalRead(button) == HIGH){
    xax=1;
  }
}