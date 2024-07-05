from flask import Flask, render_template, request, redirect, url_for
import mysql.connector

app = Flask(__name__)

# MySQL configuration
db_config = {
    'user': 'root',
    'password': '12345',
    'host': 'localhost',
    'database': 'bus_booking_db'
}

def get_db_connection():
    conn = mysql.connector.connect(**db_config)
    return conn

@app.route('/')
def index():
    conn = get_db_connection()
    cursor = conn.cursor(dictionary=True)
    cursor.execute('SELECT * FROM bookings')
    bookings = cursor.fetchall()
    cursor.close()
    conn.close()
    return render_template('index.html', bookings=bookings)

@app.route('/add', methods=['POST'])
def add_booking():
    customer_name = request.form['customer_name']
    pid = request.form['pid']
    booking_id = request.form['booking_id']
    price = request.form['price']
    from_place = request.form['from_place']
    to_place = request.form['to_place']
    
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute('INSERT INTO bookings (customer_name, pid, booking_id, price, from_place, to_place) VALUES (%s, %s, %s, %s, %s, %s)',
                (customer_name, pid, booking_id, price, from_place, to_place))
    conn.commit()
    cursor.close()
    conn.close()
    return redirect(url_for('index'))

@app.route('/update/<int:id>', methods=['POST'])
def update_booking(id):
    customer_name = request.form['customer_name']
    pid = request.form['pid']
    booking_id = request.form['booking_id']
    price = request.form['price']
    from_place = request.form['from_place']
    to_place = request.form['to_place']
    
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute('UPDATE bookings SET customer_name = %s, pid = %s, booking_id = %s, price = %s, from_place = %s, to_place = %s WHERE id = %s',
                (customer_name, pid, booking_id, price, from_place, to_place, id))
    conn.commit()
    cursor.close()
    conn.close()
    return redirect(url_for('index'))

@app.route('/delete/<int:id>', methods=['POST'])
def delete_booking(id):
    conn = get_db_connection()
    cursor = conn.cursor()
    cursor.execute('DELETE FROM bookings WHERE id = %s', (id,))
    conn.commit()
    cursor.close()
    conn.close()
    return redirect(url_for('index'))

if __name__ == '__main__':
    app.run(debug=True)
