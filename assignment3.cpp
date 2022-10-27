#include <iostream>
#include "BST.h"

void menu();

int main() {
    int menu_input;
    int node_value;
    int find_number;
    int delete_the_node;
    int predecessor_value;
    //design a mechanism to test your implementation continuously until user’s input is 0
    menu();
    std::cout << "Enter option: ";
    std::cin >> menu_input;
    BST t;

    while (menu_input != 0) {
        if (menu_input == 1){
            std::cout << "Insert Node: ";
            std::cin >> node_value;
            t.insertNode(node_value);
        }
        else if (menu_input == 2){
            // Search for a value
            std::cout << "What value do you want to find?: ";
            std::cin >> find_number;
            if(t.getValue(find_number) == -1){
                std::cout << "Number " << find_number << " is not in the Binary Tree" << std::endl;
            } else{
                std::cout << "Number " << find_number << " is in the Binary Tree" << std::endl;
            }
        } else if (menu_input == 3){
            // Find the predecessor for an existing value
            // std::cout << "Input value: ";
            // std::cin >> predecessor_value;
            // t.getPredecessor(predecessor_value);
        } else if (menu_input == 4){
            // Find the successor for an existing value
        } else if (menu_input == 5){
            // Find the height of the tree
            std::cout << "The height of the tree is: ";
            std::cout << t.getHeight() << std::endl;
        } else if (menu_input == 6){
            // Find the total number of nodes in tree
            std::cout << "The total number of nodes in the tree is: ";
            std::cout << t.getTotalNodes() << std::endl;
        } else if (menu_input == 7){
            // Delete a node
            std::cout << "What number would you like to delete?: ";
            std::cin >> delete_the_node;
            t.deleteLeafNode(delete_the_node);
            std::cout << "The number" << " " << delete_the_node << " " << "has been deleted" << std::endl;
        } else if (menu_input == 8){
            // Traverse inorder and display
            t.inorderDisplay();
        } else if (menu_input == 9){
            // Traverse preorder and display
            t.preorderDisplay();
        } else if (menu_input == 10){
            // Traverse postorder and display
            t.postorderDisplay();
        } else if (menu_input == 11){
            // Check if a tree is balanced
            std::cout << "Is Tree Balanced?: " << t.isTreeBalanced();
        } else if (menu_input == 12){
            // Destroy tree
            t.destroyTree();
        }
        std::cout << std::endl;
        menu();
        std::cout << "Enter option: ";
        std::cin >> menu_input;
        std::cout << std::endl;
    }
    std::cout << "Thank you for using the program!" << std::endl;
    return 0;
}

void menu(){
    std::cout << "Please select an operation to test:\n" << std::endl;
    std::cout << "1. Insert a node" << std::endl
              << "2. Search for a value" << std::endl
              << "3. Find the predecessor for an existing value" << std::endl
              << "4. Find the successor for an existing value" << std::endl
              << "5. Find the height of tree" << std::endl
              << "6. Find the total number of nodes in tree" << std::endl
              << "7. Delete a node" << std::endl
              << "8. Traverse inorder and display" << std::endl
              << "9. Traverse preorder and display" << std::endl
              << "10. Traverse postorder and display" << std::endl
              << "11. Check if a tree is balanced" << std::endl
              << "12. Destroy tree" << std::endl
              << "0. Quit" << std::endl;
}

