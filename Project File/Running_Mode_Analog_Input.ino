/* In this project we will modify previous project (Auto-Trigger-Mode-Analog-Input) to put the ADC in continuously running mode.
 * Then we will print the value in serial monitor when the position of the potentiometer was adjusted from 0 to 1023.
 * The Potentiometer will be assigned to the analog pin PC3(Analog pin A3) of Arduino UNO.
 * Owner: Muhammad Izzat 1717987
 * Date: 13 November 2020
 */


char*admux= (char*)0x7C; //signed or unsigned does not matter if we do not work with decimal.
char*adcsra= (char*)0x7A;
volatile unsigned char *adch= (unsigned char*)0x79;
volatile unsigned char *adcl= (unsigned char*)0x78;

void setup() {
  // put your setup code here, to run once:
  *admux=0b01000011;  //Set analog reference to AVCC and analog source to PC3.
  *adcsra=0b11100111; //Enable ADC, start conversion, enable auto-triggering
                      // and set pre-scalerto 128
   Serial.begin(9600);//Setting up Serial Baudrate at 9600

}

void loop() {
  // put your main code here, to run repeatedly:
  while(1)
  {
    int lowbyte= (*adcl);                //Capture low byte
    int highbyte= (*adch);               //Capture high byte
    int value = (highbyte<<8) | lowbyte; //Merge high byte and low byte
    Serial.println(value);               //Print the value in serial monitor
  }
}
