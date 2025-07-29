class Solution {
public:
    string maskPII(string s) {
        // Convert all characters to lowercase
        for (int i = 0; i < s.size(); i++) {
            s[i] = tolower(s[i]);
        }

        // Initialize variables for storing masked information
        string maskedString = "";
        string lastDigits = "";
        int digitCount = 0;

        // Case: Masking Phone Numbers
        if (s.find("@") == string::npos) {
            // Count the number of digits in the string
            for (int i = 0; i < s.size(); i++) {
                if (isdigit(s[i]))
                    digitCount++;
            }

            // Construct the masked string based on the number of digits
            if (digitCount - 10 == 0) {
                maskedString += "***-***-";
            } else if (digitCount - 10 == 1) {
                maskedString += "+*-***-***-";
            } else if (digitCount - 10 == 2) {
                maskedString += "+**-***-***-";
            } else if (digitCount - 10 == 3) {
                maskedString += "+***-***-***-";
            }

            // Extract the last 4 digits
            digitCount = 0;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (isdigit(s[i])) {
                    lastDigits += s[i];
                    digitCount++;
                }
                if (digitCount == 4)
                    break;
            }
            // Reverse the order of the last 4 digits
            reverse(lastDigits.begin(), lastDigits.end());
        }
        // Case: Masking Email Addresses
        else {
            // Find the position of "@" in the string
            auto it = s.find("@");
            // Construct the masked email address
            maskedString = maskedString + s[0] + "*****" + s.substr(it - 1);
        }

        // Return the final masked string
        return maskedString + lastDigits;
    }
};