/*
  MerrittSoft
  Remote Relay Slave
  //****for 4 outputs only but could be 8****
  17/04/2020
  Language: C++/Arduino
  Thank you to those people that made the Libarays in this project posable.
*/


#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

String load;

const int wificonnected = D0;
const int output1 = D2;
const int output2 = D4;
const int output3 = D5;
const int output4 = D7;

String payload = "0";

void setup() {
  pinMode(wificonnected, OUTPUT);
  pinMode(output1, OUTPUT);
  pinMode(output2, OUTPUT);
  pinMode(output3, OUTPUT);
  pinMode(output4, OUTPUT);
  digitalWrite(wificonnected, LOW);
  digitalWrite(output1, LOW);
  digitalWrite(output2, LOW);
  digitalWrite(output3, LOW);
  digitalWrite(output4, LOW);
  Serial.begin(115200);

  WiFiManager wifiManager;

  wifiManager.setConfigPortalTimeout(120);
  wifiManager.setTimeout(120);

  wifiManager.autoConnect("RelaySlave");

  digitalWrite(wificonnected, HIGH);
  Serial.println(WiFi.localIP()); // Print the IP address
}

void loop() {

  if (WiFi.status() != WL_CONNECTED)
  {
    ESP.reset();
  }
  delay(3000);

  WiFiClient client;
  HTTPClient http;    //Declare object of class HTTPClient


  //**** Below is where you add the URL or IP Address of the Server that you have setup at your premises,
  //**** and the Port you have setup in the Router for Port Forwarding at the Server premises.
  http.begin(client, "URL or IP Address:port/RELAY1");

  int httpCode = http.GET();
  Serial.println(" ");
  Serial.println(httpCode);
  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      digitalWrite(wificonnected, LOW);
      delay(500);
      digitalWrite(wificonnected, HIGH);
      payload = http.getString();

      Serial.println("payload");
      Serial.println(payload);

      Serial.println("payload-changed");

      //****for 4 outputs only 0-3 but could be 8 0-7****

      for (int a = 0; a <= 3 ; a++) {
        Serial.print(payload.charAt(a));
        load = (payload.charAt(a));
        delay(10);

        if ( a == 0) {
          slaverelay1();
        }
        else if ( a == 1) {
          slaverelay2();
        }
        else if ( a == 2) {
          slaverelay3();
        }
        else if ( a == 3) {
          slaverelay4();
        }
        else {
          Serial.println("Bad Payload");
        }


      }


    }
  } else {
    http.end();
    Serial.println(" ");
    Serial.println("Not Connected to Server");
  }
}



void slaverelay1()
{
  if (load == "0") {
    digitalWrite(output1, LOW);
  } else {
    digitalWrite(output1, HIGH);
  }

  return;
}

void slaverelay2()
{
  if (load == "0") {
    digitalWrite(output2, LOW);
  } else {
    digitalWrite(output2, HIGH);
  }

  return;
}

void slaverelay3()
{
  if (load == "0") {
    digitalWrite(output3, LOW);
  } else {
    digitalWrite(output3, HIGH);
  }

  return;
}

void slaverelay4()
{
  if (load == "0") {
    digitalWrite(output4, LOW);
  } else {
    digitalWrite(output4, HIGH);
  }

  return;
}
