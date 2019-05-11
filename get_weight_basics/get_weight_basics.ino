#include "HX711.h"

// HX711.DOUT   - pin #A1
// HX711.PD_SCK   - pin #A0

HX711 scale(A1, A0);      // parameter "gain" is ommited; the default value 128 is used by the library
/* CALIBRATING STEPS How to Calibrate Your Scale

1.  Call set_scale() with no parameter.
2.  Call tare() with no parameter.
3.  Place a known weight on the scale and call get_units(10).
4.  Divide the result in step 3 to your known weight. You should get about the parameter you need to pass to set_scale.
5.  Adjust the parameter in step 4 until you get an accurate reading.
*/

void setup() 
{
  long calibration = -433593.00/20000;
  Serial.begin(9600);
  Serial.print("Beginning");
  scale.set_scale(calibration);    // instead of Calibration put a number you calculated on last program   

}
void loop() 
{
  float ff = getWeight();
  Serial.println(ff);
  delay(2000);
}


double getWeight(){
  scale.power_up();
  float ff=scale.get_units(10);
  scale.power_down();   
  return ff;
}
