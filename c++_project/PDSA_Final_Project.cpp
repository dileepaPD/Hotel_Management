#include<iostream>
#include <limits>

using namespace std;

class Hotel
{
private:
    struct Node
    {
        int id, date;
        string name, roomtype;
        Node* next;
    };

public:
    Node* head = NULL;
    void insert();
    void menu();
    void update();
    void search();
    void del();
    void sort();
    void show();
    void list();
    void order();
    void drinks();
};

void Hotel::menu()
{
    int choice;
    while (true)
    {
        cout << "\n";
        cout << "\t     Welcome To Hotel Management System \n"<< endl;
        cout << "\n\t__________Hotel Management System__________";
        cout << "\n\nS.No      Functions                          Description" << endl;
        cout << "\n1\tAllocate Room\t\t\tInsert New Room";
        cout << "\n2\tSearch Room\t\t\tSearch Room With RoomID";
        cout << "\n3\tUpdate Room\t\t\tUpdate Room Record";
        cout << "\n4\tDelete Room\t\t\tDelete Room With RoomID";
        cout << "\n5\tShow Room Records\t\tShow Room Records that Added";
        cout << "\n6\tOrder Food\t\t\tYou Can Order A Food";
        cout << "\n7\tOrder Drinks\t\t\tYou Can Order A Drinks";
        cout << "\n8\tExit" << endl;


        cout << "Enter Your Choice" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            search();
            break;
        case 3:
            update();
            break;
        case 4:
            del();
            break;
        case 5:
            //sort();
            show();
            break;
        case 6:
            order();
            break;
        case 7:
            drinks();
            break;
        case 8:
            cout << "\nExiting the program.\n\n" << endl;
             exit(0);
        default:
            cout << "\nInvalid Input, Enter Correct Number!!!!\n\n" << endl;
        }
    }
}

void Hotel::insert()
{
    cout << "\n\t__________Hotel Management System__________";

    while (true)
    {
        Node* new_Node = new Node;
        cout << "\nEnter Room ID (enter -1 to stop inserting):" << endl;

        if (!(cin >> new_Node->id))
        {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input

            cout << "\nInvalid input. Please enter a numeric value for Room ID.\n\n";
            delete new_Node; // Release memory allocated for the unused node
            continue; // Skip the rest of the loop and ask for input again
        }

        if (new_Node->id == -1)
        {
            delete new_Node;
            break;
        }

        cout << "\nEnter Customer Name:" << endl;
        cin >> new_Node->name;
        cout << "\nEnter Allocated Date:" << endl;
        cin >> new_Node->date;
        cout << "\nEnter Room Type(single/double/twin):" << endl;
        cin >> new_Node->roomtype;

        new_Node->next = NULL;  // Initialize the next pointer to NULL

        if (head == NULL)
        {
            head = new_Node;
        }
        else
        {
            Node* ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_Node;
        }

        cout << "\n\n\t\t New Room Inserted\n\n";
    }

    menu();
}

void Hotel::search()
{
    while (true)
    {
        cout << "\n\t__________Hotel Management System__________";
        int t_id;
        bool validIdEntered = false;

        while (!validIdEntered)
        {
            cout << "\n\nRoom ID (enter -1 to go back to the menu): ";
            cin >> t_id;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //ignore last input
                cout << "\nInvalid input. Please enter a numeric value.\n\n";

            }
            else if (t_id == -1)
            {
                //exit the loop
                validIdEntered = true;
                break;
            }
            else
            {
                Node* ptr = head;
                bool found = false;
                while (ptr != NULL)
                {
                    if (t_id == ptr->id)
                    {
                        cout << "\n\nRoom ID:" << ptr->id;
                        cout << "\n\nCustomer Name:" << ptr->name;
                        cout << "\n\nRoom Allocated Date:" << ptr->date;
                        cout << "\n\nRoom Type:" << ptr->roomtype;
                        cout<<"\n";
                        found = true;
                        validIdEntered = true;
                        break;
                    }
                    ptr = ptr->next;
                }

                if (!found)
                {
                    cout << "\n\nRoom ID not found. Please enter a valid Room ID!!!!!!.\n";
                }
            }
        }

        if (validIdEntered)
        {

            menu();
            break; //exit the outor loop

        }
    }
}



void Hotel::update()
{
    cout << "\n\t__________Hotel Management System__________";
    int t_id;
    if (head == NULL)
    {
        cout << "\n\nList Is Empty\n\n";
        menu();
    }
    else
    {
        cout << "\n\nRoom ID-: ";
        cin >> t_id;
        Node* ptr = head;
        bool found = false;
        while (ptr != NULL)
        {
            if (t_id == ptr->id)
            {
                cout << "\n\nRoomID:";
                cin >> ptr->id;

                cout << "\n\nCustomer Name:";
                cin >> ptr->name;

                cout << "\n\nAllocated Date:";
                cin >> ptr->date;

                cout << "\n\nRoom Type:";
                cin >> ptr->roomtype;

                cout << "\n\n\t\t Update Record Successfully!!!!\n\n";
                found = true;
                break;
            }
            ptr = ptr->next;
        }

        if (!found)
            cout << "\n\nRoom ID not found.\n\n";


        return;
    }
}


void Hotel::del()
{
    cout << "\n\t__________Hotel Management System__________";
    int t_id;
    if (head == NULL)
    {
        cout << "\n\nList Is Empty\n";
        menu();
    }
    else
    {
        cout << "\n\nRoom ID-: ";
        cin >> t_id;
        if (t_id == head->id)
        {
            Node* ptr = head;
            head = head->next;
            delete ptr;
            cout << "\nDelete Room Record Successfully!!!!!!\n\n";
        }
        else
        {
            Node* pre = head;
            Node* ptr = head;
            while (ptr != NULL)
            {
                if (t_id == ptr->id)
                {
                    pre->next = ptr->next;
                    delete ptr;
                    cout << "\nDelete Room Record Successfully!!!!!!\n\n";
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }
        }
    }


    menu();
}

void Hotel::show()
{
    Node* ptr = head;
    if (ptr == NULL)
    {
        cout << "\n\nList Is Empty\n\n";
        return;
    }

    cout << "    __________Room records in currently used__________\n\n";
    while (ptr != NULL)
    {
        cout << "\n\nRoom ID: " << ptr->id;
        cout << "\n\nCustomer Name: " << ptr->name;
        cout << "\n\nAllocated Date: " << ptr->date;
        cout << "\n\nRoom Type: " << ptr->roomtype;
        cout << "\n\n";
        ptr = ptr->next;
    }


}


void Hotel::sort()
{
    if (head == NULL)
    {
        cout << "\n\nLinked List Is Empty\n\n";
        return;
    }

    // Bubble sort to sort the linked list in place
    bool swapped;
    Node* current;
    Node* lastSorted = NULL;

    do
    {
        swapped = false;
        current = head;

        while (current->next != lastSorted)
        {
            if (current->id > current->next->id)
            {
                // Swap data
                int tempId = current->id;
                current->id = current->next->id;
                current->next->id = tempId;

                string tempName = current->name;
                current->name = current->next->name;
                current->next->name = tempName;

                int tempDate = current->date;
                current->date = current->next->date;
                current->next->date = tempDate;

                string tempRoomType = current->roomtype;
                current->roomtype = current->next->roomtype;
                current->next->roomtype = tempRoomType;

                swapped = true;
            }

            current = current->next;
        }

        lastSorted = current;

    } while (swapped);


    cout << "\n\nSorted Room Records:" << endl;
    show();
}

void Hotel::order() {
    cout << "\n\t__________Hotel Management System__________";

    char mealChoice;
    int foodChoice;
    double totalAmount = 0.0;

    do {
        cout << "\n\nEnter meal choice (lunch(l), breakfast(b), dinner(d) -): ";
        cin >> mealChoice;

        switch (mealChoice) {
        case 'l':
        case 'L':
            cout << "\nYou selected Lunch. Lunch Menu List:\n";
            cout << "1) Rice      Rs.600.00\n";
            cout << "2) Kottu     Rs.800.00\n";
            cout << "3) Rice & Curry      Rs.900.00\n";
            cout << "4) Hoppers   Rs.500.00\n";
            cout << "5) Pittu     Rs.600.00\n";
            break;

        case 'b':
        case 'B':
            cout << "\nYou selected Breakfast. Breakfast Menu List:\n";
            cout << "1) Omelette      Rs.300.00\n";
            cout << "2) Pancakes      Rs.400.00\n";
            cout << "3) Toast with Jam Rs.250.00\n";
            cout << "4) Porridge      Rs.350.00\n";
            cout << "5) Fruit Salad   Rs.500.00\n";
            break;

        case 'd':
        case 'D':
            cout << "\nYou selected Dinner. Dinner Menu List:\n";
            cout << "1) Grilled Chicken   Rs.800.00\n";
            cout << "2) Spaghetti Bolognese Rs.700.00\n";
            cout << "3) Vegetarian Curry  Rs.600.00\n";
            cout << "4) Steak with Potatoes Rs.900.00\n";
            cout << "5) Sushi Platter     Rs.1000.00\n";
            break;

        default:
            cout << "\nInvalid input. Please enter a valid option (l/b/d/menu).\n";
            continue;
        }

        do {
            cout << "\nEnter the food number (Get bill 0, Menu -1): ";
            cin >> foodChoice;

            if (foodChoice == 0) {

                cout << "\nTotal Amount: Rs. " << totalAmount << endl;
                menu();
                return;
            } else if (foodChoice == -1) {

                menu();
                break;
            } else {

                double price = 0.0;  // Variable to store the price of the selected food item

                switch (mealChoice) {
                    case 'l':
                    case 'L':

                        switch (foodChoice) {
                            case 1:
                                price = 600.00;
                                break;
                            case 2:
                                price = 800.00;
                                break;
                            case 3:
                                price = 900.00;
                                break;
                            case 4:
                                price = 500.00;
                                break;
                            case 5:
                                price = 600.00;
                                break;
                            default:
                                cout << "\nInvalid input. Please enter a valid food number.\n";
                                continue;  // next iteration of the loop
                        }
                        break;

                    case 'b':
                    case 'B':

                        switch (foodChoice) {
                            case 1:
                                price = 300.00;
                                break;
                            case 2:
                                price = 400.00;
                                break;
                            case 3:
                                price = 250.00;
                                break;
                            case 4:
                                price = 350.00;
                                break;
                            case 5:
                                price = 500.00;
                                break;
                            default:
                                cout << "\nInvalid input. Please enter a valid food number.\n";
                                continue;
                        }
                        break;

                    case 'd':
                    case 'D':

                        switch (foodChoice) {
                            case 1:
                                price = 800.00;
                                break;
                            case 2:
                                price = 700.00;
                                break;
                            case 3:
                                price = 600.00;
                                break;
                            case 4:
                                price = 900.00;
                                break;
                            case 5:
                                price = 1000.00;
                                break;
                            default:
                                cout << "\nInvalid input. Please enter a valid food number.\n";
                                continue;
                        }
                        break;

                    default:
                        cout << "\nInvalid input. Please enter a valid meal choice.\n";
                        continue;
                }

                totalAmount += price;
            }
        } while (true);
    } while (true);
}


void Hotel::drinks()
{
    cout << "\n\t__________Hotel Management System__________";

    int drinkChoice;
    int quantity;
    double totalAmount = 0.0;

    do {
        cout << "\n\nDrinks Menu List:\n";
        cout << "1) Coca Cola      Rs.120.00\n";
        cout << "2) Pepsi          Rs.100.00\n";
        cout << "3) Orange Juice   Rs.150.00\n";
        cout << "4) Apple Juice    Rs.130.00\n";
        cout << "5) Water          Rs.50.00\n";

        cout << "\nEnter the drink number (Get total 0, Menu -1): ";
        cin >> drinkChoice;

        if (drinkChoice == 0) {

            cout << "\nTotal Amount: Rs. " << totalAmount << endl;
            menu();
            return;
        } else if (drinkChoice == -1) {

            break;
        } else {
            cout << "Enter quantity: ";
            cin >> quantity;

            double price = 0.0;


            switch (drinkChoice) {
                case 1:
                    price = 120.00;
                    break;
                case 2:
                    price = 100.00;
                    break;
                case 3:
                    price = 150.00;
                    break;
                case 4:
                    price = 130.00;
                    break;
                case 5:
                    price = 50.00;
                    break;
                default:
                    cout << "\nInvalid input. Please enter a valid drink number.\n";
                    continue;
            }

            totalAmount += (price * quantity);
        }
    } while (true);
}


int main()
{
    Hotel h;
    h.menu();
    return 0;
}


