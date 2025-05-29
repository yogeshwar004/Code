from flask import Flask, render_template, request, jsonify, session, redirect, url_for
from blockchain import Blockchain
import mysql.connector
from werkzeug.security import generate_password_hash, check_password_hash
import smtplib
from email.message import EmailMessage
import random

app = Flask(__name__)
app.secret_key = 'your_secret_key_here'

# MySQL Configuration
db = mysql.connector.connect(
    host="localhost",
    user="root",
    password="12345",
    database="voting_system"
)
cursor = db.cursor()

# Create tables if they don't exist
cursor.execute("""
CREATE TABLE IF NOT EXISTS users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    username VARCHAR(255) UNIQUE NOT NULL,
    password VARCHAR(255) NOT NULL,
    voter_id VARCHAR(255) UNIQUE NOT NULL
)
""")

cursor.execute("""
CREATE TABLE IF NOT EXISTS votes (
    id INT AUTO_INCREMENT PRIMARY KEY,
    voter_id VARCHAR(255) NOT NULL,
    vote VARCHAR(255) NOT NULL,
    block_hash VARCHAR(255) NOT NULL,
    timestamp DATETIME DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (voter_id) REFERENCES users(voter_id)
)
""")
db.commit()

blockchain = Blockchain()

# OTP Email Setup
EMAIL_ADDRESS = "naiduyogeshwar@gmail.com"
EMAIL_PASSWORD = "jemf uwlp jsvl zjol"
OTP_STORE = {}

@app.route('/')
def home():
    if 'username' in session:
        return redirect(url_for('dashboard'))
    return render_template('login.html')

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        username = request.form['username']
        password = request.form['password']

        cursor.execute("SELECT * FROM users WHERE username = %s", (username,))
        user = cursor.fetchone()

        if user and check_password_hash(user[2], password):
            otp = str(random.randint(100000, 999999))
            OTP_STORE[username] = otp

            msg = EmailMessage()
            msg['Subject'] = 'Your OTP for Blockchain Voting'
            msg['From'] = EMAIL_ADDRESS
            msg['To'] = username
            msg.set_content(f'Your OTP is: {otp}')

            try:
                with smtplib.SMTP_SSL('smtp.gmail.com', 465) as smtp:
                    smtp.login(EMAIL_ADDRESS, EMAIL_PASSWORD)
                    smtp.send_message(msg)
            except Exception as e:
                return render_template('login.html', error="Failed to send OTP: " + str(e))

            session['pending_user'] = username
            return redirect(url_for('verify_otp'))
        else:
            return render_template('login.html', error="Invalid credentials")

    return render_template('login.html')

@app.route('/verify_otp', methods=['GET', 'POST'])
def verify_otp():
    if request.method == 'POST':
        entered_otp = request.form['otp']
        username = session.get('pending_user')

        if username and OTP_STORE.get(username) == entered_otp:
            cursor.execute("SELECT * FROM users WHERE username = %s", (username,))
            user = cursor.fetchone()
            session['username'] = username
            session['voter_id'] = user[3]
            OTP_STORE.pop(username, None)
            session.pop('pending_user', None)
            return redirect(url_for('dashboard'))
        else:
            return render_template('otp.html', error="Invalid OTP")

    return render_template('otp.html')

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        username = request.form['username']
        password = generate_password_hash(request.form['password'])
        voter_id = request.form['voter_id']

        try:
            cursor.execute(
                "INSERT INTO users (username, password, voter_id) VALUES (%s, %s, %s)",
                (username, password, voter_id)
            )
            db.commit()
            return redirect(url_for('login'))
        except mysql.connector.Error as err:
            return render_template('register.html', error=str(err))

    return render_template('register.html')

@app.route('/dashboard')
def dashboard():
    if 'username' not in session:
        return redirect(url_for('login'))

    return render_template('dashboard.html', username=session['username'])

@app.route('/vote', methods=['POST'])
def vote():
    if 'voter_id' not in session:
        return jsonify({'message': 'Not logged in'}), 401

    data = request.get_json()
    vote = data.get('vote')
    voter_id = session['voter_id']

    try:
        previous_hash = blockchain.get_previous_block()['hash']
        new_block = blockchain.create_block(voter_id, vote, previous_hash)

        cursor.execute(
            "INSERT INTO votes (voter_id, vote, block_hash) VALUES (%s, %s, %s)",
            (voter_id, vote, new_block['hash'])
        )
        db.commit()

        return jsonify({
            'message': 'Vote added successfully!',
            'block': new_block,
            'candidate_votes': blockchain.smart_contract.candidate_votes
        }), 201
    except ValueError as e:
        return jsonify({'message': str(e)}), 400
    except mysql.connector.Error as err:
        return jsonify({'message': f"Database error: {err}"}), 500

@app.route('/logout')
def logout():
    session.clear()
    return redirect(url_for('home'))

@app.route('/get_chain', methods=['GET'])
def get_chain():
    return jsonify({
        'chain': blockchain.chain,
        'candidate_votes': blockchain.smart_contract.candidate_votes
    }), 200

if __name__ == '__main__':
    app.run(debug=True)
