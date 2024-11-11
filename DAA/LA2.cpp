#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class HuffmanTreeNode {
public:
    char data;
    int freq;
    HuffmanTreeNode *left, *right;

    HuffmanTreeNode(char character, int frequency) : data(character), freq(frequency), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue
struct Compare {
    bool operator()(HuffmanTreeNode* a, HuffmanTreeNode* b) {
        return a->freq > b->freq;
    }
};

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare>& pq) {
    while (pq.size() > 1) {
        HuffmanTreeNode *left = pq.top(); pq.pop();
        HuffmanTreeNode *right = pq.top(); pq.pop();

        // New internal node with combined frequency
        HuffmanTreeNode *node = new HuffmanTreeNode('$', left->freq + right->freq);
        node->left = left;
        node->right = right;

        pq.push(node);
    }
    return pq.top();
}

// Recursive function to print codes from root of Huffman Tree
void printCodes(HuffmanTreeNode *root, string code) {
    if (root->left) {
        printCodes(root->left, code + "0");
    }
    if (root->right) {
        printCodes(root->right, code + "1");
    }

    // Leaf node - print character and code
    if (!root->left && !root->right) {
        cout << root->data << ": " << code << endl;
    }
}

void HuffmanCodes(const vector<char>& data, const vector<int>& freq) {
    priority_queue<HuffmanTreeNode*, vector<HuffmanTreeNode*>, Compare> pq;

    // Populate priority queue with initial nodes
    for (size_t i = 0; i < data.size(); ++i) {
        pq.push(new HuffmanTreeNode(data[i], freq[i]));
    }

    // Generate Huffman Tree
    HuffmanTreeNode* root = generateTree(pq);

    // Print codes using a recursive helper
    printCodes(root, "");

    // Clean up dynamically allocated memory (Optional: Implement a recursive delete function if tree is large)
    delete root;
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> data(n);
    vector<int> freq(n);

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> data[i];
    }

    cout << "Enter frequencies: ";
    for (int i = 0; i < n; i++) {
        cin >> freq[i];
    }

    // Generate and print Huffman Codes
    HuffmanCodes(data, freq);
    return 0;
}
