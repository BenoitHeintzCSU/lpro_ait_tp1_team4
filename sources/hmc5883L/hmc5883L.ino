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
#include <DRV8835MotorShield.h>
#define LED_PIN 13

DRV8835MotorShield motors;
void motor_command(int command);

#define X 3  //X, Y and Z register addresses
#define Y 7
#define Z 5
double Xmagnetic;
double Ymagnetic;
double Zmagnetic;
int E[2] = {0, 0}; //[n-2,n-1]
int S[2] = {0, 0}; //[n-2,n-1]
int Kp = 10;
int Ki = 1;
int Kd = 1;
int Erreur = 0;
int Total_Erreur = 0;
int Erreur_Prec = 0;
int P = 0;
int I = 0;
int D = 0;
int vitesse = 0;
int command;

/**
 * Setup
 */
void setup()
{
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Wire.begin();         //Initialisation de la librairie Wire
  Init_HMC5803L();    //Initialiser le module boussole
}

/**
 * loop
 */
void loop()
{
  Ymagnetic = HMC5883L_read(Y);
  Serial.println (Ymagnetic);
  vitesse = 0.002586 * E[1] + 0.0016858 * E[0] + 1.5113 * S[1] - 0.5487610 * S[0];
  Erreur = 0 - Ymagnetic;
  Total_Erreur += Erreur;
  P = Erreur * Kp;
  I = Total_Erreur * Ki;
  D = (Erreur - Erreur_Prec) * Kd;
  Erreur_Prec = Erreur;
  command = P + I + D;
  vitesse = command;
  E[0] = E[1];
  E[1] = command;
  S[0] = S[1];
  S[1] = Ymagnetic;
  if(vitesse>200){motor_command(200);}
  else if(vitesse<-200){motor_command(-200);}
  else{motor_command(vitesse);}
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

void motor_command(int command)
{
  if (command < 0) {
    motors.flipM1(true);
    motors.setM1Speed(-command);
    digitalWrite(LED_PIN, LOW);
  }
  else {
    motors.flipM1(false);
    motors.setM1Speed(command);
    digitalWrite(LED_PIN, HIGH);
  }
}
