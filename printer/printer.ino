#include <Dhcp.h>
#include <Dns.h>
#include <Ethernet.h>
#include <EthernetClient.h>
#include <EthernetServer.h>
#include <EthernetUdp.h>
#include <util.h>

#include "SoftwareSerial.h"
#include "Adafruit_Thermal.h"
#include "adalogo.h"
#include "adaqrcode.h"
#include <avr/pgmspace.h>

// Printer
int printer_RX_Pin = 5;  // This is the green wire
int printer_TX_Pin = 6;  // This is the yellow wire
Adafruit_Thermal printer(printer_RX_Pin, printer_TX_Pin);

// Web server
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,177);
EthernetServer server(80);


void setup(){
  // Web server
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
  
  // Printer
  pinMode(7, OUTPUT); digitalWrite(7, LOW);
  printer.begin();
}

int i;
char thisLine[30];

void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  if (client) {
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);

        /*
        while (Serial.available() > 0) {
          memset(thisLine, ' ', sizeof(thisLine) - 1);
          Serial.readBytesUntil('\n', thisLine, sizeof(thisLine) - 1);
          printer.println(thisLine);
        }
        */

        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 204 No Content");
          client.println("Connection: close");
          break;
        } else if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    delay(1);
    client.stop();
  }
}

