#include <iostream>


class Node
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // ����� ��� ���������� �������� � ����� ������
    void append(int value)
    {
        Node* newNode = new Node(value);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node* current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // ����� ��� ���������� �������� � ������ ������
    void prepend(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // ����� ��� �������� ���������� ��������
    void deleteLast() 
    {
        if (!head) 
        {
            return;
        }
        if (!head->next) 
        {
            delete head;
            head = nullptr;
        }
        else 
        {
            Node* current = head;
            while (current->next->next)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
        size--;
    }

    // ����� ��� �������� ������� ��������
    void deleteFirst()
    {
        if (!head)
        {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    // ����� ��� ���������� �������� �� �������
    void insert(int value, int index) 
    {
        if (index < 0 || index > size) 
        {
            return;
        }
        if (index == 0) 
        {
            prepend(value);
        }
        else 
        {
            Node* newNode = new Node(value);
            Node* current = head;
            for (int i = 0; i < index - 1; i++) 
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    // ����� ��� ��������� �������� �� �������
    int get(int index) 
    {
        if (index < 0 || index >= size || !head) 
        {
            return -1; // ���������� -1 � ������ ������
        }
        Node* current = head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }
        return current->data;
    }

    // ����� ��� �������� �������� �� �������
    void removeAt(int index) 
    {
        if (index < 0 || index >= size || !head) 
        {
            return;
        }
        if (index == 0) 
        {
            deleteFirst();
        }
        else 
        {
            Node* current = head;
            for (int i = 0; i < index - 1; i++) 
            {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }

    // ����� ��� ��������� ������� ������
    int getSize()
    {
        return size;
    }

    // ����� ��� �������� ���� ��������� ������
    void clear()
    {
        while (head)
        {
            deleteFirst();
        }
    }

    // ����� ��� ������ �������� �� �������
    void replace(int value, int index) 
    {
        if (index < 0 || index >= size || !head) 
        {
            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }
        current->data = value;
    }

    // ����� ��� �������� �� ������� ������
    bool isEmpty() 
    {
        return size == 0;
    }

    // ����� ��� ��������� ������� ��������� �� ��������
    void reverse() 
    {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) 
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // ����� ��� ������� ������� ������ ������� � �������
    void insertList(LinkedList& otherList, int index) 
    {
        if (index < 0 || index > size)
        {
            return;
        }
        if (index == 0)
        {
            Node* otherTail = otherList.head;
            while (otherTail->next) 
            {
                otherTail = otherTail->next;
            }
            otherTail->next = head;
            head = otherList.head;
            size += otherList.size;
            otherList.head = nullptr; // ������� ������ ������
            otherList.size = 0;
        }
        else
        {
            Node* current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            Node* otherTail = otherList.head;
            while (otherTail->next)
            {
                otherTail = otherTail->next;
            }
            otherTail->next = current->next;
            current->next = otherList.head;
            size += otherList.size;
            otherList.head = nullptr; // ������� ������ ������
            otherList.size = 0;
        }
    }

    // ����� ��� ������� ������� ������ � �����
    void appendList(LinkedList& otherList)
    {
        Node* thisTail = head;
        while (thisTail->next)
        {
            thisTail = thisTail->next;
        }
        Node* otherTail = otherList.head;
        while (otherTail)
        {
            thisTail->next = new Node(otherTail->data);
            thisTail = thisTail->next;
            otherTail = otherTail->next;
        }
        size += otherList.size;
        otherList.head = nullptr; // ������� ������ ������
        otherList.size = 0;
    }

    // ����� ��� ������� ������� ������ � ������
    void prependList(LinkedList& otherList)
    {
        Node* otherTail = otherList.head;
        while (otherTail->next)
        {
            otherTail = otherTail->next;
        }
        otherTail->next = head;
        head = otherList.head;
        size += otherList.size;
        otherList.head = nullptr; // ������� ������ ������
        otherList.size = 0;
    }

    // ����� ��� �������� �� ���������� ������� ������ � �������
    bool containsList(LinkedList& otherList) 
    {
        if (otherList.size == 0) 
        {
            return true; // ������ ������ ������ ���������� � ������ ������
        }

        Node* current = head;
        Node* otherCurrent = otherList.head;
        while (current) 
        {
            if (current->data == otherCurrent->data) 
            {
                Node* temp = current;
                while (temp && otherCurrent && temp->data == otherCurrent->data) 
                {
                    temp = temp->next;
                    otherCurrent = otherCurrent->next;
                }
                if (!otherCurrent) 
                {
                    return true; // ���� otherList ���������� � ������� ������
                }
                otherCurrent = otherList.head; // ���������� otherCurrent
            }
            current = current->next;
        }
        return false; // OtherList �� ������ � ������� ������
    }

    // ����� ��� ������ ������� ��������� ������� ������ � �������
    int indexOfList(LinkedList& otherList) 
    {
        if (otherList.size == 0) 
        {
            return 0; // ������ ������ ������ ������ � ������
        }

        Node* current = head;
        int index = 0;
        while (current) 
        {
            if (current->data == otherList.head->data) 
            {
                Node* temp = current;
                Node* otherCurrent = otherList.head;
                while (temp && otherCurrent && temp->data == otherCurrent->data) 
                {
                    temp = temp->next;
                    otherCurrent = otherCurrent->next;
                }
                if (!otherCurrent) 
                {
                    return index; // ���� otherList ������ � ������� ������
                }
            }
            current = current->next;
            index++;
        }
        return -1; // OtherList �� ������ � ������� ������
    }

    // ����� ��� ������ ���������� ��������� ������� ������ � �������
    int lastIndexOfList(LinkedList& otherList) 
    {
        if (otherList.size == 0) 
        {
            return size; // ������ ������ ������ ������ � �����
        }

        Node* current = head;
        int lastIndex = -1; // ������ ���������� ���������� otherList
        int index = 0;
        while (current) 
        {
            if (current->data == otherList.head->data) 
            {
                Node* temp = current;
                Node* otherCurrent = otherList.head;
                while (temp && otherCurrent && temp->data == otherCurrent->data) 
                {
                    temp = temp->next;
                    otherCurrent = otherCurrent->next;
                }
                if (!otherCurrent) 
                {
                    lastIndex = index; // ���� otherList ������ � ������� ������
                }
            }
            current = current->next;
            index++;
        }
        return lastIndex;
    }

    // ����� ��� ������ ���� ��������� ������ �� ��������
    void swap(int index1, int index2)
    {
        if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size)
        {
            return;
        }
        if (index1 == index2) 
        {
            return; // ������ ������, ������� ����������
        }

        // ������� ����, ��������������� �������� index1 � index2
        Node* prev1 = nullptr;
        Node* current1 = head;
        for (int i = 0; i < index1; i++)
        {
            prev1 = current1;
            current1 = current1->next;
        }

        Node* prev2 = nullptr;
        Node* current2 = head;
        for (int i = 0; i < index2; i++)
        {
            prev2 = current2;
            current2 = current2->next;
        }

        // ���������� �������� ���������
        if (prev1)
        {
            prev1->next = current2;
        }
        else
        {
            head = current2;
        }

        if (prev2)
        {
            prev2->next = current1;
        }
        else
        {
            head = current1;
        }

        Node* temp = current1->next;
        current1->next = current2->next;
        current2->next = temp;
    }

    // ����� ��� ����������� ������
    void display()
    {
        Node* current = head;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    // ���������� ��� ������������ ������
    ~LinkedList()
    {
        clear();
    }
};



int main()
{
    LinkedList list;
    system("chcp 1251");

    while (true)
    {
        std::cout << "�������� ��������:" << std::endl;
        std::cout << "1. �������� ������� � ����� ������" << std::endl;
        std::cout << "2. �������� ������� � ������ ������" << std::endl;
        std::cout << "3. ������� ��������� �������" << std::endl;
        std::cout << "4. ������� ������ �������" << std::endl;
        std::cout << "5. �������� ������� �� �������" << std::endl;
        std::cout << "6. �������� ������� �� �������" << std::endl;
        std::cout << "7. ������� ������� �� �������" << std::endl;
        std::cout << "8. �������� ������ ������" << std::endl;
        std::cout << "9. ��������� �� �������" << std::endl;
        std::cout << "10. �������� ������� ��������� �� ��������" << std::endl;
        std::cout << "11. �������� ������ ������" << std::endl;
        std::cout << "12. ��������� �� ���������� ������� ������" << std::endl;
        std::cout << "13. ����� ������ ��������� ������� ������" << std::endl;
        std::cout << "14. ����� ��������� ��������� ������� ������" << std::endl;
        std::cout << "15. �������� ��� �������� �� ��������" << std::endl;
        std::cout << "16. ���������� ������" << std::endl;

        std::cout << "17. ������� ��� �������� ������" << std::endl;
        std::cout << "18. �������� ������� �� �������" << std::endl;
        std::cout << "19. �������� ������ ������ � �����" << std::endl;
        std::cout << "20. �������� ������ ������ � ������" << std::endl;
        std::cout << "0. �����" << std::endl;

        int choice;
        std::cout << "������� ����� ��������: ";
        std::cin >> choice;

        if (choice == 0)
        {
            break;
        }

        int value, index;

        switch (choice)
        {
        case 1:
            std::cout << "������� �������� ��� ���������� � �����: ";
            std::cin >> value;
            list.append(value);
            break;
        case 2:
            std::cout << "������� �������� ��� ���������� � ������: ";
            std::cin >> value;
            list.prepend(value);
            break;
        case 3:
            list.deleteLast();
            break;
        case 4:
            list.deleteFirst();
            break;
        case 5:
            std::cout << "������� �������� ��� �������: ";
            std::cin >> value;
            std::cout << "������� ������ ��� �������: ";
            std::cin >> index;
            list.insert(value, index);
            break;
        case 6:
            std::cout << "������� ������ ��� ��������� ��������: ";
            std::cin >> index;
            value = list.get(index);
            std::cout << "������� �� ������� " << index << ": " << value << std::endl;
            break;
        case 7:
            std::cout << "������� ������ ��� �������� ��������: ";
            std::cin >> index;
            list.removeAt(index);
            break;
        case 8:
            std::cout << "������ ������: " << list.getSize() << std::endl;
            break;
        case 9:
            std::cout << "������ ������: " << (list.isEmpty() ? "��" : "���") << std::endl;
            break;
        case 10:
            list.reverse();
            std::cout << "������� ��������� ������� �� ��������." << std::endl;
            break;
        case 11:
        {
            LinkedList otherList;
            std::cout << "������� �������� ������� ������ (������� -1 ��� ����������): ";
            while (true) 
            {
                std::cin >> value;
                if (value == -1)
                {
                    break;
                }
                otherList.append(value);
            }
            std::cout << "������� ������ ��� ������� ������� ������: ";
            std::cin >> index;
            list.insertList(otherList, index);
            break;
        }
        case 12:
        {
            LinkedList otherList;
            std::cout << "������� �������� ������� ������ (������� -1 ��� ����������): ";
            while (true)
            {
                std::cin >> value;
                if (value == -1)
                {
                    break;
                }
                otherList.append(value);
            }
            bool contains = list.containsList(otherList);
            std::cout << "�������� �� ������� ������ ������ ������: " << (contains ? "��" : "���") << std::endl;
            break;
        }
        case 13:
        {
            LinkedList otherList;
            std::cout << "������� �������� ������� ������ (������� -1 ��� ����������): ";
            while (true)
            {
                std::cin >> value;
                if (value == -1)
                {
                    break;
                }
                otherList.append(value);
            }
            int indexOf = list.indexOfList(otherList);
            std::cout << "������ ������� ��������� ������� ������: " << indexOf << std::endl;
            break;
        }
        case 14:
        {
            LinkedList otherList;
            std::cout << "������� �������� ������� ������ (������� -1 ��� ����������): ";
            while (true)
            {
                std::cin >> value;
                if (value == -1)
                {
                    break;
                }
                otherList.append(value);
            }
            int lastIndexOf = list.lastIndexOfList(otherList);
            std::cout << "������ ���������� ��������� ������� ������: " << lastIndexOf << std::endl;
            break;
        }
        case 15:
            std::cout << "������� ������� ��� ������: ";
            std::cin >> index >> value;
            list.swap(index, value);
            break;
        case 16:
            std::cout << "������: ";
            list.display();
            break;

        case 17:
            std::cout << "�������� ������: ";
            list.clear();
            break;
        case 18:
            std::cout << "������� ������ � �������� �� ��� �����: ";
            std::cin >> index >> value;
            list.replace(value, index);
            break;
        case 19:
        {
            LinkedList otherList;
            std::cout << "������� �������� ������� ������ (������� -1 ��� ����������): ";
            while (true)
            {
                std::cin >> value;
                if (value == -1)
                {
                    break;
                }
                otherList.append(value);
            }
            list.appendList(otherList);
        }
        break;
        case 20:
        {
            LinkedList otherList;
            std::cout << "������� �������� ������� ������ (������� -1 ��� ����������): ";
            while (true)
            {
                std::cin >> value;
                if (value == -1)
                {
                    break;
                }
                otherList.append(value);
            }
            list.prependList(otherList);
        }
        break;

        default:
            std::cout << "�������� �������." << std::endl;
        }
    }

    return 0;
}