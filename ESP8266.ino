#include <Arduino.h>

#ifdef ESP32
    #include <WiFi.h>
#else
    #include <ESP8266WiFi.h>
#endif

#include "AudioFileSourcePROGMEM.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2SNoDAC.h"
#include "AccidentAudio.h"

#define VIBRATION_SENSOR_PIN D5

AudioGeneratorWAV *wav;
AudioFileSourcePROGMEM *file;
AudioOutputI2SNoDAC *out;

void initializeAudio(){
  audioLogger = &Serial;
  file = new AudioFileSourcePROGMEM( viola, sizeof(viola) );
  out = new AudioOutputI2SNoDAC();
  wav = new AudioGeneratorWAV(); 
}

void setup()
{
  WiFi.mode(WIFI_OFF); 
  initializeAudio();
  pinMode(VIBRATION_SENSOR_PIN,INPUT);
}

void loop()
{
  
  if(digitalRead(VIBRATION_SENSOR_PIN)==HIGH){
    initializeAudio();
    wav->begin(file,out);//RX pin to listen to the audio
  }
    
  if(wav->isRunning()){
    if (!wav->loop())wav->stop();//stop audio when completed
  }

}

