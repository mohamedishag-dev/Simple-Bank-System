# 🏦 Bank Management System (Professional CLI)

A professional-grade **Bank Management System** featuring a multi-user environment with an integrated **Permissions System**.
This application allows administrators to manage clients and bank staff (users) with specific access levels,
ensuring secure financial operations.

## 🌟 Key Features

### 👤 User & Permission Management

- **Role-Based Access Control:** Assign specific permissions to users (e.g., a user can find clients but cannot delete them).
- **Full Access vs. Limited Access:** Support for admin accounts (`-1` permission) and restricted staff accounts.
- **User CRUD:** Add, Delete, Update, and Find bank users stored in `Users.txt`.

 ### 📂 Client Operations (CRUD)

- **Comprehensive Management:** Full control over client records (List, Add, Delete, Update, Find).
- **Duplicate Prevention:** Automatic checks to ensure Account Numbers and Usernames are unique.

 ### 💰 Transactions Module

- **Deposit/Withdraw:** Process financial transactions and update balances instantly.
- **Total Balances:** View the sum of all client balances across the bank.

 ### 🛡️ Security & Validation

- **Login Screen:** Requires valid credentials from `Users.txt` to enter the system.
- **Access Control:** Integrated `CheckAccessPermission` function that blocks unauthorized users from specific menus.

## 🛠️ Technical Highlights
- **Data Structures**: Extensive use of `std::vector` for dynamic memory management and `struct` for data modeling.
- **File I/O**: Custom-built functions to convert records to lines and vice versa using string delimiters (`#//#`).
- **Enums for Navigation**: Clean and readable menu navigation using `enum` types.
- **Input Validation**: Secure input handling to prevent account duplication and invalid operations.

## 📂 System Architecture
The project is structured to separate data logic from UI:
- **Models**: `sClient` and `stUser` structures.
- **Core Logic**: String splitting, record conversion, and file synchronization.
- **Security**: A login system that verifies credentials and checks permissions before granting access.
  
 ### 📂 Data Structure Examples

  #### `Users.txt`

   `Username#//#Password#//#Permissions`
   
```
Admin#//#1234#//#-1
Employee1#//#pass01#//#3
```

  ### `Clients.txt`

   `AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance`
   
```
A100#//#4444#//#Alice Smith#//#010203#//#6500.00
```

---
### 🛠️ How to Run
Follow these steps to get the system up and running on your local machine:
#### 1 Prerequisites
Ensure you have a C++ compiler installed:
- **Windows**: MinGW, Visual Studio, or Clion.
- **Linux/Mac**: GCC (g++) or Clang.

#### 2. File Preparation
Make sure the following data files exist in the same directory as your source code (or the ```/data``` folder as per your structure):
- ```Clients.txt```
- ```Users.txt``` (Ensure it contains at least one Admin user: ```Admin#//#1234#//#-1```)

#### 3. Compilation

Open your terminal or command prompt and navigate to the project folder, then run:

`bash`
```
g++ main.cpp -o BankSystem
```
#### 4. Execution

Run the generated executable file:

**Windows**:
`bash`

```
BankSystem.exe
```

**Linux/Mac**:
`bash`

```
./BankSystem
```

#### 5. Login
Use the default credentials to access the system:
- Username: ```Admin```
- Password: ```1234```
## 📁 Project Structure
```
Simple-Bank-System/
|
├── src/
|    ├── main.cpp
|    ├── bank_logic.cpp
|    └── bank_logic.h
|
├── include/
|    └── data/
│       ├── Clients.txt
│       └── Users.txt
│
├── docs/           # Documentation or diagrams
└── README.md       # Project overview
```
