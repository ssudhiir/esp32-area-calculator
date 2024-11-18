# esp32-area-calculator
Arduino code for ESP32 to calculate cumulative rectangle areas based on user input

# ESP32 Area Calculator

This project implements a program for the ESP32 using Arduino IDE to calculate cumulative rectangle areas based on user inputs. The rectangle is divided into smaller rectangles, and areas are categorized based on (i + j) % 3 values (0, 1, 2).

The program reads dimensions (n, A, and B) from the Serial Monitor, computes areas dynamically, and displays the results. The logic runs in a loop, allowing repeated calculations.
________________________________________
# Features:

  	Dynamic Input: Supports user-defined rows (n), column widths (A), and row heights (B).

  	Categorized Results: Calculates cumulative areas for mod values 0, 1, and 2.

  	Continuous Usage: Repeats calculations in a loop until the user decides to exit.

  	Efficient Memory Management: Dynamically allocates and frees memory for arrays.
________________________________________
# Hardware Requirements:

  	ESP32 Board: Compatible with all ESP32 development boards.

  	Micro-USB Cable: For connecting the ESP32 to your computer.
________________________________________
# Software Requirements:

  	Arduino IDE: Download from arduino.cc.

  	ESP32 Core: Install ESP32 support in Arduino IDE via the Board Manager.

  	Serial Monitor: For user input and output display.
________________________________________
# Setup and Usage:

1.	Clone or Download the Repository:


        git clone https://github.com/ssudhiir/esp32-area-calculator.git

        Or download the ZIP file from the repository and extract it.

3.	Open the Code in Arduino IDE:

    	Open the area_calculator.ino file in the Arduino IDE.

4.	Configure the ESP32 Board:

    	Go to Tools > Board > ESP32 Arduino > Your ESP32 Board.

    	Select the appropriate COM port.

5.	Upload the Code:

    	Click the Upload button in Arduino IDE to flash the code onto your ESP32.

6.	Open Serial Monitor:

    	After uploading, open the Serial Monitor (Tools > Serial Monitor).

    	Set the baud rate to 115200.

7.	Input Data:


    	Follow the commands to enter:

	    n: Number of rows/columns.

    	A: Space-separated column widths.

    	B: Space-separated row heights.

    	View the results for areas corresponding to values 0, 1, and 2.

8.	Repeat or Exit:

    	Enter y to perform another calculation.

    	Enter n to exit.

