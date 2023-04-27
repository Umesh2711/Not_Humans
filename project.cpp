#include <iostream>
#include <string>

using namespace std;

// Function to convert a number from any radix to decimal
int toDecimal(string num, int base) {
    int decimal = 0;
    int power = 1;

    for (int i = num.size() - 1; i >= 0; i--) {
        int digit;
        if (num[i] >= '0' && num[i] <= '9') {
            digit = num[i] - '0';
        } else {
            digit = num[i] - 'A' + 10;
        }
        decimal += digit * power;
        power *= base;
    }
//system("Color 9");
    return decimal;
}

// Function to convert a decimal number to any radix
string fromDecimal(int decimal, int base) {
    string num = "";

    while (decimal > 0) {
        int remainder = decimal % base;
        if (remainder < 10) {
            num = char('0' + remainder) + num;
        } else {
            num = char('A' + remainder - 10) + num;
        }
        decimal /= base;
    }

    return num;
}

// Function to convert a number from one radix to another
string convert(string num, int fromRadix, int toRadix) {
    int decimal = toDecimal(num, fromRadix);
    string result = fromDecimal(decimal, toRadix);
    return result;
}

int main() {
    string num;
    int fromRadix, toRadix;

    cout<<"\t\t\t ***** RADIX CALCULATOR *****\n";
    cout << "\n\nEnter the number: ";
    cin >> num;
    cout<<"\n";
    cout << "Enter the source radix: ";
    cin >> fromRadix;
    cout<<"\n";
    cout << "Enter the destination radix: ";
    cin >> toRadix;
    cout<<"\n";

    string result = convert(num, fromRadix, toRadix);

    cout << num << " in base " << fromRadix << " is " << result << " in base " << toRadix << endl;

    return 0;
}