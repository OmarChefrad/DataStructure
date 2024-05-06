#include <iostream>

// Structure de noeud pour la liste chaînée
struct Node {
    int data;
    Node* next;
};

// Classe pour la liste chaînée
class LinkedList {
private:
    Node* head; // Pointeur vers le premier noeud de la liste

public:
    // Constructeur
    LinkedList() : head(nullptr) {}

    // Méthode pour ajouter un élément à la fin de la liste
    void append(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Méthode pour afficher la liste
    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // Destructeur pour libérer la mémoire
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    // Création d'une liste chaînée et ajout d'éléments
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);

    // Affichage de la liste
    std::cout << "Liste chaînée : ";
    list.display();

    return 0;
}
