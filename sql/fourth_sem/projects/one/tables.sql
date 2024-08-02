CREATE DATABASE attendance_management;
USE attendance_management;

CREATE TABLE Students (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE Classes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE AttendanceRecords (
    id INT AUTO_INCREMENT PRIMARY KEY,
    student_id INT NOT NULL,
    class_id INT NOT NULL,
    date DATE NOT NULL,
    status VARCHAR(10) NOT NULL,
    FOREIGN KEY (student_id) REFERENCES Students(id),
    FOREIGN KEY (class_id) REFERENCES Classes(id)
);

CREATE TABLE Teachers (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);

CREATE TABLE Subjects (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL
);
