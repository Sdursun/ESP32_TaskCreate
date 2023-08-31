#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t Task1;
TaskHandle_t Task2;

void setup() {
  Serial.begin(115200); 
 

  //Task1kodu() fonksiyonunun çalışacağı görev bloğunu öncelik 1 olarak işlemci 0'da çalışacak şekilde ayarlıyoruz
  xTaskCreatePinnedToCore(
                    Task1kodu,   /* Görevin çalışacağı fonksiyon. */
                    "Task1",     /* Görevin adı. */
                    10000,       /* Görev stack boyutu */
                    NULL,        /* ilave parametreler */
                    1,           /* Görevin önceliği */
                    &Task1,      /* Görevin işaretçisi */
                    0);          /* Görevi 0 numaralı çekirdeğe atayalım */                  
  delay(500); 

  //Task2kodu() fonksiyonunun çalışacağı görev bloğunu öncelik 1 olarak işlemci 1'de çalışacak şekilde ayarlıyoruz
  xTaskCreatePinnedToCore(
                    Task2kodu,   /* Görevin çalışacağı fonksiyon. */
                    "Task2",     /* Görevin adı. */
                    10000,       /* Görev stack boyutu */
                    NULL,        /* ilave parametreler */
                    1,           /* Görevin önceliği */
                    &Task2,      /* Görevin işaretçisi */
                    1);          /* Görevi 1 numaralı çekirdeğe atayalım */
    delay(500); 
}

//Task1kodu: Kırmızı ledi 2000 ms'de bir yakıp söndüreceğiz
void Task1kodu( void * pvParameters ){
      //Setup parametreleri
  for(;;){ //sonsuz döner
    //Loop Döngüsü
  } 
}

//Task2kodu: Yeşil ledi 300 ms'de bir yakıp söndüreceğiz
void Task2kodu( void * pvParameters ){
      //Setup parametreleri
  for(;;){ //sonsuz döner
    //Loop Döngüsü
  } 
}

void loop() {
  
}
