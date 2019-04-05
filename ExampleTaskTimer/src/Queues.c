/*
 * GccApplication2.c
 *
 * Created: 3/28/2019 9:11:24 PM
 * Author : Stefan Harabagiu
 */

/*
* MyFirstAVRProject.c
*
* Created: 21/03/2019 13:41:34
* Author : IHA
*/

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdio.h>
#include <ATMEGA_FreeRTOS.h>
#include <semphr.h>
#include <timers.h>

#include <avr/interrupt.h>


#include "Arduino/FreeRTOSTraceDriver.h"
#include <task.h>
#include <stdio/uart.h>

#define vWriteData_TASK_PRIORITY ( tskIDLE_PRIORITY + 6 )

#define vConsumeData_TASK_PRIORITY ( tskIDLE_PRIORITY + 5 )

void vWriteData(void *pvParameters);
void vConsumeData(void *pvParameters);

TaskHandle_t xWriteHandle = NULL;
TaskHandle_t xConsumeHandle = NULL;
//One semaphore for each task; two timers to control both tasks; timer callback function calls semaphoreGive
SemaphoreHandle_t xSemaphore1;
SemaphoreHandle_t xSemaphore2;

TimerHandle_t xTimer1;
TimerHandle_t xTimer2;
QueueHandle_t xQueue1;
int n;

void vTimerCallback2(
        TimerHandle_t pxTimer ){
    xSemaphoreGive(xSemaphore2);
}

void vTimerCallback1(
        TimerHandle_t pxTimer ){
    xSemaphoreGive(xSemaphore1);
}
void CreateTimers()
{
    xTimer1 = xTimerCreate("Timer 1",
                           (3000/portTICK_PERIOD_MS),
                           pdTRUE,
                           (void*)0,
                           vTimerCallback1);

    xTimer2 = xTimerCreate("Timer 2",
                           (500/portTICK_PERIOD_MS),
                           pdTRUE,
                           (void*)0,
                           vTimerCallback2);
}

int main(void)
{
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
    sei();
    printf("\n");

    CreateTimers();

    xTimerStart(xTimer1, 0);
    xTimerStart(xTimer2, 0);

    n=42;
    xQueue1 = xQueueCreate(10, sizeof(int));

    xQueueSend(xQueue1, (void *)&n, portMAX_DELAY);

    xTaskCreate(vConsumeData, "Task 2",
                configMINIMAL_STACK_SIZE, NULL,
                vConsumeData_TASK_PRIORITY, &xConsumeHandle);

    xTaskCreate(vWriteData, "Task 1",
                configMINIMAL_STACK_SIZE, NULL,
                vWriteData_TASK_PRIORITY, &xWriteHandle);

    xSemaphore1 = xSemaphoreCreateMutex();
    xSemaphore2 = xSemaphoreCreateMutex();
    vTaskStartScheduler(); // start tasks RTOS

    while(1){
        ;
    }
}

void vWriteData(void *pvParameters) {
    // Remove compiler warnings.
    (void)pvParameters;
    while(1) {

        xSemaphoreTake(xSemaphore1,portMAX_DELAY);
        for (int i=0; i<5; i++)
        {
            n++;
            if(n >= 150)
                n=0;
            printf("Sending value to queue: %d\n", n);
            vTaskDelay(1);
            xQueueSend(xQueue1, (void *)&n, portMAX_DELAY);
        }

    }
}

void vConsumeData(void *pvParameters) {
    // Remove compiler warnings.
    (void)pvParameters;
    while(1) {
        xSemaphoreTake(xSemaphore2,portMAX_DELAY);

        int in;
        BaseType_t em = xQueueReceive(xQueue1, //queue handler
                                      &in, //address of placeholder
                                      0); //time out immediately if queue is empty
        if(em == pdTRUE)
        {
            printf("Receiving value: %d\n", in);
            vTaskDelay(1);
        }

    }
}