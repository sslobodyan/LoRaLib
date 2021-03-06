// include the library
#include <LoRaLib.h>

// create instance of LoRa class with default settings
// chip:                SX1278
// NSS pin:             7
// bandwidth:           125 kHz
// spreading factor:    9
// coding rate:         4/7
LoRa lora;

// create instance of Packet class with destination "01:23:45:67:89:AB:CD:EF" and data "Hello World !"
Packet pack("01:23:45:67:89:AB:CD:EF", "Hello World!");

void setup() {
  Serial.begin(9600);

  // initialize the LoRa module with default settings
  lora.begin();

  // create a string to store the packet information
  char str[24];

  // print the source of the packet
  pack.getSourceStr(str);
  Serial.print("Source:\t\t");
  Serial.println(str);

  // print the destination of the packet
  pack.getDestinationStr(str);
  Serial.print("Destination:\t");
  Serial.println(str);

  // print the length of the packet
  Serial.print("Length:\t\t");
  Serial.println(pack.length);
  
  // print the data of the packet
  Serial.print("Data:\t\t");
  Serial.println(pack.data);
}

void loop() {
  Serial.print("Sending packet ... ");

  // start transmitting the packet
  uint8_t state = lora.transmit(pack);
  
  if(state == ERR_NONE) {
    // a packet was suceesfully transmitted
    Serial.println(" success!");
    
  }else if(state == ERR_PACKET_TOO_LONG) {
    // the supplied packet was longer than 256 bytes
    Serial.println(" too long!");
    
  }

  // wait a second before transmitting again
  delay(1000);
}
