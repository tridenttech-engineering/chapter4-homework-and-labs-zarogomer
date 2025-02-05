#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <unistd.h> // For STDIN_FILENO, STDOUT_FILENO, dup, dup2, and close
using namespace std;

void runTest() {
  // Test case 1
  string input = "269.54\n234.47\n";
  string expected_values[] = {"283.02", "246.19", "529.21"};

  // Create temporary files for input and output redirection
  FILE *input_file = tmpfile();
  FILE *output_file = tmpfile();

  // Write the input to the input file
  fputs(input.c_str(), input_file);
  rewind(input_file);

  // Redirect stdin to the input file
  int input_fd = fileno(input_file);
  int saved_stdin_fd = dup(STDIN_FILENO);
  dup2(input_fd, STDIN_FILENO);

  // Redirect stdout to the output file
  int output_fd = fileno(output_file);
  int saved_stdout_fd = dup(STDOUT_FILENO);
  dup2(output_fd, STDOUT_FILENO);

  // Call the original program's main function
  int result = system("./hw4-16");

  // Restore stdin and stdout
  dup2(saved_stdin_fd, STDIN_FILENO);
  dup2(saved_stdout_fd, STDOUT_FILENO);
  close(saved_stdin_fd);
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

  // Close and remove the temporary files
  fclose(input_file);
  fclose(output_file);

  // Debugging information
  cout << "Expected Values:\n";
  for (const auto& value : expected_values) {
    cout << value << endl;
  }
  cout << "Actual Output:\n" << actual_output << endl;

  // Compare the actual output to the expected values
  bool all_values_found = true;
  for (const auto& value : expected_values) {
    if (actual_output.find(value) == string::npos) {
      all_values_found = false;
      break;
    }
  }

  if (!all_values_found) {
    cout << "Test Failed: Output does not contain all expected values" << endl;
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
