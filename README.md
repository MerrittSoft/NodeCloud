# NodeCloud
A basic Cloud for NodeMCU ESP8266 using a NodeMCU
NodeCloud is a working NodeMCU ESP8266 Cloud conecept using the NodeMCU to control a remote NodeMCU
where router port forwarding is not possable and you don't want to use a 3rd party cloud service
In this artical ill be using an Android App that I am developing
called NodeController, its sends commands to the NodeMCU ESP8266
NodeController is an Android app that can pe found on Google Play
https://play.google.com/store/apps/details?id=appinventor.ai_melissa2227.NodeController

You could send the command from a Web Browser address bar,
format: ip-address:port/COMMAND   ,eg:  10.220.1.22:80/RELAY1ON
would turn Relay 1 ON.

format: ip-address:port/COMMAND   ,eg:  10.220.1.22:80/RELAY1OFF
would turn Relay 1 OFF.

Or you could use the App that I have been developing
NodeController for Android you will find a link in the description

How it works
I will asume that you are using NodeClontroller and its been configured to send commands to the NodeMCU Cloud Server unit,
when you press one of the buttons in the App its send a command to the Cloud Server and it will register you request,
then it will add that request to a html page then it will wait until the Slave requests the page from the Cloud Server,
the Slave will read the data on the requested html page and perform the request
the data on the html page is only made up of Ones and Zeros,
One = ON and Zero = OFF

 What you will need,
 # Dynamic DNS (No-IP) and client if you dont have a Static Public ip Address
# You will need to setup Port Forwarding on the Router at the premises of the Cloud Server


PARTS

1 x WeMos D1 USB NodeMcu Lua V3 CH340G ESP8266 Wireless Internet Development 5-9V
or
1 x NodeMCU Lua ESP8266 ESP-12 WeMos D1 Mini WIFI
7 x LEDS what colours you want
7 x 470 ohm Resistorsor 2
2 x 5v dc Power Supply

Some other components depending how you would like to connect the wires to the PCB, eg pin headers, terminals.

for more information
http://www.meltronica.com
