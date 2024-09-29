import serial
import time
from playsound import playsound
import pygame

# Initialize pygame mixer
pygame.mixer.init()

# Set up the serial connection (replace 'COM3' with your Arduino port)
ser = serial.Serial('COM4', 115200, timeout=1)
time.sleep(2)  # Wait for the connection to initialize

print("Listening for button presses from Arduino...")

try:
    while True:
        # Read a line from the serial port
        line = ser.readline().decode('utf-8').strip()
        
        # Check if the signal is received
        if line == "Button Pressed":
            print("Button pressed! Playing sound.")
            pygame.mixer.music.load('C:/Users/Remiel/Documents/GitHub/ButtonPress/familyfeud.mp3')
            pygame.mixer.music.play()
            while pygame.mixer.music.get_busy():
                time.sleep(1)
except KeyboardInterrupt:
    print("Program terminated.")
finally:
    ser.close()
    pygame.mixer.quit()