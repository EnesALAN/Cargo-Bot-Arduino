

//Arduino Pins
int S0 = 7;
int S1 = 16;
int S2 = 17;
int S3 = 18;
int OUT = 10;
int LED = 13;


int BluesValue,RedsValue, GreensValue;
int range = 6;

int ColorPer[5][3] = {      {52,84,47}, 
                            {31,7,11}, 
                            {45,17,77}, 
                            {69,27,46},
                            {81,38,92} }; 
                            
String MyColors[5] = {"Blue", "White","Yellow", "Red", "Green"};


void setup() {
  Serial.begin(9600);
  pinMode(S0,OUTPUT); 
  pinMode(S1,OUTPUT); 
  pinMode(S2,OUTPUT); 
  pinMode(S3,OUTPUT); 
  pinMode(LED,OUTPUT); 
  pinMode(OUT,INPUT); 
}

void loop() { 
  DetectColor();
  delay(100);
}


void TCS3200_Open() {
  digitalWrite(LED,HIGH); 
  digitalWrite(S0,HIGH); 
  digitalWrite(S1,HIGH);
  delay(50);
}

void TCS3200_Off() {
  digitalWrite(LED,LOW);
  digitalWrite(S0,LOW); 
  digitalWrite(S1,LOW);
}

void None() { 
  digitalWrite(S2,HIGH);
  digitalWrite(S3,LOW);
  delay(50);
}

void RedDetecting() { 
  digitalWrite(S2,LOW); 
  digitalWrite(S3,LOW);
  delay(50);
}

void GreenDetecting() { 
  digitalWrite(S2,HIGH); 
  digitalWrite(S3,HIGH);
  delay(5);
}

void BlueDetecting() { 
  digitalWrite(S2,LOW); 
  digitalWrite(S3,HIGH);
  delay(50);
}


void DetectColor() {
  float noneFrequency, redFrequency, greenFrequency, blueFrequency;
  TCS3200_Open();
  None();
  noneFrequency = float(pulseIn(OUT,LOW,40000)); 
  RedDetecting();
  redFrequency = float(pulseIn(OUT,LOW,40000)); 
  GreenDetecting();
  greenFrequency = float(pulseIn(OUT,LOW,40000)); 
  BlueDetecting();
  blueFrequency = float(pulseIn(OUT,LOW,40000)); 
  TCS3200_Off();
  redFrequency = int((noneFrequency / redFrequency) * 100.0);
  greenFrequency = int((noneFrequency / greenFrequency) * 100.0);
  blueFrequency = int((noneFrequency / blueFrequency) * 100.0); 
  
  FoundFrequency();
}

void FoundFrequency() {
    Serial.println("Colors Specification");
    
    Serial.print("This color is RED=");
    Serial.print(redFrequency);
    
    Serial.print("This color is BLUE=");
    Serial.print(blueFrequency);
    
    Serial.print("This color is GREEN=");
    Serial.println(greenFrequency);
    
    Serial.println();
    Serial.print("COLOR=");
    
    int isSet=0;
    for(int color =0; color < 5; color++)
  {
  
      if(greenFrequency > ColorPer[color][2] - 6 && greenFrequency < ColorPer[color][2] +  6 && 
    blueFrequency > ColorPer[color][1] - 6 && blueFrequency < ColorPer[color][1] + 6 && 
         redFrequency > ColorPer[color][0] - 6 && redFrequency < ColorPer[color][0] + 6 )
         {
         Serial.println(MyColors[color]); 
         isSet=1;
         break;
         }
    }
    if(isSet == 0)
      Serial.println("Device cannot detect the color please do it again");
      
}
