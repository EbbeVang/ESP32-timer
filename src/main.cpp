// documentation
// https://docs.espressif.com/projects/esp-idf/en/latest/api-reference/peripherals/timer.html
// https://techtutorialsx.com/2017/10/07/esp32-arduino-timer-interrupts/
// http://www.iotsharing.com/2017/06/how-to-use-interrupt-timer-in-arduino-esp32.html

#include <Arduino.h>

/* create a hardware timer */
hw_timer_t * timer = NULL;

int interuptNumber = 0;

void IRAM_ATTR onTimer(){
  Serial.print ("This is an interupt ");
  interuptNumber++;
  Serial.println(interuptNumber);
}

void setup() {
  Serial.begin(9600);

  Serial.println("Testing interupts:");

  /* Use 1st timer of 4 */
  /* 1 tick take 1/(80MHZ/80) = 1us so we set divider 80 and count up */
  timer = timerBegin(0, 80, true);

  /* Attach onTimer function to our timer */
  timerAttachInterrupt(timer, &onTimer, true);

  /* Set alarm to call onTimer function every second 1 tick is 1us
  => 1 second is 1000000us */
  /* Repeat the alarm (third parameter) */
  timerAlarmWrite(timer, 1000, true);

  /* Start an alarm */
  timerAlarmEnable(timer);
  Serial.println("start timer");
}

void loop() {

}
