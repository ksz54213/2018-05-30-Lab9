
#include <IRremote.h>
const int irReceiverPin = 12;
IRrecv irrecv(irReceiverPin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
    Serial.print(" irCode: ");
    Serial.print(results.value,HEX);
    Serial.print(",  bits: ");
    Serial.print(results.bits);
    irrecv.resume();
  }
}
