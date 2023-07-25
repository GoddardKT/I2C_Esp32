#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define OLED1_RESET 4 // Pin de reinicio de la primera pantalla OLED
#define OLED2_RESET 16 // Pin de reinicio de la segunda pantalla OLED

Adafruit_SSD1306 OLED1(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED1_RESET);
Adafruit_SSD1306 OLED2(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED2_RESET);

void setup() {
  Wire.begin();
  OLED1.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Dirección I2C de la primera pantalla OLED
  OLED2.begin(SSD1306_SWITCHCAPVCC, 0x3D); // Dirección I2C de la segunda pantalla OLED

  OLED1.clearDisplay();
  OLED2.clearDisplay();
  OLED1.display();
  OLED2.display();

  // Mensaje inicial en cada pantalla
  displayMessage(OLED1, "Pantalla 1", 0, 0);
  displayMessage(OLED2, "Pantalla 2", 0, 0);
}

void loop() {
  // Actualizar mensajes en las pantallas cada 2 segundos (por ejemplo)
  displayMessage(OLED1, "Hola desde 1", 0, 20);
  displayMessage(OLED2, "Hola desde 2", 0, 20);
  delay(2000);

  displayMessage(OLED1, "¡Saludos!", 0, 40);
  displayMessage(OLED2, "¡Bienvenido!", 0, 40);
  delay(2000);
}

// Función para mostrar mensajes en la pantalla OLED específica
void displayMessage(Adafruit_SSD1306 &oled, const char* message, int x, int y) {
  oled.clearDisplay();
  oled.setTextSize(1);
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(x, y);
  oled.print(message);
  oled.display();
}
