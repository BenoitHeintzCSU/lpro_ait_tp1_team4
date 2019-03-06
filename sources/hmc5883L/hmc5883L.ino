/**
 * LPRO AIT 2019
 * TP1
 * 
 * Compass HMC5883L demo
 * 
 * This demo prints the magnetic field measured along the Y-axis
 * 
 */
#include <Wire.h>               //I2C lib
#define HMC5883L_address 0x1E  //I2C address of the HMC5883L

#define X 3  //X, Y and Z register addresses
#define Y 7
#define Z 5
double Xmagnetic;
double Ymagnetic;
double Zmagnetic;

/**
 * Setup
 */
void setup()
{
  Serial.begin(9600);
  Wire.begin();         //Initialisation de la livrairie Wire
  Init_HMC5803L();    //Initialiser le module boussole
}

/**
 * loop
 */
void loop()
{
  Xmagnetic = HMC5883L_read(X);
  Ymagnetic = HMC5883L_read(Y);
  Zmagnetic = HMC5883L_read(Z);
  Serial.println (Ymagnetic);
  delay(100);
}


/**
 * Init_HMC5803L
 * Initialize the compass
 */
void Init_HMC5803L(void)
{
  /* Set the module to 8x averaging and 15Hz measurement rate */
  Wire.beginTransmission(HMC5883L_address);
  Wire.write(0x00);
  Wire.write(0x70);

  Wire.write(0x01);
  Wire.write(0xA0);   //Règle un gain de 5
  Wire.endTransmission();
}

/**
 * HMC5803L_Read
 * Read 1 axis
 */
int HMC5883L_read(byte Axis)
{
  int Result;
  // Initiate a single measurement
  Wire.beginTransmission(HMC5883L_address);
  Wire.write(0x02);
  Wire.write(0x01);
  Wire.endTransmission();
  delay(6);

  // Move modules the resiger pointer to one of the axis data registers
  Wire.beginTransmission(HMC5883L_address);
  Wire.write(Axis);
  Wire.endTransmission();

  // Read the data from registers (there are two 8 bit registers for each axis)
  Wire.requestFrom(HMC5883L_address, 2);
  Result = Wire.read() << 8;
  Result |= Wire.read();

  return Result;
}
