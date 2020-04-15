

int led = D7;  // The D7 on-board LED
int button = D3;
int LedFreqState = 0;
int prevButton = LOW;


bool LED_state = FALSE;

// This variable stores the next time to toggle the LED. 
unsigned long int timeToToggleLED = 0;

void setup() {
    pinMode(led, OUTPUT);
    pinMode(button, INPUT_PULLDOWN);
    digitalWrite(led, LOW);
    Serial.begin(9600);
}

void loop() {
    int currButton = digitalRead(button);
    if (currButton == HIGH && prevButton == LOW) {
      LedFreqState++;
      if (LedFreqState > 2) {
        LedFreqState = 0;
      }
    }
    prevButton = currButton;
    Serial.print(currButton);
    unsigned long int currentTime = millis();  // get the current time

    // Check if it is time to toggle the LED “Are we there yet? Are we there yet? ..."
    if (LedFreqState == 0) {
      if(currentTime > timeToToggleLED){  
        // Time to Toggle!
        LED_state = !LED_state;
        digitalWrite(led, LED_state);
    
        // Calculate and store the next time to toggle the LED
        timeToToggleLED += 500;
      }
    }
    if (LedFreqState == 1) {
      if(currentTime > timeToToggleLED){  
        // Time to Toggle!
        LED_state = !LED_state;
        digitalWrite(led, LED_state);
      

        // Calculate and store the next time to toggle the LED
       timeToToggleLED += 300;
      }
    }
    if (LedFreqState == 2) {
      if(currentTime > timeToToggleLED){  
        // Time to Toggle!
        LED_state = !LED_state;
        digitalWrite(led, LED_state);
       

        // Calculate and store the next time to toggle the LED
        timeToToggleLED += 100;
      }
    }
    
}
