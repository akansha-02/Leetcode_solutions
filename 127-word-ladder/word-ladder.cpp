class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(),wordList.end());

        if(words.find(endWord)==words.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int steps=1;

        while(!q.empty()){
            int size=q.size();
            while(size--){
                string word=q.front();
                q.pop();

                if(word==endWord)
                    return steps;

                for(int i=0;i<word.size();i++){
                    char original=word[i];

                    for(char ch='a';ch<='z';ch++){
                        word[i]=ch;
                        if(words.find(word)!=words.end()){
                            q.push(word);
                            words.erase(word);
                        }
                    }
                    word[i]=original;
                }
            }
            steps++;
        }
        return 0;
    }
};