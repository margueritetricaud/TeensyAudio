
#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlaySdWav           playWav1;     //xy=263,553
AudioOutputI2S           i2s1;           //xy=633,710
AudioConnection          patchCord1(playWav1, 0, i2s1, 0);
AudioConnection          patchCord2(playWav1, 1, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=593,849
// GUItool: end automatically generated code

float vol = 0.75;

// SD CARD ACCESS
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14

//INPUT/OUTPUT PARAMETERS
char sample[] = "BIRD.WAV";  // replace this with the name of the WAV file you want to play from the SD card
char *currentSample;  

//-------------------------- SETUP ---------------------------//
void setup() {
  
  Serial.begin(9600); //serial communication between the teensy and the computer
  Serial.println("Device starting up");
  
   // ----- Audio Setup ---//
      // Audio connections require memory to work.  For more detailed information, see the MemoryAndCpuUsage example
     AudioMemory(8);
     sgtl5000_1.enable();
     sgtl5000_1.volume(vol);
     SPI.setMOSI(SDCARD_MOSI_PIN);
      SPI.setSCK(SDCARD_SCK_PIN);
    if (!(SD.begin(SDCARD_CS_PIN))) {
      // stop here, but print a message repetitively
      while (1) {
        Serial.println("Unable to access the SD card");
        delay(500);
      }
    }else{
       Serial.println("SD card found");
    }
    Serial.println("Device ready");
}


// ------------------------------- MAIN LOOP --------------------------------- //
void loop() {

  /*------ INPUT READING -----*/
 
  //Serial.println(vol);
   
  /*----- OUTPUT LOGIC -----*/

  audioTest(); // Plays the audio sample
}


// ------------------------- AUDIO FUNCTIONS ---------------------------------- //
void playFile(const char *filename)
{
  // Start playing the file if it's not already playing
  if(!playWav1.isPlaying() || (playWav1.isPlaying() &&  currentSample != filename) ) {
    Serial.print("Playing file: ");
    Serial.println(filename);
    playWav1.play(filename);
    currentSample = filename;
  }
  // A brief delay for the library read WAV info
  delay(25);
}

void stopFile(const char *filename)
{
  if(playWav1.isPlaying()){
   Serial.print("Stop playback file: ");
   Serial.println(filename);
    playWav1.stop();
  }
  // A brief delay for the library read WAV info
  delay(25);
}


// ------------------------- BEHAVIOURS ---------------------------------- //

void audioTest(){
  playFile(sample);  // filenames are always uppercase 8.3 format
}
