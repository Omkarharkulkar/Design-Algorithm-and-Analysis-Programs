/*
    This program implements Huffman Algorithm for coding and decoding a string by greedy approach taking input from user.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input string
#define MAX_SIZE 100

// Define the maximum number of characters
#define MAX_CHARS 256

// Define the Huffman tree node structure
struct HuffmanNode {
    char data;
    int freq;
    struct HuffmanNode *left, *right;
};

// Define the Huffman tree structure
struct HuffmanTree {
    struct HuffmanNode *root;
};

// Define the Huffman code structure
struct HuffmanCode {
    char data;
    char *code;
};

// Function to create a new Huffman tree node
struct HuffmanNode* newHuffmanNode(char data, int freq) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new Huffman tree
struct HuffmanTree* newHuffmanTree() {
    struct HuffmanTree* tree = (struct HuffmanTree*) malloc(sizeof(struct HuffmanTree));
    tree->root = NULL;
    return tree;
}

// Function to create a new Huffman code
struct HuffmanCode* newHuffmanCode(char data, char *code) {
    struct HuffmanCode* hc = (struct HuffmanCode*) malloc(sizeof(struct HuffmanCode));
    hc->data = data;
    hc->code = code;
    return hc;
}

// Function to swap two Huffman nodes
void swapHuffmanNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the Huffman tree
void heapify(struct HuffmanNode** nodes, int size, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && nodes[left]->freq < nodes[smallest]->freq)
        smallest = left;

    if (right < size && nodes[right]->freq < nodes[smallest]->freq)
        smallest = right;

    if (smallest != index) {
        swapHuffmanNodes(&nodes[index], &nodes[smallest]);
        heapify(nodes, size, smallest);
    }
}

// Function to build the Huffman tree
struct HuffmanNode* buildHuffmanTree(char *str) {
    int freq[MAX_CHARS] = {0};
    int i;

    // Calculate the frequency of each character
    for (i = 0; str[i] != '\0'; i++)
        freq[str[i]]++;

    // Create a Huffman node for each character
    struct HuffmanNode** nodes = (struct HuffmanNode**) malloc(MAX_CHARS * sizeof(struct HuffmanNode*));
    int size = 0;
    for (i = 0; i < MAX_CHARS; i++) {
        if (freq[i] > 0) {
            nodes[size++] = newHuffmanNode(i, freq[i]);
        }
    }

    // Build the Huffman tree
    while (size > 1) {
        struct HuffmanNode *left = nodes[0];
        struct HuffmanNode *right = nodes[1];
        struct HuffmanNode *parent = newHuffmanNode('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        nodes[0] = parent;
        nodes[1] = nodes[size - 1];
        size--;

        heapify(nodes, size, 0);
    }

    struct HuffmanNode* root = nodes[0];
    free(nodes);

    return root;
}

// Function to traverse the Huffman tree and generate the Huffman codes
void generateHuffmanCodes(struct HuffmanNode* node, char *code, int depth, struct HuffmanCode** codes, int *size) {
    if (node == NULL)
        return;

    if (node->left == NULL && node->right == NULL) {
        code[depth] = '\0';
        struct HuffmanCode* hc = newHuffmanCode(node->data, strdup(code));
        codes[(*size)++] = hc;
    } else {
        code[depth] = '0';
        generateHuffmanCodes(node->left, code, depth + 1, codes, size);

        code[depth] = '1';
        generateHuffmanCodes(node->right, code, depth + 1, codes, size);
    }
}

// Function to print the Huffman codes
void printHuffmanCodes(struct HuffmanCode** codes, int size) {
    printf("Huffman Codes:\n");
    int i;
    for (i = 0; i < size; i++) {
        printf("%c: %s\n", codes[i]->data, codes[i]->code);
    }
}

// Function to encode the input string using the Huffman codes
char* encodeString(char *str, struct HuffmanCode** codes, int size) {
    int i, j, k;
    char *encoded = (char*) malloc(MAX_SIZE * sizeof(char));
    encoded[0] = '\0';

    for (i = 0; str[i] != '\0'; i++) {
        for (j = 0; j < size; j++) {
            if (str[i] == codes[j]->data) {
                for (k = 0; codes[j]->code[k] != '\0'; k++) {
                    strncat(encoded, &codes[j]->code[k], 1);
                }
                break;
            }
        }
    }

    return encoded;
}

// Function to decode the input string using the Huffman codes
char* decodeString(char *str, struct HuffmanNode* root) {
    int i;
    char *decoded = (char*) malloc(MAX_SIZE * sizeof(char));
    decoded[0] = '\0';

    struct HuffmanNode* node = root;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == '0') {
            node = node->left;
        } else {
            node = node->right;
        }

        if (node->left == NULL && node->right == NULL) {
            strncat(decoded, &node->data, 1);
            node = root;
        }
    }

    return decoded;
}

int main() {
    char str[MAX_SIZE];
    printf("Enter a string: ");
    fgets(str, MAX_SIZE, stdin);
    str[strcspn(str, "\n")] = '\0';

    // Build the Huffman tree
    struct HuffmanNode* root = buildHuffmanTree(str);

    // Generate the Huffman codes
    char code[MAX_SIZE];
    struct HuffmanCode** codes = (struct HuffmanCode**) malloc(MAX_CHARS * sizeof(struct HuffmanCode*));
    int size = 0;
    generateHuffmanCodes(root, code, 0, codes, &size);

    // Print the Huffman codes
    printHuffmanCodes(codes, size);

    // Encode the input string using the Huffman codes
    char *encoded = encodeString(str, codes, size);
    printf("Encoded string: %s\n", encoded);

    // Decode the encoded string using the Huffman codes
    char *decoded = decodeString(encoded, root);
    printf("Decoded string: %s\n", decoded);

    free(encoded);
    free(decoded);
    free(codes);
    return 0;
}
