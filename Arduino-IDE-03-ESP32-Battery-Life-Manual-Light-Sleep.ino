#include <Arduino.h>

uint64_t sleepTime = 5000000;//Our delay length in microseconds (5 seconds)

void setup() 
{
  Serial.begin(9600);

  // Enable wake-up by timer which will be used to trigger out 5 second delay
  esp_err_t result = esp_sleep_enable_timer_wakeup(sleepTime);

    if (result == ESP_OK) 
    {
        Serial.println("Timer Wake-Up set successfully as wake-up source.");
    } else {
        Serial.println("Failed to set Timer Wake-Up as wake-up source.");
    }
  
}

void loop() 
{
  // Simulate some work in the main loop
  Serial.println("Beginning heavy computation...");
  for (volatile int i = 0; i < 100000000; i++)
  {
      double result = sin(i) * cos(i);
  }
  Serial.println("Going into light sleep mode");
  Serial.flush();
  //power down the esp32 into light sleep for 5 seconds
  esp_light_sleep_start();     // Enter light sleep
  Serial.println("Returning from light sleep");
}