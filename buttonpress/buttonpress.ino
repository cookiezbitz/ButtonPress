// Define the GPIO pins for the buttons
const int buttonPin1 = 15;  // D15
const int buttonPin2 = 2;   // D2

// Variables to store the button states
int buttonState1 = HIGH;  // HIGH means not pressed
int buttonState2 = HIGH;  // HIGH means not pressed

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(buttonPin1, INPUT_PULLDOWN);
  pinMode(buttonPin2, INPUT_PULLDOWN);

  Serial.println("Button detection initialized.");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

    // Check if button at D15 is pressed


  // Check if button at D2 is pressed
  if (buttonState2 == HIGH || buttonState1 == HIGH) {
    Serial.println("Button Pressed");
    delay(2000);  // Debounce delay
  }


}
