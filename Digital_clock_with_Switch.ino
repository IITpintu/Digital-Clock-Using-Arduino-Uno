/*Author: Pintu Kumar
Digital Clock Using Seven Segment Display and Arduino Uno*/

int analogU1,analogT1,analogU2,analogT2;
 void dgt1(int x) // seconds 1st digit
{
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  display(x);
}

void dgt2(int x) // seconds 2nd digit
{
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  display(x);
}

void dgt3(int x)// minute 1st digit
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  display(x);
}

void dgt4(int x)//minute 2nd digit
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, HIGH);
  display(x);
}

void dgt5(int x)//hour 1st digit
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  display(x);
}

void dgt6(int x)//hour 2nd digit
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  display(x);
}

void setup() 
{
  pinMode(0, OUTPUT); //pins for seven segment display
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  pinMode(7, OUTPUT);  //pins for common cathode
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  pinMode(13, INPUT);

   
for (int check=1;check ==1;check =digitalRead(13))//control the potentiometer
{
  potent();
}
}


void display(int dec)   // function for displaying number on seven segment display
{

  int a, b, c, d, e, f, g, A, B, C, D;

  A = dec % 2;
  dec = dec / 2;
  B = dec % 2;
  dec = dec / 2;
  C = dec % 2;
  D = dec / 2;

  a = A && !B && !C && !D || !A && !B && C && !D;
  b = A && !B && C && !D || !A && B && C && !D;
  c = !A && B && !C && !D;
  d = A && !B && !C && !D || !A && !B && C && !D || A && B && C && !D;
  e = A && !B && !C && !D || A && B && !C && !D || !A && !B && C && !D || A && !B && C && !D || A && B && C && !D || A && !B && !C && D;
  f = A && !B && !C && !D || !A && B && !C && !D || A && B && !C && !D || A && B && C && !D;
  g = A && !B && !C && !D || !A && !B && !C && !D || A && B && C && !D;

  digitalWrite(3, !a);
  digitalWrite(2, !b);
  digitalWrite(6, !c);
  digitalWrite(5, !d);
  digitalWrite(4, !e);
  digitalWrite(1, !f);
  digitalWrite(0, !g);
}

void displayPot1(int u, int t)
{
  dgt6(t);
  delay(2);
  dgt5(u);
  delay(2);
}

void displayPot2(int u, int t)
{
  dgt4(t);
  delay(2);
  dgt3(u);
  delay(2);
}


 void potent()
{
  int analog2=analogRead(A0);
  int analog1=analogRead(A1);
  int Scaling1=analog1/(1024/24);
  int Scaling2=analog2/(1024/60);
  analogU1=Scaling1%10;
  analogT1=Scaling1/10;
  analogU2=Scaling2%10;
  analogT2=Scaling2/10;
displayPot1(analogU1,analogT1);
  displayPot2(analogU2,analogT2);
  
 
}

int count=-1;
int z=0;


void loop()
{
count=analogT1-1;  
for(int i=analogT1; i<3; i++)
{
 count++;
 if(count==2)
 z=4;
 else
 z=10;

  for (int j=analogU1; j<z; j++)
  {
   for( int k=analogT2; k<6; k++)
    {
      for(int l=analogU2; l<10; l++)
      {
            for(int m=0; m<6; m++)
        {
          for(int p=0;p<10;p++)
          {
            
        
    int startTime= millis() ;//implementing delay
               for(int n=0; n<1000-6; n=millis() - startTime)
          { 


                               
         dgt6(i);
         delay(2);
         dgt5(j);
         delay(2); 
         dgt4(k);
         delay(2);         
         dgt3(l);
         delay(2);
        dgt2(m);
        delay(2); 
        dgt1(p);        
          delay(2);           
          }
          }}}
          analogU2=0;
          }
         analogT2=0; 
          }
          
          }

          analogT1=0;
          analogU1=0;
          
}         

  
