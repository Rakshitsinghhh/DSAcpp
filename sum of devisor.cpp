#include<iostream>
using namespace std;

bool isdiv(int num)
{
    int sum = 0;

    // Find divisors of num and calculate their sum
    for(int i = 1; i <= num / 2; i++)
    {
        if(num % i == 0)
        {
            sum += i; // Add divisor to the sum
        }
    }

    // Check if the sum of divisors equals the number
    return sum == num;
}

int main()
{
    int num = 14; // You can change this value to test other numbers

    bool ans = isdiv(num); // Call the function to check if num is a perfect number

    // Output the result
    if(ans == true)
    {
        cout << "True" << endl; // Output True if num is a perfect number
    }
    else
    {
        cout << "False" << endl; // Output False if num is not a perfect number
    }

    return 0;
}
