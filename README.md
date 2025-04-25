# ☕ Café Digital System (CDS)

A semester project for **Programming Fundamentals (CS-1002)** at FAST-NUCES, Islamabad — Fall 2023.  
This system was designed to modernize and digitize the stock and order management of the university café, offering features like login authentication, inventory tracking, order handling, and complaint management using C++.

## 🔧 Technologies Used

- Language: **C++**
- Concepts: Functions, Arrays, File Handling, Character Arrays, Bubble Sort, DMA
- Platform: Console-based (Command-line)
- File Storage: Text-based data persistence for login credentials, stocks, and transactions

---

## 🎯 Features

### 👨‍💼 Admin Panel
- Secure login for admin
- View and manage café inventory
- Low-stock notifications (🔴 threshold-based alerts)
- Add/Update/Delete/Search items in stock
- Add/remove employee and student/staff credentials
- View scheduled orders and complaints
- Respond to complaints (cleanliness, food, behavior, etc.)
- Track daily sales and see best-selling employees
- View café announcements, packages, and promotions

### 👩‍🍳 Employee Panel
- Login for at least 5 employees
- Take orders from students/staff
- Generate digital transactions
- View/search items and scheduled orders
- Record sales data for analytics

### 🎓 Student/Staff Portal
- Search items and place orders through CDS
- Schedule orders
- Submit complaints
- View promotions and notifications

---

## 📦 Stock Management System

Each stock item is stored with:
- Name
- Quantity
- Price per Item
- Total Price = Quantity × Price

### ✅ Functionalities:
- **Search** items by name, quantity, or price
- **Sort** items using Bubble Sort (asc/desc by name, price, or quantity)
- **Auto-decrement** quantities to simulate daily sales
- **Threshold Alert** when quantity ≤ 15 (🔴 RED)
- **Out of Stock Alert** when quantity = 0 (🟡 YELLOW)
- Option to **restock items** (max limit: 1000)

---

## 📈 Sales & Stats
- Daily sales calculated based on stock decrease
- Total and average quantity/price tracking
- Display of high/low-selling items

---

## 💾 File Handling
- All data is persisted using **text files**
  - `stocks.txt` – Contains inventory info
  - `users.txt` – Stores user credentials
  - `orders.txt`, `complaints.txt` – Optional extensions for full logging

---

## 📁 Project Structure

