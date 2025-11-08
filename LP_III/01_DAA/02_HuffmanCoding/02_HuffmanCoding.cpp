#include<bits/stdc++.h>
using namespace std;

// A Huffman tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Compare function for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to generate Huffman codes recursively
void buildCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    // If leaf node (contains a character)
    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;

    buildCodes(root->left, code + "0", huffmanCode);
    buildCodes(root->right, code + "1", huffmanCode);
}

// Main Huffman Encoding function
string huffmanEncode(string text) {
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;

    // Min-heap priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));

    // Greedy approach: combine two smallest freq nodes until one tree remains
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }

    Node* root = pq.top();

    // Generate Huffman codes
    unordered_map<char, string> huffmanCode;
    buildCodes(root, "", huffmanCode);

    // Encode input string
    string encoded = "";
    for (char ch : text)
        encoded += huffmanCode[ch];

    // Optional: print codes for clarity
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << endl;

    return encoded;
}

// Driver code
int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    string encoded = huffmanEncode(text);
    cout << "\nEncoded string: " << encoded << endl;
    return 0;
}
