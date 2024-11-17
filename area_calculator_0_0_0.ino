#include <Arduino.h>

// Function to calculate cumulative areas
void calculateAreas(uint16_t *A, uint16_t *B, uint16_t n, uint32_t &area0, uint32_t &area1, uint32_t &area2) {
  area0 = area1 = area2 = 0; // Initialize areas

  for (uint16_t i = 0; i < n; i++) {
    for (uint16_t j = 0; j < n; j++) {
      uint8_t number = (i + j) % 3; // Calculate (i + j) mod 3
      uint32_t area = (uint32_t)A[i] * B[j]; // Calculate rectangle area
      
      // Accumulate area based on number
      if (number == 0) area0 += area;
      else if (number == 1) area1 += area;
      else area2 += area;
    }
  }
}

// Function to clear Serial buffer
void clearSerialBuffer() {
  while (Serial.available() > 0) {
    Serial.read(); // Discard any leftover characters in the buffer
  }
}

// Function to read an integer input
uint16_t readIntFromSerial() {
  while (Serial.available() == 0) { ; } // Wait for input
  String input = Serial.readStringUntil('\n');
  input.trim(); // Remove any extra spaces or newlines
  return input.toInt(); // Convert to integer
}

// Function to read a line of integers into an array
void readArray(uint16_t *array, uint16_t n) {
  clearSerialBuffer(); // Clear buffer before reading new input
  while (Serial.available() == 0) { ; } // Wait for input
  String inputLine = Serial.readStringUntil('\n'); // Read the whole line
  inputLine.trim(); // Remove any leading/trailing whitespace

  uint16_t index = 0;
  char *token = strtok((char *)inputLine.c_str(), " "); // Split by spaces
  while (token != nullptr && index < n) {
    array[index++] = atoi(token); // Convert token to integer and store in array
    token = strtok(nullptr, " "); // Get next token
  }
}

void processInput() {
  uint16_t n;

  // Prompt user for input
  Serial.println("Enter n (number of rows/columns):");
  n = readIntFromSerial(); // Read n
  Serial.print("n = ");
  Serial.println(n);

  if (n <= 0) {
    Serial.println("Invalid input for n. Please try again.");
    return; // Return to main loop if n is invalid
  }

  // Allocate memory for arrays A and B
  uint16_t *A = new uint16_t[n];
  uint16_t *B = new uint16_t[n];

  // Read array A
  Serial.println("Enter A values (space-separated):");
  readArray(A, n);

  // Echo A values for confirmation
  Serial.print("A: ");
  for (uint16_t i = 0; i < n; i++) {
    Serial.print(A[i]);
    Serial.print(" ");
  }
  Serial.println();

  // Read array B
  Serial.println("Enter B values (space-separated):");
  readArray(B, n);

  // Echo B values for confirmation
  Serial.print("B: ");
  for (uint16_t i = 0; i < n; i++) {
    Serial.print(B[i]);
    Serial.print(" ");
  }
  Serial.println();

  // Compute cumulative areas
  uint32_t area0, area1, area2;
  calculateAreas(A, B, n, area0, area1, area2);

  // Output results
  Serial.println("Results:");
  Serial.print("Area 0: ");
  Serial.println(area0);
  Serial.print("Area 1: ");
  Serial.println(area1);
  Serial.print("Area 2: ");
  Serial.println(area2);

  // Free allocated memory
  delete[] A;
  delete[] B;
}

void setup() {
  Serial.begin(115200); // Start Serial communication
  while (!Serial) { ; } // Wait for Serial to connect
}

void loop() {
  Serial.println("\n--- New Calculation ---");
  processInput();

  // Prompt user to continue or exit
  Serial.println("\nDo you want to perform another calculation? (y/n):");
  while (Serial.available() == 0) { ; } // Wait for input
  char response = Serial.read();
  if (response == 'n' || response == 'N') {
    Serial.println("Exiting. Goodbye!");
    while (true) { ; } // Halt the program
  }
  clearSerialBuffer(); // Clear buffer before the next loop
}
