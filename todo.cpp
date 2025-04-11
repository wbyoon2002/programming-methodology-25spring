#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    size = 0;
    for (int i = 0; i < MAX_TASKS; i++)
    {
        tasks[i] = nullptr;
    }
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    size = 0;
    for (int i = 0; i < MAX_TASKS; i++)
    {
        delete []tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // Copy characters from src to dest without reallocating dest
    int lenSrc = string_length(src);
    for (int i = 0; i < lenSrc; i++) {
        dest[i] = src[i];
    }
    dest[lenSrc] = '\0';
}

void TodoList::add_task(const char* task) {
    // If full, throw. Otherwise allocate and copy new task
    if (size >= MAX_TASKS) {
        throw std::out_of_range("Full list");
    }
    tasks[size] = new char[string_length(task) + 1];
    string_copy(tasks[size], task);
    size++;
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index < 0 || index > size - 1)
    {
        throw std::out_of_range("Index is out of range");
    }
    else
    {
        for (int i = index; i < size - 1; i++)
        {
            string_copy(tasks[i], tasks[i+1]);
        }
        delete []tasks[--size];
        tasks[size] = nullptr;
    }
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    // Set count to the current size
    count = size;

    // Return the array of tasks
    return const_cast<const char**>(tasks);
}