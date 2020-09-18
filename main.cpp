//Name - Tasfique Enam
//Student ID- 5886429
//LabTask2

#include <iostream>
#include<stdlib.h>

using namespace std;
    int selection;
    int arr[3];
    int top = -1;
    int number;
    int value;
int main()
{
    //protype functions.
    bool isEmpty();
    bool isFull();
    void push(int);
    int pop();
    void display();
    void numOfItems();
    void minMax();
    void findValue(int);

    //The Selection Menu
    cout << "Enter The options you want to pick: " << endl;
    do {
        cout <<"\n=================================================="<<endl;
        cout <<"               Stack Operations Menu              "<<endl;
        cout <<"==================================================\n" <<
        "1. Add Items \n" <<
        "2. Delete Items \n" <<
        "3. Show the number of Items \n" <<
        "4. Show min and max Items \n" <<
        "5. Find an Item \n" <<
        "6. Print all Items \n" <<
        "7. Exit \n" <<
        "Enter you Choice: "<< endl;
        cin >> selection;

    switch (selection) {
        //adding item
        case 1: {
            if(isFull()) {
                cout<<"The Stack is Full! \n" << endl;
            } else {
                cout << "Enter the number you want to add to the Array" << endl;
                cin >> number;
                push(number);
            }
            break;

        }
        case 2: {
            //Deleting Item.
            if(isEmpty()) {
                cout << "The Stack is Empty \n" << endl;
            } else {
                pop();
                cout<< "The Item was deleted Successfully "<< endl;
            }

            break;
        }

        case 3: {
            //Showing the number of items.
            if (isEmpty()) {
                cout << "The Stack is Empty \n" << endl;
            } else {
                numOfItems();
            }
            break;
        }

        case 4: {
            //Showing the Minimum and Maximum
            if(isEmpty()) {
                cout << "The Stack is Empty \n" << endl;
            } else {
                minMax();
            }
            break;
        }

        case 5: {
            //Searching for an Item
            if (isEmpty()) {
                cout << "The Stack is Empty \n" << endl;
            } else {
                cout << "Enter the Item you want to find. ";
                cin >> value;
                findValue(value);
            }
            break;

        }

        case 6: {
            //Displaying all the elements in the Array.
            if(isEmpty()) {
                cout << "The Stack is Empty \n" << endl;
            } else {
                display();
            }
            break;
        }

        case 7: {
            //exiting the program.
            cout << "Program Exited. " << endl;
            exit(0);
        }

        default: {
            //wrong input.
            cout << "You have entered the wrong Input please try again. " << endl;
            break;
        }


    }

    } while (selection >0 || selection <8);

    return 0; //check here for selection error.
}

//if the stack is empty
bool isEmpty() {
    if(top == -1) {
        return true;
    } else {
        return false;
    }
}

//if the stack is full or overflows.
bool isFull() {
    if(top==2) {
        return true;

    } else {
        return false;
    }
}

//the push function to put values in the array.
void push (int v) {
    if (isFull()) {
        cout << "Stack OverFlow" << endl;
    } else {
        top++;
        arr[top] = v;
    }
}
//pop function to remove a value from the stack.
int pop () {
    if (isEmpty()) {
        cout << "The Stack is Empty" << endl;
        return 0;
    } else {
        int popv = arr[top];
        arr[top] = 0;
        top--;
        return popv;
    }
}

//display function
void display () {
    cout << "\nAll the Values in the Stack are " << endl;
    for (int i = 2; i >=0; i--) {
        cout << arr[i] << endl;
    }
}

//number of items function.
void numOfItems () {
    cout << "\nThe Number of Items are ";
    cout << top+1 << endl;
}

//minimum and maximum value function.
void minMax() {

    int max = arr[0];
    for(int i=1; i <= top; i++) {
        if(max < arr[i]) {
            max = arr[i];
        }
    }
    cout << "\nThe Maximum Item is " << max;

    int min = arr[0];
    for(int i=1; i <= top; i++) {
        if(min > arr[i]) {
            min = arr[i];
        }
    }
    cout << "\nThe Minimum Item is " << min;

}

//finding the value function.
void findValue(int value) {
    bool check = true;
    for (int i=0; i <= top; i++)
        if (value == arr[i]) {
            cout << "The Value " << value << " was found at index Number " << i << endl;
            check = false;
        }
    if (check)
        cout << "The item is not in the stack." << endl;
}
