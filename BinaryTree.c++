#include <iostream>

// Définition de la structure TreeNode pour chaque nœud de l'arbre
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Classe BinaryTree pour l'arbre binaire
class BinaryTree {
private:
    TreeNode* root; // Racine de l'arbre

    // Fonction récursive pour l'insertion d'un nœud dans l'arbre
    TreeNode* insertRecursive(TreeNode* node, int value) {
        // Si le nœud est vide, on crée un nouveau nœud avec la valeur donnée
        if (node == nullptr) {
            return new TreeNode(value);
        }

        // Sinon, on descend dans l'arbre pour insérer le nœud dans le bon sous-arbre
        if (value < node->data) {
            node->left = insertRecursive(node->left, value);
        } else if (value > node->data) {
            node->right = insertRecursive(node->right, value);
        }

        return node;
    }

    // Fonction récursive pour afficher l'arbre en parcours infixé
    void inorderTraversalRecursive(TreeNode* node) {
        if (node != nullptr) {
            inorderTraversalRecursive(node->left);
            std::cout << node->data << " ";
            inorderTraversalRecursive(node->right);
        }
    }

public:
    // Constructeur par défaut
    BinaryTree() : root(nullptr) {}

    // Méthode pour insérer un nœud dans l'arbre
    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Méthode pour afficher l'arbre en parcours infixé
    void inorderTraversal() {
        inorderTraversalRecursive(root);
    }
};

int main() {
    // Création de l'arbre binaire
    BinaryTree tree;

    // Insertion de quelques valeurs dans l'arbre
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    // Affichage de l'arbre en parcours infixé
    std::cout << "Arbre en parcours infixé : ";
    tree.inorderTraversal();
    std::cout << std::endl;

    return 0;
}
