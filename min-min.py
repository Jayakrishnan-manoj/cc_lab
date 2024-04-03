#Implement the Min-Min scheduling algorithm in Python.

def min_min(tasks, n):
    
    # Initialize the task list
    task_list = []
    for i in range(n):
        task_list.append(tasks[i])
        
    # Initialize the machine list
    machine_list = []
    for i in range(n):
        machine_list.append(0)
        
    # Initialize the completion time list
    completion_time_list = []
    for i in range(n):
        completion_time_list.append(0)
        
    # Initialize the task assignment list
    task_assignment_list = []
    for i in range(n):
        task_assignment_list.append(0)
        
        
    # Find the minimum task
    for i in range(n):
        min_task = 0
        for j in range(n):
            if task_list[j][1] < task_list[min_task][1]:
                min_task = j
                
        # Assign the task to the machine
        task_assignment_list[i] = min_task
        machine_list[i] = task_list[min_task][0]
        completion_time_list[i] = task_list[min_task][1]
        
        # Update the task list
        task_list[min_task][1] = 1000000
        
    # Print the task assignment list
    print("Task Assignment List:")
    print(task_assignment_list)
    
    # Print the machine list
    print("Machine List:")
    print(machine_list)
    
    # Print the completion time list
    print("Completion Time List:")
    
    # Calculate the total completion time
    total_completion_time = 0
    for i in range(n):
        print(completion_time_list[i])
        total_completion_time += completion_time_list[i]
        
    # Print the total completion time
    print("Total Completion Time:")
    print(total_completion_time)
    
    
    
        
        
    