class MagicDictionary {
public:
    vector<string> v;
    MagicDictionary() {}

    void buildDict(vector<string> dictionary) {
        for (int i = 0; i < dictionary.size(); i++) {
            v.push_back(dictionary[i]);
        }
    }

    bool search(string searchWord) {
        for (int i = 0; i < v.size(); i++) {
            string str = v[i];

            if(str.length() != searchWord.length()) continue;

            if(str == searchWord) continue;

            int count = 0;
            for(int j = 0; j < searchWord.length(); j++){
                if(str[j] != searchWord[j]){
                    count += 1;

                    if(count > 1) break;
                }
            }

            if(count == 1) return true;
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */