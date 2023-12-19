#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

int get_line_sum(std::string line)
{
    // get length of string
    int n = line.length();
    // declaring character array
    char char_array[2] = {'0', '0'};
    // declaring if first character is set
    bool first_char_set = false;
    // loop through string
    for (int i = n; i >= 0; i--)
    {
        // check if character is a digit
        if (isdigit(line[i]))
        {
            if (!first_char_set)
            {
                // set first character
                char_array[1] = line[i];
                char_array[0] = line[i];
                first_char_set = true;
            }
            else
            {
                // add character to array
                char_array[0] = line[i];
            }
        }
    }
    // convert character array to integer eg. "123" -> 123
    int number = atoi(char_array);
    std::cout << line << ": " << number << "\n";
    // return number
    return number;
}

int main()
{

    std::ifstream file("day-1-input");
    std::string line;
    int sum = 0;
    while (std::getline(file, line))
    {
        sum += get_line_sum(line);
    }
    std::cout << sum << "\n";

    return 0;
}
