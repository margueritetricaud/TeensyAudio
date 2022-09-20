
# Teensy Audio  

_updated code from the Teensy WavFilePlayer Example_

***


Goal : play an Audio file from an SD card on a Teensy 

### Hardware :  

- Teensy 3.2 or Teensy 4.0 

- Teensy Audio Shield 

- Micro SD Card  

- Speaker 

### SD Card file formatting 

- File type : WAV 

- Rate : 44100 Hz 

- Format  : 16 bit unsigned 

- File name : upper case  

### How to format your audio file ? 

- Download and install Audacity 

- Import your audio file (drag and drop into Audacity) 

- Make sure the project rate (bottom left of the screen) is set to 44100 Hz 

- In the track drop down Menu, select 16-bit PCM for the format 

- In the track drop down Menu, select 44100Hz for the rate 

- In the main menu, select File>Export>WAV 

- Save your file with an upper case name such as SONG or TRACK1 

- Make sure the format is signed 16bit PCM 

- Upload the track on your SD card and plug the SD card into the Teensy Audio Shield 

### Teensy Audio Code 

- Make sure you’ve downloaded and installed Teensyduino (add-on for the Arduino IDE) 

- Select your board (Teensy 3.2 or Teensy 4.0)

- If you just want to play a WAV file on the Teensy (no other inputs/outputs), you can use the Teensy Library example in File>Example>Examples for Teensy 4.0/3.2>Audio>WavFilePlayer 

- If you want your code to be checking sensors and controlling other inputs/outputs while playing some audio, I suggest using the edited code available on this GitHub. (Unlike the library example, this version isn’t using a while loop in the playFile function. This means the loop is never blocked, and the rest of the code can run while the audio is playing). 

- Don’t forget to change the name of the file in the code so that it matches the one you have on your SD card 

- Upload and test ! 
