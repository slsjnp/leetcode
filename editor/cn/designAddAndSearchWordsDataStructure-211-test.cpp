// 2021-10-19 16:49:41
#include <gtest/gtest.h>
#include <vector>
#include <queue>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)

class TrieNode{
public:
    vector<TrieNode*> children;
    bool isWord;
    TrieNode(): isWord(false), children(26, nullptr){}
    ~TrieNode(){
        for (auto& c:children) {
            delete c;
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary(){
        delete root;
    }

    void addWord(string word) {
        TrieNode *now = root;
        for (auto s: word) {
            int i = s-'a';
            if (!now->children[i]){
                now->children[i] = new TrieNode();
            }
            now = now->children[i];
        }
        now->isWord=true;
    }
    
    bool search(string word) {
        vector<TrieNode*> res;
        find(root, word, 0, res);
        while (qu.size() > 0) {
            kv kv_ = qu.front();
            qu.pop();
            find(kv_.k, word, kv_.v, res);
        }
        for (auto t: res) {
            if (t && t->isWord){
                return true;
            }
        }
        return false;
    }

    void find(TrieNode* tree, string& word, int start, vector<TrieNode*>& res){
        if (!tree) return;
        TrieNode *now = tree;
        // int flag = 1;
        while (start < word.length()) {
            if (!now) return;
            if (word[start] == '.'){
                for (auto t: now->children) {
                    kv kv_{};
                    kv_.k = t;
                    kv_.v = start+1;
                    qu.push(kv_);
                }
                return;
            }
            int i = word[start]-'a';
            now = now->children[i];
            start++;
        }
        if (start == word.length()){
            res.push_back(now);
        }
    }
private:
    struct kv{
        TrieNode* k;
        int v;
    };
    TrieNode* root;
    queue<kv> qu;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
//leetcode submit region end(Prohibit modification and deletion)


namespace {
    TEST(DesignAddAndSearchWordsDataStructure, Example1) {      // NOLINT
        // std::vector<int> nums = {  };
        // auto ans = Solution().designAddAndSearchWordsDataStructure(nums);
        WordDictionary w;
        w.addWord(string("a"));
        w.addWord(string("a"));
        auto ans = w.search(string("a."));
        decltype(ans) rightAns = false;
        ASSERT_EQ(ans, rightAns);
    }

}


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}