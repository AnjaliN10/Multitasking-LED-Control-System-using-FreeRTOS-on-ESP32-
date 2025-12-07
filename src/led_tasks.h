/**
 * led_tasks.h
 * -----------
 * Declaration of FreeRTOS LED simulation tasks.
 *
 * In this repository, the LEDs are not physically driven by GPIO pins.
 * Instead, the tasks log their activity to the console to illustrate
 * real-time scheduling behavior in a hardware-agnostic way.
 */

#ifndef LED_TASKS_H
#define LED_TASKS_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Task prototypes
void fastBlinkTask(void *pvParameters);
void slowBlinkTask(void *pvParameters);

#endif // LED_TASKS_H

