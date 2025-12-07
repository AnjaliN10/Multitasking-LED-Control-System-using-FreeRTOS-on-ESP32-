/**
 * led_tasks.c
 * -----------
 * Implementation of simulated LED control tasks for a FreeRTOS-based
 * multitasking system on ESP32.
 *
 * NOTE:
 *  - This version is designed for demonstration/documentation purposes.
 *  - Instead of toggling real GPIO pins, it prints log messages to
 *    represent LED ON/OFF events and task execution timing.
 */

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "led_tasks.h"

// Logical identifiers for the "LEDs" (for logging only)
#define LED_FAST_ID   1
#define LED_SLOW_ID   2

// Blink periods in milliseconds
#define FAST_BLINK_PERIOD_MS   500    // 0.5 seconds
#define SLOW_BLINK_PERIOD_MS   1000   // 1.0 second

// Helper function to simulate an LED toggle via console output
static void simulateLedToggle(int ledId, const char *taskName)
{
    static int fastLedState = 0;
    static int slowLedState = 0;

    int *statePtr = NULL;

    if (ledId == LED_FAST_ID) {
        statePtr = &fastLedState;
    } else if (ledId == LED_SLOW_ID) {
        statePtr = &slowLedState;
    } else {
        // Unknown LED id
        return;
    }

    // Toggle internal state
    *statePtr = !(*statePtr);

    // Print log indicating which "LED" changed and its new state
    printf("[%s] LED%d -> %s\n",
           taskName,
           ledId,
           (*statePtr ? "ON" : "OFF"));
}

/**
 * fastBlinkTask
 * -------------
 * Simulates a higher-frequency periodic task by "toggling" an LED
 * every 500 ms. Represents a time-critical task (higher priority).
 */
void fastBlinkTask(void *pvParameters)
{
    (void) pvParameters; // Unused

    printf("[FastBlinkTask] Started. Period = %d ms\n", FAST_BLINK_PERIOD_MS);

    while (1) {
        simulateLedToggle(LED_FAST_ID, "FastBlinkTask");
        vTaskDelay(pdMS_TO_TICKS(FAST_BLINK_PERIOD_MS));
    }
}

/**
 * slowBlinkTask
 * -------------
 * Simulates a lower-frequency background task, toggling every 1000 ms.
 * Represents a less time-critical task (lower priority).
 */
void slowBlinkTask(void *pvParameters)
{
    (void) pvParameters; // Unused

    printf("[SlowBlinkTask] Started. Period = %d ms\n", SLOW_BLINK_PERIOD_MS);

    while (1) {
        simulateLedToggle(LED_SLOW_ID, "SlowBlinkTask");
        vTaskDelay(pdMS_TO_TICKS(SLOW_BLINK_PERIOD_MS));
    }
}

