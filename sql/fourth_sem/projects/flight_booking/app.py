from flask import Flask, render_template, request, redirect
import mysql.connector

app = Flask(__name__)

# MySQL connection
db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="12345",
    database="flight_booking"
)
cursor = db.cursor()

# Route to display bookings
@app.route('/')
def index():
    cursor.execute("SELECT * FROM bookings")
    bookings = cursor.fetchall()
    return render_template('index.html', bookings=bookings)

# Route to add a new booking
@app.route('/add', methods=['GET', 'POST'])
def add_booking():
    if request.method == 'POST':
        passenger_name = request.form['passenger_name']
        flight_number = request.form['flight_number']
        departure_date = request.form['departure_date']
        departure_time = request.form['departure_time']
        destination = request.form['destination']
        cursor.execute("INSERT INTO bookings (passenger_name, flight_number, departure_date, departure_time, destination) VALUES (%s, %s, %s, %s, %s)",
                       (passenger_name, flight_number, departure_date, departure_time, destination))
        db.commit()
        return redirect('/')
    return render_template('add_booking.html')

# Route to update a booking
@app.route('/update/<int:id>', methods=['GET', 'POST'])
def update_booking(id):
    if request.method == 'POST':
        passenger_name = request.form['passenger_name']
        flight_number = request.form['flight_number']
        departure_date = request.form['departure_date']
        departure_time = request.form['departure_time']
        destination = request.form['destination']
        cursor.execute("UPDATE bookings SET passenger_name=%s, flight_number=%s, departure_date=%s, departure_time=%s, destination=%s WHERE id=%s",
                       (passenger_name, flight_number, departure_date, departure_time, destination, id))
        db.commit()
        return redirect('/')
    cursor.execute("SELECT * FROM bookings WHERE id=%s", (id,))
    booking = cursor.fetchone()
    return render_template('update_booking.html', booking=booking)

# Route to delete a booking
@app.route('/delete/<int:id>')
def delete_booking(id):
    cursor.execute("DELETE FROM bookings WHERE id=%s", (id,))
    db.commit()
    return redirect('/')

if __name__ == '__main__':
    app.run(debug=True)
