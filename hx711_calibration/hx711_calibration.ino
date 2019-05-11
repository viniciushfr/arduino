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
  Serial.begin(9600);
  Serial.println("Beginning");
  scale.set_scale();                    // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare();                            // reset the scale to 0
  Serial.println("10 segundos para colocar na balança (20kg)"); // my upper plate is about 6 kg ->6000 g
  delay(10000);
  float f= scale.get_units(10);
  Serial.print("f: ");
  Serial.println(f);                      //here program prints values we need to divide with 6000g 
  Serial.println("calibracao =  f / 20000");
  Serial.print("c = ");
  Serial.println(f/20000); 
 //
}
void loop() 
{

}
