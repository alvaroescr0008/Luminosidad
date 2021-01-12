#include<Wire.h>
#include<Adafruit_ADS1015.h>
Adafruit_ADS1115 ads1115(0x48);
//Aquí almacenamos los datos recogidos del LDR:

int sol=160;
int nublado=80;
int noche=17;

void setup()
{

//inicializamos monitor serie para visualizar valores de LDR
Serial.begin(9600);
ads1115.begin();
ads1115.setGain(GAIN_ONE);
}

void loop()
{
//Guardamos el valor leido en una variable
//IMPORTANTE UTILIZAR EL SERIAL PARA VER LOS VALORES Y COMPROBAR QUE RECIBE VALORES BUENOS
int adc3;
int16_t luminosidad;
adc3=ads1115.readADC_SingleEnded(3);

//Serial.println(luminosidad);
Serial.println(adc3);

if(adc3 >= sol)
{
  Serial.println("Dia despejado");
}
else if(adc3<=nublado && adc3>noche)
{
  Serial.println("Nublado");
}
else if(adc3<=noche)
{
  Serial.println("Es de noche");
}

delay(2000);
//Deepsleep en 10 segundos
ESP.deepSleep(10*1000000);
} 
