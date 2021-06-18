// 16520373 - Farrel Ahmad
// Linked List Operations Program
// Internship URO Dagozilla 2021

#include <iostream>

#define print(x) std::cout << x;  //defining print(x) as output
#define input(x) std::cin>>x;     //defining input(x) as input

// Notes : LL = Linked List

class Node //class object Node (custom data type). Notasi Algoritmik, type Node : < value : integer, next : Node*>
{
public :
    int value;   // Node's value
    Node* next;  // Node's pointer to next memory address
};

void printlistaddr(Node *a) //procedure print LinkedList all node's memory address
{
        while (a != nullptr)
        {
            print("(");print(a);print(");")
            a = a->next;
        }
        print("\n")
}

void printlist (Node* a) //procedure print LinkedList all node's value. Input head pointer : Node*
{
    if (a==nullptr)  //empty LL
    {
        print("List is empty\n");
    }
    else //not empty LL
    {
        while (a->next!=nullptr)
            {   print(a->value);
                print(" -> ")
                a = a->next;
            }
        print(a->value);
        print("\n")
    }
}

Node* initialize (Node* a) //function initialize (a : Node*) -> Node* {Notasi Algoritmik}
{
    int n;                 //a is empty pointer (nullptr)
    a = new Node;          //allocate new memory address
    print("Insert First Node Value: ");
    input(n);
    a->value = n;         //value is n
    a->next = nullptr;    //next memory address is nullptr
    return a;
}

int SizeOfList (Node *a) //function SizeOfList (a : Node*) -> integer
{
    int Count = 0;
    if (a==nullptr)      //to print size of LL
    {
        return Count;
    }
    else // a != nullptr
    {
        while (a != nullptr)
        {
            Count ++;
            a = a-> next;
        }
        return Count;
    }
}

void menu()  //procedure show menu interface
{
    print("1. Initialize\t\t");
    print("2. Print List\n");
    print("3. Insert Node (Front)\t");
    print("4. Insert Node (End)\n")
    print("5. Remove First Node\t6. Remove Last Node\n")
    print("7. Find Value\t\t8. Find Max\n9. Find Min\t\t")
    print("10. Size of List\n11. Delete List\t\t12. Copy List\n")
    print("13. Concatenate List\t14. Inverse List\n")
    print("20. Quit\n")
    print("Insert Command: ")
}

void InsertNodeFront(Node **a) //procedure InsertNodeFront (input/output a : Node**) {notasi algoritmik}
{
    int n;                     //to insert new node to the front
    print("Insert value: ");
    input(n);                 //receive integer input from user
    Node* newNode = new Node; //initialize newNode (allocate new memory address)
    newNode->value = n;       //set node's value to n
    newNode->next = *a;       //set node's next memory address to head
    (*a) = newNode;           //set head to newNode
}

void InsertNodeEnd(Node **a) //procedure InsertNodeEnd (input/output a : Node**) {notasi algoritmik}
{
    int n;                   //inserting new node to the last
    Node *temp = *a;
    print("Insert value: ");
    input(n);                  //receive input integer n from user
    Node* newNode = new Node;  //initializing new node (allocate new memory address)
    newNode->value = n;        //set node's value to n
    newNode->next = nullptr;   //set node's next memory address to nullptr
    while (temp->next != nullptr)
    {
        temp=temp->next;        //iterate to the last node
    }
    temp->next = newNode;   //set last node's next memory address to newNode's memory address
}

void InsertNodeEnd2(Node **a, int x) //procedure InsertNodeEnd2 (input/output a : Node**, input x : integer) {notasi algoritmik}
{
    Node *temp = *a;                 //inserting to the last node with known values
    Node* newNode = new Node;        //initialize newNode and allocate new memory address
    newNode->value = x;              //set newNode's value to x
    newNode->next = nullptr;         //set newNode's next memory address to nullptr
    while (temp->next != nullptr)
    {
        temp=temp->next;            //iterate to the last node
    }
    temp->next = newNode;           //set last node's next memory address to newNode's memory address
}

void RemoveFirstNode(Node **a)  //procedure RemoveFirstNode (input/output a : Node**)
{
    Node *temp = (*a)->next;    //set temporary memory address as head's next memory address
    delete (*a);                //deallocate memory address of fhead
    *a = temp;                  //set head memory address as temp
}

void RemoveLastNode(Node **a)  //procedure RemoveLastNode (input/output a : Node**)
{
    Node *temp = *a;           //set temporary memory address to head
    Node *temp2;
    if (((*a)->next)==nullptr)  //if only one node
    {
        delete (*a);        //deallocate memory address of head
        *a = nullptr;      //set head to nullptr
    }
    else  //more than one node
    {
        while ((temp->next)->next != nullptr) //iterate to node's before the last node
        {
            temp = temp->next;
        }
        temp2 = temp->next;  //set temp2 as last node's memory address
        delete(temp2);  //deallocate last node's memory address
        temp->next=nullptr; //set next memory address to nullptr
    }
}

void FindValue(Node **a) //procedure to find given value
{
    int x;
    Node *temp = *a;
    Node *temp2 = *a;
    bool found=false;
    print("Find value: "); //input
    input(x);
    while (temp != nullptr) //check whether input values x are found
    {
        if (temp->value == x)
            found = true;
        temp = temp->next;
    }
    if (found)
    {
        int no = 1;
        print("\nValue found in: \n")
        while (temp2 != nullptr)        //iterate and print all node's memory address that has value x
        {
            if (temp2->value == x)
                {
                print("(");
                print(no);
                print(") ");
                print(temp2);
                print("\n");
                no++;
                }
            temp2 = temp2->next;
        }
    }
    else //not(found)
    {
        print("\nValue not found in List\n");  //value not found
    }
    }

int FindMax (Node **a)  //function to find maxiumum values of LL -> integer
{
    int maxi;
    Node *temp = *a;
    maxi = temp->value;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        if ((temp->value)>maxi)
        {
            maxi = temp->value;
        }
    }
    return maxi;

}

int FindMin (Node **a) //function to find minimum values of LL -> integer
{
    int mini;
    Node *temp = *a;
    mini = temp->value;
    while (temp->next != nullptr)
    {
        temp = temp->next;
        if ((temp->value)<mini)
        {
            mini = temp->value;
        }
    }
    return mini;
}

void DeleteList(Node **a, int SizeList) //procedure delete whole LL
{
    if (*a != nullptr)
    {
        while (SizeList !=0)
        {
            Node *temp = *a;
            Node *temp2;
            if ((temp->next)==nullptr)
            {
                delete (*a);
                *a = nullptr;
            }
            else
            {
                while ((temp->next)->next != nullptr)
                {
                    temp = temp->next;
                }
                temp2 = temp->next;
                delete(temp2);
                temp->next=nullptr;
            }
            SizeList--;
        }
    }
    else //*a == nullptr empty list
    {
        print("\nList is empty\n")
    }
}

void CopyList(Node **a, Node *b) //procedure to copy LL1 to LL2 or LL2 to LL1
{
    // a is pointer to pointer of head2, b is node pointer of head1
    Node* newNode = new Node;
    newNode->value = b->value;
    newNode->next = nullptr;
    Node *temp = *a;
    while (temp->next!=nullptr) //temp->next == nullptr means last node
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void Concat(Node **a, Node **b, int c) //procedure concatenation (without new allocated memory address)
{     // c is code number for type of concatenation
  if (c==1) //LL1 + LL2
  {
      Node *temp1 = *a;
      while (temp1->next != nullptr)
      {
          temp1 = temp1->next;
      }
      temp1->next = *b;
  }
  else if (c==2) //LL2 + LL1
  {
      Node *temp2 = *b;
      while (temp2->next != nullptr)
      {
          temp2 = temp2->next;
      }
      temp2->next = *a;

  }
}

void Concat2(Node *h1, Node *h2, Node **h3, int c) //procedure concatenation (with new allocated memory address)
{
    Node *temp1 = h1;
    Node *temp2 = h2;
    Node *temp3 = *h3;      //head3 is head for LL3, result of concatenation with new memory address
    int x;
    if (c==1) //LL1 + LL2 -> LL3
    {
        temp3->value = temp1->value;
        temp3->next = nullptr;
        while (temp1->next!=nullptr)
        {
            temp1 = temp1->next;
            x = temp1->value;
            InsertNodeEnd2(h3, x);
        }
        x = temp2->value;
        InsertNodeEnd2(h3,x);
        while (temp2->next!=nullptr)
        {
            temp2 = temp2->next;
            x = temp2->value;
            InsertNodeEnd2(h3,x);
        }
    }
    else if (c==2) //LL2 + LL1 -> LL3
    {
        temp3->value = temp2->value;
        temp3->next = nullptr;
        while (temp2->next!=nullptr)
        {
            temp2 = temp2->next;
            x = temp2->value;
            InsertNodeEnd2(h3, x);
        }
        x = temp1->value;
        InsertNodeEnd2(h3,x);
        while (temp1->next!=nullptr)
        {
            temp1 = temp1->next;
            x = temp1->value;
            InsertNodeEnd2(h3,x);
        }
    }
    else
    {
        print("\nWrong input\n");
    }
}

void Inverse(Node **a) //procedure inverse LL
{
    Node *prev = nullptr;
    Node *next = nullptr;
    Node *curr = *a;
    while (curr != nullptr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *a = prev;
}

int main()
{   //variable initialization
    int ListSize1; //LL1 size
    int ListSize2; //LL2 size
    int n; //input code (menu)
    int c; //input code (menu)
    int d; //input code (menu)
    Node* head1=nullptr; //LL1
    Node* head2=nullptr; //LL2
    Node* head3=nullptr; //LL3, only used for Concatenation with new allocated memory address
    menu(); //show menu interface
    input(c); // input menu code
    while (c!=20) //c==20 is quit program
    {
    switch(c)
    {
    case 1 : //Initialize
        if (head1==nullptr && head2==nullptr)
        {
            print("1. LL1\n2. LL2\nSelect Linked List: ");
            input(d);
            if (d==1)
            {
                head1=initialize(head1);
            }
            else if (d==2)
            {
                head2=initialize(head2);
            }
            else
            {print("\nWrong Input\n")}
        }
        else if (head1==nullptr && head2!=nullptr)
        {
            print("\nInitializing LL1\n");
            head1=initialize(head1);
        }
        else if (head1!=nullptr && head2==nullptr)
        {
            print("\nInitializing LL2\n");
            head2=initialize(head2);
        }
        else
        {
            print("\nLL1 and LL2 Already Initialized\n")
        }
        break;
    case 2 : //Print List
        print("\n")
        print("LL1 \t : ");printlist(head1);
        print("LL1 Addr : ");printlistaddr(head1);print("\n")
        print("LL2 \t : ");printlist(head2);
        print("LL2 Addr : ");printlistaddr(head2);
        break;
    case 3 : //Insert Node (Front)
        print("\n");
        print("1. LL1\n2. LL2\nSelect Linked List: ");
        input(d);
        if (d==1)
        {
            if (head1==nullptr)
            {
                print("Initializing LL1\n");
                head1 = initialize(head1);
            }
            else //head != NULL
            {
                InsertNodeFront(&head1);
            }
        }
        else if (d==2)
        {
            if (head2==nullptr)
            {
                print("Initializing LL2\n");
                head2 = initialize(head2);
            }
            else //head != NULL
            {
                InsertNodeFront(&head2);
            }
        }
        else
        {
            print("\nWrong input\n");
        }
        break;
    case 4 : //Insert Node (End)
        print("\n");
        print("1. LL1\n2. LL2\nSelect Linked List: ");
        input(d);
        if (d==1)
        {
            if (head1==nullptr)
            {
                print("Initializing LL1\n")
                head1 = initialize(head1);
            }
            else //head != NULL
            {
                InsertNodeEnd(&head1);
            }
        }
        else if (d==2)
        {
            if (head2==nullptr)
            {
                print("Initializing LL2\n")
                head2 = initialize(head2);
            }
            else //head != NULL
            {
                InsertNodeEnd(&head2);
            }
        }
        else
        {
            print("\nWrong input\n");
        }
        break;
    case 5: //Remove First Node
        if (head1==nullptr && head2==nullptr)
        {
            print("\nLL1 : List is empty\nLL2 : List is empty\n");
        }
        else
        {
                print("\n1. LL1\n2. LL2\nSelect Linked List : ");
                input(d);
                if (d==1)
                {
                    if (head1==nullptr)
                    {
                        print("LL1 : List is empty")
                    }
                    else
                    {
                        print("LL1 first node removed\n");
                        RemoveFirstNode(&head1);
                    }
                }
                else if (d==2)
                {
                    if (head2==nullptr)
                    {
                        print("LL2 : List is empty")
                    }
                    else
                    {
                        print("LL2 first node removed\n");
                        RemoveFirstNode(&head2);
                    }
                }
                else
                {
                    print("Wrong input");
                }

        }
        break;
    case 6: //Remove Last Node
        if (head1==nullptr && head2==nullptr)
        {
            print("\nLL1 : List is empty\nLL2 : List is empty\n");
        }
        else
        {
                print("\n1. LL1\n2. LL2\nSelect Linked List : ");
                input(d);
                if (d==1)
                {
                    if (head1==nullptr)
                    {
                        print("LL1 : List is empty")
                    }
                    else
                    {
                        print("LL1 last node removed\n")
                        RemoveLastNode(&head1);
                    }
                }
                else if (d==2)
                {
                    if (head2==nullptr)
                    {
                        print("LL2 : List is empty")
                    }
                    else
                    {
                        print("LL2 last node removed\n")
                        RemoveLastNode(&head2);
                    }
                }
                else
                {
                    print("Wrong input");
                }

        }
        break;
    case 7: //Find Value
        if (head1==nullptr && head2==nullptr)
        {
            print("\nLL1 : List is empty\nLL2 : List is empty\n");
        }
        else
        {
                print("\n1. LL1\n2. LL2\nSelect Linked List : ");
                input(d);
                if (d==1)
                {
                    if (head1==nullptr)
                    {
                        print("LL1 : List is empty");
                    }
                    else
                    {
                        FindValue(&head1);
                    }
                }
                else if (d==2)
                {
                    if (head2==nullptr)
                    {
                        print("LL2 : List is empty");
                    }
                    else
                    {
                        FindValue(&head2);
                    }
                }
                else
                {
                    print("Wrong input");
                }
        }
        break;
    case 8: //Find Max
        if (head1==nullptr && head2==nullptr)
        {
            print("\nLL1 : List is empty\nLL2 : List is empty\n");
        }
        else
        {
            int maximum;
            if (head1 != nullptr)
            {
                maximum = FindMax(&head1);
                print("\nLL1 Max Value : ");
                print(maximum);

            }
            else
            {
                print("\nLL1 Max Value : Unknown (Empty List)");

            }
            if (head2 != nullptr)
            {
                maximum = FindMax(&head2);
                print("\nLL2 Max Value : ");
                print(maximum);
                print("\n")
            }
            else
            {
                print("\nLL2 Max Value : Unknown (Empty List)\n")
            }
        }
        break;
    case 9: //Find Min
        if (head1==nullptr && head2==nullptr)
        {
            print("\nLL1 : List is empty\nLL2 : List is empty\n");
        }
        else
        {
            int minimum;
            if (head1 != nullptr)
            {
                minimum = FindMin(&head1);
                print("\nLL1 Min Value : ");
                print(minimum);

            }
            else
            {
                print("\nLL1 Min Value : Unknown (Empty List)");

            }
            if (head2 != nullptr)
            {
                minimum  = FindMin(&head2);
                print("\nLL2 Min Value : ");
                print(minimum);
                print("\n")
            }
            else
            {
                print("\nLL2 Min Value : Unknown (Empty List)\n")
            }
        }
        break;
    case 10: //Size of List
        ListSize1 = SizeOfList(head1);
        ListSize2 = SizeOfList(head2);
        print("\nLL1 Size : ");print(ListSize1);print("\n")
        print("LL2 Size : ");print(ListSize2);print("\n")
        break;
    case 11: //Delete List
        print("\n1. LL1\n2. LL2\nSelect Linked List : ");
        input(d);
        if (d==1)
        {
            if (head1 == nullptr)
            {
                print("LL1 : List is Empty\n")
            }
            else
            {
                print("LL1 deleted\n")
                ListSize1 = SizeOfList(head1);
                DeleteList((&head1), ListSize1);
                break;
            }
        }
        else if (d==2)
        {
            if (head2 == nullptr)
            {
                print("LL2 : List is Empty\n")
            }
            else
            {
                print("LL2 deleted\n");
                ListSize2 = SizeOfList(head2);
                DeleteList((&head2), ListSize2);
                break;
            }
        }
        else
        {
            print("Wrong input")
        }
        break;
    case 12: //Copy List
        if (head1 != nullptr && head2 == nullptr)
        {
            print("\nLL1 has been copied to LL2\n\n")
            head2 = new Node;
            Node *temp = head1;
            head2->value = temp->value;
            head2->next = nullptr;
            while (temp->next != nullptr)
            {
                temp = temp->next;
                CopyList(&head2, temp);
            }
            print("LL1 \t : ");printlist(head1);
            print("LL1 Addr : ");printlistaddr(head1);print("\n")
            print("LL2 \t : ");printlist(head2);
            print("LL2 Addr : ");printlistaddr(head2);
        }
        else if (head1 == nullptr && head2 != nullptr)
        {
            print("\nLL2 has been copied to LL1\n\n")
            head1 = new Node;
            Node *temp = head2;
            head1->value = temp->value;
            head1->next = nullptr;
            while (temp->next != nullptr)
            {
                temp = temp->next;
                CopyList(&head1, temp);
            }
            print("LL1 \t : ");printlist(head1);
            print("LL1 Addr : ");printlistaddr(head1);print("\n")
            print("LL2 \t : ");printlist(head2);
            print("LL2 Addr : ");printlistaddr(head2);
        }
        else if (head1 != nullptr && head2 != nullptr)
        {
            print("1. Copy LL1 to LL2 (Overwrite)\n2. Copy LL2 to LL1 (Overwrite)\nSelect Option : ")
            input(d);
            if (d==1)
            { //delete and deallocate LL2
                ListSize2 = SizeOfList(head2);
                DeleteList(&head2, ListSize2);
                print("\nLL1 has been copied to LL2\n\n")
                head2 = new Node;
                Node *temp = head1;
                head2->value = temp->value;
                head2->next = nullptr;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                    CopyList(&head2, temp);
                }
            print("LL1 \t : ");printlist(head1);
            print("LL1 Addr : ");printlistaddr(head1);print("\n")
            print("LL2 \t : ");printlist(head2);
            print("LL2 Addr : ");printlistaddr(head2);
            }
            else if (d==2)
            {
                //Deallocate LL1
                ListSize1 = SizeOfList(head1);
                DeleteList(&head1, ListSize1);
                print("\nLL2 has been copied to LL1\n\n")
                head1 = new Node;
                Node *temp = head2;
                head1->value = temp->value;
                head1->next = nullptr;
                while (temp->next != nullptr)
                {
                    temp = temp->next;
                    CopyList(&head1, temp);
                }
            print("LL1 \t : ");printlist(head1);
            print("LL1 Addr : ");printlistaddr(head1);print("\n")
            print("LL2 \t : ");printlist(head2);
            print("LL2 Addr : ");printlistaddr(head2);
            }
            else
            {
                print("Wrong input")
            }
        }
        else
        {
            print("\nLL1 : List is empty\nLL2 : List is empty\n")
        }
        break;
    case 13: //Concatenate List
        print("\n1. Without New Allocated Memory\n2. With New Allocated Memory\nSelect Method: ")
        input(d);
        if (d==1)
        {
            if (head1 != nullptr && head2 != nullptr)
            {
                print("\n1. Concatenate LL1 + LL2\n2. Concatenate LL2 + LL1\nSelect option : ")
                input(d);
                if (d==1 || d==2)
                {
                    Concat(&head1,&head2,d);
                    if (d==1)
                    {
                        ListSize2 = SizeOfList(head2);
                        print("\nLL1 + LL2 concatenated\nResult in Print List\n");
                    }
                    else if (d==2)
                    {
                        ListSize1 = SizeOfList(head1);
                        print("\nLL2 + LL1 concatenated\nResult in Print List\n");
                    }
                }
                else
                {
                    print("\nWrong input");
                }
            }
            else
            {
                print("\nUnable to concatenate")
                if (head1 == nullptr)
                {
                    print("\nLL1 : List is empty")
                }
                if (head2 == nullptr)
                {
                    print("\nLL2 : List is empty\n")
                }
            }
        }
        else if (d==2)
        {
            if (head1!=nullptr && head2!=nullptr)
            {
                print("\n1. Concatenate LL1 + LL2 into LL3\n2. Concatenate LL2 + LL1 into LL3\nSelect option : ")
                head3 = new Node;
                input(d);
                Concat2(head1, head2, &head3, d);
                if (d==1 || d==2)
                {print("\nLL1 \t : ");printlist(head1);
                print("LL1 Addr : ");printlistaddr(head1);print("\n")
                print("LL2 \t : ");printlist(head2);
                print("LL2 Addr : ");printlistaddr(head2);print("\n")
                print("LL3 \t : ");printlist(head3);
                print("LL3 Addr : ");printlistaddr(head3);print("\n")}
            }
            else //head1==nullptr || head2==nullptr
            {
                print("\nUnable to concatenate");
                if (head1 == nullptr)
                {
                    print("\nLL1 : List is empty");
                }
                if (head2 == nullptr)
                {
                    print("\nLL2 : List is empty\n");
                }
            }
        }
        else
        {
            print("\nWrong input\n")
        }
        break;
    case 14: //Inverse List
        print("\n1. Without New Allocated Memory\n2. With New Allocated Memory\nSelect Method: ")
        input(d);
        if (d==1)
        {
            if (head1 != nullptr ||head2 != nullptr)
            {
                print("\n1. LL1\n2. LL2\nSelect Linked List: ");
                input(d);
                if (d==1)
                {
                    if (head1 != nullptr)
                    {
                        print("\nLL1 Inversed\n");
                        Inverse(&head1);
                    }
                    else
                    {
                        print("\nLL1 : List is Empty\n")
                    }

                }
                else if (d==2)
                {
                    if (head2 != nullptr)
                    {
                        print("\nLL2 Inversed\n");
                        Inverse(&head2);
                    }
                    else
                    {
                        print("\nLL2 : List is Empty\n")
                    }
                }
                else
                {
                    print("Wrong input")
                }
            }
            else
            {
                print("\nLL1 : List is Empty\nLL2 : List is Empty\n")
            }
        }
        else if (d==2)
        {
            if (head1==nullptr && head2==nullptr)
            {
                print("\nLL1 : List is Empty\nLL2 : List is Empty\n")
            }
            else if (head1==nullptr&&head2!=nullptr)
                {
                    head1 = new Node;
                    Node *temp = head2;
                    head1->value = temp->value;
                    head1->next = nullptr;
                    while (temp->next != nullptr)
                    {
                        temp = temp->next;
                        CopyList(&head1, temp);
                    }
                    Inverse(&head1);
                    print("\nInversed result stored in LL1 with new allocated memory\n")
                }
            else if (head1 != nullptr&&head2 == nullptr)
                {
                    head2 = new Node;
                    Node *temp = head1;
                    head2->value = temp->value;
                    head2->next = nullptr;
                    while (temp->next != nullptr)
                    {
                        temp = temp->next;
                        CopyList(&head2, temp);
                    }
                    Inverse(&head2);
                    print("\nInversed result stored in LL2 with new allocated memory\n")
                }
            else
            {
                print("\nLL1 and LL2 are full\nUnable to inverse using this method\nPlease delete either LL1 or LL2 using Delete List\n")
            }
        }


        else
        {
            print("Wrong input")
        }
        break;
    default: //else, Wrong input
        print("\nWrong input\n")
    }
        print("\n");
        menu();
        input(c);
    }

    return 0;
}
