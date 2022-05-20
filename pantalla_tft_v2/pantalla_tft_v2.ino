//Arduino UNO control botones y pantalla TFT
#include <Adafruit_GFX.h> // Libreria de graficos
#include <Adafruit_TFTLCD.h> // Libreria de LCD

// Pines de conexion del LCD 
#define LCD_CS A3 // Chip Select - Pin analogico 3
#define LCD_CD A2 // Command/Data - Pin Analogico 2
#define LCD_WR A1 // LCD Write - Pin Analogico 1
#define LCD_RD A0 // LCD Read - Pin Analogico 0
#define LCD_RESET A4 // LCD Reset - Pin Analogico 4

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET); // Instancia del LCD
#define ORANGE 0XFEA0
#define BLACK 0x0000 // Definimos los colores para poder referirnos a ellos con su nombre 
#define RED 0xF800 // en lugar de usar el código hexadecimal de cada uno. 
#define GREEN 0x07E0 
#define WHITE 0xFFFF 
#define BLUE 0x001F 
#define CYAN 0x07FF
#define YELLOW 0xFFE0
#define MAGENTA 0xF81F

int32_t notas_acert, x1, x2, bandera = 0, start = 0;
int32_t nota1 = 75, nota2 = 75, imprimio = 0; //la bandera imprimio es para controlar el mensaje de bien o mal.
char nota_tocada = 0;

void pantalla_inicio(){
  tft.fillScreen(BLACK); // Colocamos el fondo del LCD en Negro
  tft.setTextSize(1);//Definimos el tamaño de la letra
  tft.setTextColor(RED);//Definimos el color del texto de abajo
  //Escribimos el texto:
  tft.setCursor(5,10);//Posicion del cursor, donde va a imprimir el texto
  // (X, Y) siendo X el ancho (240 px max.) e Y el alto (320 px max.), VERTICAl
  // (X, Y) siendo X el ancho (320 px max.) e Y el alto (240 px max.), HORIZONTAL
  tft.print("Octava del piano: "); 
  tft.setTextColor(WHITE);
  tft.setCursor(110,10);
  tft.print("Quinta");

  tft.setTextSize(1);
  tft.setTextColor(RED);
  tft.setCursor(5,30);
  tft.print("Notas acertadas: ");

  tft.setTextSize(2);
  tft.setTextColor(CYAN);
  tft.setCursor(130,35);
  tft.print("Pulsa para");
  tft.setCursor(145,50);
  tft.print("empezar");

  tft.setTextSize(2);
  tft.setTextColor(WHITE);
  tft.setCursor(25,220);
  tft.print("DO");
  tft.setCursor(65,220);
  tft.print("RE");
  tft.setCursor(105,220);
  tft.print("MI");
  tft.setCursor(143,220);
  tft.print("FA");
  tft.setCursor(178,220);
  tft.print("SOL");
  tft.setCursor(225,220);
  tft.print("LA");
  tft.setCursor(265,220);
  tft.print("SI");
  //tft.drawLine(x1,y1,x2,y2,color);
  //RECUADRO
  tft.drawLine(15,74,295,74,GREEN);
  tft.drawLine(295,75,295,210,GREEN);
  for(int i = 15; i < 300; i+=40){
    tft.drawLine(i,75,i,210,GREEN);
  }
  //CASILLAS LLEGADA DE NOTAS
  tft.drawLine(15,178,295,178,GREEN);
  tft.drawLine(15,211,295,211,GREEN);
  //tft.drawCircle(280, 40, 30, WHITE); // Dibujamos un circulo sin color de relleno
}

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(115200);
  Serial.begin(9600);
  tft.begin(0x9341); // Iniciamos el LCD especificando el controlador de nuestro LC. En este caso el ILI9341. 
  // Otros controladores: 0x9325, 0x9328,0x7575, 0x9341, 0x8357.
    
  tft.fillScreen(BLACK); // Colocamos el fondo del LCD en Negro
  //TFT init
  tft.setRotation(1); //1-Horizontal Y 0-Vertical
  pantalla_inicio();
}

void imprimir_bien_mal(int i){
  if((i >= 105) && (i <= 130)){    //i + 55 > 170 && i + 55 < 180 (rango donde la nota esta sobre el cuadro a tocar)
    tft.fillRect(100, 30, 20, 9, BLACK);  //para sobreescribir las notas acertadas
    ++notas_acert; 
    tft.setTextSize(2);
    tft.setTextColor(YELLOW);
    tft.setCursor(160,45);
    tft.print("Bien!!");  //No se puede escribir 3 ! o si no no compila 
    //Impresion de notas acertadas
    tft.setTextSize(1);
    tft.setTextColor(WHITE);
    tft.setCursor(100,30);
    tft.print(int(notas_acert),DEC);
    delay(90);
  }else{
    tft.setTextSize(2);
    tft.setTextColor(YELLOW);
    tft.setCursor(130,45);
    tft.print("Que paso ahi??");  //No se puede escribir 3 ! o si no no compila  
    delay(90); 
  }
  imprimio = 1;
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(bandera){
    case 0:
      x1 = 20;
      x2 = 20;
      break;
    case 1:
      x1 = 20;
      x2 = 180;
      break;
    case 2:
      x1 = 180;
      x2 = 180;
      break;
    case 3:
      x1 = 180;
      x2 = 220;
      break;
    case 4:
      x1 = 220;
      x2 = 220;
      break;
    case 5:
      x1 = 220;
      x2 = 180;
      break;
    case 6:
      x1 = 180;
      x2 = 180;
      break;
    case 7:
      x1 = 180;
      x2 = 140;
      break;
    case 8:
      x1 = 140;
      x2 = 140;
      break;
    case 9:
      x1 = 140;
      x2 = 100;
      break;
    case 10:
      x1 = 100;
      x2 = 100;
      break;
    case 11:
      x1 = 100;
      x2 = 60;
      break;
    case 12:
      x1 = 60;
      x2 = 60;
      break;
    case 13:
      x1 = 60;
      x2 = 20;
      break;
    case 14:
      x1 = 20;
      x2 = 20;
      break;
    default:
      x1 = 20;
      x2 = 20;
      break;
  }
  imprimio = 0; //se resetea la bandera ya que quiere decir que cambio de nota y puede imprimir un nuevo mensaje de bien o mal
  if((Serial.read() == 'w') && (start == 0)){
    Serial.write('P');
    start = 1;
    notas_acert = 0;
    tft.fillRect(130, 35, 120, 35, BLACK);   //borrar: pulsa para empezar
  }
  if((nota1 < 126) && (start == 1)){
    tft.setTextSize(1);
    tft.setTextColor(WHITE);
    tft.setCursor(100,30);
    tft.print(int(notas_acert),DEC);
    tft.drawLine(15,178,295,178,GREEN);
    tft.fillRect(16, 75, 39, 103, BLACK); // Dibujamos un rectangulo relleno de color
    tft.fillRect(16, 179, 39, 31, BLACK);
    //tft.fillrect(xPos, yPos, length, width,color);
    tft.fillRect(x1, nota1, 30, 30, WHITE);
    nota1 += 5;
    delay(110);
  }else if((nota2 < 126) && (start == 1)){
    tft.fillRect(130, 35, 180, 35, BLACK);   //borrar bien!!, casi!!, mal!!
    for(int i = 75; i < 130; i += 5){
      //Patron de descenso de las notas
      tft.drawLine(15,178,295,178,GREEN);
      tft.fillRect(x1-4, 75, 39, 103, BLACK); // Dibujamos un rectangulo relleno de color
      tft.fillRect(x1-4, 179, 39, 31, BLACK);
      tft.fillRect(x2-4, 75, 39, 103, BLACK);
      tft.fillRect(x2-4, 179, 39, 31, BLACK);
      //tft.fillrect(xPos, yPos, length, width,color);
      if((bandera == 6) || (bandera == 14) || (bandera == 15)){
        tft.fillRect(x2, i, 30, 30, BLACK);
      }else{
        tft.fillRect(x2, i, 30, 30, WHITE); 
      }
      if((bandera == 7) || (bandera == 15)){
        tft.fillRect(x1, i+55, 30, 30, BLACK);
      }else{
        tft.fillRect(x1, i+55, 30, 30, WHITE); 
      }
      nota_tocada = Serial1.read(); 
      //Serial.print(nota_tocada); Serial.print(","); Serial.print(i);Serial.print(",");Serial.println(bandera);
      if((nota_tocada == 'D') && ((bandera == 0) || (bandera == 1) || (bandera == 14)) && (imprimio == 0)){
        imprimir_bien_mal(i);
      }else if((nota_tocada == 'R') && ((bandera == 12) || (bandera == 13)|| (bandera == 11)) && (imprimio == 0)){
        imprimir_bien_mal(i);
      }else if((nota_tocada == 'M') && ((bandera == 9) || (bandera == 10) || (bandera == 11)) && (imprimio == 0)){
        imprimir_bien_mal(i);
      }else if((nota_tocada == 'F') && ((bandera == 9) || (bandera == 8) || (bandera == 7)) && (imprimio == 0)){
        imprimir_bien_mal(i);
      }else if((nota_tocada == 'S') && ((bandera == 2) || (bandera == 5) || (bandera == 6)) && (imprimio == 0)){
        imprimir_bien_mal(i);
      }else if((nota_tocada == 'L') && ((bandera == 5) || (bandera == 4)) && (imprimio == 0)){
        imprimir_bien_mal(i);
      }else if((i > 120) && (bandera < 15) && (bandera != 7) && (imprimio == 0)){
        tft.setTextSize(2);
        tft.setTextColor(YELLOW);
        tft.setCursor(130,45);
        tft.print("Que paso ahi??");  //No se puede escribir 3 ! o si no no compila 
        delay(80); 
      }
      delay(110);
    }
    tft.fillRect(x1-4, 179, 39, 31, BLACK);
    bandera += 1;
  }
  if (bandera > 15){
    tft.fillScreen(BLACK); // Colocamos el fondo del LCD en Negro
    tft.drawRect(5, 5, 310, 230, YELLOW);
    tft.setTextSize(4);
    tft.setTextColor(BLUE);
    tft.setCursor(125,15);
    tft.print("Tu");
    tft.setCursor(40,50);
    tft.print("Puntuacion");
    tft.setCursor(65,85);
    tft.print("fue:");
    tft.setTextColor(WHITE);
    tft.print(int(notas_acert),DEC);
    tft.print("/14");
    tft.setTextColor(BLUE);
    tft.setCursor(55,120);
    tft.print("Atrevete a");
    tft.setCursor(40,160);
    tft.print("intentarlo");
    tft.setCursor(55,195);
    tft.print("de nuevo");
    delay(5000);
    bandera = 0;
    start = 0;
    nota2 = 75;
    nota1 = 75;
    pantalla_inicio();
    Serial.write('N');
    delay(500);
    Serial.write(notas_acert);
  }
}
