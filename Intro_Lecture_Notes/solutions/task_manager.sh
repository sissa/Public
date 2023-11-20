#!/bin/bash

TASKS_FILE="current_tasks.txt"
COMPLETED_TASKS_FILE="completed_tasks.txt"

function check_files {
    if [[ ! -e "$TASKS_FILE" ]]; then
        touch "$TASKS_FILE"
    fi
    if [[ ! -e "$COMPLETED_TASKS_FILE" ]]; then
        touch "$COMPLETED_TASKS_FILE"
    fi
}

function add_task {
    echo "$1" >> "$TASKS_FILE"
}

function complete_task {
    # Add task to completed with timestamp
    echo "$1 - Completed on $(date +"%Y-%m-%d %H:%M")" >> "$COMPLETED_TASKS_FILE"
    # Remove task from current
    sed -i "${2}d" "$TASKS_FILE"
}

function remove_task {
    sed -i "${1}d" "$TASKS_FILE"
}

function view_tasks {
    echo "Current Tasks:"
    nl -s '. ' "$TASKS_FILE"
    echo ""
    echo "Completed Tasks:"
    cat "$COMPLETED_TASKS_FILE"
}

check_files

while true; do
    echo "Simple Task Manager"
    echo "1. Add Task"
    echo "2. Complete Task"
    echo "3. Remove Task"
    echo "4. View Tasks"
    echo "5. Exit"
    read -p "Choose an option (1-5): " choice

    case $choice in
        1)
            read -p "Enter the task you want to add: " task
            add_task "$task"
            ;;
        2)
            read -p "Enter the number of the task you've completed: " task_num
            task=$(sed "${task_num}q;d" "$TASKS_FILE")
            if [[ -n "$task" ]]; then
                complete_task "$task" "$task_num"
            else
                echo "Invalid task number."
            fi
            ;;
        3)
            read -p "Enter the number of the task you want to remove: " task_num
            if sed -n "${task_num}p" "$TASKS_FILE" &>/dev/null; then
                remove_task "$task_num"
            else
                echo "Invalid task number."
            fi
            ;;
        4)
            view_tasks
            ;;
        5)
            echo "Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid option!"
            ;;
    esac
done

