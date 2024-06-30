from flask import Flask, render_template, request, redirect, url_for
import pymysql

app = Flask(__name__)

def get_db_connection():
    return pymysql.connect(
        host='localhost',
        user='root',
        password='12345',
        database='financial_db',
        cursorclass=pymysql.cursors.DictCursor
    )

@app.route('/')
def index():
    conn = get_db_connection()
    with conn.cursor() as cursor:
        cursor.execute('SELECT * FROM financial_data')
        data = cursor.fetchall()
    conn.close()
    return render_template('index.html', data=data)

@app.route('/add', methods=('GET', 'POST'))
def add():
    if request.method == 'POST':
        account_number = request.form['account_number']
        account_name = request.form['account_name']
        balance = request.form['balance']
        account_type = request.form['account_type']
        branch_name = request.form['branch_name']

        conn = get_db_connection()
        with conn.cursor() as cursor:
            cursor.execute('INSERT INTO financial_data (account_number, account_name, balance, account_type, branch_name) VALUES (%s, %s, %s, %s, %s)',
                           (account_number, account_name, balance, account_type, branch_name))
            conn.commit()
        conn.close()
        return redirect(url_for('index'))

    return render_template('add_data.html')

@app.route('/update/<int:id>', methods=('GET', 'POST'))
def update(id):
    conn = get_db_connection()
    with conn.cursor() as cursor:
        cursor.execute('SELECT * FROM financial_data WHERE id = %s', (id,))
        data = cursor.fetchone()

    if request.method == 'POST':
        account_number = request.form['account_number']
        account_name = request.form['account_name']
        balance = request.form['balance']
        account_type = request.form['account_type']
        branch_name = request.form['branch_name']

        with conn.cursor() as cursor:
            cursor.execute('UPDATE financial_data SET account_number = %s, account_name = %s, balance = %s, account_type = %s, branch_name = %s WHERE id = %s',
                           (account_number, account_name, balance, account_type, branch_name, id))
            conn.commit()
        conn.close()
        return redirect(url_for('index'))

    conn.close()
    return render_template('update_data.html', data=data)

@app.route('/delete/<int:id>', methods=('POST',))
def delete(id):
    conn = get_db_connection()
    with conn.cursor() as cursor:
        cursor.execute('DELETE FROM financial_data WHERE id = %s', (id,))
        conn.commit()
    conn.close()
    return redirect(url_for('index'))

if __name__ == "__main__":
    app.run(debug=True)
