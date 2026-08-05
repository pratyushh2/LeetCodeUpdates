class Solution {
public:

    // Function to check whether a single word
    // matches the given pattern.
    bool match(string word, string pattern) {

        // Maps pattern characters to word characters.
        unordered_map<char, char> pToW;

        // Maps word characters back to pattern characters.
        unordered_map<char, char> wToP;

        // Compare each character.
        for (int i = 0; i < word.size(); i++) {

            char p = pattern[i];
            char w = word[i];

            // If pattern character already has a mapping,
            // it must map to the current word character.
            if (pToW.count(p)) {

                if (pToW[p] != w)
                    return false;
            }
            else {

                pToW[p] = w;
            }

            // Check reverse mapping.
            // Every word character must map back
            // to exactly one pattern character.
            if (wToP.count(w)) {

                if (wToP[w] != p)
                    return false;
            }
            else {

                wToP[w] = p;
            }
        }

        return true;
    }

    vector<string> findAndReplacePattern(vector<string>& words,
                                         string pattern) {

        vector<string> ans;

        // Check every word.
        for (string word : words) {

            if (word.size() == pattern.size() &&
                match(word, pattern)) {

                ans.push_back(word);
            }
        }

        return ans;
    }
};