CREATE DATABASE bus_booking_db;

USE bus_booking_db;

CREATE TABLE bookings (
    id INT AUTO_INCREMENT PRIMARY KEY,
    customer_name VARCHAR(255) NOT NULL,
    pid VARCHAR(255) NOT NULL,
    booking_id VARCHAR(255) NOT NULL,
    price DECIMAL(10, 2) NOT NULL,
    from_place VARCHAR(255) NOT NULL,
    to_place VARCHAR(255) NOT NULL
);
