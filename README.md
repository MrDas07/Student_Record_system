

# **STUDENT RECORDS MANAGEMENT SYSTEM**

## **OVERVIEW**
<img width="518" alt="image" src="https://github.com/user-attachments/assets/af3e26d9-1767-4237-95be-9f00e9739b93">


This program is designed to manage student records, including inserting new records, searching, displaying, and deleting existing records. It utilizes a text file to store student data and provides a simple menu-driven interface for interaction. Access to the system is protected by a password.

##**FLOW CHART**



        +---------+
        |  Start  |
        +----+----+
             |
             v
  +------------------+
  | Input Password   |
  +--------+---------+
           |
  +--------v---------+
  | Password Correct?|
  +----+-------+-----+
       |       |
       | No    | Yes
       v       |
+------->--------+ 
| Retry Attempts | 
+--------+-------+
         |
         v
+--------+--------+
| Exit Program     |
+------------------+

    |
    v
  +------------------+
  | Main Menu        |
  +----+----+----+---+----+-----+----+----+
       |        |    |    |    |    |
       v        v    v    v    v    v
+------+--+ +-----+ +-----+ +------++----+
| Insert   | | Search| | Search| | Display |
| Data     | | by    | | by    | | All     |
|          | | Name  | | Roll  | | Data    |
+-----+----+ +---+--+ +---+--+ +--+-------+
      |           |      |          |
      v           v      v          v
+-----+-----+ +-----+ +-----+ +----+-----+
| Save to   | | Search| | Search| | Read and|
| File      | | and   | | and   | | Display |
|           | | Display| | Delete| | All     |
+-----------+ +-------+ +------+ +---------+
       |
       v
    +------+
    | Exit |
    +------+
       |
       v
    +------+
    | End  |
    +------+




## **FEATURES**

1. **INSERT DATA**: Add new student records to the file.
2. **SEARCH DATA BY NAME**: Find student records by name.
3. **SEARCH DATA BY ROLL NUMBER**: Find student records by roll number.
4. **DISPLAY DATA**: Display all student records.
5. **DELETE DATA BY ROLL NUMBER**: Remove student records based on roll number.

## **FILE FORMAT**

The student data is stored in a text file (`students.txt`) with the following format for each record:

```
Name,Roll Number,Address
```

For example:

```
John Doe,12345,123 Elm Street
```

## **GETTING STARTED**

### **PREREQUISITES**

- A C compiler (e.g., GCC)
- Basic understanding of C programming

### **COMPILATION**

To compile the program, use the following command:

```sh
gcc -o student_management student_management.c
```

Replace `student_management.c` with the name of your source file if it's different.

### **RUNNING THE PROGRAM**

1. **RUN THE EXECUTABLE**: Execute the compiled program:

    ```sh
    ./student_management
    ```

2. **PASSWORD AUTHENTICATION**: Enter the password `admin123` when prompted. You have 3 attempts to enter the correct password.

3. **MENU OPTIONS**: Once authenticated, you will see a menu with the following options:
    - **1. INSERT DATA TO FILE**: Add new student records.
    - **2. SEARCH DATA BY NAME**: Search for student records by name.
    - **3. SEARCH DATA BY ROLL NUMBER**: Search for student records by roll number.
    - **4. DISPLAY THE DATA**: View all student records.
    - **5. DELETE DATA BY ROLL NUMBER**: Remove student records by roll number.
    - **6. EXIT**: Exit the program.

4. **FOLLOW PROMPTS**: The program will prompt you for necessary information based on the selected menu option.

## **EXAMPLE USAGE**

1. **INSERTING DATA**:
    - Choose option `1`.
    - Enter the student's name, roll number, and address as prompted.
    - The data will be saved to `students.txt`.

2. **SEARCHING DATA BY NAME**:
    - Choose option `2`.
    - Enter the student's name to search.
    - If found, the details will be displayed.

3. **DISPLAYING ALL DATA**:
    - Choose option `4`.
    - All student records in `students.txt` will be displayed.

4. **DELETING DATA BY ROLL NUMBER**:
    - Choose option `5`.
    - Enter the roll number of the student record to delete.
    - The record will be removed, and the file will be updated accordingly.

## **ERROR HANDLING**

- The program will notify you if there is an issue opening the files.
- You will be informed if no records are found for your search or deletion requests.

## **SECURITY**

- The program uses a hardcoded password (`admin123`) for authentication. In a real-world application, consider implementing a more secure authentication mechanism.

## **LICENSE**

This program is provided for educational purposes and personal use. Modify and use it as needed for your own projects.

---

Feel free to copy this format into your README file for improved readability and clarity!
