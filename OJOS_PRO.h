#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <arrays/normales.hpp>
#include <arrays/enojados.hpp>
#include <arrays/preocupados.hpp>
#include <arrays/relajados.hpp>
#include <arrays/sorprendidos.hpp>
#include <arrays/atentos.hpp>
#include <arrays/guino.hpp>
#ifndef __OJOS_PRO_h__
#define __OJOS_PRO_h__
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// define los arrays de los ojos normales
#define OJOS_normales_00ARRAY ojos_normales_00array
#define OJOS_normales_01ARRAY ojos_normales_01array
#define OJOS_normales_02ARRAY ojos_normales_02array
#define OJOS_normales_03ARRAY ojos_normales_03array
#define OJOS_normales_04ARRAY ojos_normales_04array
#define OJOS_normales_05ARRAY ojos_normales_05array
#define OJOS_normales_06ARRAY ojos_normales_06array
#define OJOS_normales_07ARRAY ojos_normales_07array
#define OJOS_normales_08ARRAY ojos_normales_08array
#define OJOS_normales_09ARRAY ojos_normales_09array
#define OJOS_normales_10ARRAY ojos_normales_10array
#define OJOS_normales_11ARRAY ojos_normales_11array
#define OJOS_normales_12ARRAY ojos_normales_12array
#define OJOS_normales_13ARRAY ojos_normales_13array
#define OJOS_normales_14ARRAY ojos_normales_14array
#define OJOS_normales_15ARRAY ojos_normales_15array
#define OJOS_normales_16ARRAY ojos_normales_16array
#define OJOS_normales_17ARRAY ojos_normales_17array
#define OJOS_normales_18ARRAY ojos_normales_18array
#define OJOS_normales_19ARRAY ojos_normales_19array

// define los arrays de los ojos enojados
#define OJOS_enojados_00ARRAY ojos_enojados_00array
#define OJOS_enojados_01ARRAY ojos_enojados_01array
#define OJOS_enojados_02ARRAY ojos_enojados_02array
#define OJOS_enojados_03ARRAY ojos_enojados_03array
#define OJOS_enojados_04ARRAY ojos_enojados_04array
#define OJOS_enojados_05ARRAY ojos_enojados_05array
#define OJOS_enojados_06ARRAY ojos_enojados_06array
#define OJOS_enojados_07ARRAY ojos_enojados_07array
#define OJOS_enojados_08ARRAY ojos_enojados_08array
#define OJOS_enojados_09ARRAY ojos_enojados_09array
#define OJOS_enojados_10ARRAY ojos_enojados_10array
#define OJOS_enojados_11ARRAY ojos_enojados_11array
#define OJOS_enojados_12ARRAY ojos_enojados_12array
#define OJOS_enojados_13ARRAY ojos_enojados_13array
#define OJOS_enojados_14ARRAY ojos_enojados_14array
#define OJOS_enojados_15ARRAY ojos_enojados_15array
#define OJOS_enojados_16ARRAY ojos_enojados_16array
#define OJOS_enojados_17ARRAY ojos_enojados_17array
#define OJOS_enojados_18ARRAY ojos_enojados_18array
#define OJOS_enojados_19ARRAY ojos_enojados_19array

// define los arrays de los ojos preocupados
#define OJOS_preocupados_00ARRAY ojos_preocupados_00array
#define OJOS_preocupados_01ARRAY ojos_preocupados_01array
#define OJOS_preocupados_02ARRAY ojos_preocupados_02array
#define OJOS_preocupados_03ARRAY ojos_preocupados_03array
#define OJOS_preocupados_04ARRAY ojos_preocupados_04array
#define OJOS_preocupados_05ARRAY ojos_preocupados_05array
#define OJOS_preocupados_06ARRAY ojos_preocupados_06array
#define OJOS_preocupados_07ARRAY ojos_preocupados_07array
#define OJOS_preocupados_08ARRAY ojos_preocupados_08array
#define OJOS_preocupados_09ARRAY ojos_preocupados_09array
#define OJOS_preocupados_10ARRAY ojos_preocupados_10array
#define OJOS_preocupados_11ARRAY ojos_preocupados_11array
#define OJOS_preocupados_12ARRAY ojos_preocupados_12array
#define OJOS_preocupados_13ARRAY ojos_preocupados_13array
#define OJOS_preocupados_14ARRAY ojos_preocupados_14array
#define OJOS_preocupados_15ARRAY ojos_preocupados_15array
#define OJOS_preocupados_16ARRAY ojos_preocupados_16array
#define OJOS_preocupados_17ARRAY ojos_preocupados_17array
#define OJOS_preocupados_18ARRAY ojos_preocupados_18array
#define OJOS_preocupados_19ARRAY ojos_preocupados_19array

// define los arrays de los ojos relajados
#define OJOS_relajados_00ARRAY ojos_relajados_00array
#define OJOS_relajados_01ARRAY ojos_relajados_01array
#define OJOS_relajados_02ARRAY ojos_relajados_02array
#define OJOS_relajados_03ARRAY ojos_relajados_03array
#define OJOS_relajados_04ARRAY ojos_relajados_04array
#define OJOS_relajados_05ARRAY ojos_relajados_05array
#define OJOS_relajados_06ARRAY ojos_relajados_06array
#define OJOS_relajados_07ARRAY ojos_relajados_07array
#define OJOS_relajados_08ARRAY ojos_relajados_08array
#define OJOS_relajados_09ARRAY ojos_relajados_09array
#define OJOS_relajados_10ARRAY ojos_relajados_10array
#define OJOS_relajados_11ARRAY ojos_relajados_11array
#define OJOS_relajados_12ARRAY ojos_relajados_12array
#define OJOS_relajados_13ARRAY ojos_relajados_13array
#define OJOS_relajados_14ARRAY ojos_relajados_14array
#define OJOS_relajados_15ARRAY ojos_relajados_15array
#define OJOS_relajados_16ARRAY ojos_relajados_16array
#define OJOS_relajados_17ARRAY ojos_relajados_17array
#define OJOS_relajados_18ARRAY ojos_relajados_18array
#define OJOS_relajados_19ARRAY ojos_relajados_19array

// define los arrays de los ojos sorprendidos
#define OJOS_sorprendidos_00ARRAY ojos_sorprendidos_00array
#define OJOS_sorprendidos_01ARRAY ojos_sorprendidos_01array
#define OJOS_sorprendidos_02ARRAY ojos_sorprendidos_02array
#define OJOS_sorprendidos_03ARRAY ojos_sorprendidos_03array
#define OJOS_sorprendidos_04ARRAY ojos_sorprendidos_04array
#define OJOS_sorprendidos_05ARRAY ojos_sorprendidos_05array
#define OJOS_sorprendidos_06ARRAY ojos_sorprendidos_06array
#define OJOS_sorprendidos_07ARRAY ojos_sorprendidos_07array
#define OJOS_sorprendidos_08ARRAY ojos_sorprendidos_08array
#define OJOS_sorprendidos_09ARRAY ojos_sorprendidos_09array
#define OJOS_sorprendidos_10ARRAY ojos_sorprendidos_10array
#define OJOS_sorprendidos_11ARRAY ojos_sorprendidos_11array
#define OJOS_sorprendidos_12ARRAY ojos_sorprendidos_12array
#define OJOS_sorprendidos_13ARRAY ojos_sorprendidos_13array
#define OJOS_sorprendidos_14ARRAY ojos_sorprendidos_14array
#define OJOS_sorprendidos_15ARRAY ojos_sorprendidos_15array
#define OJOS_sorprendidos_16ARRAY ojos_sorprendidos_16array
#define OJOS_sorprendidos_17ARRAY ojos_sorprendidos_17array
#define OJOS_sorprendidos_18ARRAY ojos_sorprendidos_18array
#define OJOS_sorprendidos_19ARRAY ojos_sorprendidos_19array

// define los arrays de los ojos atentos
#define OJOS_atentos_00ARRAY ojos_atentos_00array
#define OJOS_atentos_01ARRAY ojos_atentos_01array
#define OJOS_atentos_02ARRAY ojos_atentos_02array
#define OJOS_atentos_03ARRAY ojos_atentos_03array
#define OJOS_atentos_04ARRAY ojos_atentos_04array
#define OJOS_atentos_05ARRAY ojos_atentos_05array
#define OJOS_atentos_06ARRAY ojos_atentos_06array
#define OJOS_atentos_07ARRAY ojos_atentos_07array
#define OJOS_atentos_08ARRAY ojos_atentos_08array
#define OJOS_atentos_09ARRAY ojos_atentos_09array
#define OJOS_atentos_10ARRAY ojos_atentos_10array
#define OJOS_atentos_11ARRAY ojos_atentos_11array
#define OJOS_atentos_12ARRAY ojos_atentos_12array
#define OJOS_atentos_13ARRAY ojos_atentos_13array
#define OJOS_atentos_14ARRAY ojos_atentos_14array
#define OJOS_atentos_15ARRAY ojos_atentos_15array
#define OJOS_atentos_16ARRAY ojos_atentos_16array
#define OJOS_atentos_17ARRAY ojos_atentos_17array
#define OJOS_atentos_18ARRAY ojos_atentos_18array
#define OJOS_atentos_19ARRAY ojos_atentos_19array

// define los arrays de los ojos guiño
#define OJOS_guino_00ARRAY ojos_guino_00array
#define OJOS_guino_01ARRAY ojos_guino_01array
#define OJOS_guino_02ARRAY ojos_guino_02array
#define OJOS_guino_03ARRAY ojos_guino_03array
#define OJOS_guino_04ARRAY ojos_guino_04array
#define OJOS_guino_05ARRAY ojos_guino_05array
#define OJOS_guino_06ARRAY ojos_guino_06array
#define OJOS_guino_07ARRAY ojos_guino_07array
#define OJOS_guino_08ARRAY ojos_guino_08array
#define OJOS_guino_09ARRAY ojos_guino_09array
#define OJOS_guino_10ARRAY ojos_guino_10array
#define OJOS_guino_11ARRAY ojos_guino_11array
#define OJOS_guino_12ARRAY ojos_guino_12array
#define OJOS_guino_13ARRAY ojos_guino_13array
#define OJOS_guino_14ARRAY ojos_guino_14array
#define OJOS_guino_15ARRAY ojos_guino_15array
#define OJOS_guino_16ARRAY ojos_guino_16array
#define OJOS_guino_17ARRAY ojos_guino_17array
#define OJOS_guino_18ARRAY ojos_guino_18array
#define OJOS_guino_19ARRAY ojos_guino_19array

#endif

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

class OJOS_PRO{
  public:

  void normales(); //< metodo para animacion de ojos normales
  void enojados(); //< metodo para animacion de ojos enojados
  void preocupados(); //< metodo para animacion de ojos preocupados
  void relajados(); //< metodo para animacion de ojos relajados
  void sorprendidos(); //< metodo para animacion de ojos sorprendidos
  void atentos(); //< metodo para animacion de ojos atentos
  void guino(); //< metodo para animacion de ojos guiñando
  void ejemplo(); //< metodo para animacion de un ejemplo

  void begin(); //< llama este metodo en la funcion setup() del main

  OJOS_PRO();
};

OJOS_PRO::OJOS_PRO(){}

void OJOS_PRO::normales(){
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_00ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_01ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_02ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_03ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_04ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_05ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_06ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_07ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_08ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_09ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_10ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_11ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_12ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_13ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_14ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_15ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_16ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_17ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_18ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_normales_19ARRAY, 128, 64, 1);
  display.display();
}

void OJOS_PRO::enojados(){
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_00ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_01ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_02ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_03ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_04ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_05ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_06ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_07ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_08ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_09ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_10ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_11ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_12ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_13ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_14ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_15ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_16ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_17ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_18ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_enojados_19ARRAY, 128, 64, 1);
  display.display();
}

void OJOS_PRO::preocupados(){
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_00ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_01ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_02ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_03ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_04ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_05ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_06ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_07ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_08ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_09ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_10ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_11ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_12ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_13ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_14ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_15ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_16ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_17ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_18ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_preocupados_19ARRAY, 128, 64, 1);
  display.display();
}

void OJOS_PRO::relajados(){
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_00ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_01ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_02ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_03ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_04ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_05ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_06ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_07ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_08ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_09ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_10ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_11ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_12ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_13ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_14ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_15ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_16ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_17ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_18ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_relajados_19ARRAY, 128, 64, 1);
  display.display();
}

void OJOS_PRO::sorprendidos(){
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_00ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_01ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_02ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_03ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_04ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_05ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_06ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_07ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_08ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_09ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_10ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_11ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_12ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_13ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_14ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_15ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_16ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_17ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_18ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_sorprendidos_19ARRAY, 128, 64, 1);
  display.display();
}

void OJOS_PRO::atentos(){
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_00ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_01ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_02ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_03ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_04ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_05ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_06ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_07ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_08ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_09ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_10ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_11ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_12ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_13ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_14ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_15ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_16ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_17ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_18ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_atentos_19ARRAY, 128, 64, 1);
  display.display();
}

void OJOS_PRO::guino(){
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_00ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_01ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_02ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_03ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_04ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_05ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_06ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_07ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_08ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_09ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_10ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_11ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_12ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_13ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_14ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_15ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_16ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_17ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_18ARRAY, 128, 64, 1);
  display.display();

  delay(100);
  display.clearDisplay();

  display.drawBitmap(0, 0, OJOS_guino_19ARRAY, 128, 64, 1);
  display.display();
}

void OJOS_PRO::ejemplo(){
  
  display.clearDisplay();
 
  // Tamaño del texto
  display.setTextSize(1);
  // Color del texto
  display.setTextColor(SSD1306_WHITE);
  // Posición del texto
  display.setCursor(10, 32);
  //Activar página de código 437
  display.cp437(true);
  // Escribir el carácter ¡ dos veces
  display.write(173);
  display.write(173);
  // Escribir texto
  display.println("OJOS PRO");
  
  // Enviar a pantalla
  display.display();
  delay(2000);
 
  // Mover texto de izquierda a derecha
  display.startscrollright(0x00, 0x0F);
  delay(5000);
  display.stopscroll();
  
  // Mover texto de derecha a izquierda
  display.startscrollleft(0x00, 0x0F);
  delay(5000);
  display.stopscroll();
 
  // Mover texto en diagonal hacia la derecha
  display.startscrolldiagright(0x00, 0x07);
  delay(5000);
  display.stopscroll();
 
  // Mover texto en diagonal hacia la izquierda
  display.startscrolldiagleft(0x00, 0x07);
  delay(5000);
  display.stopscroll();
}

void OJOS_PRO::begin(){
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  delay(2000);
  display.clearDisplay();
}