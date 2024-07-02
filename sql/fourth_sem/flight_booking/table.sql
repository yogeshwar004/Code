CREATE DATABASE flight_booking;

USE flight_booking;

CREATE TABLE bookings (
    id INT AUTO_INCREMENT PRIMARY KEY,
    passenger_name VARCHAR(100),
    flight_number VARCHAR(10),
    departure_date DATE,
    departure_time TIME,
    destination VARCHAR(100)
);
