/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
     // Encodes a tree to a single string.
    string serialize(Node* root) {
        string s;
        encode_dfs(root, s);
        return s;
    }

    void encode_dfs(Node* root, string& s){
        if(!root) return;
        s += " " + to_string(root->val) + " " + to_string(root->children.size());
        for(auto p:root->children) encode_dfs(p, s);
    }
    
    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        stringstream ss(data);
        return decode(ss);
    }
    
    Node* decode(stringstream& ss){
        ss.peek(); 
        if(ss.eof()) return nullptr;
        auto root = new Node();
        int child_size;
        ss >> root->val >> child_size;
        for(int i=0; i<child_size;i++) root->children.push_back(decode(ss));                
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));