#include <gtest/gtest.h>
#include "todo.h"

TEST(TodoListTest, AddSingleTask) {
    TodoList todo;
    todo.init();
    todo.add_task("Write code");

    int count;
    const char** tasks = todo.get_pending_tasks(count);

    ASSERT_EQ(count, 1);
    EXPECT_STREQ(tasks[0], "Write code");

    todo.destroy();
}

TEST(TodoListTest, AddMultipleTasks) {
    TodoList todo;
    todo.init();
    todo.add_task("A");
    todo.add_task("B");
    todo.add_task("C");

    int count;
    const char** tasks = todo.get_pending_tasks(count);
    ASSERT_EQ(count, 3);
    EXPECT_STREQ(tasks[0], "A");
    EXPECT_STREQ(tasks[1], "B");
    EXPECT_STREQ(tasks[2], "C");

    todo.destroy();
}

TEST(TodoListTest, RemoveTask) {
    TodoList todo;
    todo.init();
    todo.add_task("A");
    todo.add_task("B");
    todo.add_task("C");

    todo.remove_task(1);  // Remove "B"

    int count;
    const char** tasks = todo.get_pending_tasks(count);
    ASSERT_EQ(count, 2);
    EXPECT_STREQ(tasks[0], "A");
    EXPECT_STREQ(tasks[1], "C");

    todo.destroy();
}

TEST(TodoListTest, RemoveInvalidIndexThrows) {
    TodoList todo;
    todo.init();
    todo.add_task("Sample Task");

    // TODO: Try removing at invalid indices
    // Example: negative index and out-of-bound index
    EXPECT_THROW(todo.remove_task(-1), std::out_of_range);
    EXPECT_THROW(todo.remove_task(1), std::out_of_range);

    todo.destroy();
}

TEST(TodoListTest, AddTooManyTasksThrows) {
    TodoList todo;
    todo.init();

    // TODO: Add exactly 32 tasks in a loop
    // Then try adding a 33rd task and expect an exception
    for (int i = 0; i < 32; i++)
    {
        todo.add_task("ABC");
    }
    EXPECT_THROW(todo.add_task("CDE"), std::out_of_range);

    todo.destroy();
}