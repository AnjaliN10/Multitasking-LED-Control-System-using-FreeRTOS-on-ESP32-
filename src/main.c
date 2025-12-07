/**
 * Multitasking LED Control System using FreeRTOS on ESP32
 * --------------------------------------------------------
 * This file demonstrates how FreeRTOS tasks are created and scheduled
 * on an ESP32 for parallel LED control. Hardware-specific operations
 * are abstracted out so the logic can be understood even without
 * running the project on physical hardware.
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_tasks.h"   // Task function declarations

// Application entry point for FreeRTOS (ESP-IDF)
void app_main(void)
{
    printf("Starting Multitasking LED Control System (Simulation Mode)\n");

    // Create Task 1 – Fast blink simulation
    xTaskCreate(
        fastBlinkTask,          // Task function
        "FastBlinkTask",        // Task name (debugging)
        2048,                   // Stack size
        NULL,                   // Task parameters
        2,                      // Priority
        NULL                    // Task handle
    );

    // Create Task 2 – Slow blink simulation
    xTaskCreate(
        slowBlinkTask,
        "SlowBlinkTask",
        2048,
        NULL,
        1,
        NULL
    );

    // No code here should block; FreeRTOS scheduler takes control now.
}
