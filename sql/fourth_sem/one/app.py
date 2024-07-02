from flask import Flask, render_template, request, redirect, url_for
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)

db=mysql.connector.connect(
        host='localhost',
        user='root',
        password='12345',
        database='financial_db',
    )

from models import Student, Class, AttendanceRecord, Teacher, Subject

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/students')
def students():
    students = Student.query.all()
    return render_template('students.html', students=students)

@app.route('/add_student', methods=['POST'])
def add_student():
    name = request.form['name']
    new_student = Student(name=name)
    db.session.add(new_student)
    db.session.commit()
    return redirect(url_for('students'))

@app.route('/classes')
def classes():
    classes = Class.query.all()
    return render_template('classes.html', classes=classes)

@app.route('/add_class', methods=['POST'])
def add_class():
    name = request.form['name']
    new_class = Class(name=name)
    db.session.add(new_class)
    db.session.commit()
    return redirect(url_for('classes'))

@app.route('/attendance')
def attendance():
    records = AttendanceRecord.query.all()
    return render_template('attendance.html', records=records)

@app.route('/add_attendance', methods=['POST'])
def add_attendance():
    student_id = request.form['student_id']
    class_id = request.form['class_id']
    date = request.form['date']
    status = request.form['status']
    new_record = AttendanceRecord(student_id=student_id, class_id=class_id, date=date, status=status)
    db.session.add(new_record)
    db.session.commit()
    return redirect(url_for('attendance'))

@app.route('/teachers')
def teachers():
    teachers = Teacher.query.all()
    return render_template('teachers.html', teachers=teachers)

@app.route('/add_teacher', methods=['POST'])
def add_teacher():
    name = request.form['name']
    new_teacher = Teacher(name=name)
    db.session.add(new_teacher)
    db.session.commit()
    return redirect(url_for('teachers'))

@app.route('/subjects')
def subjects():
    subjects = Subject.query.all()
    return render_template('subjects.html', subjects=subjects)

@app.route('/add_subject', methods=['POST'])
def add_subject():
    name = request.form['name']
    new_subject = Subject(name=name)
    db.session.add(new_subject)
    db.session.commit()
    return redirect(url_for('subjects'))

if __name__ == '__main__':
    db.create_all()
    app.run(debug=True)
