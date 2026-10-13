#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int number_of_nodes(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!=nullptr){
        count++;
        temp = temp->next;
    }
    return count;
}

void insert_at_begining(Node* &head, int val){
    Node* newNode = new Node();
    if(newNode==nullptr){
        cout<<"Memory allocation failed"<<endl;
        return;
    }
    newNode->data = val;
    newNode->next = head;
    head = newNode;
}

void insert_at_last(Node* &head,int val){
    Node* newNode = new Node();
    if(newNode==nullptr){
        cout<<"Memory allocation failed"<<endl;
        return;
    }
    newNode->data = val;
    newNode->next = nullptr;
    if(head==nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void insert_at_position(Node* &head, int val, int position){
    if(position<1){
        cout<<"Inavlid position"<<endl;
        return;
    }
    
    Node* newNode = new Node();
    if(newNode==nullptr){
        cout<<"Memory allocation failed"<<endl;
        return;
    }
    newNode->data = val;

    if(position==1){
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for(int i=1; i<position-1 && temp!=nullptr; i++){
        temp = temp->next;
    }

    if(temp==nullptr){ 
        cout<<"Position out of range"<<endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    
}

void traversal(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void update_node(Node* &head,int target, int val){
    if(head==nullptr){
        cout<<"The list is empty"<<endl;
        return;
    }

    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data == target){
            temp->data = val;
            cout<<"Value updated!"<<endl;
            return;
        }
        temp = temp->next;
    }

    cout<<"Target not found"<<endl;
}

void delete_at_begining(Node* &head){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void delete_at_last(Node* &head){
    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    if(head->next==nullptr){
        delete head;
        head = nullptr;
        return;
    }
    
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
}

void delete_at_position(Node* &head,int position){
    
    if(position<1){
        cout<<"invalid position"<<endl;
        return;
    }

    if(head==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }

    if(position == 1){
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        return;
    }

    Node* temp = head;
    for(int i=1; i<position-1 && temp!=nullptr; i++){
        temp = temp->next;
    }

    if(temp == nullptr || temp->next == nullptr){
        cout << "Position out of range" << endl;
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
    
    
}

void free_memory(Node* &head){
    Node* temp;
    while(head!=nullptr){
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main(){

    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();
    Node* fourth = new Node();

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = fourth;

    fourth->data = 40;
    fourth->next = nullptr;

    traversal(head);
    cout<<endl;
    
    
    return 0;
}
