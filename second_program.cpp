/*
Hikmatullah Hussain Zada
0761906
COIS 2040 Assignment 2
*/

// Libraries
#include <iostream> // For input/output operations
#include <fstream>  // For file handling

// Main program
int main()
{
    std::ifstream fileIn;  // Input file stream
    std::ofstream fileOut; // Output file stream
    std::string fileName;  // Variable to store the file name

    int num, sum = 0, count = 0; // Variables to store numbers, sum, and count of numbers

    // Prompt user for input file name
    std::cout << "Enter input file name: ";
    std::cin >> fileName;

    // Open the file for reading
    fileIn.open(fileName);

    // Check if file opened successfully
    if (!fileIn.is_open())
    {
        std::cerr << "Error: failed opening the input file!\n"; // Display error message if file cannot be opened
        return 1;                                               // Exit program with error status
    }

    // Open the file for writing
    fileOut.open("output.txt");

    // Check if file opened successfully
    if (!fileOut.is_open())
    {
        std::cerr << "Error: failed opening the output file!\n"; // Display error message if file cannout be opened
        return 1;                                                // Exit program with error status
    }

    // Display table headers
    fileOut << "Number\tSquare\tSum\n";

    // Read numbers from file and process them
    while (fileIn >> num)
    {
        sum += num;                                                   // Update cumulative sum
        fileOut << num << "\t" << (num * num) << "\t" << sum << "\n"; // Print number, its square, and cumulative sum
        count++;                                                      // Increment count of numbers
    }

    // Calculate and display the average if at least one number was read
    if (count > 0)
    {
        fileOut << "Average: " << (sum / static_cast<double>(count)) << "\n";
    }

    // Close the file
    fileIn.close();
    fileOut.close();
    std::cout << "Results written to output.txt\n";

    return 0; // Program executed successfully
}
