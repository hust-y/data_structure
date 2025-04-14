
#include "func.h"

// 根据01串在哈夫曼树中查找对应字符
char find_char(node *root, const char *code, int *index) {
    node *current = root;
    while(current) {
        if(current->name) {  // 找到叶子节点，返回对应字符
            return current->name;
        }
        if(code[*index] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        (*index)++;
    }
    return '\0';
}

void dec(const char *filename1, char *filename2, char *dictionary) {
    // 读取字典文件重建哈夫曼树
    node *root = NULL;
    freopen(dictionary, "r", stdin);
    int n;
    scanf("%d", &n);
    
    // 创建根节点
    root = (node*)malloc(sizeof(node));
    root->name = 0;
    root->left = NULL;
    root->right = NULL;
    
    // 根据编码重建哈夫曼树
    for(int i = 0; i < n; i++) {
        char c;
        char code[256];
        scanf(" %c %s", &c, code);
        
        // 根据编码在树中找到位置并插入字符
        node *current = root;
        for(int j = 0; code[j]; j++) {
            if(code[j] == '0') {
                if(!current->left) {
                    current->left = (node*)malloc(sizeof(node));
                    current->left->name = 0;
                    current->left->left = NULL;
                    current->left->right = NULL;
                }
                current = current->left;
            } else {
                if(!current->right) {
                    current->right = (node*)malloc(sizeof(node));
                    current->right->name = 0;
                    current->right->left = NULL;
                    current->right->right = NULL;
                }
                current = current->right;
            }
            
            // 如果是编码的最后一位，将字符存入节点
            if(!code[j + 1]) {
                current->name = c;
            }
        }
    }
    fclose(stdin);
    
    // 读取待解码文件
    freopen(filename1, "r", stdin);
    char encoded[100000];
    scanf("%s", encoded);
    fclose(stdin);
    
    // 解码并输出到文件
    freopen(filename2, "w", stdout);
    int index = 0;
    while(encoded[index]) {
        int current_index = index;
        char c = find_char(root, encoded, &index);
        if(c) {
            printf("%c", c);
        }
    }
    fclose(stdout);
}
