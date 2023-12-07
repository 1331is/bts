#include <iostream>


class Bin_tree
{   
private:
    int size = 0;

public:
    void print_all() {
        if (root != nullptr) {
            std::cout << root->data;
            root->print_all();
        }
    }
    void insert(int val){
        size++;
        if (root == nullptr) {
            root = new Node(val);
        }
        else {
            root->insert(val);
        }
    }
    void erase(int val) {
        if (find(val) == false) {
            return;
        }
        else {
            size--;

            root->erase(val);
              
        }
    }
    int get_size() {
        return size;
    }
    bool find(int val) {
        if (root->data == val) {
            return true;
        }
        if (root == nullptr) {
            return false;
        }
        else {
            root->find(val);
        }
    }
public:
    class Node {
    public:
        void print_all() {
            if (left != nullptr) {
                std::cout << left->data;
                left->print_all();
            }
            if (right != nullptr) {
                std::cout << right->data;
                right->print_all();
            }
        }
        void insert(int val) {
            ;
            if (val < data) {
                if (left != nullptr) {
                    left->insert(val);
                }
                else {
                    left = new Node(val);
                }
            }
            if (data < val) {
                if (right != nullptr) {
                    right->insert(val);
                }
                else {
                    right = new Node(val);
                }
            }

        }
        void erase(int val) {
            if (val == data and left == nullptr and right == nullptr) {
                std::cout << 1; //«ƒесь код писать


            }
            if (val < data and left != nullptr) {

                left->find(val);

            }
            if (data < val and right != nullptr) {

                right->find(val);

            }

        }
        bool find(int val) {
            if (val == data) {
                return true;
            }
            if (val < data and left != nullptr) {

                    left->find(val);
                
            }
            if (data < val and right != nullptr) {

                    right->find(val);

            }
            if (left == nullptr and right == nullptr) {
                return false;
            }
        }

    public:
        int data;
        Node* left;
        Node* right;
        Node() = default;
        Node(int val)
        {
            data = val;
            left = nullptr;
            right = nullptr;
        }
    };
    Node* root = nullptr;
};

int main() {
    Bin_tree a;
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(6);
    a.insert(2);
    a.insert(9);
    a.insert(1);
    a.print_all();
    std::cout << a.find(3) << std::endl;
    std::cout << a.find(1) << std::endl;
    std::cout << a.find(9) << std::endl;
    std::cout << a.find(6) << std::endl;
    std::cout << "\n" << a.get_size();
    std::cout << std::endl;
}