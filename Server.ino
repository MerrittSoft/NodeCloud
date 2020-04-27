/*
  MerrittSoft
  Remote Relay Cloud Server
  17/04/2020
  Language: C++/Arduino
  Thank you to those people that made the Libarays in this project posable.
*/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


ESP8266WebServer server(80);

char* ssid = "ssid-name";
char* password = "ssid-password";
const int wificonnected = D0;
const int slaveconnected = D2;

String one = "1";
String zero = "0";


String relay1 = "0";
String relay2 = "0";
String relay3 = "0";
String relay4 = "0";
String relay5 = "0";
String relay6 = "0";
String relay7 = "0";
String relay8 = "0";

void setup() {
  pinMode(wificonnected, OUTPUT);
  pinMode(slaveconnected, OUTPUT);
  digitalWrite(wificonnected, LOW);
  digitalWrite(slaveconnected, LOW);

  WiFi.begin(ssid, password);
  WiFi.hostname("RemoteRelayCloudServer");
  WiFi.mode(WIFI_STA);
  Serial.begin(115200);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  digitalWrite(wificonnected, HIGH);
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  server.on("/", []() {
    server.send(200, "text/plain", "RemoteRelayCloudServer");
  });

  server.on("/RELAY1", remote1); // This is where the Slave comes in
  server.on("/RELAY1ON", relay1on); // The rest of them is where the commands come in from
  server.on("/RELAY1OFF", relay1off); // the controller eg: NodeController App
  server.on("/RELAY2ON", relay2on);
  server.on("/RELAY2OFF", relay2off);
  server.on("/RELAY3ON", relay3on);
  server.on("/RELAY3OFF", relay3off);
  server.on("/RELAY4ON", relay4on);
  server.on("/RELAY4OFF", relay4off);
  server.on("/RELAY5ON", relay5on);
  server.on("/RELAY5OFF", relay5off);
  server.on("/RELAY6ON", relay6on);
  server.on("/RELAY6OFF", relay6off);
  server.on("/RELAY7ON", relay7on);
  server.on("/RELAY7OFF", relay7off);
  server.on("/RELAY8ON", relay8on);
  server.on("/RELAY8OFF", relay8off);

  server.begin();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED)
  {
    ESP.reset();
  }
  server.handleClient();
}

void remote1()
{
  Serial.print("reseved request");
  Serial.println();
  digitalWrite(slaveconnected, HIGH);
  delay(1000);
  digitalWrite(slaveconnected, LOW);

  // The next section is where it puts the html page together for the Slave
  server.send(200, "text/plain", relay1 + relay2 + relay3 + relay4 + relay5 + relay6 + relay7 + relay8);
  Serial.println(relay1 + relay2 + relay3 + relay4 + relay5 + relay6 + relay7 + relay8);
  return;
}

void relay1on()
{
  Serial.print("relay1 = 1");
  Serial.println();
  delay(1000);
  relay1 = one;
  server.send(204, "");

  return;
}

void relay1off()
{
  Serial.print("relay1 = 0");
  Serial.println();
  delay(1000);
  relay1 = zero;
  server.send(204, "");

  return;
}

void relay2on()
{
  Serial.print("relay2 = 1");
  Serial.println();
  delay(1000);
  relay2 = one;
  server.send(204, "");

  return;
}

void relay2off()
{
  Serial.print("relay2 = 0");
  Serial.println();
  delay(1000);
  relay2 = zero;
  server.send(204, "");

  return;
}

void relay3on()
{
  Serial.print("relay3 = 1");
  Serial.println();
  delay(1000);
  relay3 = one;
  server.send(204, "");

  return;
}

void relay3off()
{
  Serial.print("relay3 = 0");
  Serial.println();
  delay(1000);
  relay3 = zero;
  server.send(204, "");

  return;
}

void relay4on()
{
  Serial.print("relay4 = 1");
  Serial.println();
  delay(1000);
  relay4 = one;
  server.send(204, "");

  return;
}

void relay4off()
{
  Serial.print("relay4 = 0");
  Serial.println();
  delay(1000);
  relay4 = zero;
  server.send(204, "");

  return;
}

void relay5on()
{
  Serial.print("relay5 = 1");
  Serial.println();
  delay(1000);
  relay5 = one;
  server.send(204, "");

  return;
}

void relay5off()
{
  Serial.print("relay5 = 0");
  Serial.println();
  delay(1000);
  relay5 = zero;
  server.send(204, "");

  return;
}

void relay6on()
{
  Serial.print("relay6 = 1");
  Serial.println();
  delay(1000);
  relay6 = one;
  server.send(204, "");

  return;
}

void relay6off()
{
  Serial.print("relay6 = 0");
  Serial.println();
  delay(1000);
  relay6 = zero;
  server.send(204, "");

  return;
}

void relay7on()
{
  Serial.print("relay7 = 1");
  Serial.println();
  delay(1000);
  relay7 = one;
  server.send(204, "");

  return;
}

void relay7off()
{
  Serial.print("relay7 = 0");
  Serial.println();
  delay(1000);
  relay7 = zero;
  server.send(204, "");

  return;
}

void relay8on()
{
  Serial.print("relay8 = 1");
  Serial.println();
  delay(1000);
  relay8 = one;
  server.send(204, "");

  return;
}

void relay8off()
{
  Serial.print("relay8 = 0");
  Serial.println();
  delay(1000);
  relay8 = zero;
  server.send(204, "");

  return;
}
