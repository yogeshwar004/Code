from flask import Flask, render_template, request, redirect, url_for
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql://root:12345@localhost/attendance_db'
db = SQLAlchemy(app)

# Define SQLAlchemy model (example)
class AttendanceRecord(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    student_name = db.Column(db.String(100), nullable=False)
    date = db.Column(db.Date, nullable=False)
    status = db.Column(db.String(20), nullable=False)

    def __repr__(self):
        return f"<AttendanceRecord(student_name='{self.student_name}', date='{self.date}', status='{self.status}')>"

# Routes
@app.route('/')
def index():
    return render_template('index.html')

@app.route('/attendance')
def attendance():
    records = AttendanceRecord.query.all()
    return render_template('attendance.html', records=records)

@app.route('/add_record', methods=['POST'])
def add_record():
    student_name = request.form['student_name']
    date = datetime.strptime(request.form['date'], '%Y-%m-%d').date()
    status = request.form['status']

    new_record = AttendanceRecord(student_name=student_name, date=date, status=status)
    db.session.add(new_record)
    db.session.commit()
    
    return redirect(url_for('attendance'))

@app.route('/edit_record/<int:id>', methods=['GET', 'POST'])
def edit_record(id):
    record = AttendanceRecord.query.get_or_404(id)

    if request.method == 'POST':
        record.student_name = request.form['student_name']
        record.date = datetime.strptime(request.form['date'], '%Y-%m-%d').date()
        record.status = request.form['status']

        db.session.commit()
        return redirect(url_for('attendance'))
    
    return render_template('edit_record.html', record=record)

@app.route('/delete_record/<int:id>', methods=['POST'])
def delete_record(id):
    record = AttendanceRecord.query.get_or_404(id)
    db.session.delete(record)
    db.session.commit()
    
    return redirect(url_for('attendance'))

if __name__ == '__main__':
    with app.app_context():
        db.create_all()
    app.run(debug=True)
