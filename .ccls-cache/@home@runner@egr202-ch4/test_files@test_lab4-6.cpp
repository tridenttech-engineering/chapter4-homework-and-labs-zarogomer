#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <unistd.h> // For STDIN_FILENO, STDOUT_FILENO, dup, dup2, and close
using namespace std;

void runTest() {
  // Expected output value
  string expected_value = "71.5";

  // Create temporary file for output redirection
  FILE *output_file = tmpfile();

  // Redirect stdout to the output file
  int output_fd = fileno(output_file);
  int saved_stdout_fd = dup(STDOUT_FILENO);
  dup2(output_fd, STDOUT_FILENO);

  // Call the original program's main function
  int result = system("./lab4-6");

  // Restore stdout
  dup2(saved_stdout_fd, STDOUT_FILENO);
  close(saved_stdout_fd);

  // Check if the system call was successful
  if (result != 0) {
    cout << "Test Failed: Program did not run successfully" << endl;
    exit(-1);
  }

  // Read the output from the output file
  rewind(output_file);
  char buffer[256];
  string actual_output;
  while (fgets(buffer, sizeof(buffer), output_file)) {
    actual_output += buffer;
  }

  // Close and remove the temporary file
  fclose(output_file);

  // Debugging information
  cout << "Expected Value:\n" << expected_value << endl;
  cout << "Actual Output:\n" << actual_output << endl;

  // Compare the actual output to the expected value
  if (actual_output.find(expected_value) == string::npos) {
    cout << "Test Failed: Output does not contain the expected value" << endl;
    exit(-1);
  }

  cout << "Test passed!" << endl;
}

int main() {
  try {
    runTest();
  } catch (const exception &e) {
    cout << "Test Failed: " << e.what() << endl;
    return -1;
  } catch (...) {
    cout << "Test Failed: Unknown error occurred" << endl;
    return -1;
  }
  return 0;
}
