class Trie {
private: 
    struct Node{
        Node* links[26];
        bool flag=false; 
        bool containsKey(char ch)
        {
            if(links[ch-'a'])
                return true;
            else 
                return false;
        }
        void put(char ch,Node* node)
        {
            links[ch-'a']= node;
        }
        Node* get(char ch)
        {
            return links[ch-'a'];
        }
    };
public:

    /** Initialize your data structure here. */
    Node* root;
    Trie() {
            root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
            Node * node = root;
            for(int i=0;i<word.length();i++)
            {
                if(!node->containsKey(word[i]))
                {
                    node->put(word[i],new Node);
                }
                node = node->get(word[i]);
            }
        node->flag=true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node * node = root;
        for(int i=0;i<word.length();i++)
        {
            if(!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->flag;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node * node = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(!node->containsKey(prefix[i]))
            {
                return false;
            }  
            node = node->get(prefix[i]);
        }
        return true;
    }
};