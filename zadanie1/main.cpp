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

    // Метод для добавления элемента в конец списка
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

    // Метод для добавления элемента в начало списка
    void prepend(int value) 
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Метод для удаления последнего элемента
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

    // Метод для удаления первого элемента
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

    // Метод для добавления элемента по индексу
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

    // Метод для получения элемента по индексу
    int get(int index) 
    {
        if (index < 0 || index >= size || !head) 
        {
            return -1; // Возвращаем -1 в случае ошибки
        }
        Node* current = head;
        for (int i = 0; i < index; i++) 
        {
            current = current->next;
        }
        return current->data;
    }

    // Метод для удаления элемента по индексу
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

    // Метод для получения размера списка
    int getSize()
    {
        return size;
    }

    // Метод для удаления всех элементов списка
    void clear()
    {
        while (head)
        {
            deleteFirst();
        }
    }

    // Метод для замены элемента по индексу
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

    // Метод для проверки на пустоту списка
    bool isEmpty() 
    {
        return size == 0;
    }

    // Метод для изменения порядка элементов на обратный
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

    // Метод для вставки другого списка начиная с индекса
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
            otherList.head = nullptr; // Очищаем другой список
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
            otherList.head = nullptr; // Очищаем другой список
            otherList.size = 0;
        }
    }

    // Метод для вставки другого списка в конец
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
        otherList.head = nullptr; // Очищаем другой список
        otherList.size = 0;
    }

    // Метод для вставки другого списка в начало
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
        otherList.head = nullptr; // Очищаем другой список
        otherList.size = 0;
    }

    // Метод для проверки на содержание другого списка в текущем
    bool containsList(LinkedList& otherList) 
    {
        if (otherList.size == 0) 
        {
            return true; // Пустой список всегда содержится в другом списке
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
                    return true; // Весь otherList содержится в текущем списке
                }
                otherCurrent = otherList.head; // Сбрасываем otherCurrent
            }
            current = current->next;
        }
        return false; // OtherList не найден в текущем списке
    }

    // Метод для поиска первого вхождения другого списка в текущем
    int indexOfList(LinkedList& otherList) 
    {
        if (otherList.size == 0) 
        {
            return 0; // Пустой список всегда найден в начале
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
                    return index; // Весь otherList найден в текущем списке
                }
            }
            current = current->next;
            index++;
        }
        return -1; // OtherList не найден в текущем списке
    }

    // Метод для поиска последнего вхождения другого списка в текущем
    int lastIndexOfList(LinkedList& otherList) 
    {
        if (otherList.size == 0) 
        {
            return size; // Пустой список всегда найден в конце
        }

        Node* current = head;
        int lastIndex = -1; // Индекс последнего найденного otherList
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
                    lastIndex = index; // Весь otherList найден в текущем списке
                }
            }
            current = current->next;
            index++;
        }
        return lastIndex;
    }

    // Метод для обмена двух элементов списка по индексам
    void swap(int index1, int index2)
    {
        if (index1 < 0 || index1 >= size || index2 < 0 || index2 >= size)
        {
            return;
        }
        if (index1 == index2) 
        {
            return; // Нечего менять, индексы одинаковые
        }

        // Находим узлы, соответствующие индексам index1 и index2
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

        // Обмениваем значения элементов
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

    // Метод для отображения списка
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

    // Деструктор для освобождения памяти
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
        std::cout << "Выберите операцию:" << std::endl;
        std::cout << "1. Добавить элемент в конец списка" << std::endl;
        std::cout << "2. Добавить элемент в начало списка" << std::endl;
        std::cout << "3. Удалить последний элемент" << std::endl;
        std::cout << "4. Удалить первый элемент" << std::endl;
        std::cout << "5. Вставить элемент по индексу" << std::endl;
        std::cout << "6. Получить элемент по индексу" << std::endl;
        std::cout << "7. Удалить элемент по индексу" << std::endl;
        std::cout << "8. Получить размер списка" << std::endl;
        std::cout << "9. Проверить на пустоту" << std::endl;
        std::cout << "10. Изменить порядок элементов на обратный" << std::endl;
        std::cout << "11. Вставить другой список" << std::endl;
        std::cout << "12. Проверить на содержание другого списка" << std::endl;
        std::cout << "13. Найти первое вхождение другого списка" << std::endl;
        std::cout << "14. Найти последнее вхождение другого списка" << std::endl;
        std::cout << "15. Обменять два элемента по индексам" << std::endl;
        std::cout << "16. Отобразить список" << std::endl;

        std::cout << "17. Удалить все элементы списка" << std::endl;
        std::cout << "18. Заменить элемент по индексу" << std::endl;
        std::cout << "19. Вставить другой список в конец" << std::endl;
        std::cout << "20. Вставить другой список в начало" << std::endl;
        std::cout << "0. Выход" << std::endl;

        int choice;
        std::cout << "Введите номер операции: ";
        std::cin >> choice;

        if (choice == 0)
        {
            break;
        }

        int value, index;

        switch (choice)
        {
        case 1:
            std::cout << "Введите значение для добавления в конец: ";
            std::cin >> value;
            list.append(value);
            break;
        case 2:
            std::cout << "Введите значение для добавления в начало: ";
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
            std::cout << "Введите значение для вставки: ";
            std::cin >> value;
            std::cout << "Введите индекс для вставки: ";
            std::cin >> index;
            list.insert(value, index);
            break;
        case 6:
            std::cout << "Введите индекс для получения элемента: ";
            std::cin >> index;
            value = list.get(index);
            std::cout << "Элемент по индексу " << index << ": " << value << std::endl;
            break;
        case 7:
            std::cout << "Введите индекс для удаления элемента: ";
            std::cin >> index;
            list.removeAt(index);
            break;
        case 8:
            std::cout << "Размер списка: " << list.getSize() << std::endl;
            break;
        case 9:
            std::cout << "Список пустой: " << (list.isEmpty() ? "Да" : "Нет") << std::endl;
            break;
        case 10:
            list.reverse();
            std::cout << "Порядок элементов изменен на обратный." << std::endl;
            break;
        case 11:
        {
            LinkedList otherList;
            std::cout << "Введите элементы другого списка (введите -1 для завершения): ";
            while (true) 
            {
                std::cin >> value;
                if (value == -1)
                {
                    break;
                }
                otherList.append(value);
            }
            std::cout << "Введите индекс для вставки другого списка: ";
            std::cin >> index;
            list.insertList(otherList, index);
            break;
        }
        case 12:
        {
            LinkedList otherList;
            std::cout << "Введите элементы другого списка (введите -1 для завершения): ";
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
            std::cout << "Содержит ли текущий список другой список: " << (contains ? "Да" : "Нет") << std::endl;
            break;
        }
        case 13:
        {
            LinkedList otherList;
            std::cout << "Введите элементы другого списка (введите -1 для завершения): ";
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
            std::cout << "Индекс первого вхождения другого списка: " << indexOf << std::endl;
            break;
        }
        case 14:
        {
            LinkedList otherList;
            std::cout << "Введите элементы другого списка (введите -1 для завершения): ";
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
            std::cout << "Индекс последнего вхождения другого списка: " << lastIndexOf << std::endl;
            break;
        }
        case 15:
            std::cout << "Введите индексы для обмена: ";
            std::cin >> index >> value;
            list.swap(index, value);
            break;
        case 16:
            std::cout << "Список: ";
            list.display();
            break;

        case 17:
            std::cout << "Удаление списка: ";
            list.clear();
            break;
        case 18:
            std::cout << "Введите индекс и значение на его место: ";
            std::cin >> index >> value;
            list.replace(value, index);
            break;
        case 19:
        {
            LinkedList otherList;
            std::cout << "Введите элементы другого списка (введите -1 для завершения): ";
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
            std::cout << "Введите элементы другого списка (введите -1 для завершения): ";
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
            std::cout << "Неверная команда." << std::endl;
        }
    }

    return 0;
}