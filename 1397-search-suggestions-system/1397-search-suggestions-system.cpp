

struct Node {
    Node* links[26];
    bool flag = false;
    int k;
    priority_queue<string> pq;
    Node(int k) {
        this->k = k;
        for (int i = 0; i < 26; ++i)
            links[i] = nullptr;
    }
    bool containsKey(char ch) { return links[ch - 'a'] != NULL; }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    void push(string word) {
        pq.push(word);
        if (pq.size() > k) {
            pq.pop();
        }
    }
    vector<string> topkel() {
        vector<string> v;
        stack<string>st;
        while (!pq.empty()) {
            st.push(pq.top());
            pq.pop();
        }
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        return v;
    }
    Node* get(char ch) { return links[ch - 'a']; }

    void setEnd() { flag = true; }

    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie(int k) { root = new Node(k); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node(3));
            }

            node = node->get(word[i]);
            node->push(word);
        }
        node->setEnd();
    }
    vector<vector<string>> find(string word) {
        Node* node = root;
        vector<vector<string>> ans;
        for (int i = 0; i < word.length(); i++) {
            vector<string> v;
            if (!node->containsKey(word[i])) {
                while(i<word.length())
                {
                    ans.push_back(v);
                    i++;
                }
                return ans;
            }
            node = node->get(word[i]);
            v = node->topkel();
            ans.push_back(v);
        }
        return ans;
    }
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& p, string s) {
        Trie T(3);
        for (auto it : p) {
            T.insert(it);
        }
        return T.find(s);
    }
};