CREATE DATABASE financial_db;
USE financial_db;

CREATE TABLE financial_data (
    id INT AUTO_INCREMENT PRIMARY KEY,
    account_number VARCHAR(50),
    account_name VARCHAR(100),
    balance DECIMAL(10, 2),
    account_type VARCHAR(50),
    branch_name VARCHAR(100)
);
