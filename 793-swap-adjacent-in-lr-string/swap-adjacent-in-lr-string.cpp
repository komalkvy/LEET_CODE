class Solution {
public:

    bool canTransform(string start, string end) {
        // If lengths are different, transformation is impossible
        if (start.length() != end.length()) {
            return false;
        }
        
        // Create strings without 'X' to check if character sequences match
        string startChars, endChars;
        for (char c : start) {
            if (c != 'X') startChars += c;
        }
        for (char c : end) {
            if (c != 'X') endChars += c;
        }
        
        // If the sequences without 'X' don't match, return false
        if (startChars != endChars) {
            return false;
        }
        
        // Initialize pointers for both strings
        int p1 = 0, p2 = 0;
        int n = start.size();
        
        while (p1 < n && p2 < n) {
            // Skip 'X' in both strings
            while (p1 < n && start[p1] == 'X') p1++;
            while (p2 < n && end[p2] == 'X') p2++;
            
            // If both pointers reach the end, the strings are transformable
            if (p1 == n && p2 == n) {
                return true;
            }
            
            // If only one pointer reaches the end, strings aren't transformable
            if (p1 == n || p2 == n) {
                return false;
            }
            
            // If current characters don't match, transformation is impossible
            if (start[p1] != end[p2]) {
                return false;
            }
            
            // 'L' should not move right (should be left or same position)
            if (start[p1] == 'L' && p1 < p2) {
                return false; 
            }
            // 'R' should not move left (should be right or same position)
            if (start[p1] == 'R' && p1 > p2) {
                return false; 
            }
            
            // Move to the next character in both strings
            p1++;
            p2++;
        }
        
        // If all checks pass, the transformation is possible
        return true;
    }
};