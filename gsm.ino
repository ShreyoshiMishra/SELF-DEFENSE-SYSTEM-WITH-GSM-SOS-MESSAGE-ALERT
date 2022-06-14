#include <SoftwareSerial.h>
SoftwareSerial SIM900A(2,3);
void setup()
{
SIM900A.begin(9600); // GSM Module Baud rate – communication speed
Serial.begin(9600); // Baud rate of Serial Monitor in the IDE app
}
void loop()
{
if (Serial.available()>0)
SendMessage();
RecieveMessage();
if (SIM900A.available()>0)
Serial.write(SIM900A.read());
}
void SendMessage()
{
SIM900A.println("AT+CMGF=1"); //Text Mode initialisation
SIM900A.println("AT+CMGS=\”+918409147737\”\r"); // Receiver’s Mobile Number
SIM900A.println("EMERGENCY!! this messege has been sent through Arduino Uno not a mobile phone wink wink ");// Messsage content
SIM900A.println((char)26);// delay(1000);
}
void RecieveMessage()
{
SIM900A.println("AT+CNMI=2,2,0,0,0"); // Eeceiving Mode Enabled
delay(1000);
}