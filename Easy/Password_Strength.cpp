// Problem: Password Strength
// Difficulty: Easy
// Approach: Character Classification + Frequency Tracking
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int passwordStrength(string password) {
        bool lowercase[26] = {}, uppercase[26] = {}, digit[10] = {};
        bool specialchar[256] = {};
        int strength = 0;

        for (char ch : password) {
            if (ch >= 'a' && ch <= 'z') {
                int i = ch - 'a';
                if (!lowercase[i]) {
                    strength += 1;
                    lowercase[i] = true;
                }
            } 
            else if (ch >= 'A' && ch <= 'Z') {
                int i = ch - 'A';
                if (!uppercase[i]) {
                    strength += 2;
                    uppercase[i] = true;
                }
            } 
            else if (ch >= '0' && ch <= '9') {
                int i = ch - '0';
                if (!digit[i]) {
                    strength += 3;
                    digit[i] = true;
                }
            } 
            else {
                unsigned char x = ch;
                if (!specialchar[x]) {
                    strength += 5;
                    specialchar[x] = true;
                }
            }
        }

        return strength;
    }
};
