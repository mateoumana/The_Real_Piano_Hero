#include "driver/i2s.h"
#include <arduinoFFT.h>

const i2s_port_t I2S_PORT = I2S_NUM_0;
const int BLOCK_SIZE = 1024;
const double samplingFrequency = 8000;
double vReal[BLOCK_SIZE];
double vImag[BLOCK_SIZE];
int32_t samples[BLOCK_SIZE];
double X[BLOCK_SIZE];
arduinoFFT FFT = arduinoFFT();
double ydo[BLOCK_SIZE], yre[BLOCK_SIZE], ymi[BLOCK_SIZE], yfa[BLOCK_SIZE] ,ysol[BLOCK_SIZE], yla[BLOCK_SIZE];
float r = 0.97;
double Coef_do[3] = {0.0236242705577962, 1.7784708554741, r*r}, Coef_re[3] = {0.026317836613089, 1.73723152417433, r*r};
double Coef_mi[3] = {0.0292620202031746, 1.68570718704845, r*r}, Coef_fa[3] = {0.0308281218217969, 1.65534950918135, r*r};
double Coef_sol[3] = {0.0341421080250755, 1.58370615463853, r*r}, Coef_la[3] = {0.0376781398788917, 1.49479569098503, r*r};

double Ex, Edo, Ere, Emi, Efa, Esol, Ela = 0;
int time_nota = 0;

#define LED_GREEN 5
#define LED_RED 18

void setup() {
  // put your setup code here, to run once:
  time_nota = millis();
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  Serial.begin(115200);
  esp_err_t err;

  //Thw I2S config as per the example
  const i2s_config_t i2s_config = { 
      .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),//Receive, not transfer
      .sample_rate = samplingFrequency,                 //16KHz
      .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,     //could only get it to work with 32bits
      .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT,     //use right channel
      .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
      .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,         //Interrupt level 1
      .dma_buf_count = 3,                               //NUMBER OF BUFFERS(4)
      .dma_buf_len = BLOCK_SIZE                         //8 samples per buffer (minimum)
  };
  const i2s_pin_config_t pin_config = {
      .bck_io_num = 26,                                 //Serial Clock (SCK)
      .ws_io_num = 25,                                  //Word Select (WS)
      .data_out_num = I2S_PIN_NO_CHANGE,                //not used (only for speakers)
      .data_in_num = 33                                 //Serial Data (SD)
    };
  //Configuring the I2S driver and pins
  //This function must be called before any I2S driver read/write operations.
  err = i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
  if(err != ESP_OK){
    Serial.printf("Failed installing driver: %d\n",err);
    while(true);
    }
  err = i2s_set_pin(I2S_PORT, &pin_config);
  if(err != ESP_OK){
    Serial.printf("Failed setting pin: %d\n",err);
    while(true);
    }
  Serial.println("I2S driver installed.");
}

void loop() {
  // put your main code here, to run repeatedly:
  //Read a single sample and log it for the Serial Plotter
  Ex = 0; Edo = 0; Ere = 0; Emi = 0; Efa = 0; Esol = 0; Ela = 0;
  for(int i=0; i<BLOCK_SIZE; i++){
    int32_t sample = 0;
    int bytes_read = i2s_pop_sample(I2S_PORT, (char *)&sample, portMAX_DELAY); // no timeout
    X[i]=sample/100000;  
    Ex = X[i]*X[i]+Ex;
  }
  for(int n=2; n< BLOCK_SIZE; n++){
    //ESPACIO PARA APLICAR LOS FILTROS
    //y(n) = b0*x(n) + 2*r*cos(w0)*y(n-1) - r*r*y(n-2);
    ydo[n] = Coef_do[0]*X[n] + Coef_do[1]*ydo[n-1] - Coef_do[2]*ydo[n-2];
    yre[n] = Coef_re[0]*X[n] + Coef_re[1]*yre[n-1] - Coef_re[2]*yre[n-2];
    ymi[n] = Coef_mi[0]*X[n] + Coef_mi[1]*ymi[n-1] - Coef_mi[2]*ymi[n-2];
    yfa[n] = Coef_fa[0]*X[n] + Coef_fa[1]*yfa[n-1] - Coef_fa[2]*yfa[n-2];
    ysol[n] = Coef_sol[0]*X[n] + Coef_sol[1]*ysol[n-1] - Coef_sol[2]*ysol[n-2];
    yla[n] = Coef_la[0]*X[n] + Coef_la[1]*yla[n-1] - Coef_la[2]*yla[n-2];
    //ESPACIO PARA PLOTEAR Y[N] Y X[N]
    //Serial.print(X[n]); Serial.print(" "); Serial.print(y24[n]);
    //Serial.println();
    //CALCULO DE ENERGIA
    Edo = ydo[n]*ydo[n] + Edo;
    Ere = yre[n]*yre[n] + Ere;
    Emi = ymi[n]*ymi[n] + Emi;
    Efa = yfa[n]*yfa[n] + Efa;
    Esol = ysol[n]*ysol[n] + Esol;
    Ela = yla[n]*yla[n] + Ela;    
  }
  //Condicion
  if ((millis()-time_nota > 500)){
    if(((Edo/Ex) > 0.35)){ //0.89
      Serial.write("D");
      Serial.println();
      time_nota = millis();
    }else if((Ere/Ex) > 0.40){  //0.9
      Serial.write("R");
      Serial.println();
      time_nota = millis();
    }else if((Emi/Ex) > 0.80){  //0.94
      Serial.write("M");
      Serial.println();
      time_nota = millis();
    }else if((Efa/Ex) > 0.80){  //0.94
      Serial.write("F");
      Serial.println();
      time_nota = millis();
    }else if((Esol/Ex) > 0.90){ //0.91
      Serial.write("S");
      Serial.println();
      time_nota = millis();
    }else if((Ela/Ex) > 0.90){   //0.915
      Serial.write("L");
      Serial.println();
      time_nota = millis();
    }
  }
  //ESPACIO PARA PLOTEAR Ex/Ey
  //Serial.print(Edo/Ex); Serial.print(" , "); Serial.print(Ere/Ex); Serial.print(" , "); Serial.print(Emi/Ex); Serial.print(" , "); Serial.print(Efa/Ex); 
  //Serial.print(" , "); Serial.print(Esol/Ex); Serial.print(" , "); Serial.println((Ela/Ex));
} 
