#include <Arduino.h>


int mycount1 = 0;
int mycount2 = 2;


void task1(void * parameters){
    for(;;){
        Serial.print("task1 counter : ");
        Serial.print(mycount1++);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
}

void task2(void * parameters){
    for(;;){
        Serial.print("task2 counter : ");
        Serial.print(mycount2++);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
}

void setup(){
    Serial.begin(9600);

    xTaskCreate(
    task1,   //function name
    "task1", //task description
    1000,    //stack size
    NULL,    //params
    1,        //task priority
    NULL     //task handle
    );

    xTaskCreate(
    task2,   //function name
    "task2", //task description
    1000,    //stack size
    NULL,    //params
    2,      //task priority
    NULL    //task handle
    );
}


void loop(){

    delay(1000);
    Serial.print("loop");
}