#include <WiFi.h>
#include <HTTPClient.h>
//#include <ArduinoJson.h>

const char* ssid = "Muller House";
const char* password = "48927893";

HTTPClient http;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to wifi...");
  }
  Serial.println("Connected to the Wifi network");

  http.begin("http://192.168.0.105:3000/msg"); //Specify destination for HTTP request
  http.addHeader("Content-Type", "text/plain"); //Specify content-type header
  
//  String postMessage;
}

void loop() {
  // put your main code here, to run repeatedly:
  int httpResponseCode = http.POST("POSTING from ESP32"); //Send the actual POST request

  if(httpResponseCode>0){
   
      String response = http.getString();  //Get the response to the request
   
      Serial.println(httpResponseCode);   //Print return code
      Serial.println(response);           //Print request answer
   
  }else{
   
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
  }

  http.end();
  delay(50000);

}
