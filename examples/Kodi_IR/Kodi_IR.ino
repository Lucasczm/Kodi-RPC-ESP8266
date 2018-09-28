#include <IRrecv.h>
#include <Kodi.h>

#define RECV_P 4 //Pin of IR Receiver
#define LEDBUILTIN 2 //Pin of esp8266 led builtin

Kodi kodi;

uint16_t RECV_PIN = RECV_P;
IRrecv irrecv(RECV_PIN);
decode_results results;

int useKodi = 0; //Store if use kodi or not;  0 desactive 1 active

void blink(int times) { //Blink the led when ative or desactive 
  for (int i = 0; i < times; i++){
    for (int fadeValue = 1023; fadeValue >= 0; fadeValue -= 100) {
      analogWrite(LEDBUILTIN, fadeValue);
      delay(30);
    }
    for (int fadeValue = 0; fadeValue <= 1023; fadeValue += 100) {
      analogWrite(LEDBUILTIN, fadeValue);
      delay(30);
    }
    digitalWrite(LEDBUILTIN, HIGH);
  }
}

void setup(){
  irrecv.enableIRIn();
}

void loop() {

  if (irrecv.decode(&results)) {
    
    if (0xE17A48B7 == results.value) { // If IR read is the same of controller  swtich state to use kodi
      useKodi = (useKodi == 1) ? 0 : 1;
      if (useKodi == 1) {
        kodi.ActiveKodi(true);
        blink(1); // Blink 1 time to show is up
      }
      else {
        kodi.ActiveKodi(false);
        blink(3); // Blink 3 times to show is off
      }
    }
    kodi.HandlerKodi(results.value); //Send values to kodi class
    irrecv.resume();  // Receive the next value
  }
}
