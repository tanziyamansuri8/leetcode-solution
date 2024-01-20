class Solution {
public:
    static bool compare(std::pair<char, int> a, std::pair<char, int> b) {
        return a.second > b.second;
    }

    string frequencySort(std::string s) {
        // Step 1: Count the frequency of each character using std::map
        map<char, int> charFrequency;
        for (char c : s) {
            charFrequency[c]++;
        }

        // Step 2: Convert the map to a vector of pairs for sorting
        vector<std::pair<char, int>> charFrequencyVector(charFrequency.begin(), charFrequency.end());

        // Step 3: Sort the vector based on frequency
        std::sort(charFrequencyVector.begin(), charFrequencyVector.end(), compare);

        // Step 4: Construct the sorted string
        string sortedString;
        for (auto pair : charFrequencyVector) {
            sortedString +=string(pair.second, pair.first);
        }

        return sortedString;
    }
};