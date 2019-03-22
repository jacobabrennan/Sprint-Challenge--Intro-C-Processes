**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
Running: A currently active process, executing code on the CPU.
Runnable: The process is ready to run, and is waiting its turn from the OS.
Sleeping: The process is waiting for the OS to wake it up, usually once a resource is free.
Zombie: A process that has exited, but is holding a return value until waited on.


**2. What is a zombie process?**
A zombie process is no longer running, but the process can't be completely removed by the OS until another process has received its return value. These are often cleaned by the init process, which becomes the parent process of orphaned children and will wait for them.



**3. How does a zombie process get created? How does one get destroyed?**
When a process exits, by crashing, returning, using the exit() call, etc., the process becomes a zombie until another process waits for it. A zombie process can be destoryed by waiting for it.



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**
Compiled code is run directly by the CPU, instead of being run through an interpreter. This results in better performance ("faster code") because interpretation requires many more instructions to the CPU.
