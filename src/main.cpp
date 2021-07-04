#include <Arduino.h>

const uint8_t  Number_Stages = 10; // HAVE TO BE ALWAYS "PAIR"
const uint8_t  Number_Step = 10;


int Max_Iteration =4;

unsigned long Delay_Chosen = 1000;

uint8_t Angles_Servo[Number_Stages - 1]; // et oui, je me fais chier la byte avec cette putain d'indexation.
uint8_t Angle_Step = 10;


uint16_t my_array_Power[Number_Step - 1];

uint8_t maxIndex[Number_Stages - 1];
uint16_t maxValuePower[Number_Stages - 1] ;


uint16_t MaxMaxValuePower;
uint8_t MaxMaxIndices;
uint8_t Search_Best_Step;
uint8_t Search_Best_Servo;


int period = 4000;
unsigned long time_now = 0;

void step(uint8_t Stages)
{

  maxValuePower[Stages] = my_array_Power[Number_Step - 1];
  maxIndex[Stages] = Number_Step - 1;

  for (int j = 0; j < Number_Step; j++)
  {
    my_array_Power[j] = random(0, 50000);
    Serial.println( my_array_Power[j]);

    if ( my_array_Power[j] > maxValuePower[Stages]) {


      maxValuePower[Stages] = my_array_Power[j];
      maxIndex[Stages] = j;


    }
  }
}

void setup()
{


  randomSeed(analogRead(0)) ;
  Serial.begin(9600);

  //  Angles_Servo[0] = 170;
  //  for (uint8_t i = 1; i < Number_Stages; i++)
  //  {
  //    Angles_Servo[i] = Angles_Servo[i - 1] - Angle_Step;
  //  }
  //
  //  for (uint8_t i = 0; i < Number_Stages; i++)
  //  {
  //    Serial.println(Angles_Servo[i]);
  //  }

  memset(my_array_Power, 0, sizeof(my_array_Power));
  memset( maxIndex, 0, sizeof( maxIndex));
  memset( maxValuePower, 0, sizeof( maxValuePower));


  for (int i=0;i<Number_Stages;i++)
  {
    Serial.println(maxIndex[i]);
  }
  //
  //
  //  Serial.println(my_array_Power[Number_Step - 1]);
  //  Serial.println(maxIndex[Number_Stages - 1]);
  //  Serial.println(maxValuePower[Number_Stages - 1]);

}


void loop()
{


  for (int i = 0 ; i < Max_Iteration; i++)
  {


    Serial.print(i); Serial.print(",");
//    step(i);
//
    Serial.print(i); Serial.print(",");
    Serial.print(maxIndex[i]); Serial.print(",");
    Serial.println(maxValuePower[i]);
    
//    time_now = millis();
//    while(millis() < time_now + period){
//        //wait approx. [period] ms
//    }

delay(1000);
  }

  

}
