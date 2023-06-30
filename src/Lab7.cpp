/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/CTD_2023/Lab7/src/Lab7.ino"
void setup();
void loop();
#line 1 "/Users/admin/CTD_2023/Lab7/src/Lab7.ino"
SYSTEM_THREAD(ENABLED);

#include "env.h"


#define NOTIFY_EVENT_CODE "notify"
/* Comment this out to disable prints and save space */
//#define BLYNK_PRINT Serial

#include <blynk.h>

BlynkTimer timer;

BLYNK_WRITE(V0)
{
	Serial.println("Button Tapped");
	if (param.asInt() == 1)
	{
		Blynk.logEvent("notify", "Hey, Blynk push here!");
	}
}

// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
  // Change Web Link Button message to "Congratulations!"
  
}

// This function sends Arduino's uptime every second to Virtual Pin 2.

void setup()
{
  // Debug console
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D3, INPUT);
  pinMode(A5, INPUT);

  delay(5000); // Allow board to settle
  Blynk.begin(BLYNK_AUTH_TOKEN);

  // Setup a function to be called every second
}

void loop()
{
  Blynk.run();
  timer.run();

  if (digitalRead(D3)) {
    Blynk.logEvent("notify", "Hey, Blynk push here!");
  }
  float celsius = ((analogRead(A5) * 3.3 / 4095.0) - 0.5) * 100;
  float fahrenheit = celsius * 9.0 / 5.0 + 32.0;

  Blynk.virtualWrite(V6, celsius);
  Blynk.virtualWrite(V7, fahrenheit);
  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}