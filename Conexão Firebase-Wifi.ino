//Bibliotecas Utilizadas
#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>


// Autenticação Firebase e Wi-Fi
#define FIREBASE_AUTH "AIzaSyBixl3nhwPhP3j6ZMdcE5tRzzfU5qu4864"
#define FIREBASE_HOST "tccc-ffedf-default-rtdb.firebaseio.com"
#define WIFI_SSID "RZNN_2.4G"
#define WIFI_PASSWORD "**************"

FirebaseData firebaseData;

int vaga1 = 16; // GPIO16 - Porta ESP8266
int vaga2 = 12; // GPIO12 - Porta ESP8266
int val;
int LED = 4;
int LED2 = 2;
String value;

void setup()  
{  
   pinMode(vaga1, INPUT);
   pinMode(vaga2, INPUT);
   pinMode(LED, OUTPUT);
   //pinMode(LED2, OUTPUT);
  Serial.begin(115200);

// Conexão com o Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi");

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("Conectado ao Firebase");  
}  
   
void loop()  
{  
  // Envio dos valores da Vaga1 para o Firebase
  if (Firebase.getString(firebaseData, "Vagas1")){
   value = firebaseData.stringData();
   if(digitalRead(vaga1) == 0)  
  {  
    Firebase.setString(firebaseData,"/Vagas1","Ocupado");
    digitalWrite(LED,HIGH); 
  }  
  if(digitalRead(vaga1) == 1 && value.indexOf("Ocupado") != -1)
  {  
    Firebase.setString(firebaseData,"/Vagas1","Livre");
    digitalWrite(LED,LOW );
  }
  if (value.indexOf("Reservado") != -1){
  digitalWrite(LED,HIGH);  
  }
  if (value.indexOf("Livre") != -1){
  digitalWrite(LED,LOW);
}
  }

  
  // Envio dos valores da Vaga2 para o Firebase
  if (Firebase.getString(firebaseData, "Vagas2")){
   value = firebaseData.stringData();
   if(digitalRead(vaga2) == 0)  
  {  
    Firebase.setString(firebaseData,"/Vagas2","Ocupado");
   // digitalWrite(LED2,HIGH); 
  }  
  if(digitalRead(vaga2) == 1 && value.indexOf("Ocupado") != -1)
  {  
    Firebase.setString(firebaseData,"/Vagas2","Livre");
   // digitalWrite(LED2,LOW );
  }
  if (value.indexOf("Reservado") != -1){
  //digitalWrite(LED2,HIGH);  
  }
  
  }

    
  
} 
